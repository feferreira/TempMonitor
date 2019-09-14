#include "ad.h"
#include <xc.h>

void startAdConversion(void){
    GO = 1;
    while(nDONE){
        CLRWDT();
    }
}
uint16_t readAdResult(void){
    return (((uint16_t)(ADRESH)) << 8) + ADRESL;
}