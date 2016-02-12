//
// Created by pawel on 11/02/16.
//

#include "game.h"
#include <QApplication>
#include "mainWindow.h"

namespace game2048 {

Game &Game::getInstance() {
    static Game instance;
    return instance;
}

Game::Game() {

}

int Game::execute(int argc, char **argv) {
    QApplication app(argc, argv);

    auto game = std::make_shared<gameLogic2048::GameLogic>();
    auto window = std::make_shared<MainWindow>(std::ref(game));

    game->addObserver(window);
    game->startGame();

    window->show();
    return app.exec();
}

}//game2048