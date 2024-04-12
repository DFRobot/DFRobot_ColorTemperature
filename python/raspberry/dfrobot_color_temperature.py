# -*- coding: utf-8 -*
'''!
  @file        dfrobot_color_temperature.py
  @brief       This is the implementation file for DFRobot_Color_Temperature
  @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      TangJie(jie.tang@dfrobot.com)
  @version     V1.0
  @date        2024-04-01
  @url         https://github.com/DFRobot/DFRobot_ColorTemperature
'''

import serial
import time
import smbus
import os
import math
import RPi.GPIO as GPIO
import math

import modbus_tk
import modbus_tk.defines as cst
from modbus_tk import modbus_rtu

I2C_MODE                  = 0x01
UART_MODE                 = 0x02
DEV_ADDRESS               = 0x32

DEVICE_ADDRESS            = 0x32


class DFRobot_Color_Temperature():
  '''!
    @brief Define DFRobot_Color_Temperature basic class
    @details For driving the environmental sensor
  '''
  def __init__(self ,bus ,baud = 9600):
    if bus != 0:
      self.i2cbus = smbus.SMBus(bus)
      self._uart_i2c = I2C_MODE
    else:
      self.master = modbus_rtu.RtuMaster(serial.Serial(port="/dev/ttyAMA0",baudrate=baud, bytesize=8, parity='N', stopbits=1))
      self.master.set_timeout(1.0)
      self._uart_i2c = UART_MODE

  def _detect_device_address(self):
    '''!
      @brief Get sensor address
      @return  Return sensor address
    '''
    rbuf = self._read_reg(0X02,2)
    if self._uart_i2c == I2C_MODE:
      data = rbuf[1] << 8 | rbuf[0]
    elif self._uart_i2c == UART_MODE:
      data = rbuf[0]
    return data

  def begin(self):
    '''!
      @brief Init SEN0611 sensor
      @return Return init status
      @retval 0  Succeed
      @retval -1 Failed
    '''
    if self._detect_device_address() != DEV_ADDRESS:
      return False
    return True
  
  def read_lux(self):
    '''!
      @brief Get sensor illuminance
      @return Illuminance obtained
    '''
    rbuf = self._read_reg(0X06,2)
    if self._uart_i2c == I2C_MODE:
      data = rbuf[1] << 8 | rbuf[0]
    elif self._uart_i2c == UART_MODE:
      data = rbuf[0]
    return data
  
  def read_cct(self):
    '''!
      @brief Get color temperature data
      @return Color temperature obtained
    '''
    rbuf = self._read_reg(0X07,2)
    if self._uart_i2c == I2C_MODE:
      data = rbuf[1] << 8 | rbuf[0]
    elif self._uart_i2c == UART_MODE:
      data = rbuf[0]
    return data
  
  def read_x(self):
    '''!
      @brief Get color coordinate X
      @return Color coordinate X obtained
    '''
    rbuf = self._read_reg(0X08,2)
    if self._uart_i2c == I2C_MODE:
      data = float(rbuf[1] << 8 | rbuf[0]) / 10000.0
    elif self._uart_i2c == UART_MODE:
      data = float(rbuf[0]) /10000.0
    return data
  
  def read_y(self):
    '''!
      @brief Get color coordinate Y
      @return Color coordinate Y obtained
    '''
    rbuf = self._read_reg(0X09,2)
    if self._uart_i2c == I2C_MODE:
      data = float(rbuf[1] << 8 | rbuf[0]) / 10000.0
    elif self._uart_i2c == UART_MODE:
      data = float(rbuf[0]) / 10000.0
    return data
  
class DFRobot_Color_Temperature_I2C(DFRobot_Color_Temperature):
  '''!
    @brief An example of an i2c interface module
  '''
  def __init__(self ,bus ,addr):
    self._addr = addr
    DFRobot_Color_Temperature.__init__(self,bus,0)   
    
  
  def _read_reg(self, reg_addr ,length):
    '''!
      @brief read the data from the register
      @param reg register address
      @param value read data
    '''
    try:
      rslt = self.i2cbus.read_i2c_block_data(self._addr ,reg_addr , length)
    except:
      rslt = -1
    return rslt    


class DFRobot_Color_Temperature_UART(DFRobot_Color_Temperature):
  '''!
    @brief An example of an UART interface module
  '''
  def __init__(self ,baud, addr):
    self._baud = baud
    self._addr = addr
    try:
      DFRobot_Color_Temperature.__init__(self,0,self._baud)
    except:
      print ("plese get root!")
   
  
  def _read_reg(self, reg_addr ,length):
    '''!
      @brief Read data from the sensor
    '''
    return list(self.master.execute(self._addr, cst.READ_INPUT_REGISTERS, reg_addr, length))
    