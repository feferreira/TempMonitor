#include "menu.h"
#include "display.h"
#include "keyboard.h"
#include <stdbool.h>
#include "io.h"
#include "eeprom.h"
#include <stdint.h>
#include "config.h"

bool (*menuPtr)(void);
uint8_t key = '$';

void configMenu(void){
    setDisplayBack(YELLOW);
    menuPtr = configLimitsMenu;
    while(!menuPtr());
    setDisplayBack(GREEN);
}

bool configLimitsMenu(void){
    showConfigLimitsMenu();
    key = '$';
    while(key == '$'){
        key = scanKeys();
    }
    // next Item
    if(key == 'A'){
        menuPtr=configLimitsMenu;
        return false;
    }
    // exit
    else if(key == '*'){
        return true;
    }
    // enter menu
    else if(key == '#'){
        menuPtr=configSensors;
        return false;
    }
    return false;
}

bool changeMaxValue(){
    key = '$';
    while(key == '$'){
        key = scanKeys();
    }
}

bool changeTimeValue(){
    key = '$';
     while(key == '$'){
        key = scanKeys();
    }
}

bool configSensors(void){
    showChangeParam();
    key = '$';
    bool (*changeValuePtr)(void) = changeMaxValue;
    
    for(uint8_t i=0; i < Config_numberOfSensors; i++){
        setConfigSensorParam(i,Config_timeOut[i],Config_maxValues[i]);
        changeValuePtr();
    }
    
}

