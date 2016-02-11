//
// Created by pawel on 11/02/16.
//

#ifndef INC_2048_OBSERVER_H
#define INC_2048_OBSERVER_H


class Observer {
public:
    virtual void applyUpdate() = 0;

    virtual ~Observer() {}
};


#endif //INC_2048_OBSERVER_H
