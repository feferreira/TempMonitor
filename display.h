#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdint.h>

void showSplashScreen(void);
void writeOperationMask(void);
void writeSensorValues(uint8_t sensor, uint8_t value, uint8_t max);
void showConfigLimitsMenu(void);
void showConfigNsensors(void);
void showChangePassword(void);
void showChangeParam(void);
void setSensorNumber(uint8_t sensor);

#endif