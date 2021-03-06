/*************************************************** 
  This is a library for the MCP23008 i2c port expander

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#ifndef _ADAFRUIT_MCP23008_H
#define _ADAFRUIT_MCP23008_H
// Don't forget the Wire library

class AdafruitMCP23008 {
public:
  void begin(uint8_t addr);
  void begin(void);
  void reset();

  void pinMode(const uint8_t portNumber, const uint8_t direction);
  void digitalWrite(const uint8_t portNumber, const uint8_t writeValue);
  void pullUp(const uint8_t portNumber, const uint8_t d);
  void inputPolarity(const uint8_t portNumber, const bool inverted);

  uint8_t digitalRead(const uint8_t portNumber);
  
  void clearInterrupts(void);
  void useActiveInterrupts(const uint8_t polarity); // HIGH or LOW
  void interruptsOnPinChange(const uint8_t portNumber, const bool enabled);
  void interruptsOnChangeFromRegister(const uint8_t portNumber, const bool registerValue, const bool enabled);
  uint8_t wasInterruptedAt(const uint8_t portNumber);


  uint8_t readGPIO(void);
  void writeGPIO(uint8_t);
  uint8_t readINTCAP(void);
  uint8_t readIOCON(void);

  void dumpConfigurationTo(Stream& stream);

 private:
  uint8_t i2caddr;
  void dumpRegister(Stream& stream, const uint8_t registerId, char* name);
  uint8_t read8(const uint8_t addr);
  void write8(const uint8_t addr, const uint8_t data);
  void setRegisterBit(const uint8_t registerId, const uint8_t offset, const bool bitValue);
};

#define MCP23008_ADDRESS 0x20

// registers
#define MCP23008_IODIR 0x00
#define MCP23008_IPOL 0x01
#define MCP23008_GPINTEN 0x02
#define MCP23008_DEFVAL 0x03
#define MCP23008_INTCON 0x04
#define MCP23008_IOCON 0x05
#define MCP23008_GPPU 0x06
#define MCP23008_INTF 0x07
#define MCP23008_INTCAP 0x08
#define MCP23008_GPIO 0x09
#define MCP23008_OLAT 0x0A

#endif
