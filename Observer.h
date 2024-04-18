//
// Created by German Albershteyn on 16.04.2024.
//

#ifndef UNTITLED13_OBSERVER_H
#define UNTITLED13_OBSERVER_H
class Observer{
public:
    virtual void update(double temp, double pressure, double humid) = 0;
    virtual ~Observer() = default;
};
#endif //UNTITLED13_OBSERVER_H
