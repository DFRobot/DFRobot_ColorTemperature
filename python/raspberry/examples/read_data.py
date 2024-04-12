# -*- coding: utf-8 -*
'''!
  @file  read_data.py
  @brief This is a demo for retrieving data from SEN0593.
  @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      TangJie(jie.tang@dfrobot.com)
  @version     V1.0
  @date        2024-04-01
  @url         https://github.com/DFRobot/DFRobot_ColorTemperature
'''
from __future__ import print_function
import sys
import os
sys.path.append("../")
import time
import RPi.GPIO as GPIO

from python.raspberry.dfrobot_color_temperature import *

'''
  Select communication mode
  ctype=1：UART
  ctype=0：IIC
'''
ctype=1

ADDRESS = 0x32  
I2C_1   = 0x01               
if ctype==0:
  ct = DFRobot_Color_Temperature_I2C(I2C_1 ,ADDRESS)
else:
  ct = DFRobot_Color_Temperature_UART(9600, ADDRESS)


def setup():
  while (ct.begin() == False):
    print("Sensor initialize failed!!")
    time.sleep(1)
  print("Sensor  initialize success!!")
  
def loop():
  ##Obtain sensor data
  print("-----------------------\r\n")
  print("Lux: " + str(ct.read_lux()) + "\r\n")
  print("CCT: " + str(ct.read_cct()) + "\r\n")
  print("X: " + str(ct.read_x()) + "\r\n")
  print("Y: " + str(ct.read_y()) + "\r\n")
  print("-----------------------\r\n")
  time.sleep(1)

if __name__ == "__main__":
  setup()
  while True:
    loop()
    
