/**
 Example from http://stevephillips.me/blog/using-ws2812b-pic-microcontroller
 Super thanks to 
 Author: Steve Phillips kingcoyote
 Github: https://gist.github.com/kingcoyote/
 */

#ifndef WS2812_H
#define	WS2812_H

// The pin that the LEDs are on. Please check FOSC compatible with the datasheet.
#define PIN IO_WS_PORT

#define NUMBER_OF_LEDS 10

typedef struct 
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ws2812_ptr;

// Transmit to WS2812
void ws2812_send(ws2812_ptr* led);
void ws2812_send_multiple(ws2812_ptr* leds, uint16_t len);

#endif	/* WS2812_H */
