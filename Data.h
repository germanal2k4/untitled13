//
// Created by German Albershteyn on 16.04.2024.
//

#ifndef UNTITLED13_DATA_H
#define UNTITLED13_DATA_H

#include "Subject.h"
#include <vector>
#include "Observer.h"
#include <memory>

class Data : public Subject{
private:
    double temperature;
    double humidity;
    double pressure;
    std::vector<std::shared_ptr<Observer>> Observers;
public:
    explicit Data();
    void registerObserver(const std::shared_ptr<Observer>& o) override;
    void notifyObserver() override;
    void removeObserver(const std::shared_ptr<Observer>& o) override;
    void measurmentsChanged();
    void setMeasurements(const double& temperature, const double& pressure,const double& humidity);
    Data& operator=(const Data& data);
};


#endif //UNTITLED13_DATA_H
