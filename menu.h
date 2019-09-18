#ifndef MENU_H
#define MENU_H
#include <stdbool.h>
#include <stdint.h>

void configMenu(void);
bool configLimitsMenu(void);
bool configQuantityMenu(void);
bool setPassword(void);
bool getPassword(void);
bool configSensors(void);
bool configTimeOut(uint8_t *value);
bool configMaxValue(uint8_t *value);


#endif