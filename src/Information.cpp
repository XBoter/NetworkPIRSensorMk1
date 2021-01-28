#include "../include/Information.h"

// ToDo Update function descriptions

Information::Information(Network *network,
                         PirReader *pirReader)
{
    this->network = network;
    this->pirReader = pirReader;
};

/**
 * Does init stuff for the Information component
 * 
 * @return True if successfull, false if not 
 */
bool Information::Init()
{
    if (!init)
    {
        Serial.println(F("Information initialized"));
        init = true;
    }

    return init;
};

/**
 * Runs the Information component. 
 */
void Information::Run()
{
    if (!init)
    {
        return;
    }

    // -- Motion Detection
    if (this->pirReader->sensor1Triggered != memPirReader.sensor1Triggered ||
        this->pirReader->sensor2Triggered != memPirReader.sensor2Triggered ||
        this->pirReader->sensorTriggered != memPirReader.sensorTriggered)
    {
        FormatPrintMotionDetected(BoolToString(this->pirReader->sensorTriggered),
                                  BoolToString(this->pirReader->sensor1Triggered),
                                  BoolToString(this->pirReader->sensor2Triggered));

        this->network->PublishMotionDetected(this->pirReader->sensorTriggered);

        memPirReader.sensorTriggered = this->pirReader->sensorTriggered;
        memPirReader.sensor1Triggered = this->pirReader->sensor1Triggered;
        memPirReader.sensor2Triggered = this->pirReader->sensor2Triggered;
    }
};

/**
 * Prints a single parameter/component formatted message to serial
 * 
 * @param name      The name of the parameter or component
 * @param value     The value of the given parameter or component
 **/
void Information::FormatPrintSingle(String name,
                                    String value)
{
    TopSpacerPrint();

    // Paramter name
    InsertPrint();
    Serial.print(F("Paramter/Component/Mode '"));
    Serial.print(name);
    Serial.println(F("' changed"));

    // Parameter value
    InsertPrint();
    Serial.print(F("Value : "));
    Serial.println(value);

    BottomSpacerPrint();
};

/**
 * 
 **/
void Information::FormatPrintMotionDetected(String sensorTriggered,
                                            String sensor1Triggered,
                                            String sensor2Triggered)
{
    TopSpacerPrint();

    // Sensor 1 Triggered
    InsertPrint();
    Serial.print(F("Combined PIR Sensor     : "));
    Serial.println(sensorTriggered);

    // Sensor 1 Triggered
    InsertPrint();
    Serial.print(F("Physical PIR Sensor 1   : "));
    Serial.println(sensor1Triggered);

    // Sensor 2 Triggered
    InsertPrint();
    Serial.print(F("Physical PIR Sensor 2   : "));
    Serial.println(sensor2Triggered);

    BottomSpacerPrint();
};

/**
 * Prints a formatted top spacer message to serial
 **/
void Information::TopSpacerPrint()
{
    Serial.println(F(""));
    Serial.print(" # ");
    for (uint8_t i = 0; i < spacerLength; i++)
    {
        Serial.print(symbol);
    }
    Serial.print(" #");
    Serial.println(F(""));
};

/**
 * Prints a formatted bottom spacer message to serial
 **/
void Information::BottomSpacerPrint()
{
    Serial.print(" # ");
    for (uint8_t i = 0; i < spacerLength; i++)
    {
        Serial.print(symbol);
    }
    Serial.print(" #");
    Serial.println(F(""));
};

/**
 * Converts a given bool value to the corresponding string message
 * 
 * @param b     The bool value to convert
 * 
 * @return The value of the bool as string
 **/
String Information::BoolToString(bool b)
{
    if (b)
    {
        return "true";
    }
    else
    {
        return "false";
    }
};

/**
 * Prints a string message with length of insertLength * spaces to serial
 **/
void Information::InsertPrint()
{
    for (uint8_t i = 0; i < insertLength; i++)
    {
        Serial.print("");
    }
};