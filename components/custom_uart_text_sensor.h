#ifndef CUSTOM_UART_TEXT_SENSOR_H
#define CUSTOM_UART_TEXT_SENSOR_H

#include <esphome.h>
#include <HardwareSerial.h>
// 包含你的头文件
#include "../components/asrpro_uart_command.h"

class CustomUartTextSensor : public PollingComponent, public TextSensor {
 public:
  HardwareSerial* serial_;
  CustomUartTextSensor(HardwareSerial* serial);
  void setup() override;
  void update() override;
};

#endif