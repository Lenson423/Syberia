#include "AnotherWindow.h"

#include "ui_anotherwindow.h"

AnotherWindow::AnotherWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::AnotherWindow) {
    ui->setupUi(this);

    controller.loadNewLocation(currentLevel);

    connect(&timer, SIGNAL(timeout()), SLOT(updatePicture()));
    timer.start(10);
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
        if(controller.dialIsActive()){
            painter.drawText(200, 435, currDialog.getReplics()[currDialog.getCurrentStep()]);
            currDialog.inkCurrentStep();
           if(currDialog.getCurrentStep() == currDialog.getReplics().size()){
               currDialog.eraseCurrentStep();
               controller.setDialogActivity(false);
          }

        }else{
            for (int i = 0; i < controller.getNpc()->getDialogs().size(); ++i) {
                painter.drawText(200, 435 + i * 20, QString(controller.getNpc()->getDialogs()[i].second));
            }
            for (int i = 0; i < controller.getNpc()->getDialogs().size(); ++i) {
                painter.drawRect(controller.getButtonsForDialog()[i]);
            }
        }
    }else if (mode == Inventory){
        screen.fill(QColorConstants::Black);
        painter.drawPixmap(0, 0, screen);
    }
}

void AnotherWindow::updatePicture() {
    if (mode == Game) {
        QPoint newPoint(controller.getPerson().getPosition().x() + controller.getPerson().getSpeed().first,
                        controller.getPerson().getPosition().y() + controller.getPerson().getSpeed().second);
        controller.getPerson().setNewSpeed(0, 0);
        if (controller.getLocation().getBorder().containsPoint(newPoint, Qt::OddEvenFill)) {
            controller.getPerson().setPosition(newPoint);
            repaint();
        }

        for (auto npc: controller.getLocation().getNpc()) {
            if (checkNpcPosition(npc)) {
                ui->centralwidget->setCursor(QCursor(QPixmap(":/sources/cursor.png")));
            } else {
                ui->centralwidget->setCursor(QCursor());
            }
        }
    } else if (mode == Dialog) {
    }
}


void AnotherWindow::keyPressEvent(QKeyEvent *event) {
    if(mode == Game){
        if (event->key() == Qt::Key_W) {
            controller.getPerson().setNewSpeed(0, -5);
        } else if (event->key() == Qt::Key_A) {
            controller.getPerson().setNewSpeed(-5, 0);
        } else if (event->key() == Qt::Key_S) {
            controller.getPerson().setNewSpeed(0, 5);
        } else if (event->key() == Qt::Key_D) {
            controller.getPerson().setNewSpeed(5, 0);
        }else if (event->key() == Qt::Key_Escape) {
            screen = QWidget::grab();
            mode = Inventory;
        }
    }else if(mode == Mode::Dialog){
        if (event->key() == Qt::Key_Space) {
            repaint();
        }else if(event->key() == Qt::Key_Escape && !controller.dialIsActive()){
            mode = Game;
        }

    }else if ( mode == Mode::Inventory){
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
        }else if (mode == Dialog) {
            if(!controller.dialIsActive()) {
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
        }
    }
}

void AnotherWindow::loadCurrnetDialog() {
    currDialog = controller.getNpc()->getDialogs()[controller.getDialogNum()].first;
}


