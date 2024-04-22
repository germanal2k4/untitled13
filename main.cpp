#include <iostream>
#include "Data.h"
#include "Conditioner.h"
#include "memory"
#include "Barometr.h"

int main() {
    auto dataPtr = std::make_shared<Data>();
    auto conditionerPtr = std::make_shared<Conditioner>();
    dataPtr->registerObserver(conditionerPtr);
    auto pressurePtr = std::make_shared<Barometr>();
    dataPtr->registerObserver(pressurePtr);
    dataPtr->setMeasurements(20.0, 10.0, 20.0);
    dataPtr->removeObserver(conditionerPtr);
    dataPtr->setMeasurements(20.0, 20.0, 20.0);
}
