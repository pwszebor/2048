//
// Created by pawel on 11/02/16.
//

#ifndef INC_2048_GAMELOGIC_H
#define INC_2048_GAMELOGIC_H

#include "subject.h"

namespace gameLogic2048 {

const int BOARD_SIZE = 16;

class GameLogic : public Subject {
public:
    GameLogic();
    ~GameLogic();

    void startGame();

private:
    void resetBoard();
    void spawnRandomTile();
    size_t getRandomIndex();
    int get2or4();

private:
    std::vector<int> board_;
};

} //gameLogic2048

#endif //INC_2048_GAMELOGIC_H
