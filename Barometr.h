//
// Created by German Albershteyn on 18.04.2024.
//

#ifndef UNTITLED13_BAROMETR_H
#define UNTITLED13_BAROMETR_H

#include "Data.h"
#include "DisplayElem.h"
#include "Observer.h"
#include <memory>

class Barometr : public DisplayElem, public Observer{
    double temperature;
    double humidity;
    std::shared_ptr<Subject> data;
public:
    void update(double temp, double pressure, double humid) override;
    void display() override;
};


#endif //UNTITLED13_BAROMETR_H
