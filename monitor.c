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
#include "config.h"


bool compareSensor(uint8_t sensor, uint8_t value){
    return value > Config_maxValues[sensor] ? true : false;
}

void monitor(){
        for(uint8_t i=0; i < Config_numberOfSensors; i++){
            uint8_t readValue = getTemp(i);
            writeSensorValues(i,readValue, Config_maxValues[i]);
            if(compareSensor(i,readValue)){
                setDisplayBack(RED);
            }
            else{
                setDisplayBack(GREEN);
            }
            __delay_ms(500);
        }
}