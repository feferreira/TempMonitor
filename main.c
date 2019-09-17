#include <xc.h>
#include "setup.h"
#include "io.h"
#include "keyboard.h"
#include "lcd.h"
#include <stdint.h>
#include "display.h"
#include "ad.h"
#include "menu.h"
#include "monitor.h"
#include "serial.h"

void main(){
    setupPic();
    uint8_t key;
    while(1){
        monitor();
        
        key = scanKeys();
        if(key=='A'){
            configMenu();
            writeOperationMask();
        }
    }
}