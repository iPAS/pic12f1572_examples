/*
 * File:   main.c
 * Author: ipas
 *
 * Created on November 17, 2019, 2:12 PM
 */

// An example from https://www.microchip.com/forums/m838765.aspx
#define _XTAL_FREQ 500000L

#include <xc.h>

// ### BEGIN CONFIG
// CONFIG1
#pragma config FOSC = INTOSC // (INTOSC oscillator; I/O function on CLKIN pin)
#pragma config WDTE = OFF // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
// CONFIG2
#pragma config WRT = OFF // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOREN = OFF // Low Power Brown-out Reset enable bit (LPBOR is disabled)
#pragma config LVP = ON // Low-Voltage Programming Enable (Low-voltage on MCLR/VPP is allowed to used for programming)
//### END CONFIG

void main(void) {
    OSCCON = 0b01010000; // 1010 = 500kHz HF(1)page 53
    ANSELA = 0b00000000; // all pins to digital
    LATA   = 0b00000000; // all port bits off
    TRISA  = 0b00001100; // all pins to outputs except RA2(AN2) & RA3(MCLR)

    while(1) {
        RA5 = 1;  // LED ON
        __delay_ms(200); // 1 Second Delay
        RA5 = 0;  // LED OFF
        __delay_ms(200); // 1 Second Delay
    }
    
    return;
}
