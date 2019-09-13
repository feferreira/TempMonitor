#include <xc.h>
#include "setup.h"

void setupPorts(void){
    TRISC = 0x00;
    TRISD = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTD = 0xFF;
}