#include "AnotherWindow.h"

#include "ui_anotherwindow.h"

AnotherWindow::AnotherWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::AnotherWindow) {
    ui->setupUi(this);

    controller.loadNewLocation(currentLevel);
    settingsWindow = new SettingsWindow();
    settingsWindow->setFixedSize(400, 300);

    QTimer::singleShot(1, this, SLOT(startMusic()));
    connect(&timer, SIGNAL(timeout()), SLOT(updatePicture()));
    timer.start(20);

    tempDir.setAutoRemove(false);
    connect(&musicTimer, SIGNAL(timeout()), SLOT(startMusic()));
    musicTimer.start(49000);
}

AnotherWindow::~AnotherWindow() {
    delete ui;
}

void AnotherWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (mode == Game) {
        painter.drawPixmap(0, 0, controller.getLocation().getFont());
        for (auto npc: controller.getLocation().getNpc()) {
            painter.drawPixmap(npc.getPosition(), npc.getSprite());
        }
        for (auto item: controller.getLocation().getItem()) {
            if (!controller.getInventory().findItemWithId(item.getId())) {
                painter.drawPixmap(item.getPoint().x(), item.getPoint().y(), 25, 25,
                                   item.getImage());
            }
        }
        if (!inMoovements) {
            painter.drawPixmap(controller.getPerson().getPosition(), QPixmap(":/sources/character.png"));
        } else {
            QString tmp = ":/sources/character" + QString::number(QTime::currentTime().second() % 2) + ".png";
            painter.drawPixmap(controller.getPerson().getPosition(), QPixmap(tmp));
        }
    } else if (mode == Dialog) {
        painter.drawPixmap(0, 0, QPixmap(":/sources/dialog_font.png"));
        painter.drawPixmap(175, 400, QPixmap(":/sources/dialog_border.png"));
        if (controller.dialIsActive()) {
            painter.drawText(200, 435, currDialog.getReplics()[currDialog.getCurrentStep()]);
            currDialog.inkCurrentStep();
            if (currDialog.getCurrentStep() == currDialog.getReplics().size()) {
                currDialog.eraseCurrentStep();
                controller.setDialogActivity(false);
            }

        } else {
            for (int i = 0; i < controller.getNpc()->getDialogs().size(); ++i) {
                painter.drawText(200, 435 + i * 20, QString(controller.getNpc()->getDialogs()[i].second));
            }
        }
    } else if (mode == Inventory) {
        painter.drawPixmap(0, 0, screen);
        painter.setOpacity(0.75);
        painter.setBrush(QBrush(QColorConstants::DarkGray));
        painter.drawRect(0, 0, 150, 600);
        painter.setOpacity(1);
        painter.setBrush(QBrush());
        painter.drawPixmap(0, 0, QPixmap(":/sources/menu.png"));
        painter.drawPixmap(50, 0, QPixmap(":/sources/settings.png"));
        painter.drawPixmap(100, 0, QPixmap(":/sources/save.png"));

        int i = 1;
        for (Item item: controller.getInventory().getItems()) {
            painter.drawPixmap(25, 110 * i, QPixmap(":/sources/item_border.png"));
            painter.drawPixmap(35, 110 * i + 10, 80, 80, item.getImage());
            ++i;
        }
    } else if (mode == ViewingOfImage) {
        painter.drawPixmap(0, 0, QPixmap(":/sources/viewing_image_background.png"));
        painter.drawPixmap((845 - tmpItem->getImage().width()) / 2, (575 - tmpItem->getImage().height()) / 2,
                           tmpItem->getImage());
    }
}

void AnotherWindow::updatePicture() {
    inMoovements = false;
    if (mode == Game) {
        if (isNeedToReload) {
            QPointF tmp = controller.getPerson().getPosition();
            controller.loadNewLocation(currentLevel);
            controller.getPerson().setPosition(tmp);
            isNeedToReload = false;
        }
        QPoint newPoint(controller.getPerson().getPosition().x() + controller.getPerson().getSpeed().first,
                        controller.getPerson().getPosition().y() + controller.getPerson().getSpeed().second);
        if (controller.getLocation().getBorder().containsPoint(newPoint, Qt::OddEvenFill)) {
            if (newPoint != controller.getPerson().getPosition()) {
                inMoovements = true;
                controller.getPerson().setPosition(newPoint);
            }
            repaint();
        }

        ui->centralwidget->setCursor(QCursor());

        for (auto npc: controller.getLocation().getNpc()) {
            if (checkNpcPosition(npc)) {
                ui->centralwidget->setCursor(QCursor(QPixmap(":/sources/cursor.png")));
            }
        }

        for (auto portal: controller.getLocation().getPortals()) {
            if (checkPortalPosition(portal)) {
                ui->centralwidget->setCursor(QCursor(QPixmap(":/sources/cursor2.png")));
            }
        }
    } else if (mode == Dialog) {
    }
}

