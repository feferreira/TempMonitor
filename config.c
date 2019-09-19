#include "config.h"
#include "eeprom.h"

void getConfig(){
    Config_numberOfSensors = readE2p(SENSOR_QUANTITY);
    for(uint8_t i=0; i < Config_numberOfSensors; i++){
        Config_maxValues[i] = readE2p(MAX_VALUES + i);
        Config_timeOut[i] = readE2p(TIMEOUT_VALUES + i);
    }
}