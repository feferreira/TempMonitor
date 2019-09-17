#include "monitor.h"
#include <xc.h>
#include "setup.h"
#include <stdint.h>
#include <stdbool.h>
#include "ad.h"
#include "io.h"
#include "display.h"
#include "eeprom.h"
#include "serial.h"

uint8_t maxValues[8];
uint8_t numberOfSensors = 0;
uint8_t alarm = 0xFF;

void getE2pValues(){
    numberOfSensors = readE2p(SENSOR_QUANTITY);
    for(uint8_t i=0; i < numberOfSensors; i++){
        maxValues[i] = readE2p(MAX_VALUES + i);
    }
}

bool compareSensor(uint8_t sensor, uint8_t value){
    return value > maxValues[sensor] ? true : false;
}

void monitor(){
        for(uint8_t i=0; i < numberOfSensors; i++){
            uint8_t readValue = getTemp(i);
            writeSensorValues(i,readValue, maxValues[i]);
            if(compareSensor(i,readValue)){
                setDisplayBack(RED);
            }
            else{
                setDisplayBack(GREEN);
            }
            __delay_ms(500);
        }
}