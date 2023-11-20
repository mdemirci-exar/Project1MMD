// Humidifier.cpp
#include <iostream>
#include <string>
#include "Humidifier.h"

// Kurucu iþlev, environment nesnesini alýr
Humidifier::Humidifier(const Environment& env) : env(env) {}

// Nem seviyesine göre humidifier'ý kontrol eden iþlev
void Humidifier::controlHumidifier() {
    int humidity = env.getHumidity();

    // Nem seviyesi 55% altýndaysa humidifier'ý aç
    if (humidity < 55) {
        std::cout << "Humidifier açýldý." << std::endl;
        env.setHumidifer("On");
    }
    // Nem seviyesi 55% ve üzerindeyse humidifier'ý kapat
    else {
        std::cout << "Humidifier kapatýldý." << std::endl;
        env.setHumidifer("Off");
    }
}

// Nem seviyesine göre dehumidifier'ý kontrol eden iþlev
void Humidifier::controlDehumidifier() {
    int humidity = env.getHumidity();

    // Nem seviyesi 60% üzerindeyse dehumidifier'ý aç
    if (humidity > 60) {
        std::cout << "Dehumidifier açýldý." << std::endl;
        env.setHumidifer("On");
    }
    // Nem seviyesi 60% ve altýndaysa dehumidifier'ý kapat
    else {
        std::cout << "Dehumidifier kapatýldý." << std::endl;
        env.setHumidifer("Off");
    }
}
