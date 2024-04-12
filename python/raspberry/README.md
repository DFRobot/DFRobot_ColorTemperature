DFRobot_ColorTemperature
===========================

- [中文版](./README_CN.md)

The SEN0611 is a color temperature sensor. By using the APIs provided in the library, you can obtain color temperature data, illuminance, and color coordinate data.

![产品效果图](../../resources/images/SEN0611.png)

## Product Link (https://www.dfrobot.com)

    SKU：SEN0611

## Table of Contents

  * [summary](#summary)
  * [installation](#installation)
  * [methods](#methods)
  * [compatibility](#compatibility)
  * [history](#history)
  * [credits](#credits)

## Summary

The SEN0593 is a color temperature sensor. By using the APIs provided in the library, you can obtain color temperature data, illuminance, and color coordinate data.

## Installation

Download this library to Raspberry Pi before use, then open the routine folder. Type python demox.py on the command line to execute a routine demox.py. For example, to execute the read_data.py routine, you need to enter:

```python
python read_data.py
```

## Methods

```python
  def begin(self):
    '''!
      @brief Init SEN0611 sensor
      @return Return init status
      @retval 0  Succeed
      @retval -1 Failed
    '''
  
  def read_lux(self):
    '''!
      @brief Get sensor illuminance
      @return Illuminance obtained
    '''
  
  def read_cct(self):
    '''!
      @brief Get color temperature data
      @return Color temperature obtained
    '''
  
  def read_x(self):
    '''!
      @brief Get color coordinate X
      @return Color coordinate X obtained
    '''
  
  def read_y(self):
    '''!
      @brief Get color coordinate Y
      @return Color coordinate Y obtained
    '''
```

## Compatibility

* RaspberryPi Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| Raspberry Pi2 |           |            |    √     |         |
| Raspberry Pi3 |           |            |    √     |         |
| Raspberry Pi4 |       √   |            |          |         |

* Python Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |

## History

- 2024-04-01 - Version 1.0.0 released.

## Credits

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