void AnotherWindow::keyReleaseEvent(QKeyEvent *event) {
    if (mode == Game) {
        if (event->nativeVirtualKey() == Qt::Key_A || event->nativeVirtualKey() == Qt::Key_D) {
            controller.getPerson().setNewSpeed(0, controller.getPerson().getSpeed().second);
        }
        if (event->nativeVirtualKey() == Qt::Key_W || event->nativeVirtualKey() == Qt::Key_S) {
            controller.getPerson().setNewSpeed(controller.getPerson().getSpeed().first, 0);
        }
    }
}

void AnotherWindow::keyPressEvent(QKeyEvent *event) {
    if (mode == Game) {
        if (event->nativeVirtualKey() == Qt::Key_W) {
            controller.getPerson().setNewSpeed(controller.getPerson().getSpeed().first, -3);
        }
        if (event->nativeVirtualKey() == Qt::Key_A) {
            controller.getPerson().setNewSpeed(-3, controller.getPerson().getSpeed().second);
        }
        if (event->nativeVirtualKey() == Qt::Key_S) {
            controller.getPerson().setNewSpeed(controller.getPerson().getSpeed().first, 3);
        }
        if (event->nativeVirtualKey() == Qt::Key_D) {
            controller.getPerson().setNewSpeed(3, controller.getPerson().getSpeed().second);
        }
        if (event->key() == Qt::Key_Escape) {
            screen = QWidget::grab();
            mode = Inventory;
            ui->centralwidget->setCursor(QCursor());
            repaint();
        }
    } else if (mode == Mode::Dialog) {
        if (event->key() == Qt::Key_Space) {
            startMusicEffect(":/sources/dialog_click_music.wav");
            repaint();
        } else if (event->key() == Qt::Key_Escape && !controller.dialIsActive()) {
            mode = Game;
        }

    } else if (mode == Mode::Inventory) {
        if (event->key() == Qt::Key_Escape) {
            mode = Game;
            repaint();
        }
    } else if (mode == ViewingOfImage) {
        if (event->key() == Qt::Key_Escape) {
            mode = Inventory;
            repaint();
        }
    }

}

bool AnotherWindow::checkNpcPosition(NPC &npc) {
    auto distanceBetweenYouAndNpc = (controller.getPerson().getPosition() - npc.getPosition()).manhattanLength();
    return QPolygonF(QRectF(npc.getPosition(), QSize(40, 70))).containsPoint(
            AnotherWindow::mapFromGlobal(QCursor::pos()), Qt::OddEvenFill)
           && distanceBetweenYouAndNpc < 95;
}

