//
// Created by German Albershteyn on 18.04.2024.
//

#include "Barometr.h"
#include "memory"
#include <iostream>

void Barometr::update(double temp, double pressure, double humid) {
    this->temperature = temp;
    this->humidity = humid;
    display();
}
Barometr::Barometr(std::unique_ptr<Subject> data) {
    this->data = std::move(data);
}

void Barometr::display() {
    std::cout << "Message from Baro" << std::endl << "Humidity is - " << this->humidity << std::endl << "Temperature is - " << this->temperature << std::endl;
}