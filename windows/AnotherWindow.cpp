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
    painter.drawPixmap(0, 0, controller.getLocation().getFont());
    painter.drawPixmap(controller.getPerson().getPosition(), QPixmap(":/sources/character.png"));
    for (auto npc: controller.getLocation().getNpc()) {
        painter.drawPixmap(npc.getPosition(), npc.getSprite());
    }
}

void AnotherWindow::updatePicture() {
    QPoint newPoint(controller.getPerson().getPosition().x() + controller.getPerson().getSpeed().first,
                     controller.getPerson().getPosition().y() + controller.getPerson().getSpeed().second);
    controller.getPerson().setNewSpeed(0, 0);
    if (controller.getLocation().getBorder().containsPoint(newPoint, Qt::OddEvenFill)) {
        controller.getPerson().setPosition(newPoint);
        repaint();
    }

    for(auto npc : controller.getLocation().getNpc()){
        if(QPolygonF(QRectF(npc.getPosition(), QSize(40, 70))).containsPoint(
                AnotherWindow::mapFromGlobal(QCursor::pos()), Qt::OddEvenFill)){
                    ui->centralwidget->setCursor(QCursor(QPixmap(":/sources/cursor.png")));
        }else{
            ui->centralwidget->setCursor(QCursor());
        }
    }

}

void AnotherWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) {
        controller.getPerson().setNewSpeed(0, -5);
    } else if (event->key() == Qt::Key_A) {
        controller.getPerson().setNewSpeed(-5, 0);
    } else if (event->key() == Qt::Key_S) {
        controller.getPerson().setNewSpeed(0, 5);
    } else if (event->key() == Qt::Key_D) {
        controller.getPerson().setNewSpeed(5, 0);
    }
}

