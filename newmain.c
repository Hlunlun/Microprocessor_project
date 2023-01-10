#include "configure_header_file.h"
#define Left_1 PORTDbits.RD1
#define Left_2 PORTDbits.RD0
#define Right_1 PORTDbits.RD3
#define Right_2 PORTDbits.RD2

#define ButtonForward PORTCbits.RC0
#define ButtonBack PORTCbits.RC1
#define ButtonLeft PORTCbits.RC3
#define ButtonRight PORTCbits.RC4
#define ButtonStop PORTCbits.RC5
void forward();
void backward();
void left();
void right();
void stop();
void ShowMove(int direcion);
void MSdelay(unsigned int val);
#define row1 PORTAbits.RA0   
#define row2 PORTAbits.RA5 
#define row3 PORTDbits.RD6 
#define row4 PORTAbits.RA3  
#define row5 PORTBbits.RB5 
#define row6 PORTBbits.RB4 
#define row7 PORTDbits.RD7 
#define row8 PORTBbits.RB1

#define col1 PORTAbits.RA4 
#define col2 PORTBbits.RB0 
#define col3 PORTBbits.RB2 
#define col4 PORTDbits.RD4 
#define col5 PORTBbits.RB3 
#define col6 PORTCbits.RC7  
#define col7 PORTDbits.RD5  
#define col8 PORTEbits.RE1 

void setcol(unsigned char c1,unsigned char c2,unsigned char c3,unsigned char c4,unsigned char c5,unsigned char c6,unsigned char c7,unsigned char c8){
    col1 = c1;
    col2 = c2;
    col3 = c3;
    col4 = c4;
    col5 =c5;
    col6 = c6;
    col7 = c7;
    col8 =c8;
}

void setrow(unsigned char r1,unsigned char r2,unsigned char r3,unsigned char r4,unsigned char r5,unsigned char r6,unsigned char r7,unsigned char r8){
    row1 = r1;
    row2 = r2;
    row3 = r3;
    row4 = r4;
    row5 =r5;
    row6 = r6;
    row7 = r7;
    row8 =r8;
}
void main(void) { 
    TRISD = 0x00;                /* set PORT as output port */
    LATD = 0x00;
    TRISC = 0b00111111;
    PORTC = 0;
    TRISA = 0;
    TRISE=0;
    TRISB = 0;
    
    static unsigned char buttonDisable = 0;
    
    setcol(1,1,1,1,1,1,1,1);
    setrow(0,0,0,0,0,0,0,0);
    while(1){
        if(!ButtonForward){
            forward();
        }
        else if(!ButtonBack){
            backward();
        }
        else if(!ButtonLeft){
            left();
        }
        else if(!ButtonStop){
            stop();
        }
        else if(!ButtonRight){
            right();
            
        }
    }
    return;
}
void ShowMove(int direction){
    switch(direction){
        case 0: //move forward;
            //setrow(1,1,1,1,1,1,1,1);
            break;
        case 1: // move back;
            break;
        case 2: // move left;
            break;
        case 3: // move right;
            break;
    }
}
void forward(){
    while(1){   
        Left_1 = 1;
        Left_2 = 0;
        Right_1 = 1;
        Right_2 = 0;
        if(ButtonLeft ==0 || ButtonRight == 0 || ButtonStop == 0 || ButtonBack == 0){
            ButtonForward = 1;
            break;
        }
        else{
            MSdelay(200);
            ShowMove(0);
        }
    }
}
void backward(){   
    while(1){
        Left_1 = 0;
        Left_2 = 1;
        Right_1 = 0;
        Right_2 = 1;
        if(ButtonLeft ==0|| ButtonRight == 0 || ButtonStop == 0 || ButtonForward == 0){
            ButtonBack = 1;
            break;
        }
        else{
            MSdelay(200);
            ShowMove(1);
        }
    }
}
void left(){
    while(1){
        Left_1 = 0;
        Left_2 = 0;
        Right_1 = 1;
        Right_2 = 0;
        if(ButtonBack ==0 || ButtonRight == 0 || ButtonStop == 0 || ButtonForward == 0){
            ButtonLeft =1;
            break;
        }
        else{
            MSdelay(200);
            ShowMove(2);
        }
    }
}
void right(){
    while(1){
        Left_1 = 1;
        Left_2 = 0;
        Right_1 = 0;
        Right_2 = 0;
        if(ButtonBack ==0 || ButtonLeft == 0 || ButtonStop == 0 || ButtonForward == 0){
            ButtonRight = 1;
            break;
        }
        else{
            MSdelay(200);
            ShowMove(3);
        }
    }
}
void stop(){
    while(1){
        Left_1 = 0;
        Left_2 = 0;
        Right_1 = 0;
        Right_2 = 0;
        if(ButtonBack ==0 || ButtonLeft == 0 || ButtonRight == 0 || ButtonForward == 0){
            ButtonStop = 1;
            break;
        }
    }
}
void MSdelay(unsigned int val)
{
     unsigned int i,j;
        for(i=0;i<=val;i++)
            for(j=0;j<81;j++);      /*This count Provide delay of 1 ms for 8MHz Frequency */
 }