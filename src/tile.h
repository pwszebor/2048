//
// Created by pawel on 11/02/16.
//

#ifndef INC_2048_TILE_H
#define INC_2048_TILE_H

#include <QGraphicsPixmapItem>

class Tile : public QGraphicsPixmapItem {
public:
    Tile(int value, QGraphicsItem *parent = nullptr);
    void changeValue(int value);
};


#endif //INC_2048_TILE_H
