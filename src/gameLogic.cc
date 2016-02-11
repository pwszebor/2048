//
// Created by pawel on 11/02/16.
//

#include "gameLogic.h"
#include <random>

namespace gameLogic2048 {

GameLogic::GameLogic() :
        board_(BOARD_SIZE, 0) {
}

GameLogic::~GameLogic() {
}

void GameLogic::startGame() {
    resetBoard();
    spawnRandomTile();
    notify();
    spawnRandomTile();
    notify();
}


void GameLogic::resetBoard() {
    if(board_.size() == BOARD_SIZE)
        std::fill(board_.begin(), board_.end(), 0);
    else {
        board_.clear();
        board_.insert(board_.begin(), 16, 0);
    }
}

void GameLogic::spawnRandomTile() {
    auto index = getRandomIndex();
    while(board_.at(index) != 0) {
        index = getRandomIndex();
    }
    board_.at(index) = get2or4();
}

size_t GameLogic::getRandomIndex() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    return static_cast<size_t>(dis(gen));
}

int GameLogic::get2or4() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    return dis(gen) > 0.1 ? 2 : 4;
}

}//gameLogic2048