/*
 * WS2812.h
 *
 *  Created on: 04-Sep-2023
 *      Author: vineet
 */

#ifndef CONFIG_WS2812_H_
#define CONFIG_WS2812_H_

#include "stdint.h"

/*
 You mcu clock must be running on 48Mz. The timing calculation for generating bits(1/0) for neopixel is based
 on that
 */

// define the neopixel pin as output using ra configurator or calling R_IOPORT_PinCfg in main
#define PORT_NUMBER 5  // give your neopixel pin port
#define PIN_NUMBER  0 // give your neopixel pin
#define RGB_LED_NUMBERS 16 // number of neopixel leds you want to drive

#define GPIO_PORT_BASE_ADDR (0x40040000U)
#define GPIO_PORT_OFFSET_ADDR (0x0020U * PORT_NUMBER)
#define GPIOx_PORT_ADDR (GPIO_PORT_BASE_ADDR + GPIO_PORT_OFFSET_ADDR)
#define PCNTR3_OFFSET_ADDR (0x008U)
#define PORTx_PCNTR3_ADDR (volatile uint32_t *)(GPIOx_PORT_ADDR + PCNTR3_OFFSET_ADDR)

#define DATA(b) ((b == 0) ? (*PORTx_PCNTR3_ADDR |= (1<<(PIN_NUMBER + 16))) : (*PORTx_PCNTR3_ADDR |= (1<<PIN_NUMBER)))

#define send(b) DATA(1); __NOP(); __NOP(); __NOP(); DATA(b); __NOP(); __NOP(); __NOP(); __NOP(); DATA(0); __NOP(); __NOP(); __NOP(); __NOP();

volatile uint8_t rgb_val[RGB_LED_NUMBERS][3] = {0x00};

// auxiliary functions to control the WS2812 NeoPixel LEDs
void sendByte (unsigned char b);
void sendRGB (unsigned char r, unsigned char g, unsigned char b);
void setRGB_LEDs(uint8_t _id, uint8_t _r, uint8_t _g, uint8_t _b);

// send out a byte b in WS2812 protocol
void sendByte (unsigned char b) {

    if (b & 0b10000000) { send(1); } else { send(0); }
    if (b & 0b01000000) { send(1); } else { send(0); }
    if (b & 0b00100000) { send(1); } else { send(0); }
    if (b & 0b00010000) { send(1); } else { send(0); }
    if (b & 0b00001000) { send(1); } else { send(0); }
    if (b & 0b00000100) { send(1); } else { send(0); }
    if (b & 0b00000010) { send(1); } else { send(0); }
    if (b & 0b00000001) { send(1); } else { send(0); }

}

// send red, green, and blue values in WS2812 protocol
void sendRGB (unsigned char r, unsigned char g, unsigned char b) {

    sendByte(g);
    sendByte(r);
    sendByte(b);

}

void setRGB_LEDs(uint8_t _id, uint8_t _r, uint8_t _g, uint8_t _b)
{
    if(_id > RGB_LED_NUMBERS) return;
    rgb_val[_id][0] = _r;
    rgb_val[_id][1] = _g;
    rgb_val[_id][2] = _b;
    for(uint8_t i = 0; i < RGB_LED_NUMBERS; i++)
    {
        sendRGB(rgb_val[i][0], rgb_val[i][1], rgb_val[i][2]);
    }
}

#endif /* CONFIG_WS2812_H_ */
