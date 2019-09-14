#include <xc.h>
#include "keyboard.h"
#include "setup.h"

uint8_t scanKeys(void){    
    uint8_t keys[4][4]={{'D','C','B','A'},
                        {'#','9','6','3'},
                        {'0','8','5','2'},
                        {'*','7','4','1'}};
    uint8_t counterC=0;
    uint8_t counterL=0;
    for(uint8_t line=16; line; line *= 2){
        KBD_PORT = ~line;
        counterC = 0;
        for(uint8_t column=1; column != 16; column *= 2){
            if((~(KBD_PORT | 0xF0)) & column){
                return keys[counterC][counterL];
            }
            counterC++;
        }
        counterL++;
    }
    return '$';
}