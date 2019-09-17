#include "menu.h"
#include "display.h"
#include "keyboard.h"
#include <stdbool.h>
#include "io.h"

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