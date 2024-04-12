/*!
 * @file DFRobot_ColorTemperature.h
 * @brief This is the method documentation file for DFRobot_ColorTemperature
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version  V1.0
 * @date  2023-12-7
 * @url https://github.com/DFRobot/DFRob0t_ColorTemperature
 */
#ifndef DFROBOT_COLOR_TEMPERATURE
#define DFROBOT_COLOR_TEMPERATURE
#include "Arduino.h"
#include "Wire.h"
#include "DFRobot_RTU.h"
#include "String.h"
#if (defined ARDUINO_AVR_UNO) && (defined ESP8266)
#include "SoftwareSerial.h"
#else
#include "HardwareSerial.h"
#endif


#define COLORTEMPERATURE_ENABLE_DBG ///< Open this macro to see the detailed execution process of the program
#ifdef COLORTEMPERATURE_ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif


class DFRobot_ColorTemperature: public DFRobot_RTU{
public:
    #define COLORTEMPERATURE_ADDR     0x32 ///<Device Address
    #define COLORTEMPERATURE_ADDR_REG 0X02 ///< Device Address Register
    #define COLORTEMPERATURE_LUX_REG  0X06 ///< Illuminance Register
    #define COLORTEMPERATURE_CCT_REG  0X07 ///< Color Temperature Register
    #define COLORTEMPERATURE_X_REG    0X08 ///< Color Coordinate X Register
    #define COLORTEMPERATURE_Y_REG    0X09 ///< Color Coordinate Y Register



  /**
   * @fn DFRobot_ColorTemperature
   * @brief DFRobot_ColorTemperature constructor
   * @param pWire I2C pointer to the TowWire stream, which requires calling begin in the demo to init Arduino I2C config.
   * @param addr  I2C communication address of SEN0611 device
   */
  DFRobot_ColorTemperature(TwoWire *pWire);

  /**
   * @fn DFRobot_ColorTemperature
   * @brief DFRobot_ColorTemperature constructor
   * @param addr The device address of the communication between the host computer and SEN0611 slave device
   * @param s  The serial port pointer to the Stream, which requires calling begin in the demo to init communication serial port config of Arduino main controller, in line with that of SEN0611 device slave.
   * @n SEN0611 serial port config: 9600 baud rate, 8-bit data bit, no check bit, 1 stop bit, the parameters can't be changed.
   */
  DFRobot_ColorTemperature(Stream *s);
  ~DFRobot_ColorTemperature(){};
  /**
   * @fn begin
   * @brief Initialize SEN0593
   * @return Initialization status
   * @retval 0  Success
   * @retval -1 Failure
   */
  int8_t begin(void);

  /**
   * @fn readLUX
   * @brief Get sensor illuminance
   * @return Illuminance obtained
  */
  uint16_t readLUX(void);

  /**
   * @fn readCCT
   * @brief Get color temperature data
   * @return Color temperature obtained
  */
  uint16_t readCCT(void);

  /**
   * @fn readX
   * @brief Get color coordinate X
   * @return Color coordinate X obtained
  */
  float readX(void);

  /**
   * @fn readY
   * @brief Get color coordinate Y
   * @return Color coordinate Y obtained
  */
  float readY(void);
private:
  bool detectDeviceAddress(uint8_t addr);
  uint8_t readReg(uint16_t reg, void *pBuf, uint8_t size);
  //uint8_t writeReg(uint8_t reg, void *pBuf, size_t size);
  TwoWire   *_pWire = NULL;
  Stream    *_s = NULL;
  uint8_t   _addr;
  uint8_t _mode;

};
#endif