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
void ShowMove();
void DrawMove();
void MSdelay(unsigned int val);
#define row1 PORTAbits.RA1 
#define row2 PORTAbits.RA0 
#define row3 PORTDbits.RD6 
#define row4 PORTCbits.RC6  
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

#define high 0
#define low 1
unsigned int direction = 0; // 0 : forward , 1 : back , 2: right, 3: left;

void setrowBits(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g,unsigned char h){
    row1=a;
    row2=b;
    row3=c;
    row4=d;
    row5=e;
    row6=f;
    row7=g;
    row8=h;
}
void setcolBits(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g,unsigned char h){
    col1=a;
    col2=b;
    col3=c;
    col4=d;
    col5=e;
    col6=f;
    col7=g;
    col8=h;
}
int interval = 100;
unsigned int array[8][8];
unsigned int curRow = 0;
unsigned int curCol = 0;
void main(void) { 
    ADCON1 = 0x0F;
    TRISD = 0x00;                /* set PORT as output port */
    LATD = 0x00;
    TRISC = 0b00111111;
    PORTC = 0;
    TRISA = 0;
    TRISE=0;
    TRISB = 0;
    setcolBits(1,0,0,0,0,0,0,0);
    setrowBits(0,1,1,1,1,1,1,1);
    row1 = 0;
    static unsigned char buttonDisable = 0;


    while(1){
        DrawMove();
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
void DrawMove(){
        if(curRow == 0)      setrowBits(0,1,1,1,1,1,1,1);
        else if(curRow == 1) setrowBits(1,0,1,1,1,1,1,1);
        else if(curRow == 2) setrowBits(1,1,0,1,1,1,1,1);
        else if(curRow == 3) setrowBits(1,1,1,0,1,1,1,1);
        else if(curRow == 4) setrowBits(1,1,1,1,0,1,1,1);
        else if(curRow == 5) setrowBits(1,1,1,1,1,0,1,1);
        else if(curRow == 6) setrowBits(1,1,1,1,1,1,0,1);
        else if(curRow == 7) setrowBits(1,1,1,1,1,1,1,0);
        
        if(curCol == 0)      setcolBits(1,0,0,0,0,0,0,0);
        else if(curCol == 1) setcolBits(0,1,0,0,0,0,0,0);
        else if(curCol == 2) setcolBits(0,0,1,0,0,0,0,0);
        else if(curCol == 3) setcolBits(0,0,0,1,0,0,0,0);
        else if(curCol == 4) setcolBits(0,0,0,0,1,0,0,0);
        else if(curCol == 5) setcolBits(0,0,0,0,0,1,0,0);
        else if(curCol == 6) setcolBits(0,0,0,0,0,0,1,0);
        else if(curCol == 7) setcolBits(0,0,0,0,0,0,0,1);    
}


void ShowMove(){
    switch(direction){
        case 0: //move forward;
            if(curRow!=7) curRow = curRow + 1;
            break;
        case 1: // move back;
            if(curRow!=0) curRow = curRow - 1;
            break;
        case 2: // move left;
            if(curCol!=7) curCol = curCol + 1;
            break;
        case 3: // move right;
            if(curCol!=0) curCol = curCol - 1;
            break;
    }
    array[curRow][curCol] = 1;
    DrawMove();
}
void forward(){
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
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
            direction = 0;
            count1++;
            if(count1==interval){
                count1 = 0;
                count2++;
            }
            if(count2==interval){
                count2 =0;
                ShowMove();
            }
        }
    }
}
void backward(){   
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
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
            direction = 1;
            count1++;
            if(count1==interval){
                count1 = 0;
                count2++;
            }
            if(count2==interval){
                count2 =0;
                ShowMove();
            }
        }
    }
}
void left(){
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
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
            direction = 2;
            count1++;
            if(count1==interval){
                count1 = 0;
                count2++;
            }
            if(count2==interval){
                count2 =0;
                ShowMove();
            }
        }
    }
}
void right(){
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
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
            direction = 3;
            count1++;
            if(count1==interval){
                count1 = 0;
                count2++;
            }
            if(count2==interval){
                count2 =0;
                ShowMove();
            }
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
     for(unsigned int j=0;j<val;j++){
            for(unsigned int k =0;k<100;k++);
        }
 }
