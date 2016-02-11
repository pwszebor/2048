//
// Created by pawel on 11/02/16.
//

#include "game.h"

int main(int argc, char **argv) {
    return game2048::Game::getInstance().execute(argc, argv);
}