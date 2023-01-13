#include <xc.h>
#include <pic18f4520.h>
#include <stdio.h>

#pragma config OSC = INTIO67    // Oscillator Selection bits
#pragma config WDT = OFF        // Watchdog Timer Enable bit 
#pragma config PWRT = OFF       // Power-up Enable bit
#pragma config BOREN = ON       // Brown-out Reset Enable bit
#pragma config PBADEN = OFF     // Watchdog Timer Enable bit 
#pragma config LVP = OFF        // Low Voltage (single -supply) In-Circute Serial Pragramming Enable bit
#pragma config CPD = OFF        // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)

//seven display
#define _2digit_C PORTAbits.RA2
#define _2digit_DP PORTAbits.RA3
#define _2digit_E PORTAbits.RA4
#define _2digit_D PORTAbits.RA5
#define _2digit_G PORTEbits.RE0

#define _2digit_A PORTCbits.RC6
#define _2digit_B PORTCbits.RC7
#define _2digit_D2 PORTDbits.RD4
#define _2digit_D1 PORTDbits.RD5
#define _2digit_F PORTDbits.RD6

// dc motor
#define Left_1 PORTDbits.RD1
#define Left_2 PORTDbits.RD0
#define Right_1 PORTDbits.RD3
#define Right_2 PORTDbits.RD2

//ultrasonic
#define _XTAL_FREQ 8000000	/* Define freq */
#define Trigger_Pulse LATC5	/* Define Trig pin of HC-SR04 */

void Trigger_Pulse_10us();

