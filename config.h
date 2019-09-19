#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>

uint8_t Config_maxValues[8];
uint8_t Config_timeOut[8];
uint8_t Config_numberOfSensors = 0;

void getConfig(void);

#endif