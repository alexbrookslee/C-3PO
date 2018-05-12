
#include <Adafruit_PWMServoDriver.h>
#define HMIN  0
#define HMAX  600 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
int photoAdd[] = {A0,A1,A2,A3};
int motorAdd[] = {4,5,6,7};
const double baseLine = 500;
double mResp[] = {0,0,0,0};


void setup() {
    Serial.begin(9600);
    pwm.begin();
    pwm.setPWMFreq(12);
    attachInterrupt(digitalPinToInterrupt(photoAdd[0]),lWrist , CHANGE);
    attachInterrupt(digitalPinToInterrupt(photoAdd[1]),rWrist , CHANGE);
    attachInterrupt(digitalPinToInterrupt(photoAdd[2]),lLeg , CHANGE);
    attachInterrupt(digitalPinToInterrupt(photoAdd[3]),rLeg , CHANGE);
    
}

void loop() {
  for(int i =0; i < 4; i++){
    pwm.setPWM(i, 0, mResp[i]);
   // pwm.setPWM(i, 0, 4096);
  }
 
    
}

void lWrist(){
    double lW = analogRead(photoAdd[0]);
    if(lW <= baseLine){
      lW = 0;
    }
    Serial.print("Left Wrist  ");
    Serial.println(lW);
    mResp[0] = map(lW, 0, 1023, HMIN, HMAX);
    Serial.print("Left Wrist Converted  ");
    Serial.println(lW);
}

void rWrist(){
    double rW = analogRead(photoAdd[1]);
      if(rW <= baseLine){
        rW = 0;
      }
      Serial.print("Right Wrist  ");
      Serial.println(rW);
      mResp[1] = map(rW, 0, 1023, HMIN, HMAX);
      Serial.print("Right Wrist Converted  ");
      Serial.println(rW);
}

void lLeg(){
    double lL = analogRead(photoAdd[2]);
      if(lL <= baseLine){
        lL = 0;
    }
    Serial.print("Left Leg  ");
    Serial.println(lL);
    mResp[2] = map(lL, 0, 1023, HMIN, HMAX);
    Serial.print("Left Leg Converted ");
    Serial.println(lL);
  
}

void rLeg(){
   double rL = analogRead(photoAdd[3]);
      if(rL <= baseLine){
        rL = 0;
      }
      Serial.print("Right Leg  ");
      Serial.println(rL);
      mResp[3] = map(rL, 0, 1023, HMIN, HMAX);
      Serial.print("Right Leg Converted  ");
      Serial.println(rL);
      
  
} 
