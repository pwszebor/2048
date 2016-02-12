//
// Created by pawel on 11/02/16.
//

#include "gameLogic.h"
#include <random>

namespace gameLogic2048 {

GameLogic::GameLogic() :
        board_(BOARD_SIZE, 0),
        score_(0),
        victory_(false) {
}

GameLogic::~GameLogic() {
}

std::vector<int> GameLogic::getState() const {
    return board_;
}

void GameLogic::startGame() {
    score_ = 0;
    victory_ = false;
    resetBoard();
    spawnRandomTile();
    spawnRandomTile();
    notify();
}

void GameLogic::moveTilesRight() {
    if(moveRight() + combineRight() + moveRight()) {
        spawnRandomTile();
        notify();
    }
}

void GameLogic::moveTilesLeft() {
    if(moveLeft() + combineLeft() + moveLeft()) {
        spawnRandomTile();
        notify();
    }
}

void GameLogic::moveTilesUp() {
    if(moveUp() + combineUp() + moveUp()) {
        spawnRandomTile();
        notify();
    }
}

void GameLogic::moveTilesDown() {
    if(moveDown() + combineDown() + moveDown()) {
        spawnRandomTile();
        notify();
    }
}

void GameLogic::resetBoard() {
    if(board_.size() == BOARD_SIZE)
        std::fill(board_.begin(), board_.end(), 0);
    else {
        board_.clear();
        board_.insert(board_.begin(), BOARD_SIZE, 0);
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
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, BOARD_SIZE - 1);

    return static_cast<size_t>(distribution(generator));
}

int GameLogic::get2or4() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<> distribution(0, 1);

    return distribution(generator) > 0.1 ? 2 : 4;
}

int GameLogic::moveRight() {
    int movements = 0;
    for(int row = 0; row < ROWS; ++row) {
        for(int column = ROWS - 2; column >= 0; --column) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            while(index < row * ROWS + ROWS - 1 && board_.at(index + 1) == 0) {
                board_.at(index + 1) = board_.at(index);
                board_.at(index) = 0;
                ++movements;
                ++index;
            }
        }
    }
    return movements;
}

int GameLogic::moveLeft() {
    int movements = 0;
    for(int row = 0; row < ROWS; ++row) {
        for(int column = 1; column <= ROWS - 1; ++column) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            while(index > row * ROWS && board_.at(index - 1) == 0) {
                board_.at(index - 1) = board_.at(index);
                board_.at(index) = 0;
                --index;
                ++movements;
            }
        }
    }
    return movements;
}

int GameLogic::moveUp() {
    int movements = 0;
    for(int column = 0; column < ROWS; ++column) {
        for(int row = 1; row <= ROWS - 1; ++row) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            while(index > column && board_.at(index - ROWS) == 0) {
                board_.at(index - ROWS) = board_.at(index);
                board_.at(index) = 0;
                index -= ROWS;
                ++movements;
            }
        }
    }
    return movements;
}

int GameLogic::moveDown() {
    int movements = 0;
    for(int column = 0; column < ROWS; ++column) {
        for(int row = ROWS - 2; row >= 0; --row) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            while(index < (ROWS - 1) * ROWS + column && board_.at(index + ROWS) == 0) {
                board_.at(index + ROWS) = board_.at(index);
                board_.at(index) = 0;
                index += ROWS;
                ++movements;
            }
        }
    }
    return movements;
}

int GameLogic::combineRight() {
    int recombinations = 0;
    for(int row = 0; row < ROWS; ++row) {
        for(int column = ROWS - 1; column >= 1; --column) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            if(board_.at(index - 1) == board_.at(index)) {
                board_.at(index) *= 2;
                board_.at(index - 1) = 0;
                score_ += board_.at(index);
                if(board_.at(index) == VICTORY)
                    victory_ = true;
                ++recombinations;
            }
        }
    }
    return recombinations;
}

int GameLogic::combineLeft() {
    int recombinations = 0;
    for(int row = 0; row < ROWS; ++row) {
        for(int column = 0; column <= ROWS - 2; ++column) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            if(board_.at(index + 1) == board_.at(index)) {
                board_.at(index) *= 2;
                board_.at(index + 1) = 0;
                score_ += board_.at(index);
                if(board_.at(index) == VICTORY)
                    victory_ = true;
                ++recombinations;
            }
        }
    }
    return recombinations;
}

int GameLogic::combineUp() {
    int recombinations = 0;
    for(int column = 0; column < ROWS; ++column) {
        for(int row = 0; row <= ROWS - 2; ++row) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            if(board_.at(index + ROWS) == board_.at(index)) {
                board_.at(index) *= 2;
                board_.at(index + ROWS) = 0;
                score_ += board_.at(index);
                if(board_.at(index) == VICTORY)
                    victory_ = true;
                ++recombinations;
            }
        }
    }
    return recombinations;
}

int GameLogic::combineDown() {
    int recombinations = 0;
    for(int column = 0; column < ROWS; ++column) {
        for(int row = ROWS - 1; row >= 1; --row) {
            int index = row * ROWS + column;
            if(board_.at(index) == 0)
                continue;
            if(board_.at(index - ROWS) == board_.at(index)) {
                board_.at(index) *= 2;
                board_.at(index - ROWS) = 0;
                score_ += board_.at(index);
                if(board_.at(index) == VICTORY)
                    victory_ = true;
                ++recombinations;
            }
        }
    }
    return recombinations;
}

int GameLogic::getScore() const {
    return score_;
}

bool GameLogic::victory() const {
    return victory_;
}

}//gameLogic2048