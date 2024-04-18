#include <iostream>
#include "Data.h"
#include "Conditioner.h"
#include "memory"
#include "Barometr.h"

int main() {
    auto data = Data();
    auto dataPtr = std::make_unique<Data>(data);
    auto conditionerPtr = std::make_shared<Conditioner>(std::move(dataPtr));
    data.registerObserver(conditionerPtr);
    auto pressurePtr = std::make_shared<Barometr>(std::move(dataPtr));
    data.registerObserver(pressurePtr);
    data.setMeasurements(20.0, 10.0, 20.0);
    data.removeObserver(conditionerPtr);
    data.setMeasurements(20.0, 20.0, 20.0);
}
