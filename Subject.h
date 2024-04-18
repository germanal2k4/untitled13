//
// Created by German Albershteyn on 16.04.2024.
//

#ifndef UNTITLED13_SUBJECT_H
#define UNTITLED13_SUBJECT_H
#include "Observer.h"
#include <memory>

class Subject{
public:
    virtual void registerObserver(const std::weak_ptr<Observer>& o) = 0;
    virtual void notifyObserver() = 0;
    virtual void removeObserver(const std::weak_ptr<Observer>& o) = 0;
    virtual ~Subject() = default;
};
#endif //UNTITLED13_SUBJECT_H
