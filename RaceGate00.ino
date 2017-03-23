/*
  RaceGates by Jambonbill
  Use HC-SR04 Ping distance sensor]
  Speaker to pin 9-10 for 8bit gate sounds.
*/

#include <toneAC.h>
#include "midinotes.h"
#include "avr/pgmspace.h"

#define trigPin 14
#define echoPin 15
#define ledGate 7
#define ledPass 8

//#define COMMON_ANODE
#define redPin 3
#define greenPin 5
#define bluePin 6

long lastdistance;
byte gatepassed=0;
byte transpose=0;//midi note transposition
int frame=0;
int major[] = { 40, 44, 47, 44};
int minor[] = { 40, 43, 47, 43};
int blues[]={0,3,5,6,7,10,12};//7 values

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGate, OUTPUT);
  pinMode(ledPass, OUTPUT);
  //tran
  majChord(36);
  delay(40);
  majChord(36+5);
  
  //initSound();
  //pipeSound();
  //oneUpSound();
  //pauseSound();
  //powerUpSound();
}

void randomSound(){
  byte r=random(8);
  switch(r){
      
      case 0:
        coinSound(); break;
      case 1:
        oneUpSound() break;
      
      case 2:
        powerUpSound();break;
      
      case 3:
        pipeSound();break;
      case 4:
        gateSound();break;
        
  }
}

void initSound(){  //play a little melody
  for (int thisNote = 0; thisNote < 7; thisNote++) {
    int noteDuration =50;    
    toneAC(getMidiNotePhaseIncrement(blues[thisNote]+36), 10, noteDuration, false); // Play thisNote at full volume for noteDuration in the background.
    //delay(noteDuration); // Wait while the tone plays in the background, plus another 33% delay between notes.
  }
}

void coinSound(){// super mario bros !
  byte noteDuration=50;
  toneAC(getMidiNotePhaseIncrement(59), 10, 50, false);
  toneAC(getMidiNotePhaseIncrement(64), 10, 80, false);
}

void oneUpSound(){//E4-G4-E5-C5-D5-G5
    byte noteDuration=80;
    toneAC(getMidiNotePhaseIncrement(76-24), 10, noteDuration, false);//52
    toneAC(getMidiNotePhaseIncrement(79-24), 10, noteDuration, false);
    toneAC(getMidiNotePhaseIncrement(88-24), 10, noteDuration, false);
    toneAC(getMidiNotePhaseIncrement(84-24), 10, noteDuration, false);
    toneAC(getMidiNotePhaseIncrement(86-24), 10, noteDuration, false);
    toneAC(getMidiNotePhaseIncrement(91-24), 10, noteDuration, false);
}

void pauseSound(){//E2-C2-E2-C2
  byte noteDuration=80;
  toneAC(getMidiNotePhaseIncrement(52), 10, noteDuration, false);//E
  toneAC(getMidiNotePhaseIncrement(48), 10, noteDuration, false);//C
  toneAC(getMidiNotePhaseIncrement(52), 10, noteDuration, false);//E
  toneAC(getMidiNotePhaseIncrement(48), 10, noteDuration, false);//C
}

void powerUpSound(){//F2-B2-D3 - F3-B3-G#2 - C3-D#3-G#3 - C4-A#2-D3 - F3-A#3-D4
  byte noteDuration=40;
  toneAC(getMidiNotePhaseIncrement(53-12), 10, noteDuration, false);//F2
  toneAC(getMidiNotePhaseIncrement(59-12), 10, noteDuration, false);//B2
  toneAC(getMidiNotePhaseIncrement(62-12), 10, noteDuration, false);//D3
  
  toneAC(getMidiNotePhaseIncrement(65-12), 10, noteDuration, false);//F3
  toneAC(getMidiNotePhaseIncrement(71-12), 10, noteDuration, false);//B3
  toneAC(getMidiNotePhaseIncrement(56-12), 10, noteDuration, false);//G#2

  toneAC(getMidiNotePhaseIncrement(60-12), 10, noteDuration, false);//C3
  toneAC(getMidiNotePhaseIncrement(63-12), 10, noteDuration, false);//D#3
  toneAC(getMidiNotePhaseIncrement(68-12), 10, noteDuration, false);//G#3
  
  toneAC(getMidiNotePhaseIncrement(72-12), 10, noteDuration, false);//C4
  toneAC(getMidiNotePhaseIncrement(58-12), 10, noteDuration, false);//A#2
  toneAC(getMidiNotePhaseIncrement(62-12), 10, noteDuration, false);//D3
  
  toneAC(getMidiNotePhaseIncrement(65-12), 10, noteDuration, false);//F3
  toneAC(getMidiNotePhaseIncrement(70-12), 10, noteDuration, false);//A#3
  toneAC(getMidiNotePhaseIncrement(74-12), 10, noteDuration, false);//D4
}

