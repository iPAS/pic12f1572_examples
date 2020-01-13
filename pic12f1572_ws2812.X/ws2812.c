/**
 Example from http://stevephillips.me/blog/using-ws2812b-pic-microcontroller
 Super thanks to 
 Author: Steve Phillips kingcoyote
 Github: https://gist.github.com/kingcoyote/
 */

#include "mcc_generated_files/mcc.h"
#include "ws2812.h"


/** 
 * Reverse the bits in a char
 */
unsigned long int bitflip(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return (unsigned long int)b;
}

/**
 * Transmit the WS2812 led
 */
void ws2812_send(ws2812_ptr* led) {
    int j;
    long int val;
    // the WS2812 wants bits in the order of:
    //   GGGGGGGGRRRRRRRRBBBBBBBB
    // but I want to work in the opposite order. so i'm going to flip
    // the bits around and do some shifting so my order is
    //   BBBBBBBBRRRRRRRRGGGGGGGG
    // with the most significant bit on the far right. so the RGB value
    // of 128 64 32, which normally would be:
    // R : 0b10000000
    // G : 0b01000000
    // B : 0b00100000
    // will become:
    //   BBBBBBBBRRRRRRRRGGGGGGGG
    //   000001000000000100000010
    val = (bitflip(led->b) << 16) + (bitflip(led->r) << 8) + (bitflip(led->g));

    // now begin shifting them over one at a time
    for(j = 0; j < 24; j++) {
        // Depending on if the currently viewed bit is 1 or 0
        //   the pin will stay high for different times

        if ((val & 1) == 1) {
            // if it is a 1, let it stay higher a bit longer
            PIN = 1;
            NOP();
            NOP();
            NOP();
            PIN = 0;
        } else {
            // But a 0 should go high and then low as fast as possible
            PIN = 1;
            PIN = 0;
        }
        
        // Then right shift to get the next bit
        val = val >> (unsigned char)1;
    }
}
