//
// Created by pawel on 11/02/16.
//

#ifndef INC_2048_SUBJECT_H
#define INC_2048_SUBJECT_H

#include <memory>
#include <vector>
#include "observer.h"

class Subject {
public:
    virtual void notify() {
        for(auto observer : observers_)
            observer->applyUpdate();
    }

    virtual void addObserver(std::shared_ptr<Observer> observer) {
        observers_.push_back(observer);
    }

private:
    std::vector<std::shared_ptr<Observer>> observers_;
};

#endif //INC_2048_SUBJECT_H
