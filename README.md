# 2022 Microprocessor-Project
###### tags: `microcomputer`
[Source Code Link](https://drive.google.com/file/d/1x6EfPmAoLbmSHL_loayxDHxZCGnzOWUP/view?usp=share_link) 

[Video Link](https://drive.google.com/file/d/1tw06FpkpIOctcW2E6TfR4HpdDEFLRIUX/view?usp=share_link)

[Github Link](https://github.com/weihsinyeh/Microprocessor-Project.git)

Group Members :

●陳紅宏 F74097065

●雷美心 F74095314

●葉惟欣 F74109016 

●黃佳倫 E64096245

## a.Description of System Functions and Principles
The aging labor force in agriculture is a big issue in Taiwan. Digging, sowing, and watering are very tiring activities for farmers . In order to reduce the burden of farmers, The Agricultural Robot is designed. Farmers can control the machine to move forward, back , turn around , sow, water, light the plant, plant by self-controller. Farmers can know when to supply water when farmers see the amount of water. Additionally, farmers can know where the Agricultural Robot is when they see the location display.
The machine have 6 functions in total:
1. Watering, using a button and a servo motor to control the switch.
    ● Press button to open the switch.
    ● Press button one more time to close the switch.
2. Planting seeds, using a button and a servo motor to control the switch for releasing the seed.
    ● Press button to open the switch.
    ● Press button one more time to close the switch.
3. Lighting: using a button to control light up and off of the LED.
    ● Press button turn on the LED.
    ● Press button one more time to turn off the LED.
4. Digging the soil, using a DC motor for rotating the plow, and a button to control.
    ● Press button to rotate the plow
5. Direction control, using DC motor to control only one side of the wheel to control the direction of the machine.
6. Automatically display the location of the robot on the 8*8 dot matrix display. 
7. Automatically display the amount of water the robot has.
8. The 1st to 5th can be controlled by the buttons on the self-made controller, and the 6th is automatically displayed

---

## b. System Usage Environment and Objects
  ● Environment: MPLAB X IDE
  ● Language: XC8
  ● Object: PicKit 4
  
---

## c. Complete System Architecture Diagram, Flowchart, Circuit diagram, Design

### 1. System Architecture Diagram

![](https://i.imgur.com/kMwAWcP.png)
![](https://i.imgur.com/TrcY4sb.png)
Demo video : https://youtu.be/HZmYcK4nnb8 

#### 1.1 self made controller 

![](https://i.imgur.com/F98o1t3.png)

#### 1.2 Watering machine 

![](https://i.imgur.com/cAPndpn.png)

Demo video : https://youtu.be/vNmy5nwkuUk 

#### 1.3 Plant Machine 

![](https://i.imgur.com/0EX8zxe.png)

Demo video : https://youtu.be/Qj_ujl7H98E 

#### 1.4 Digging the soil 

![](https://i.imgur.com/O1n3t9K.png)

Demo Video : https://youtu.be/v89_Q-JRsBY  

#### 1.5 Robot moving control

![](https://i.imgur.com/MiLTAjl.png)

Demo Video : https://youtu.be/W0g9xHhyw_U 

#### 1.6 Location display on 8*8 dot matrix

![](https://i.imgur.com/CKOMptn.png)
![](https://i.imgur.com/AB1VD64.png)

Demo  video : https://youtu.be/jXSN8A6g8iw 

#### 1.7 the amount of water show on 7-Segment display

![](https://i.imgur.com/4CPrCbT.png)

### 2.Flowchart

* Check which button is pressed (watering, planting seed, or lights)

![](https://i.imgur.com/K994ZEI.png)

* Watering Flow Chart

![](https://i.imgur.com/XkIHRHw.png)

* Planting the seed Flow Chart

![](https://i.imgur.com/WFcaV1x.png)


* Digging the soil Flow Chart

![](https://i.imgur.com/I6I1sTz.png)

* Lighting (LED) Flow Chart

![](https://i.imgur.com/52sCy8q.png)

* Seven-Segment Display Flow Chart

![](https://i.imgur.com/qO8kDVI.png)

* Moving Direction Control Flow Chart

![](https://i.imgur.com/RtyMUTG.png)

* 8*8 Dot Matrix Display Location Flow Chart

![](https://i.imgur.com/W7ajeyG.png)

### 3.Circuits: 
* main.c

![](https://i.imgur.com/QyLcJx7.png)

* function.c 

![](https://i.imgur.com/4bFMWQW.png)

* Dig the soil with DC motor

![](https://i.imgur.com/zAl086v.png)

* 8*8 dot matrix 

set row and column pin that tell the farmer where the agriculture robot is. 
![](https://i.imgur.com/JOiGKMd.png)

[Reference : Interfacing 8×8 LED Matrix](https://www.circuitstoday.com/interfacing-8x8-led-matrix-with-arduino?fbclid=IwAR1Dwr7snI5L6WABfz_edGxfDH6wiEoKvDJpHciI9DBSWRIvzOQmyx_M33Q)

* PIC18F4520 main.c pin setting

![](https://i.imgur.com/s1YA29v.png)

* Seven-segment display the amount of water to tell the farmer when to supply water.

![](https://i.imgur.com/bbApwGN.png)

* PIC18F4520 function.c pin setting

![](https://i.imgur.com/tDc8cwH.png)

---

## d. System Development Tools, Materials and Technologies
 ● LED
 ● Servo motor
 ● DC motor
 ● Button
 ● Pickit 4
 ● PIC18F4520
 ● Bread board
 ● 8*8 dot matrix
 ● 7-segment display
 ● L9110
 ● HC-SR04

---

## e. Peripheral interface or Library and API instructions
 ● PIC18F4520.h
 ● xc.h

---

## f. The division of labor of the actual team members
![](https://i.imgur.com/WSufUuN.png)

---

## g. Difficulties encountered and how to solve them

**1. Difficulties about function of watering , plant , lighting **

One of the difficulties we face is to interface the buttons with the functions. We need a lot of buttons for different functions, and at first, when we set the function to run if PORTx.RBx = 1 and if INT0IF =1, it doesn’t work.

In the end, we used interrupts INT0, INT1, and INT2 for each button. After we set the function to run if INTxIF = 1, the function will run. Because we could only use two PICKit 4, each PIC only has 3 interrupts, we had to limit the usage of our buttons.

**2. Difficulties about high/low voltage**

When writing code, the common understanding is that pressing a button (e.g., pressing '1') should result in a high voltage input. However, surprisingly, after extensive debugging efforts, we discovered that our button press was providing a low voltage input instead. Initially, we assumed that the issue was related to the circuitry of our button, leading to such unexpected results. However, later on, we realized that the button's circuitry was not the cause of the discrepancy.

![](https://i.imgur.com/vZXfoLK.png)

But in the end, I believe it was an issue with the resistor. This is illustrated in the diagram below.

![](https://i.imgur.com/qgCGjg4.png)

Case 1: If the resistance is high, when I press the button, the voltage input to the pin is equivalent to low (2 Volt is largely consumed by the resistor, approaching 0 Volt. Since 0 Volt and 1 Volt are in parallel, the output is 1 Volt) - as shown in the left diagram.

Case 2: If the resistance is low, when I press the button, the voltage input to the pin is equivalent to high (2 Volt and 1 Volt in parallel, resulting in a 2 Volt output) - as shown in the right diagram.

As our button is connected to a resistor, I believe we fall into Case 1. Therefore, we check if the potential after pressing the button is 0 Volt. In ordinary situations, where we assume an unconnected button (equivalent to Case 2 with a low resistance), we check if the potential after pressing the button is 1 Volt.

**3. Difficulties about control direction**

When dealing with motors, our logical operations were generally correct, but we encountered difficulties determining where to set the delay for the motor in the configuration. Despite referencing code from others, the execution in our code didn't proceed as smoothly. Eventually, after organizing our thoughts, we decided to employ polling I/O. If a button corresponding to a specific direction is pressed, the code enters the respective control function. Within that function, there is an infinite loop that only terminates when another button is pressed. The reason for setting an infinite loop is that when we provided the motor with high and low voltage for left and right movements, it seemed to run for just a fraction of a moment. Therefore, setting a continuous high-low voltage sequence allows the motor to keep moving.

Simultaneously, the infinite loop must include a termination condition, triggered when another button is pressed. If this event occurs, the button for the specific direction is set to 1 (as per the explanation in Difficulty 2). The code then exits the infinite loop, returning to the main function to check which button has been pressed again and proceeds to the corresponding control direction function.

**4. Difficulties about location display**

In the initial setup of the 8x8 dot matrix, I initially misunderstood the configuration, thinking that the rows and columns were aligned separately in rows and columns. Consequently, our initial outputs were incorrect. It was later discovered that the real configuration of the dot matrix involves an interleaved arrangement of the 8 pins on the top and bottom.

The second challenging aspect was my lack of awareness that for an 8x8 dot matrix, setting one row to high and the corresponding column to low allows the diode to conduct. Therefore, it's crucial to set one of them to 1 and the other to 0 to illuminate the desired LED at a specific location.
![](https://i.imgur.com/MygejFv.png)
![](https://i.imgur.com/2has1xq.png)

The third challenge arose when we initially aimed to display a path. However, upon further consideration, I realized that achieving this goal would only be possible by displaying one position at a time. This limitation arises because not all of our code runs the dot matrix display continuously; instead, there are directional changes or delays before entering the display section. To achieve a comprehensive display of points, we would need to refresh the matrix row by row, as the dot matrix can only show one row or one column at a time. The switching between rows is done in nanoseconds, imperceptible to the human eye, creating the illusion of simultaneous display.

To implement a broad path display, we would need to refresh row by row, requiring all the code to run the dot matrix continuously. However, in our case, we only update the location when changing the path or after a specific time, rather than continuously recording the entire path. Therefore, I modified the approach to focus on location-based updates rather than recording the entire path.

**5. Difficulties about amount of water display**
At the beginning, we had to measure the height of the bottle that contained water. Also, we tried to figure out how ultrasonic and seven displays work. We referred to this code. We selected an 8 MHz oscillator frequency, so time to execute 1 instruction is 1/(125k/4) = 0.8 us. Therefore, the timer value increases every 0.8 us . The distance of object is 
Sound velocity*Timer/2 	= 34300*( TIMER value) x 0.8 x (10^-6 )cm
= 0.01372 *( TIMER value) cm
