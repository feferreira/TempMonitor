#ifndef EEPROM_H
#define EEPROM_H
#include <stdint.h>
#include <xc.h>

#define COLD_START 0x00
#define SENSOR_QUANTITY 0x01
#define MAX_VALUES 0x08
#define TIMEOUT_VALUES 0x0F

__EEPROM_DATA(0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
__EEPROM_DATA(0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
        

void writeE2p(uint8_t address, uint8_t value);
uint8_t readE2p(uint8_t address);

#endif