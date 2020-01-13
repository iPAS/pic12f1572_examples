/**
 Example from http://stevephillips.me/blog/using-ws2812b-pic-microcontroller
 Super thanks to 
 Author: Steve Phillips kingcoyote
 Github: https://gist.github.com/kingcoyote/
 */

#ifndef WS2812_H
#define	WS2812_H

// the pin that the LEDs are on. I don't like this being in here
// but timing is so tight, it is hard to put it elsewhere
#define PIN IO_WS_PORT

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ws2812_ptr;

// transmit a single WS2812
void ws2812_send(ws2812_ptr* led);

#endif	/* WS2812_H */
