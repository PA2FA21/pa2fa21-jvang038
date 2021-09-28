/*
 * Name        : temperature.cpp
 * Author      : Jasmine Vang
 * Description : Temperature Class
 *               This is the implementation file
 */


#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature() {
    kelvin_ = 0.00;
}

Temperature::Temperature(double kelvin) {
    kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit) {
    if (unit == 'f' || unit == 'F') {
        // dont have to assign to anything bc it will assign
        // in the SetTemp call
        SetTempFromFahrenheit(temp);
    } else if (unit == 'c' || unit == 'C') {
        SetTempFromCelsius(temp);
    } else {
        kelvin_ = temp;
    }
}

void Temperature::SetTempFromKelvin(double kelvin) {
    kelvin_ = kelvin;
}


void Temperature::SetTempFromCelsius(double celsius) {
    kelvin_ = (celsius + 273.15);
}

void Temperature::SetTempFromFahrenheit(double fahrenheit) {
    kelvin_ = ((5.0 * (fahrenheit - 32) / 9) + 273.15);
}

double Temperature::GetTempAsKelvin() const {
    return kelvin_;
}

double Temperature::GetTempAsCelsius() const {
    return (kelvin_ - 273.15);
}

double Temperature::GetTempAsFahrenheit() const {
    return (((GetTempAsCelsius() * 9.0) / 5) + 32);
}

string Temperature::ToString(char unit) const {
    stringstream ss;
    ss.setf(std::ios::showpoint | std::ios::fixed);
    ss.precision(2);
    if (unit == 'f' || unit == 'F') {
        ss << GetTempAsFahrenheit() << " Fahrenheit";
    } else if (unit == 'c' || unit == 'C') {
        ss << GetTempAsCelsius() << " Celsius";
    } else if (unit == 'k' || unit == 'K') {
        ss << GetTempAsKelvin() << " Kelvin";
    } else {
        ss << "Invalid Unit";
    }
    return ss.str();
}
