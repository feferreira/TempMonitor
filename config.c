#include "config.h"
#include "eeprom.h"

void getConfig(){
    Config_numberOfSensors = readE2p(SENSOR_QUANTITY);
    for(uint8_t i=0; i < Config_numberOfSensors; i++){
        Config_newMaxValues[i] = Config_maxValues[i] = readE2p(MAX_VALUES + i);
        Config_newTimeValues[i] = Config_timeOut[i] = readE2p(TIMEOUT_VALUES + i);
    }
}

void setConfigMaxValue(uint8_t sensor, uint8_t value){
    Config_newMaxValues[sensor] = value;
}
void setConfigTimeOut(uint8_t sensor, uint8_t value){
    Config_newMaxValues[sensor] = value;
}

void writeConfigSensors(){
    for(uint8_t i=0; i < Config_numberOfSensors; i++){
        writeE2p(MAX_VALUES + i, Config_newMaxValues[i]);
        Config_maxValues[i] = Config_newMaxValues[i];
        writeE2p(TIMEOUT_VALUES + i, Config_newTimeValues[i]);
        Config_timeOut[i] = Config_newTimeValues[i];
    }
}