#include <xc.h>
#include "setup.h"
#pragma config FOSC=HS, WDTE=OFF, BOREN=OFF, LVP=OFF

void main(){
    setupPorts();
    PORTD = 0;
            EN_IO = 1;
        EN_DISPLAY = 1;
        
    while(1){
        PORTD = 0;
        for(char x=0;x < 7; x++){
            PORTD = x;
                                    EN_IO = 1;
        EN_DISPLAY = 1;
            __delay_ms(500);

        }
    }
}