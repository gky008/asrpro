#include "custom_uart_text_sensor.h"

CustomUartTextSensor::CustomUartTextSensor(HardwareSerial* serial)
    : PollingComponent(1000), serial_(serial) {}

void CustomUartTextSensor::setup() {
  serial_->begin(9600);  // 根据实际情况设置波特率
}

void CustomUartTextSensor::update() {
  if (serial_->available()) {
    std::string line = serial_->readStringUntil('\n');
    // 在这里应用 asrpro_uart_command.h 里的规则处理 line
    // 假设 asrpro_uart_command.h 里有一个函数 processUartData 来处理数据
    std::string processed_data = processUartData(line); 
    this->publish_state(processed_data.c_str());
  }
}
