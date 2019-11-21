
// PIC16F1614 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    //  (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = ON    // Clock Out Enable (CLKOUT function is enabled on the CLKOUT pin)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
#pragma config ZCD = OFF        // Zero Cross Detect Disable Bit (ZCD disable.  ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PLLEN = ON       // PLL Enable Bit (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// CONFIG3
#pragma config WDTCPS = WDTCPS1F// WDT Period Select (Software Control (WDTPS))
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config WDTCWS = WDTCWSSW// WDT Window Select (Software WDT window size control (WDTWS bits))
#pragma config WDTCCS = SWC     // WDT Input Clock Selector (Software control, controlled by WDTCS bits)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic16f1614.h>

void __interrupt() INT_RTN(void)
{
    
}

void main(void) {
    OSCCONbits.IRCF = 0b1110;
    OSCTUNEbits.TUN = 0b11;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    TRISAbits.TRISA0 = 0;
    PORTAbits.RA0 = 1;
    
    INTCONbits.T0IF = 0;
    INTCONbits.T0IE = 1;
    
    OPTION_REGbits.PS = 0;
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.T0SE = 0b11;
    TMR0 = 100;

    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
    
    T1CONbits.TMR1CS = 0b00;
    T1CONbits.T1CKPS = 0b11;
    T1CONbits.nT1SYNC = 0;
    TMR1 = 60535;
    T1CONbits.TMR1ON  = 1;
    
    while(1)
    {
        
    }
}
