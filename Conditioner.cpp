//
// Created by German Albershteyn on 16.04.2024.
//

#include "Conditioner.h"
#include <memory>
#include <iostream>

void Conditioner::update(double temp, double pressure, double humid) {
    this->temperature = temp;
    this->pressure = pressure;
    display();
}
Conditioner::Conditioner(std::unique_ptr<Subject> data) {
    this->data = std::move(data);
}

void Conditioner::display() {
    std::cout << "Message from Conditioner" << std::endl << "Pressure is - " << this->pressure << std::endl << "Temperature is - " << this->temperature << std::endl;
}
