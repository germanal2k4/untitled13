//
// Created by German Albershteyn on 16.04.2024.
//

#ifndef UNTITLED13_CONDITIONER_H
#define UNTITLED13_CONDITIONER_H

#include "Data.h"
#include "DisplayElem.h"
#include "Observer.h"
#include <memory>

class Conditioner : public DisplayElem, public Observer{
private:
    double temperature;
    double pressure;
    std::unique_ptr<Subject> data;
public:
    explicit Conditioner(std::unique_ptr<Subject> data);
    void update(double temp, double pressure, double humid) override;
    void display() override;
};


#endif //UNTITLED13_CONDITIONER_H
