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

#define high 0
#define low 1
unsigned int direction = 0; // 0 : forward , 1 : back , 2: right, 3: left;
/*
 |              ^         
 |  forward     |  back  --> right < --left
 v                          |
 */
void setcol(unsigned int col){
    switch(col){
        case 0: col1 = high; break;
        case 1: col2 = high; break;
        case 2: col3 = high; break;
        case 3: col4 = high; break;
        case 4: col5 = high; break;
        case 5: col6 = high; break;
        case 6: col7 = high; break;
        case 7: col8 = high; break;
    }
}
void unsetcol(unsigned int col){
    switch(col){
        case 0: col1 = low; break;
        case 1: col2 = low; break;
        case 2: col3 = low; break;
        case 3: col4 = low; break;
        case 4: col5 = low; break;
        case 5: col6 = low; break;
        case 6: col7 = low; break;
        case 7: col8 = low; break;
    }
}
void setrow(unsigned int row){
    switch(row){
        case 0: row1 = high; break;
        case 1: row2 = high; break;
        case 2: row3 = high; break;
        case 3: row4 = high; break;
        case 4: row5 = high; break;
        case 5: row6 = high; break;
        case 6: row7 = high; break;
        case 7: row8 = high; break;       
    }
}
void unsetrow(unsigned int row){
    switch(row){
        case 0: row1 = low; break;
        case 1: row2 = low; break;
        case 2: row3 = low; break;
        case 3: row4 = low; break;
        case 4: row5 = low; break;
        case 5: row6 = low; break;
        case 6: row7 = low; break;
        case 7: row8 = low; break;
    }
}
unsigned int array[8][8];
unsigned int curRow = 0;
unsigned int curCol = 0;
void main(void) { 
    TRISD = 0x00;                /* set PORT as output port */
    LATD = 0x00;
    TRISC = 0b00111111;
    PORTC = 0;
    TRISA = 0;
    TRISE=0;
    TRISB = 0;
    
    for(unsigned int i = 0;i < 8;i++){
        for(unsigned int j = 0;j < 8;j++)
            array[i][j] = 0;
    }
    array[0][0] = 1;
    static unsigned char buttonDisable = 0;
    
//    for(unsigned int i = 0;i<8;i++){
//        unsetrow(i);
//        setcol(i);
//    }
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
void DrawMove(){
    for(unsigned int i=0;i<8;i++){
        setrow(i);
        for(unsigned int j=0;j<8;j++){
            if(array[i][j] == 0){
                setcol(i);
            }
            else{
                unsetcol(i);
            }
        }
        unsetrow(i);
        for(unsigned int j=0;j<10000;j++){
            for(unsigned int k =0;k<10000;k++);
        }
    }
}
void ShowMove(){
    switch(direction){
        case 0: //move forward;
            if(curRow!=7) curRow++;
            break;
        case 1: // move back;
            if(curRow!=0) curCol--;
            break;
        case 2: // move left;
            if(curCol!=7) curCol++;
            break;
        case 3: // move right;
            if(curCol!=0) curCol--;
            break;
        array[curRow][curCol] = 1;
    }
    DrawMove();
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
            direction = 0;
            ShowMove();
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
            direction = 1;
            ShowMove();
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
            direction = 2;
            ShowMove();
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
            direction = 3;
            ShowMove();
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
            for(unsigned int k =0;k<10000;k++);
        }
 }