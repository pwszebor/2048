//
// Created by pawel on 11/02/16.
//

#ifndef INC_2048_GAMELOGIC_H
#define INC_2048_GAMELOGIC_H

#include "subject.h"

namespace gameLogic2048 {

const int BOARD_SIZE = 16;
const int ROWS = 4;
const int VICTORY = 2048;

class GameLogic : public Subject {
public:
    GameLogic();
    ~GameLogic();

    void startGame();
    void moveTilesRight();
    void moveTilesLeft();
    void moveTilesUp();
    void moveTilesDown();

    std::vector<int> getState() const;
    int getScore() const;
    bool victory() const;

private:
    int moveRight();
    int moveLeft();
    int moveUp();
    int moveDown();
    int combineRight();
    int combineLeft();
    int combineUp();
    int combineDown();
    void resetBoard();
    void spawnRandomTile();
    size_t getRandomIndex();
    int get2or4();

private:
    std::vector<int> board_;
    int score_;
    bool victory_;
};

} //gameLogic2048

#endif //INC_2048_GAMELOGIC_H
