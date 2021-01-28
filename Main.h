#pragma once

// Includes
#include <Arduino.h>
#include "include/Network.h"
#include "include/Information.h"
#include "include/PirReader.h"
#include "include/Configuration.h"
#include "include/OTA.h"

//-------------------- Basic Information --------------------//
#define Name "12V LED Controller Mk4"
#define Programmer "Nico Weidenfeller"
#define Created "28.01.2021"
#define LastModifed "28.01.2021"
#define Version "1.0.0"

/*
      ToDo      Add ESP OTA GitHub upgrade 
      ToDo      Update Readme.md
      ToDo      Update Function description
*/

//++++ Global Defines ++++//
#define BAUDRATE 115200
#define PIR_SENSOR_1_PIN D6
#define PIR_SENSOR_2_PIN D7

// Classes
class Main
{
    // ## Constructor ## //
public:
    Main();

    // ## Data ## //
private:
    uint8_t state = 0;

public:
    // Components
    Network network = Network();

    Configuration configuration = Configuration();

    OTA ota = OTA(&network,
                  &configuration);

    PirReader pirReader = PirReader(PIR_SENSOR_1_PIN,
                                    PIR_SENSOR_2_PIN,
                                    &network);

    Information information = Information(&network,
                                          &pirReader);

    // ## Functions ## //
private:
public:
    void _loop();
    void _setup();
};

// Tell compiler to create only one instance of Main
extern Main mainController;
