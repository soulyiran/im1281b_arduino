#include "Arduino.h"
#if defined(__AVR__) || defined(ESP8266)
#include <SoftwareSerial.h>
#elif defined(FREEDOM_E300_HIFIVE1)
#include <SoftwareSerial32.h>
#define SoftwareSerial SoftwareSerial32
#endif


class IM1281B
{

#define Read_ID 0x01
private:
  Stream *mySerial;
  #if defined(__AVR__) || defined(ESP8266) || defined(FREEDOM_E300_HIFIVE1)
  SoftwareSerial *swSerial;
  #endif
  HardwareSerial *hwSerial;

  void read_data_message();
  bool get_CMD_message();
  void clear_CMD_Buffer();
  bool analysis_data();
  bool chkCRC(uint8_t* pucFrame, uint16_t usLen);

  uint8_t Tx_Buffer[8] = {0x01, 0x03, 0x00, 0x48, 0x00, 0x08, 0xc4, 0x1a};
  uint8_t TX_Buffer_clear[13] = {0x01, 0x10, 0x00, 0x4b, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x2c};
  uint8_t Rx_Buffer[40];
  uint16_t cmdLenth = 0;
  uint32_t Voltage_data, Current_data, Power_data, Energy_data, Pf_data, CO2_data, Frequency_data;




public:
  #if defined(__AVR__) || defined(ESP8266) || defined(FREEDOM_E300_HIFIVE1)
  IM1281B(SoftwareSerial *ss, uint16_t baudrate = 4800);
  #endif
  IM1281B(HardwareSerial *hs, uint16_t baudrate = 4800);
  IM1281B(Stream *serial, uint16_t baudrate = 4800);
  void begin(uint16_t baudrate);
  void update();
  void clearPower();
  float getVotage();
  float getCurrent();
  float getPower();
  float getEnergy();
  float getPf();
  float getCO2();
  float getFreq();
};
