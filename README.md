# MSP430 - Hello World
Initial development for `MSP430` board. 

![MSP430-specs](/assets/images/MSP430-Launchpad-Pinout.jpg)

## Configuration

Configuring Visual Studio with [PlatformIO Extension](https://platformio.org/install/ide?install=vscode). Remember to set the `platform.ini` file with:

```
[env:lpmsp430g2553]
platform = timsp430
framework = arduino
board = lpmsp430g2553
```

For Linux you might need to run this command
```
sudo apt-get install python3-venv
```

You can check this [repo](https://github.com/platformio/platform-timsp430) out for some examples.

## Pin Reference from pins_energia.h

```
/*
  ************************************************************************
  *   pins_energia.h
  *
  *   Energia core files for MSP430
  *      Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: Rei VILO
  *
  ***********************************************************************
*/
#ifndef Pins_Energia_h
#define Pins_Energia_h
#ifndef BV
#define BV(x) (1 << (x))
#endif

static const uint8_t SS      = 8;  /* P2.0 */
static const uint8_t SCK     = 7;  /* P1.5 */
static const uint8_t MOSI    = 15; /* P1.7 */
static const uint8_t MISO    = 14; /* P1.6 */
static const uint8_t TWISCL1  = 9;   /* P2.1 SW I2C */
static const uint8_t TWISDA1  = 10;  /* P2.2 SW I2C */
static const uint8_t TWISDA0  = 15;  /* P1.7 */
static const uint8_t TWISCL0  = 14;  /* P1.6 */
static const uint8_t DEBUG_UARTRXD = 4;  /* Receive  Data (RXD) at P1.2 */
static const uint8_t DEBUG_UARTTXD = 3;  /* Transmit Data (TXD) at P1.1 */
#define TWISDA1_SET_MODE  (INPUT)
#define TWISCL1_SET_MODE  (INPUT)
#if defined(__MSP430_HAS_USCI__)
#define TWISDA0_SET_MODE  (PORT_SELECTION0 | PORT_SELECTION1 /* | INPUT_PULLUP*/) /* do not enable the pull ups for this device */
#define TWISCL0_SET_MODE  (PORT_SELECTION0 | PORT_SELECTION1 /* | INPUT_PULLUP*/)
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION0 | PORT_SELECTION1 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION0 | PORT_SELECTION1 | OUTPUT)
#define SPISCK_SET_MODE (PORT_SELECTION0 | PORT_SELECTION1)
#define SPIMOSI_SET_MODE (PORT_SELECTION0 | PORT_SELECTION1)
#define SPIMISO_SET_MODE (PORT_SELECTION0 | PORT_SELECTION1)
#endif
#if defined(__MSP430_HAS_USI__)
#define TWISDA0_SET_MODE  (PORT_SELECTION0 | INPUT_PULLUP)
#define TWISCL0_SET_MODE  (PORT_SELECTION0 | INPUT_PULLUP)
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION0 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION0 | OUTPUT)
#define SPISCK_SET_MODE (PORT_SELECTION0)
#define SPIMOSI_SET_MODE (PORT_SELECTION0)
#define SPIMISO_SET_MODE (PORT_SELECTION0)
#endif

/* Define the default I2C settings */
#define DEFAULT_I2C -1 /* indicates SW I2C on pseudo module 1 */
#define TWISDA TWISDA1
#define TWISCL TWISCL1
#define TWISDA_SET_MODE  TWISDA1_SET_MODE
#define TWISCL_SET_MODE  TWISCL1_SET_MODE

#define DEBUG_UART_MODULE_OFFSET 0x0

#define DEBUG_UART_MODULE 0x0

static const uint8_t A0  = 2;
static const uint8_t A1  = 3;
static const uint8_t A2  = 4;
static const uint8_t A3  = 5;
static const uint8_t A4  = 6;
static const uint8_t A5  = 7;
static const uint8_t A6  = 14;
static const uint8_t A7  = 15;
static const uint8_t A10 = 128 + 10; // special. This is the internal temp sensor

//                      +-\/-+
//               VCC   1|    |20  GND
//         (A0)  P1.0  2|    |19  XIN
//         (A1)  P1.1  3|    |18  XOUT
//         (A2)  P1.2  4|    |17  TEST
//         (A3)  P1.3  5|    |16  RST#
//         (A4)  P1.4  6|    |15  P1.7  (A7) (SCL) (MISO) depends on chip
//         (A5)  P1.5  7|    |14  P1.6  (A6) (SDA) (MOSI)
//               P2.0  8|    |13  P2.5
//               P2.1  9|    |12  P2.4
//               P2.2 10|    |11  P2.3
//                      +----+
//

// Pin names based on the silkscreen
//
static const uint8_t P1_0 = 2;
static const uint8_t P1_1 = 3;
static const uint8_t P1_2 = 4;
static const uint8_t P1_3 = 5;
static const uint8_t P1_4 = 6;
static const uint8_t P1_5 = 7;
static const uint8_t P2_0 = 8;
static const uint8_t P2_1 = 9;
static const uint8_t P2_2 = 10;
static const uint8_t P2_3 = 11;
static const uint8_t P2_4 = 12;
static const uint8_t P2_5 = 13;
static const uint8_t P1_6 = 14;
static const uint8_t P1_7 = 15;
static const uint8_t P2_7 = 18;
static const uint8_t P2_6 = 19;

static const uint8_t RED_LED = 2;
static const uint8_t GREEN_LED = 14;
static const uint8_t PUSH2 = 5;
static const uint8_t TEMPSENSOR = 128 + 10; // depends on chip


#ifdef ARDUINO_MAIN
```

### Blink

```
#include <Arduino.h>

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  // wait for a second
  delay(500);
  // turn the LED off by making the voltage LOW
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
   // wait for a second
  delay(500);
}
```