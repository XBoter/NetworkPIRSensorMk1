#include "Main.h"

// Global instace of the mainController
Main mainController;

/**
 *  Empty constructor
 */
Main::Main()
{
}

/**
 * Setup function for Arduino file to call in setup
 */
void Main::_setup()
{
    // Setup Serial
    Serial.begin(BAUDRATE);
    delay(100);

    // Info and Version print
    Serial.println("# ======================== #");
    Serial.print("Name          : ");
    Serial.println(Name);
    Serial.print("Programmer    : ");
    Serial.println(Programmer);
    Serial.print("Created       : ");
    Serial.println(Created);
    Serial.print("Last Modifed  : ");
    Serial.println(LastModifed);
    Serial.print("Version       : ");
    Serial.println(Version);
    Serial.println("# ======================== #");
    Serial.println("");

    // Init all configuration
    configuration.Init();
};

/**
 * Loop function for Arduino file to call in loop
 */
void Main::_loop()
{
    // Run configuration before all other components
    configuration.Run();

    if (configuration.isFinished)
    {
        switch (state)
        {
        case 0:
            // Init all components
            ota.Init();
            network.Init();
            information.Init();
            pirReader.Init();
            state++;
            break;

        case 1:
            // Run all components
            ota.Run();
            network.Run();
            information.Run();
            pirReader.Run();
            break;
        }
    }
    else
    {
        ota.init = false;
        network.init = false;
        information.init = false;
        pirReader.init = false;
        state = 0;
    }
};