void AnotherWindow::mousePressEvent(QMouseEvent *event) {
    qDebug() << event->pos();
    if (event->button() == 1) {
        if (mode == Game) {
            for (auto npc: controller.getLocation().getNpc()) {
                if (checkNpcPosition(npc)) {
                    controller.setCurrentNpc(npc);
                    controller.clearButtonForDialog();
                    for (int i = 0; i < controller.getNpc()->getDialogs().size(); ++i) {
                        controller.addButtonForDialog(QRect(200, 422 + 20 * i, 200, 20));
                    }
                    ui->centralwidget->setCursor(QCursor());
                    mode = Dialog;
                    startMusicEffect(":/sources/on_npc_clicked_music.wav");
                    repaint();
                    break;
                }
            }
            for (auto portal: controller.getLocation().getPortals()) {
                if (checkPortalPosition(portal)) {
                    controller.loadNewLocation(portal.getNextLocationId());
                    currentLevel = portal.getNextLocationId();
                    startMusicEffect(":/sources/new_location.wav");
                    repaint();
                }
            }

            auto tmp = controller.getItemsPosition();
            for (auto it = tmp.begin(); it != tmp.end(); ++it) {
                if (it.key().contains(event->pos())) {
                    controller.addItemToInventory(controller.getLocation().getItem()[it.value()]);
                }
            }
        } else if (mode == Dialog) {
            if (!controller.dialIsActive()) {
                for (int i = 0; i < controller.getButtonsForDialog().size(); ++i) {
                    if (controller.getButtonsForDialog()[i].contains
                            (AnotherWindow::mapFromGlobal(QCursor::pos()), Qt::OddEvenFill)) {
                        controller.setDialogActivity(true);
                        controller.setCurrentDialogNum(i);
                        loadCurrnetDialog();
                        startMusicEffect(":/sources/dialog_click_music.wav");
                        break;
                    }
                }
                repaint();
            }
        } else if (mode == Inventory) {
            if (QRect(0, 0, 50, 50).contains(event->pos())) {
                this->close();
            } else if (QRect(50, 0, 50, 50).contains(event->pos())) {
                settingsWindow->show();
                isNeedToReload = true;
            } else if (QRect(100, 0, 50, 50).contains(event->pos())) {
                saveFile();
            }
            auto tmp = controller.getItemsInInventory();
            for (auto it = tmp.begin(); it != tmp.end(); ++it) {
                if (it.key().contains(event->pos())) {
                    mode = ViewingOfImage;
                    tmpItem = &it.value();
                    repaint();
                    qDebug() << mode;
                }
            }
        }
    }
}

void AnotherWindow::loadCurrnetDialog() {
    currDialog = controller.getNpc()->getDialogs()[controller.getDialogNum()].first;
}

bool AnotherWindow::checkPortalPosition(Portal &portal) {
    auto distanceBetweenYouAndPortal = (controller.getPerson().getPosition() - portal.getPortalBorder().topLeft())
            .manhattanLength();
    return QPolygon(portal.getPortalBorder()).containsPoint(
            AnotherWindow::mapFromGlobal(QCursor::pos()), Qt::OddEvenFill)
           && distanceBetweenYouAndPortal < 95;
}

void AnotherWindow::saveFile() {
    QString path = qApp->applicationDirPath(); //location of the file, assuming in application dir
    QString name = "./syberia" + QTime::currentTime().toString("hh.mm.ss") + ".syb";
    path.append(name);
    QFile fileUrl(path);
    if (fileUrl.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&fileUrl);
        out << currentLevel << Qt::endl;
        out << controller.getPerson().getPosition().x() << " " << controller.getPerson().getPosition().y() << Qt::endl;
        for (const auto &elem: controller.getInventory().getItems()) {
            out << elem.getId() << " ";
        }
    }
}

void AnotherWindow::loadFile(const QString &path) {
    QFile fileUrl(path);
    if (fileUrl.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&fileUrl);
        currentLevel = in.readLine().toInt();
        QList<QString> tmp = in.readLine().split(" ");
        for (const auto &elem: in.readLine().split(" ")) {
            for (int i = 1; i <= LevelCount; ++i) {
                controller.loadNewLocation(i);
                if (controller.getLocation().getItem().contains(elem.toInt())) {
                    controller.addItemToInventory(controller.getLocation().getItem()[elem.toInt()]);
                }
            }
        }
        controller.loadNewLocation(currentLevel);
        controller.getPerson().setPosition(QPointF(tmp[0].toDouble(), tmp[1].toDouble()));
    }
}

void AnotherWindow::startMusic() {
    Music music;
    QString tempFile = tempDir.path() + "/tmp.wav";
    if (tempDir.isValid()) {
        QFile::copy(":/sources/music_menu.wav", tempFile);
        music.play(QFileInfo(tempFile));
    }
}

void AnotherWindow::closeEvent(QCloseEvent *event) {
    tempDir.remove();
    QMainWindow::closeEvent(event);
}

void AnotherWindow::startMusicEffect(const QString &link) {
    Music music;
    QString tempFile = tempDir.path() + "/" + link.split("/").back();
    if (tempDir.isValid()) {
        QFile::copy(link, tempFile);
        music.play(QFileInfo(tempFile));
    }
}

