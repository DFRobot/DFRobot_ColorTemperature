DFRobot_ColorTemperature
===========================

* [中文版](./README_CN.md)
The SEN0611 is a color temperature sensor. By using the APIs provided in the library, you can obtain color temperature data, illuminance, and color coordinate data.

![产品效果图片](../../resources/images/SEN0611.png)
  
## Product Link (https://www.dfrobot.com)
    SKU: SEN0611

## Table of Contents

  * [Summary](#summary)
  * [Installation](#installation)
  * [Methods](#methods)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Credits](#credits)

## Summary

The SEN0593 is a color temperature sensor. By using the APIs provided in the library, you can obtain color temperature data, illuminance, and color coordinate data.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
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


```

## Compatibility

MCU                | SoftwareSerial | HardwareSerial |      IIC      |
------------------ | :----------: | :----------: | :----------: | 
Arduino Uno        |      √       |      X       |      √       |
Mega2560           |      √       |      √       |      √       |
Leonardo           |      √       |      √       |      √       |
ESP32              |      X       |      √       |      √       |
ESP8266            |      √       |      X       |      √       |
FireBeetle M0      |      X       |      √       |      √       |
Raspberry Pi       |      X       |      √       |      √       |

## History

- 2024-04-01 - Version 1.0.0 released.

## Credits

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
