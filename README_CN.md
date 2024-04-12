DFRobot_ColorTemperature
===========================

* [English Version](./README.md)

SEN0611是一个色温传感器，通过调用库中api能够获取色温数据、光照强度、色坐标数据。

![产品效果图片](../../resources/images/SEN0611.png)

## 产品链接（https://www.dfrobot.com）

    SKU：SEN0611
  
## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

SEN0593是一个色温传感器，通过调用库中api能够获取色温数据、光照强度、色坐标数据。

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。


## 方法

```C++
  /**
   * @fn begin
   * @brief 初始化SEN0593
   * @return 返回初始化状态
   * @retval 0  成功
   * @retval -1 失败
   */
  int8_t begin(void);

  /**
   * @fn readLUX
   * @brief 获取传感器光照强度
   * @return 返回获取得光照强度
  */
  uint16_t readLUX(void);
  /**
   * @fn readCCT
   * @brief 获取色温数据
   * @return 返回获取得色温
  */
  uint16_t readCCT(void);
  /**
   * @fn readX
   * @brief 获取色坐标X
   * @return 返回获取得色坐标X
  */
  float readX(void);
  /**
   * @fn readY
   * @brief 获取色坐标Y
   * @return 返回获取得色坐标Y
  */
  float readY(void);

```


## 兼容性

MCU                | SoftwareSerial | HardwareSerial |      IIC      |
------------------ | :----------: | :----------: | :----------: | 
Arduino Uno        |      √       |      X       |      √       |
Mega2560           |      √       |      √       |      √       |
Leonardo           |      √       |      √       |      √       |
ESP32              |      X       |      √       |      √       |
ESP8266            |      √       |      X       |      √       |
FireBeetle M0      |      X       |      √       |      X        |
raspberry          |      X       |      √       |      √       |

## 历史
- 2024-04-01 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))