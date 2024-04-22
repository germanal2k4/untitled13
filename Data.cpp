//
// Created by German Albershteyn on 16.04.2024.
//

#include "Data.h"


void Data::registerObserver (const std::weak_ptr<Observer>& o) {
    observers.push_back(o);
}
void Data::removeObserver(const std::weak_ptr<Observer> &o)
{
    for (int i = 0; i < observers.size(); ++i) {
        std::shared_ptr<Observer> tmp  = observers[i].lock();
        if ((tmp && o.lock() == tmp) || (!tmp)){
            observers.erase(observers.begin() + i);
        }
    }
}
void Data::notifyObserver(){
    for (int i = 0; i < observers.size(); ++i) {
        std::shared_ptr<Observer> tmp  = observers[i].lock();
        if(tmp) {
            tmp->update(temperature, pressure, humidity);
        }
        else{
            observers.erase(observers.begin() + i);
        }
    }
}
void Data::measurmentsChanged() {
    notifyObserver();
}

void Data::setMeasurements(const double& temperature,const double& pressure, const double& humidity) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurmentsChanged();
}