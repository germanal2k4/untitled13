//
// Created by German Albershteyn on 16.04.2024.
//

#include "Conditioner.h"
#include <memory>

void Conditioner::update(double temp, double pressure, double humid) {
}
Conditioner::Conditioner(const Subject& data) {
    this->data = (Data&) data;
}