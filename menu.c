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

void configSensor(uint8_t sensor){
    setSensorNumber(sensor);
}

bool configSensors(void){
    uint8_t key = '$';
    showChangeParam();
    uint8_t numberOfSensors = readE2p(SENSOR_QUANTITY);
    for (uint8_t i=0; i < numberOfSensors; i++){
        configSensor(i);
        while(1);
    }
}