void set7(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g,unsigned char h){
    _2digit_D2 = 1;
    _2digit_D1 = 0;
    _2digit_A = a;
    _2digit_B = b;
    _2digit_C = c;
    _2digit_D = d;
    _2digit_E = e;    
    _2digit_F = f;
    _2digit_G = g;    
    _2digit_DP = h;
}
void main(void) {
    
    float Distance;
    int Time;
    OSCCON=0x72;		/* Use internal oscillator frequency */
    TRISD = 0;			/* Make PORTD as Output port*/
    INTCON2bits.RBPU=0;		/* Enable PORTB Pull-ups */
    Trigger_Pulse = 0;
/* Enable 16-bit TMR1 Register,No prescale, internal clock, Timer OFF */    
    T1CON = 0x80;
    TMR1IF = 0;			/* Make Timer1 Overflow Flag to '0' */
    TMR1=0;	
    
    
    // 2digit seven display 
    TRISA = 0;
    TRISC = 0;
    TRISD = 0;
    TRISE = 0;
    PORTD = 0;
    
    ADCON1 = 0x0F;

    //Timer2 -> On, prescale -> 4
    T2CONbits.TMR2ON = 0b1;
    T2CONbits.T2CKPS = 0b01;

    // Internal Oscillator Frequency, Fosc = 125 kHz, Tosc = 8 탎
    OSCCONbits.IRCF = 0b001;
    
    // PWM mode, P1A, P1C active-high; P1B, P1D active-high
    CCP1CONbits.CCP1M = 0b1100;
    CCP2CONbits.CCP2M = 0b1100;
    // CCP1/RC2 -> Output
    TRISC = 0;
    LATC = 0;
    
    TRISA = 0;
    LATA = 0;
    
    // button RB0 -> input
    PORTB = 0;
    TRISB = 0b00001111;
    // Set up PR2, CCP to decide PWM period and Duty Cycle
    /** 
     * PWM period
     * = (PR2 + 1) * 4 * Tosc * (TMR2 prescaler)
     * = (0x9b + 1) * 4 * 8탎 * 4
     * = 0.019968s ~= 20탎
     */
    PR2 = 0x9b;
    
    /**
     * Duty cycle
     * = (CCPR1L:CCP1CON<5:4>) * Tosc * (TMR2 prescaler)
     * = (0x04*4 + 0b00) * 8탎 * 4
     * = 0.00512s ~= 512탎
     */
    CCPR1L = 0x04;
    CCP1CONbits.DC1B = 0b00; 
    
    CCPR2L = 0x04;
    CCP2CONbits.DC2B = 0b00; 
    
//    RCONbits.IPEN = 1; //enable priority levels on interrupts
    INTCONbits.GIEH = 1; //enable all high-priority interrupts
    INTCONbits.GIEL = 1; //enable all low-priority interrupts

    INTCONbits.INT0IE = 1; //enable INT0 external interrupt
    INTCON3bits.INT1IE = 1; //enable INT1 external interrupt
    INTCON3bits.INT2IE = 1;
    
    INTCONbits.INT0IF = 0;
    INTCON3bits.INT1IF = 0;
    INTCON3bits.INT2IF = 0;
    
    INTCON3bits.INT1IP = 0;
    INTCON3bits.INT2IP = 1;
    
    INTCON2 = 0;
    IPR1bits.RCIP = 0;
    PIE1bits.RCIE = 1;
    while(){
        
        Trigger_Pulse_10us();	/* Transmit 10us pulse to HC-SR04 */
    	while(PORTBbits.RB0==0){
             if(PORTBbits.RB3 == 1){
                Right_1 =1;
                Right_2 = 0;
            }
        }/* Wait for rising edge at Echo pin */
    	TMR1=0;			/* Load Timer1 register with 0 */
    	TMR1ON=1;			/* Turn ON Timer1*/
    	while(PORTBbits.RB0==1 && !TMR1IF){
             if(PORTBbits.RB3 == 1){
                Right_1 =1;
                Right_2 = 0;
            }
        }/* Wait for falling edge */
    	Time = TMR1;		/* Copy Time when echo is received */
    	TMR1ON=0;			/* Turn OFF Timer1 */
    	Distance = ((float)Time/117.00);/* Distance =(velocity x Time)/2 */
        
        if(Distance<9){
            set7(0,0,0,0,0,0,0,1);
        }else if(Distance<8){
            set7(0,0,0,1,1,1,1,1);
        }else if(Distance<7){
            set7(0,1,0,0,0,0,0,1);
        }else if(Distance<6){
            set7(0,1,0,0,1,0,0,1);
        }else if(Distance<5){
            set7(1,0,0,1,1,0,0,1);
        }else if(Distance<4){
            set7(0,0,0,0,0,0,0,1);
        }else if(Distance<3){
            set7(0,0,0,0,1,1,0,1);
        }else if(Distance<2){
            set7(1,0,0,1,1,1,1,1);
        }else if(Distance<1){
            set7(0,0,0,0,0,0,1,1);
        }
        
        if(PORTBbits.RB3 == 1){
            Right_1 =1;
            Right_2 = 0;
        }
    
    
    }
    return;
}
int i = 0;
int j = 0;
int k = 0;
int soil = 0;
void __interrupt() ISR(void){   
    
     if (INTCONbits.INT0IF==1 && PORTBbits.RB1==1){ 
        if(i % 2==0){
            CCPR1L = 0x0b;
            CCP1CONbits.DC1B = 0b01; 
        }
        else{
            CCPR1L = 0x12;
            CCP1CONbits.DC1B = 0x03; 
        }
        i++;
        INTCONbits.TMR0IF = 0;
        INTCONbits.INT0IF = 0;
    }else if (INTCON3bits.INT1IF==1 && PORTBbits.RB2==1){ 
        if(j % 2==0){
            CCPR2L = 0x0b;
            CCP2CONbits.DC2B = 0b01; 
        }
        else{
            CCPR2L = 0x12;
            CCP2CONbits.DC2B = 0x03; 
        }
        j++;
        INTCON3bits.INT1IF = 0;
    }else if (INTCON3bits.INT2IF == 1 && PORTBbits.RB0==1){ 
        if(k % 2==0){
            LA0 = 1;
            LA1 = 1; 

        }
        else{
            LA0 = 0;
            LA1=0; 
        }
        k++;
        INTCON3bits.INT2IF = 0;
    }
}

void Trigger_Pulse_10us()
{
    Trigger_Pulse = 1;
    __delay_us(10);
    Trigger_Pulse = 0;
}