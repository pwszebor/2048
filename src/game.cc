//
// Created by pawel on 11/02/16.
//

#include "game.h"
#include <QApplication>
#include "mainWindow.h"
#include "gameLogic.h"

namespace game2048 {

Game &Game::getInstance() {
    static Game instance;
    return instance;
}

Game::Game() {

}

int Game::execute(int argc, char **argv) {
    QApplication app(argc, argv);
    auto window = std::make_shared<MainWindow>();

    gameLogic2048::GameLogic game;
    game.addObserver(window);
    game.startGame();

    window->show();
    return app.exec();
}

}//game2048