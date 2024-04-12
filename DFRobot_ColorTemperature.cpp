/*!
 * @file DFRobot_ColorTemperature.cpp
 * @brief This is the implementation file for DFRobot_ColorTemperature
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version  V1.0
 * @date  2024-04-01
 * @url https://github.com/DFRobot/DFRobot_ColorTemperature
 */

#include "DFRobot_ColorTemperature.h"

DFRobot_ColorTemperature::DFRobot_ColorTemperature(TwoWire *pWire)
{
  _pWire = pWire;
  _addr = COLORTEMPERATURE_ADDR;
};

DFRobot_ColorTemperature::DFRobot_ColorTemperature(Stream *s):DFRobot_RTU(s)
{
  _s = s;
  _addr = COLORTEMPERATURE_ADDR;
};

int8_t DFRobot_ColorTemperature::begin(void)
{
  delay(500);
  setTimeoutTimeMs(200);
  
  if(_addr > 0xF7){
    DBG("Invaild Device addr.");
  }
  if(_addr != 0){
    if(!detectDeviceAddress(_addr)){
      DBG("Device addr Error.");
      return -1;
    }
  }else{
    return -1;
  }
  return 0;
}

uint16_t DFRobot_ColorTemperature::readLUX(void)
{
  uint16_t data = 0;
  uint8_t buffer[4];
  readReg(COLORTEMPERATURE_LUX_REG,buffer,2);
  if(_pWire){
    data = buffer[1] << 8 | buffer[0];
  }else{
    data = buffer[0] << 8 | buffer[1];
  }
  
  return data;
}

uint16_t DFRobot_ColorTemperature::readCCT(void)
{
  uint16_t data = 0;
  uint8_t buffer[4];
  readReg(COLORTEMPERATURE_CCT_REG,buffer,2);
  if(_pWire){
    data = buffer[1] << 8 | buffer[0];
  }else{
    data = buffer[0] << 8 | buffer[1];
  }
  return data;
}

float DFRobot_ColorTemperature::readX(void)
{
  float data = 0;
  uint8_t buffer[4];
  readReg(COLORTEMPERATURE_X_REG,buffer,2);
  if(_pWire){
    data = (float)(buffer[1] << 8 | buffer[0]) / 10000;
  }else{
    data = (float)(buffer[0] << 8 | buffer[1]) / 10000;
  }
  
  return data;
}

float DFRobot_ColorTemperature::readY(void)
{
  float data = 0;
  uint8_t buffer[4];
  readReg(COLORTEMPERATURE_Y_REG,buffer,2);
  if(_pWire){
    data = (float)(buffer[1] << 8 | buffer[0]) / 10000;
  }else{
    data = (float)(buffer[0] << 8 | buffer[1]) / 10000;
  }
  return data;
}

bool  DFRobot_ColorTemperature::detectDeviceAddress(uint8_t addr)
{
uint8_t buf[2];
  if(_pWire){
  _pWire->begin();
  }
  readReg(COLORTEMPERATURE_ADDR_REG, buf, 2);
  DBG((buf[0] << 8| buf[1]));
  if(_pWire){
    if(addr == ((buf[1] << 8| buf[0]) & 0xFF))
    return true;
  }else{
    if(addr == ((buf[0] << 8| buf[1]) & 0xFF))
    return true;
  }
  return false;
}

uint8_t DFRobot_ColorTemperature::readReg(uint16_t reg, void *pBuf, uint8_t size)
{
  uint8_t* _pBuf = (uint8_t*)pBuf;
  
    if(pBuf == NULL){
      DBG("data error");
      return 0;
    }
  if(_pWire){
    uint8_t _reg = reg;
    _pWire->begin();
    _pWire->beginTransmission(_addr);
    _pWire->write(_reg);
    _pWire->endTransmission();
    _pWire->requestFrom(_addr, size);
    for(uint8_t i = 0; i < size; i++)
      _pBuf[i] = _pWire->read();
    
    return size;
  }else{
    return readInputRegister(_addr, reg, _pBuf, size);
  }
}