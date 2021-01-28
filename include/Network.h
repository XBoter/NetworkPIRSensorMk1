#pragma once

// Arduino Lib Includes
#include <PubSubClient.h> // @installed via Arduino Library Manger    GitHub => https://github.com/knolleary/pubsubclient

// Includes
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Enums.h"
#include "Structs.h"
#include "Configuration.h"

// Interface
#include "../interface/IBaseClass.h"

// Classes
class Network : public IBaseClass
{
    // ## Constructor ## //
public:
    Network();

    // ## Interface ## //
private:
public:
    virtual bool Init();
    virtual void Run();

    // ## Data ## //
private:
    ConfiguredData data;

    WiFiClient wifiMqtt;
    WiFiUDP ntpUDP;

    // Network Info
    String ipAddress = "";
    String macAddress = "";

    // Prev Millis
    unsigned long PrevMillis_WiFiTimeout = 0;
    unsigned long PrevMillis_MQTTTimeout = 0;

    // Timeout
    const unsigned long TimeOut_WiFiTimeout = 5000; // 5 sec
    const unsigned long TimeOut_MQTTTimeout = 5000; // 5 sec

    bool wifiOneTimePrint = true;
    bool mqttOneTimePrint = true;
    bool memWifiConnected = false;
    bool memMqttConnected = false;

public:
    PubSubClient mqttClient;
    NetworkWiFiState wifiState = NetworkWiFiState::StartWifi;
    NetworkMQTTState mqttState = NetworkMQTTState::StartMqtt;
    bool wifiConnected = false;
    bool mqttConnected = false;

    // ## Functions ## //
private:
    // Network handles
    void HandleWifi();
    void HandleMqtt();

public:
    void PublishMotionDetected(bool sensorTriggered);
};
