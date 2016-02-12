#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QGraphicsScene>
#include "observer.h"
#include "tile.h"
#include "gameLogic.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<gameLogic2048::GameLogic> &game, QWidget *parent = nullptr);
    ~MainWindow();

    virtual void applyUpdate() override;

protected:
    virtual void keyPressEvent(QKeyEvent *keyEvent) override;

private slots:
    void newGame();

private:
    void updateScore();
    void updateScene();
    void victoryNotification();

private:
    std::unique_ptr<Ui::MainWindow> ui_;
    std::unique_ptr<QGraphicsScene> scene_;
    std::shared_ptr<gameLogic2048::GameLogic> game_;
    std::map<int, std::shared_ptr<Tile> > tiles_;
};

#endif // MAINWINDOW_H
