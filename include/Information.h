#pragma once

// Includes
#include <Arduino.h>
#include "Network.h"
#include "PirReader.h"

// Interface
#include "../interface/IBaseClass.h"

// Classes
class Information : public IBaseClass
{
    // ## Constructor ## //
public:
    Information(Network *network, PirReader *pirReader);

    // ## Interface ## //
private:
public:
    virtual bool Init();
    virtual void Run();

    // ## Data ## //
private:
    PirReader *pirReader;                        // Pointer to used pirReader instance
    PirReader memPirReader = PirReader(0, 0, 0); // Memory version of pirReader instance
    Network *network;                            // Pointer to used network instance
    const String symbol = "=";
    const uint8_t spacerLength = 40; // x * Spaces
    const uint8_t insertLength = 4;  // x * Spaces
public:
    // ## Functions ## //
private:
    // Format print functions
    void FormatPrintSingle(String name,
                           String paramterValue);

    void FormatPrintMotionDetected(String sensorTriggered,
                                   String sensor1Triggered,
                                   String sensor2Triggered);

    // Help functions
    void TopSpacerPrint();
    void BottomSpacerPrint();
    void InsertPrint();

public:
    // Help functions
    String BoolToString(bool b);
};