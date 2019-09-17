#include <xc.h>
#include "setup.h"
#include "lcd.h"
#include "io.h"
#include "display.h"
#include "eeprom.h"
#include "monitor.h"

void setupPic(void){
    setupPorts();
    setupAd();
    setupSerial();
    getE2pValues();
    setupDisplay();
}

void setupPorts(void){
    TRISA = 0xFF;
    TRISC = 0x00;
    TRISD = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0xFF;
    ANSELH = 0;
    nRBPU = 0;
    TRISB = 0b00001111;
    PORTB = 0x00;
}

void setupDisplay(void){
    setDisplayBack(OFF);
    init_lcd();
    showSplashScreen();
    __delay_ms(2000);
    writeOperationMask();
}

void setupAd(void){
    ADCS1 = 1; // Fosc/32
    ADCS0 = 0; 
    ADFM = 1; //right justified
    VCFG1 = 0; //Vref
    VCFG0 = 0;
    ADON = 1;
}

void setupSerial(void){
    SYNC = 0; //modo assincrono
    SPBRG = 5; //baud rate de 115200
    BRGH = 1;
    TX9 = 0; //desabilita bit 9 (TX9D) de ser transmitido
    RX9 = 0; //desabilita bit 9 (RX9D) de ser recebido
    TXEN = 1; //habilita transmiss�o serial (TX)
    SPEN = 1; //habilita toda a porta serial
    CREN = 1;
}