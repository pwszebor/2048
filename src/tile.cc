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

void Tile::moveTo(int index) {
    auto position = pos();
    moveBy(-position.x(), -position.y());

    int row = index / 4;
    int column = index % 4;

    int dx = 5 + column * 105;
    int dy = 5 + row * 105;

    moveBy(dx, dy);
}
