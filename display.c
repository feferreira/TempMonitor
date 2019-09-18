#include "display.h"
#include "lcd.h"
#include "io.h"

void showSplashScreen(void){
    clr_lcd();
    setDisplayBack(CYAN);
    text_lcd("  TEMP MONITOR");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("  VERSAO:0.1.0");
}

void writeOperationMask(void){
    clr_lcd();
    setDisplayBack(GREEN);
    text_lcd("SEN:   MAX:    C");
    byte_lcd(LCD_CMD, 0x8E);
    byte_lcd(LCD_CHAR, 0b11011111);
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("   TEMP:    C   ");
    byte_lcd(LCD_CMD, 0xCB);
    byte_lcd(LCD_CHAR, 0b11011111);
}

void writeSensorValues(uint8_t sensor, uint8_t value, uint8_t max){
    setSensorNumber(sensor);
    byte_lcd(LCD_CMD, 0xC8);
    byte_lcd(LCD_CHAR, value/100 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)%10 + 0x30);
    byte_lcd(LCD_CMD, 0x8B);
    byte_lcd(LCD_CHAR, max/100 + 0x30);
    byte_lcd(LCD_CHAR, (max%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (max%100)%10 + 0x30);
}

void showConfigLimitsMenu(){
    clr_lcd();
    text_lcd("CONFIGURAR");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("SENSORES");
}

void showConfigNsensors(){
    clr_lcd();
    text_lcd("QUANTIDADE DE");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("SENSORES");
}

void showChangePassword(void){
    clr_lcd();
    text_lcd("ALTERAR SENHA");
}

void showChangeParam(void){
    clr_lcd();
    text_lcd("SEN:   TIME:   s");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("MAX:    C");
}

void setSensorNumber(uint8_t sensor){
    byte_lcd(LCD_CMD, 0x84);
    byte_lcd(LCD_CHAR, 0x30);
    byte_lcd(LCD_CHAR, sensor+0x31);
}

void setConfigSensorParam(uint8_t sensor, uint8_t time, uint8_t max){
    setSensorNumber(sensor);
    byte_lcd(LCD_CMD, 0x8C);
    byte_lcd(LCD_CHAR, time/100 + 0x30);
    byte_lcd(LCD_CHAR, (time%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (time%100)%10 + 0x30);
    byte_lcd(LCD_CMD, 0xC4);
    byte_lcd(LCD_CHAR, max/100 + 0x30);
    byte_lcd(LCD_CHAR, (max%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (max%100)%10 + 0x30);
    
}