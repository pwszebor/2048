//
// Created by pawel on 11/02/16.
//

#ifndef INC_2048_GAME_H
#define INC_2048_GAME_H

namespace game2048 {

class Game {
public:
    static Game &getInstance();

    int execute(int argc, char **argv);

private:
    Game();
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
};

} //game2048

#endif //INC_2048_GAME_H
