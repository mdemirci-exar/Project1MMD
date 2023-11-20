// Humidifier.cpp
#include <iostream>
#include <string>
#include "Humidifier.h"

// Kurucu i�lev, environment nesnesini al�r
Humidifier::Humidifier(const Environment& env) : env(env) {}

// Nem seviyesine g�re humidifier'� kontrol eden i�lev
void Humidifier::controlHumidifier() {
    int humidity = env.getHumidity();

    // Nem seviyesi 55% alt�ndaysa humidifier'� a�
    if (humidity < 55) {
        std::cout << "Humidifier a��ld�." << std::endl;
        env.setHumidifer("On");
    }
    // Nem seviyesi 55% ve �zerindeyse humidifier'� kapat
    else {
        std::cout << "Humidifier kapat�ld�." << std::endl;
        env.setHumidifer("Off");
    }
}

// Nem seviyesine g�re dehumidifier'� kontrol eden i�lev
void Humidifier::controlDehumidifier() {
    int humidity = env.getHumidity();

    // Nem seviyesi 60% �zerindeyse dehumidifier'� a�
    if (humidity > 60) {
        std::cout << "Dehumidifier a��ld�." << std::endl;
        env.setHumidifer("On");
    }
    // Nem seviyesi 60% ve alt�ndaysa dehumidifier'� kapat
    else {
        std::cout << "Dehumidifier kapat�ld�." << std::endl;
        env.setHumidifer("Off");
    }
}
