//
// Created by German Albershteyn on 16.04.2024.
//

#include "Data.h"

Data::Data(){
    observers = *new std::vector<std::weak_ptr<Observer>>();
}
void Data::registerObserver (const std::weak_ptr<Observer>& o) {
    observers.push_back(o);
}
void Data::removeObserver(const std::weak_ptr<Observer> &o)
{
    for (int i = 0; i < observers.size(); ++i) {
        std::shared_ptr<Observer> tmp  = observers[i].lock();
        if (tmp && o.lock() && o.lock() == tmp){
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
    }
}
void Data::measurmentsChanged() {
    notifyObserver();
}
Data& Data::operator=(const Data &data) {
    this->observers = data.observers;
    this->temperature = data.temperature;
    this->pressure = data.pressure;
    this->humidity = data.humidity;
    return *this;
}
void Data::setMeasurements(const double& temperature,const double& pressure, const double& humidity) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurmentsChanged();
}
