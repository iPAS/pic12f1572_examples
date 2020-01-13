/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC12F1572
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_WS aliases
#define IO_WS_TRIS                 TRISAbits.TRISA4
#define IO_WS_LAT                  LATAbits.LATA4
#define IO_WS_PORT                 PORTAbits.RA4
#define IO_WS_WPU                  WPUAbits.WPUA4
#define IO_WS_OD                   ODCONAbits.ODA4
#define IO_WS_ANS                  ANSELAbits.ANSA4
#define IO_WS_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_WS_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_WS_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_WS_GetValue()           PORTAbits.RA4
#define IO_WS_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_WS_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_WS_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_WS_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_WS_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define IO_WS_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define IO_WS_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_WS_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_LED aliases
#define IO_LED_TRIS                 TRISAbits.TRISA5
#define IO_LED_LAT                  LATAbits.LATA5
#define IO_LED_PORT                 PORTAbits.RA5
#define IO_LED_WPU                  WPUAbits.WPUA5
#define IO_LED_OD                   ODCONAbits.ODA5
#define IO_LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_LED_GetValue()           PORTAbits.RA5
#define IO_LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_LED_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define IO_LED_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/