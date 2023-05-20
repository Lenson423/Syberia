#include "AnotherWindow.h"

#include "ui_anotherwindow.h"

AnotherWindow::AnotherWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::AnotherWindow) {
    ui->setupUi(this);

    controller.loadNewLocation(currentLevel);
    settingsWindow = new SettingsWindow();
    settingsWindow->setFixedSize(400, 300);

    connect(&timer, SIGNAL(timeout()), SLOT(updatePicture()));
    timer.start(20);
}

AnotherWindow::~AnotherWindow() {
    delete ui;
}

void AnotherWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (mode == Game) {
        painter.drawPixmap(0, 0, controller.getLocation().getFont());
        painter.drawPixmap(controller.getPerson().getPosition(), QPixmap(":/sources/character.png"));
        for (auto npc: controller.getLocation().getNpc()) {
            painter.drawPixmap(npc.getPosition(), npc.getSprite());
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
        painter.setBrush(QBrush(QColorConstants::DarkGray));
        painter.drawRect(0, 0, 150, 600);
        painter.setBrush(QBrush());
        painter.drawPixmap(0, 0, QPixmap(":/sources/menu.png"));
        painter.drawPixmap(50, 0, QPixmap(":/sources/settings.png"));
        painter.drawPixmap(100, 0, QPixmap(":/sources/save.png"));
    }
}

void AnotherWindow::updatePicture() {
    if (mode == Game) {
        QPoint newPoint(controller.getPerson().getPosition().x() + controller.getPerson().getSpeed().first,
                        controller.getPerson().getPosition().y() + controller.getPerson().getSpeed().second);
        if (controller.getLocation().getBorder().containsPoint(newPoint, Qt::OddEvenFill)) {
            controller.getPerson().setPosition(newPoint);
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
        if (event->key() == Qt::Key_A || event->key() == Qt::Key_D) {
            controller.getPerson().setNewSpeed(0, controller.getPerson().getSpeed().second);
        }
        if (event->key() == Qt::Key_W || event->key() == Qt::Key_S) {
            controller.getPerson().setNewSpeed(controller.getPerson().getSpeed().first, 0);
        }
    }
}

void AnotherWindow::keyPressEvent(QKeyEvent *event) {
    if (mode == Game) {
        if (event->key() == Qt::Key_W) {
            controller.getPerson().setNewSpeed(controller.getPerson().getSpeed().first, -3);
        }
        if (event->key() == Qt::Key_A) {
            controller.getPerson().setNewSpeed(-3, controller.getPerson().getSpeed().second);
        }
        if (event->key() == Qt::Key_S) {
            controller.getPerson().setNewSpeed(controller.getPerson().getSpeed().first, 3);
        }
        if (event->key() == Qt::Key_D) {
            controller.getPerson().setNewSpeed(3, controller.getPerson().getSpeed().second);
        }
        if (event->key() == Qt::Key_Escape) {
            screen = QWidget::grab();
            mode = Inventory;
            repaint();
        }
    } else if (mode == Mode::Dialog) {
        if (event->key() == Qt::Key_Space) {
            repaint();
        } else if (event->key() == Qt::Key_Escape && !controller.dialIsActive()) {
            mode = Game;
        }

    } else if (mode == Mode::Inventory) {
        if (event->key() == Qt::Key_Escape) {
            mode = Game;
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
                    repaint();
                    break;
                }
            }
            for (auto portal: controller.getLocation().getPortals()) {
                if (checkPortalPosition(portal)) {
                    controller.loadNewLocation(portal.getNextLocationId());
                    currentLevel = portal.getNextLocationId();
                    repaint();
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
            } else if (QRect(100, 0, 50, 50).contains(event->pos())) {
                saveFile();
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
    QString name = "./syberia" + QTime::currentTime().toString("hh.mm.ss") + ".txt";
    path.append(name);
    QFile fileUrl(path);
    if (fileUrl.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&fileUrl);
        out << currentLevel << Qt::endl;
        out << controller.getPerson().getPosition().x() << " " << controller.getPerson().getPosition().y();
    }
}

void AnotherWindow::loadFile(const QString &path) {
    QFile fileUrl(path);
    if (fileUrl.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&fileUrl);
        currentLevel = in.readLine().toInt();
        controller.loadNewLocation(currentLevel);
        QList<QString> tmp = in.readLine().split(" ");
        controller.getPerson().setPosition(QPointF(tmp[0].toDouble(), tmp[1].toDouble()));
    }
}

