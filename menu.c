#include "menu.h"
#include "display.h"
#include "keyboard.h"
#include <stdbool.h>
#include "io.h"
#include "eeprom.h"
#include <stdint.h>

bool (*menuPtr)(void);

void configMenu(void){
    setDisplayBack(BLUE);
    uint8_t key = '$';
    menuPtr = configLimitsMenu;
    while(!menuPtr());
    setDisplayBack(GREEN);
}

bool configLimitsMenu(void){
    uint8_t key = '$';
    showConfigLimitsMenu();
    while(key == '$'){
        key = scanKeys();
    }
    if(key == 'A'){
        menuPtr=configQuantityMenu;
        return false;
    }
    else if(key == '*'){
        return true;
    }
    else if(key == '#'){
        menuPtr=configSensors;
        return false;
    }
    return false;
}

bool configQuantityMenu(void){
    uint8_t key = '$';
    showConfigNsensors();
    while(key == '$'){
        key = scanKeys();
    }
    if(key == 'A'){
        menuPtr=setPassword;
        return false;
    }
    else if(key == '*'){
        return true;
    }
    return false;
}

bool setPassword(void){
    uint8_t key = '$';
    showChangePassword();
    while(key == '$'){
        key = scanKeys();
    }
    if(key == 'A'){
        menuPtr=configLimitsMenu;
        return false;
    }
    else if(key == '*'){
        return true;
    }
    return false;
}

bool configSensor(uint8_t sensor){
    uint8_t key = '$';
    uint8_t value;
    bool (*configPtr)(uint8_t *) = configMaxValue;
    setConfigSensorParam(sensor, readE2p(SENSOR_QUANTITY + sensor), readE2p(SENSOR_QUANTITY + sensor));
    configPtr(&value);
    
    while(1){
    key = scanKeys();
    if(key == '#'){
        configPtr = configPtr == configMaxValue ? configTimeOut : configMaxValue; 
    }
    else if(key == '*'){
        return false;
    }
    configPtr(&value);
    }
    return true;
}

bool configMaxValue(uint8_t *value){
    
    setConfigSensorParam(2,64,23);
}

bool configTimeOut(uint8_t *value){
    setConfigSensorParam(5,33,222);
}

bool configSensors(void){
    showChangeParam();
    uint8_t numberOfSensors = readE2p(SENSOR_QUANTITY);
    for (uint8_t i=0; i < numberOfSensors; i++){
        if(!configSensor(i)){
            return false;
        }
    }
    return true;
}