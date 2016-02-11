#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui_(new Ui::MainWindow),
        scene_(new QGraphicsScene) {
    ui_->setupUi(this);
    ui_->boardView_->setScene(scene_.get());
    scene_->setBackgroundBrush(QBrush(QPixmap(":/background/background.png")));
}

MainWindow::~MainWindow() {
}

void MainWindow::applyUpdate() {

}
