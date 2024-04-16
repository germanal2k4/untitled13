//
// Created by German Albershteyn on 16.04.2024.
//

#include "Data.h"

Data::Data(){
    Observers = std::vector<std::shared_ptr<Observer>>();
}
void Data::registerObserver (const std::shared_ptr<Observer>& o) {
    Observers.push_back(o);
}
void Data::removeObserver(const std::shared_ptr<Observer> &o)
{
    for (int i = 0; i < Observers.size(); ++i) {
        if (o == Observers[i]){
            Observers.erase(Observers.begin() + i);
        }
    }
}
void Data::notifyObserver(){
    for (int i = 0; i < Observers.size(); ++i) {
        Observers[i]->update(temperature, pressure, humidity);
    }
}
void Data::measurmentsChanged() {
    notifyObserver();
}
Data& Data::operator=(const Data &data) {
    this->Observers = data.Observers;
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
