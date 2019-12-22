/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC12F1572
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"


#include <stdio.h>
#include "onewire.h"

#define skip_rom 0xCC
#define	convert_temp 0x44 
#define	write_scratchpad 0x4E
#define	resolution_12bit 0x7F
#define read_scratchpad 0xBE


/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    
    uint16_t temp;
    
    
    while (1)
    {
        // Add your application code
        
        
        RA5 = 1;  // LED ON
        __delay_ms(200); // 1 Second Delay
        RA5 = 0;  // LED OFF
        __delay_ms(200); // 1 Second Delay


        //--- Perform temperature reading
        ow_reset();                  // Onewire reset signal
        ow_write_byte(skip_rom);     // Issue command SKIP_ROM
        ow_write_byte(convert_temp); // Issue command CONVERT_T
        __delay_ms(750); 
        
        ow_reset();
        ow_write_byte(skip_rom);        // Issue command SKIP_ROM
        ow_write_byte(read_scratchpad); // Issue command READ_SCRATCHPAD

        temp = ow_read_byte();
        temp = (ow_read_byte() << 8) + temp;
        uint16_t after_point = 
                ((temp&0b1000)? 5000:0) +
                ((temp&0b0100)? 2500:0) +
                ((temp&0b0010)? 1250:0) +
                ((temp&0b0001)? 0625:0);
        
        //--- Show
        char buf[16], *p=buf;
        sprintf(buf, "%d.%d\r\n", temp>>4, after_point);
        while (*p != '\0')
        {
            EUSART_Write(*p++);
        }
    }
}
/**
 End of File
*/