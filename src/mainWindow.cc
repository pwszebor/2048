#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QKeyEvent>
#include <QMessageBox>

MainWindow::MainWindow(std::shared_ptr<gameLogic2048::GameLogic> &game, QWidget *parent) :
        QMainWindow(parent),
        ui_(new Ui::MainWindow),
        scene_(new QGraphicsScene),
        game_(game) {
    ui_->setupUi(this);
    ui_->boardView_->setScene(scene_.get());
    scene_->setBackgroundBrush(QBrush(QPixmap(":/background/background.png")));
    scene_->setSceneRect(0, 0, 420, 420);

    connect(ui_->newGame_, &QPushButton::released, this, &MainWindow::newGame);
}

MainWindow::~MainWindow() {
}

void MainWindow::applyUpdate() {
    auto newState = game_->getState();

    for(auto index = 0; index < newState.size(); ++index) {
        auto value = newState.at(index);
        if(value != 0) {
            if(tiles_.count(index))
                tiles_.at(index)->changeValue(value);
            else
                tiles_[index] = std::make_shared<Tile>(value);
        }
        else if(tiles_.count(index))
            tiles_.erase(index);
    }
    updateScene();
    updateScore();

    if(game_->victory())
        victoryNotification();
}

void MainWindow::updateScore() {
    ui_->score_->setText(QString::number(game_->getScore()));
}

void MainWindow::updateScene() {
    for(auto tile : tiles_) {
        if(!scene_->items().contains(tile.second.get()))
            scene_->addItem(tile.second.get());
        tile.second->moveTo(tile.first);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_Right:
            game_->moveTilesRight();
            break;
        case Qt::Key_Left:
            game_->moveTilesLeft();
            break;
        case Qt::Key_Up:
            game_->moveTilesUp();
            break;
        case Qt::Key_Down:
            game_->moveTilesDown();
            break;
        default:
            break;
    }
    QWidget::keyPressEvent(event);
}

void MainWindow::newGame() {
    game_->startGame();
}

void MainWindow::victoryNotification() {
    QMessageBox victory(this);
    victory.setWindowTitle("Victory");
    victory.setText("You've won the game!");
    victory.addButton("Keep going", QMessageBox::AcceptRole);
    auto playAgainButton = victory.addButton("Play again", QMessageBox::ResetRole);
    connect(playAgainButton, SIGNAL(released()), this, SLOT(newGame()));
    victory.exec();
}
