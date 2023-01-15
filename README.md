# 2022微算機期末專題文件
###### tags: `microcomputer`
[原始碼下載連結](https://drive.google.com/file/d/1x6EfPmAoLbmSHL_loayxDHxZCGnzOWUP/view?usp=share_link) 

[影片檔觀看連結](https://drive.google.com/file/d/1tw06FpkpIOctcW2E6TfR4HpdDEFLRIUX/view?usp=share_link)

[原始碼GitHub連結](https://github.com/weihsinyeh/Microprocessor-Project.git)

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

1. Difficulties about function of watering , plant , lighting 

One of the difficulties we face is to interface the buttons with the functions. We need a lot of buttons for different functions, and at first, when we set the function to run if PORTx.RBx = 1 and if INT0IF =1, it doesn’t work.

In the end, we used interrupts INT0, INT1, and INT2 for each button. After we set the function to run if INTxIF = 1, the function will run. Because we could only use two PICKit 4, each PIC only has 3 interrupts, we had to limit the usage of our buttons.

2. Difficulties about high/low voltage

當我們在寫code時候，我們以一般認知認為按鈕按下1 ，則會給我們輸入端high voltage。但神奇的是，經過我們一番努力的debug後，我們發現我們的按鈕按下，是給輸入端low voltage。我原本以為是我們button的電路接法問題，而導致如此的結果。但後來發現其實這沒有差。
![](https://i.imgur.com/vZXfoLK.png)

最後，我認為是電阻的問題。由以下圖來說明。
![](https://i.imgur.com/qgCGjg4.png)

Case1 : 如果電阻很大的時候則當我按下button 則，輸入到pin的電壓相當於low (2V被電阻吃掉剩趨近於0V，0V與1V並聯，所以輸出為1V)。(如左圖)
Case2 : 如果電阻很小的時候則當我按下button 則，輸入到pin的電壓相當於high (2V 與 1V並聯，所以輸出為2V)。(如右圖)
而我們button有接電阻，因此我認為我們是Case1，所以判斷button按下後的電位 check是否為0。而平時我們認為的是未接電阻的button(相當於Case2 電阻很小)，所以判斷button按下後的電位check是否為1。

3. Difficulties about control direction

當我們在用馬達的時候邏輯基本上都正確，但在設定馬達的時候我們一直搞不清楚馬達的delay要設在哪裡，我們參考別人的code，但用在我們的code上面卻執行的不是那麼順利。最後我們理清思緒，決定用polling I/O 假如按下某個方向控制的button 就可以進到相對應控制的function，而在那個function中有一個無限迴圈，只會終止於按下其他button的事件。設一個無限迴圈的原因是因為，我們發現只給他左右馬達高低電位，他似乎只run了微乎其微的一瞬間，因此要設定讓他一直給他高低電位來讓馬達可以讓它移動。與此同時無限迴圈也要設定終止條件，此為其他button按下。如果此事件觸發，則將自己的button = 1(根據困難2說明)。然後跳出此無限迴圈回到main function去檢查是哪個button再次被按下，再進到相對應控制方向的function中。

4. Difficulties about location display
一開始我們在設定8*8 dot matrix，我以為row都是在一排，而column都是在一排，所以我們剛開始跑出來都是錯的。因為真正的dot matrix 上面8個pin角，與下面8個pin角的設定都是交錯的。去查了之後才從新更正。
第二個困難的部份是我原先不知道8*8 dot matrix 一個row 要設定為high column 要設定為low，二極體才會流過，所以我們一定要有一個設為1一個設為0，才會使想要的位置的燈泡發光。
![](https://i.imgur.com/MygejFv.png)
![](https://i.imgur.com/2has1xq.png)

第三個困難的部分是原先我們想要做到顯示路徑，但後來我思考過後我們只有顯示一個位置一個點才有可能實現，因為我們不是所有的code都在跑dot matrix display ，而是有改變方向或經過幾秒才進去跑，如果要實現大範圍的點矩陣顯示，就要透過一排一排刷的去顯示，因為dot matrix只能實現一行 或 一列的顯示。而其中切換一排一排的間距時間是奈秒，因為人的肉眼看不到所以就認為他是同時顯示，但其實不竟然。
要實現大面積路徑顯示就要一排排刷，而一排排的效果就要所有的code都在run點矩陣，但我們是只有在改變路徑或到行經特定時間才會再做location定位的移動，所以我就改成只做location定位，而不是record the path.

5. Difficulties about amount of water display
At the beginning, we had to measure the height of the bottle that contained water. Also, we tried to figure out how ultrasonic and seven displays work. We referred to this code. We selected an 8 MHz oscillator frequency, so time to execute 1 instruction is 1/(125k/4) = 0.8 us. Therefore, the timer value increases every 0.5 us . The distance of object is 
Sound velocity*Timer/2 	= 34300*( TIMER value) x 0.8 x (10^-6 )cm
= 0.01372 *( TIMER value) cm
