#pragma warning(disable:4996)
// MURATHAN DEMÝRCÝ
// DENÝZ AÐAR
// MUSTAFA ÇETÝNKAYA
#include "HumiditySensor.h" 
#include "TemperatureSensor.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib> 
#include "Environment.h"
#include <cstdlib> 
// Mutex for synchronizing mock data updates

#include <mutex>
#include "Alarm.h"
// Create instances of sensors and alarm

Environment env;
bool programRunning = false;
bool mockDataEnabled = false;
std::mutex mockDataMutex;
HumiditySensor humiditySensor;
TemperatureSensor temperatureSensor;
Alarm alarm;
// Function to initialize the environment with default values

void InitializeEnvironment() {
    env.setHeating("Off");
    env.setCooling("Off");
    env.setSecurity("Off");
    env.setHumidifer("Off");
    env.setDehumidifer("Off");
    env.setEnergySave("Off");
    env.setIdealTemperatureMin(20);
    env.setIdealTemperatureMax(25);
}
// Function to update mock data for sensors

void UpdateMockData() {
    while (true) {
        if (mockDataEnabled) {
            // Generate a random motion sensor value ("1" or "-1")

            std::string randomMotionSensor = (rand() % 2 == 0) ? "1" : "-1";
            env.setMotionSens(randomMotionSensor);
            // Generate a random contact sensor status ("On" or "Off")

            std::string randomContactStatus = (rand() % 2 == 0) ? "On" : "Off";
            env.setContact(randomContactStatus);
            // Generate random temperature and humidity values (between 0 and 40)

            int randomTemperature = rand() % 41;
            int randomHumidity = rand() % 101;
            // Update the environmental data

            env.setTemperature(randomTemperature);
            env.setHumidity(randomHumidity);
            // Check and activate the alarm

            alarm.checkAndActivate(env);
        }
        // Sleep for a specified time interval (5 seconds)

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
// Function to display environmental data

void DataThread() {
    while (true) {
        if (programRunning) {
            // Update humidity and temperature data from sensors

            humiditySensor.update(env);
            temperatureSensor.update(env);
            // Clear the console screen and display the main menu

            std::cout << "\033[2J\033[1;1H";
            std::cout << "--- Main Menu ---" << std::endl;
            // Get the system time

            std::time_t t = std::time(0);
            std::tm* now = std::localtime(&t);
            // Display the system time

            std::cout << "System Time: " << (now->tm_year + 1900) << '-';
            std::cout << (now->tm_mon + 1) << '-';
            std::cout << now->tm_mday << " ";
            std::cout << now->tm_hour << ':';
            std::cout << now->tm_min << ':';
            std::cout << now->tm_sec << "\n";
            // Display temperature, sensors, and other environmental data

            std::cout << "Temperature: " << env.getTemperature() << " C\n";
            std::cout << "Contact Sensor " << env.getContact() << "\n";
            std::cout << "Motion Sensor " << env.getMotionSens() << "\n";
            std::cout << "Humidity: " << env.getHumidity() << " %\n";
            std::cout << "Security: " << env.getSecurity() << "\n";
            std::cout << "Energy Saving: " << env.getEnergySave() << "\n";
            std::cout << "Cooling: " << env.getCooling() << "\n";
            std::cout << "Heating: " << env.getHeating() << "\n";
            std::cout << "Humidifier: " << env.getHumidifer() << "\n";
            std::cout << "Dehumidifier: " << env.getDehumidifer() << "\n";
            // Check and display the alarm status in red if activated

            if (env.getAlarm() == "Activated") {
                std::cout << "\033[91m";
                std::cout << "Alarm Value: " << env.getAlarm() << "\n";
                std::cout << "\033[0m";
            }
            else {
                std::cout << "Alarm Value: " << env.getAlarm() << "\n";
            }
            // Display the mock data update status

            std::cout << "Mock Data Update: " << (mockDataEnabled ? "On" : "Off") << "\n";
            // Sleep for a specified time interval (2 seconds)

            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}
// Main function

int main() {
    std::string username;
    std::string password;

    bool loggedIn = false;

    while (!loggedIn) {
        // User login loop

        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;
        // Check username and password for login

        if (username == "admin" && password == "123") {
            std::cout << "Login Successful. Starting the main application..." << std::endl;
            loggedIn = true;
        }
        else {
            std::cout << "Login Failed. Incorrect username or password." << std::endl;
        }
    }
    // Initialize the environment with default values

    InitializeEnvironment();
    // Start the mock data update thread

    std::thread mockDataThread(UpdateMockData);
    // Start the data monitoring thread

    std::thread dataThread(DataThread);

    while (true) {
        // Clear the console screen and display the main menu
        std::cout << "\033[2J\033[1;1H";
        std::cout << "--- Main Menu ---" << std::endl;
        std::cout << "1. Set Temperature Threshold" << std::endl;
        std::cout << "2. Set Security Status" << std::endl;
        std::cout << "3. Set Energy Saving" << std::endl;
        std::cout << "4. Start Program (Display Data Every 2 Seconds)" << std::endl;
        std::cout << "5. Mock Data Update (On/Off)" << std::endl;
        std::cout << "M. Return to Main Menu" << std::endl;

        char choice;
        std::cin >> choice;

        switch (choice) {
        case '1':
            // Set temperature threshold
            int newTempMax, newTempMin;
            std::cout << "Enter New Temperature Threshold (Min Max): ";
            std::cin >> newTempMin >> newTempMax;
            env.setIdealTemperatureMin(newTempMin);
            env.setIdealTemperatureMax(newTempMax);
            break;

        case '2':
        {
            // Set security status
            std::string newSecurityStatus;
            std::cout << "Enter New Security Status (On/Off): ";
            std::cin >> newSecurityStatus;
            env.setSecurity(newSecurityStatus);
            break;
        }

        case '3':
        {
            // Set energy-saving mode
            std::string newEnergySaving;
            std::cout << "Enter New Energy Saving (On/Off): ";
            std::cin >> newEnergySaving;
            env.setEnergySave(newEnergySaving);
            break;
        }

        case '4':
            // Start or stop data monitoring program
            programRunning = !programRunning;
            break;

        case '5':
            // Enable or disable mock data updates
            mockDataEnabled = !mockDataEnabled;
            break;

        case 'M':
        case 'm':
            // Return to the main menu
            programRunning = false;
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}