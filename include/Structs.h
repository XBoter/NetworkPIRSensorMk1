#pragma once

#include "Enums.h"

/**
 * Hold the configuration data
 */
struct ConfiguredData
{
    String wifiSSID = "";
    String wifiPassword = "";
    String mqttBrokerIpAddress = "";
    uint16_t mqttBrokerPort = 0;
    String mqttBrokerUsername = "";
    String mqttBrokerPassword = "";
    String mqttClientName = "";
    bool isConfigured = false;
    String mqttLEDControllerClientName = "";
};
