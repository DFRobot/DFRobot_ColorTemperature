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

要使用这个库，首先将库下载到Raspberry Pi，然后打开例程文件夹。要执行一个例程demox.py，请在命令行中输入python demox.py。例如，要执行read_data.py例程，你需要输入:

```python
python read_data.py
```



## 方法

```python
def begin(self):
    '''!
      @brief 初始化传感器
      @return 返回初始状态
      @retval 0  成功
      @retval -1 失败
    '''
  
  def read_lux(self):
    '''!
      @brief 回去传感器光线强度
      @return 返回光线强度数据
    '''
  def read_cct(self):
    '''!
      @brief 获取色温数据
      @return 色温数据
    '''
  
  def read_x(self):
    '''!
      @brief 获取色温坐标x
      @return 返回色温坐标x
    '''
  
  def read_y(self):
    '''!
      @brief 获取色温坐标y
      @return 返回色温坐标y
    '''
```

## Compatibility

* RaspberryPi Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |     √     |            |          |         |
| RaspberryPi4 |           |            |     √    |         |

* Python Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |

## History

- 2024-04-01 - 1.0.0 版本

## Credits

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))