void pipeSound(){//A3-E3-A2 (3 times) (33,28,21)
  byte noteDuration=50;
  for(byte i=0;i<3;i++){
    toneAC(getMidiNotePhaseIncrement(33), 10, noteDuration, false); // Play thisNote at full volume for noteDuration in the background.
    toneAC(getMidiNotePhaseIncrement(28), 10, noteDuration, false); // Play thisNote at full volume for noteDuration in the background.  
    toneAC(getMidiNotePhaseIncrement(21), 10, noteDuration, false); // Play thisNote at full volume for noteDuration in the background.  
  }
}


void gateSound(){
  
  byte rnd=random(7);
  byte chord=random(2);
  
  for (int thisNote = 0; thisNote < 6; thisNote++) {
    int noteDuration =25;
    // Play thisNote at full volume for noteDuration in the background.
    //toneAC(getMidiNotePhaseIncrement(major[thisNote]), 10, noteDuration, true);
    //delay(noteDuration);//crap
    
    if(chord==0){
      toneAC(getMidiNotePhaseIncrement(major[thisNote%3]+blues[rnd]), 10, noteDuration, false);
    }else if(chord==1){
      toneAC(getMidiNotePhaseIncrement(minor[thisNote%3]+blues[rnd]), 10, noteDuration, false);
    }else{
      toneAC(getMidiNotePhaseIncrement(minor[thisNote%3]+blues[rnd]), 10, noteDuration, false);
    }
  }
}

void swooshSound(){//crap
  for (unsigned long freq = 125; freq <= 1250; freq += 10) {  
    toneAC(freq); // Play the frequency (125 Hz to 15 kHz sweep in 10 Hz steps).
    delay(1);     // Wait 1 ms so you can hear it.
  }
}

void majChord(byte midinote){
  byte noteDuration=20;
  toneAC(getMidiNotePhaseIncrement(midinote), 10, noteDuration, false);
  toneAC(getMidiNotePhaseIncrement(midinote+4), 10, noteDuration, false);
  toneAC(getMidiNotePhaseIncrement(midinote+7), 10, noteDuration, false);
}

void setColor(int red, int green, int blue)
{
  //common anode
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void loop() {
  
  long duration, distance, diff;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;//cm
  
  if(gatepassed==0 && distance < 50){

    //check difference
    if(distance>lastdistance){
      diff=distance-lastdistance;  
    }else{
      diff=lastdistance-distance;  
    }
    
    //if(distance!=lastdistance){      
    if(diff>5){
      
      gatepassed=20;//
      
      // Debug //
      Serial.print("diff=");
      Serial.print(diff);
      Serial.print(" - ");
      Serial.print(lastdistance);
      Serial.print("!=");
      Serial.print(distance);
      Serial.println(" cm");    
    }
  }
  
  lastdistance=distance;

  if(gatepassed==20){
    digitalWrite(ledPass,1);//instant blink
    setColor(0, 255,0);
     coinSound();
      //oneUpSound();
  } else if(gatepassed>0) {
    digitalWrite(ledPass,(frame/4)%2==0);//led blink
  } else {
    setColor(255,0,0);
    digitalWrite(ledPass,0);//led off
  }
  
  if (gatepassed>0) {
    gatepassed--;
  }
  
  delay(10);
  frame++;//global frame counter
}
