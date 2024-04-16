//
// Created by German Albershteyn on 16.04.2024.
//

#ifndef UNTITLED13_CONDITIONER_H
#define UNTITLED13_CONDITIONER_H

#include "Data.h"
#include "DisplayElem.h"
#include "Observer.h"

class Conditioner : public DisplayElem, Observer{
private:
    double temperature;
    double pressure;
    Data data;
public:
    explicit Conditioner(const Subject &data);
    void update(double temp, double pressure, double humid) override;

};


#endif //UNTITLED13_CONDITIONER_H
