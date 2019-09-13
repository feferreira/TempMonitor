#ifndef SETUP_H
#define SETUP_H

#define _XTAL_FREQ 11520000


// analog ports
#define S0 RA0
#define S1 RA1
#define S2 RA2
#define S3 RA3
#define S4 RA5
#define S5 RE0
#define S6 RE1
#define S7 RE2

#define KEYBOARD_PORT PORTB

#define EN_DISPLAY RC5
#define EN_IO RC4

void setupPorts(void);

#endif