#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>

class Environment {
private:
    std::string lastCheck;
    int temperature;
    int humidity;
    std::string motionSens;
    std::string contact;
    std::string motionSensTime;
    std::string security;
    std::string contactTime;
    std::string alarm;
    std::string cooling;
    std::string heating;
    int idealTemperatureMin;
    int idealHumidity;
    int idealTemperatureMax;
    std::string Dehumidifer;
    std::string Humidifer;
    std::string energySave;

public:

    std::string getLastCheck() const { return lastCheck; }
    int getIdealTemperatureMax() const { return idealTemperatureMax; }
    int getIdealTemperatureMin() const { return idealTemperatureMin; }
    int getTemperature() const { return temperature; }
    int getHumidity() const { return humidity; }
    std::string getMotionSens() const { return motionSens; }
    std::string getDehumidifer() const { return Dehumidifer; }
    std::string getHumidifer() const { return Humidifer; }
    std::string getContact() const { return contact; }
    std::string getMotionSensTime() const { return motionSensTime; }
    std::string getSecurity() const { return security; }
    std::string getContactTime() const { return contactTime; }
    std::string getAlarm() const { return alarm; }
    std::string getCooling() const { return cooling; }
    std::string getHeating() const { return heating; }
    int getIdealHumidity() const { return idealHumidity; }
    std::string getEnergySave() const { return energySave; }

    void setIdealTemperatureMax(int value) { idealTemperatureMax = value; }
    void setIdealTemperatureMin(int value) { idealTemperatureMin = value; }
    void setLastCheck(const std::string& value) { lastCheck = value; }
    void setTemperature(int value) { temperature = value; }
    void setHumidity(int value) { humidity = value; }
    void setMotionSens(const std::string& value) { motionSens = value; }
    void setDehumidifer(const std::string& value) { Dehumidifer = value; }
    void setHumidifer(const std::string& value) { Humidifer = value; }
    void setContact(const std::string& value) { contact = value; }
    void setMotionSensTime(const std::string& value) { motionSensTime = value; }
    void setSecurity(const std::string& value) { security = value; }
    void setContactTime(const std::string& value) { contactTime = value; }
    void setAlarm(const std::string& value) { alarm = value; }
    void setCooling(const std::string& value) { cooling = value; }
    void setHeating(const std::string& value) { heating = value; }
    void setIdealHumidity(int value) { idealHumidity = value; }
    void setEnergySave(const std::string& value) { energySave = value; }
};

#endif