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
void main(void) { 
    TRISD = 0x00;                /* set PORT as output port */
    LATD = 0x00;
    TRISC = 0b00111111;
    PORTC = 0;
    
    static unsigned char buttonDisable = 0;
    
    
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