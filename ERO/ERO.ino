#include "Hardware.h"
#include <EROBLE.h>
#include <ERO.h>

EROBLE ble(RX_PIN, TX_PIN, &GamePad);
ERO BoBot(motorPin, signalPin, BEEPER, SPEEDCTRL);

void setup()
{
    Serial.begin(9600);
    BoBot.begin();
    ble.begin(9600);
}

void loop()
{
    if (ble.available() > 7)
    {
        ble.process();
    }
    int speed = BoBot.speedCtrl();
    Serial.println(speed);
    if (GamePad.UP)
    {
        Serial.println("Key press = UP");
        BoBot.forward(speed);
    }

    else if (GamePad.DOWN)
    {
        Serial.println("Key press = DOWN");
        BoBot.backward(speed);
    }

    else if (GamePad.LEFT)
    {
        Serial.println("Key press = LEFT");
        BoBot.turnLeft(speed);
    }

    else if (GamePad.RIGHT)
    {
        Serial.println("Key press = RIGHT");
        BoBot.turnRight(speed);
    }

    else if (GamePad.SELECT)
    {
        Serial.println("Key press = SELECT");
    }

    else if (GamePad.START)
    {
        Serial.println("Key press = START");
    }

    else if (GamePad.CIRCLE)
    {
        Serial.println("Key press = CIRCLE");
        BoBot.rightSignal("ON");
    }

    else if (GamePad.TRIANGLE)
    {
        Serial.println("Key press = TRIANGLE");
        BoBot.beeper("ON",1);
    }

    else if (GamePad.CROSS)
    {
        Serial.println("Key press = CROSS");
    }

    else if (GamePad.SQUARE)
    {
        Serial.println("Key press = SQUARE");
        BoBot.leftSignal("ON");
    }

    else
    {
        BoBot.stop();
        BoBot.leftSignal("OFF");
        BoBot.rightSignal("OFF");
    }
}
