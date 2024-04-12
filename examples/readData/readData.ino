/*!
 *@file  readData.ino
 *@brief This is a demo for retrieving data from SEN0593.
 * @n connected table
 * ---------------------------------------------------------------------------------------------------------------
 *    board   |             MCU                | Leonardo/Mega2560/M0 |    UNO    | ESP8266 | ESP32 |  microbit  |
 *     VCC    |            3.3V/5V             |        VCC           |    VCC    |   VCC   |  VCC  |     X      |
 *     GND    |              GND               |        GND           |    GND    |   GND   |  GND  |     X      |
 *     RX     |              TX                |     Serial1 TX1      |     5     |   5/D6  |  D2   |     X      |
 *     TX     |              RX                |     Serial1 RX1      |     4     |   4/D7  |  D3   |     X      |
 * ---------------------------------------------------------------------------------------------------------------
 * 
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [TangJie](jie.tang@dfrobot.com)
 * @version     V1.0
 * @date        2024-04-01
 * @url         https://github.com/DFRobot/DFRobot_ColorTemperature
 */
#include "DFRobot_ColorTemperature.h"
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
#include <SoftwareSerial.h>
#endif

#define MODESWITCH        /*UART:*/0 /*I2C: 0*/

#if MODESWITCH
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
  SoftwareSerial mySerial(/*rx =*/4, /*tx =*/5);
  DFRobot_ColorTemperature CT(/*s =*/&mySerial);
#else
  DFRobot_ColorTemperature CT(/*s =*/&Serial1);
#endif
#else
DFRobot_ColorTemperature CT(/*pWire = */&Wire);
#endif

void setup()
{
#if MODESWITCH
  //Init MCU communication serial port
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
  mySerial.begin(9600);
#elif defined(ESP32)
  Serial1.begin(9600, SERIAL_8N1, /*rx =*/D3, /*tx =*/D2);
#else
  Serial1.begin(9600);
#endif
#endif
  Serial.begin(115200);
  while(CT.begin() != 0){
    Serial.println(" Sensor initialize failed!!");
    delay(1000);
  }
  Serial.println(" Sensor  initialize success!!");
}

void loop()
{
  //Print the data obtained from sensor
  Serial.println("-------------------------------");
  Serial.print("LUX: ");
  Serial.println(CT.readLUX());
  Serial.print("CCT: ");
  Serial.println(CT.readCCT());
  Serial.print("X: ");
  Serial.println(CT.readX());
  Serial.print("Y: ");
  Serial.println(CT.readY());
  Serial.println("-------------------------------");
  delay(500);
}
