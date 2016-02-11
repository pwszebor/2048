//
// Created by pawel on 11/02/16.
//

#include "tile.h"

Tile::Tile(int value, QGraphicsItem *parent) :
        QGraphicsPixmapItem(parent) {
    changeValue(value);
}

void Tile::changeValue(int value) {
    setPixmap(QPixmap(QString(":/tiles/%1.png").arg(value)));
}

