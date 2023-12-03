#include <Servo.h>
Servo bullet;
Servo jfkHead;
Servo dpd;
const int gunButtonPin=7;
const int cpOneBP=3;
const int cpTwoBP=4;
const int cpThreeBP=5;
const int lhoBP=6;
int shotCount=0;
void setup() 
{
  Serial.begin(9600);
  bullet.attach(9);
  jfkHead.attach(12);
  dpd.attach(11);
  pinMode(gunButtonPin, INPUT);
  pinMode(cpOneBP, INPUT);
  pinMode(cpTwoBP, INPUT);
  pinMode(cpThreeBP, INPUT);
  pinMode(lhoBP, INPUT);

}

void loop() {
  bullet.write(0);
  jfkHead.write(0);
  dpd.write(0);
  

  if(digitalRead(lhoBP))
  {
    
    //Serial.println("assassin");
    
      if(shotCount==0&&digitalRead(gunButtonPin)&&digitalRead(cpOneBP))
      {
        bullet.write(70);
        shotCount++;
        delay(500);
        bullet.write(0);
        Serial.println(shotCount);
      }
    
     if(shotCount==1&&digitalRead(gunButtonPin)&&digitalRead(cpTwoBP))
     {
       shotCount++;
       bullet.write(70);
       delay(500);
       bullet.write(0);
       Serial.println(shotCount);
     }

     if(shotCount==2&&digitalRead(gunButtonPin)&&digitalRead(cpTwoBP))
     {
       bullet.write(70);
       shotCount++;
       delay(500);
       bullet.write(0);
       Serial.println(shotCount);
     }
    
    if(shotCount==3) 
    {
      jfkHead.write(180);delay(500);
      Serial.println("ouchie");
      shotCount++;
    }
    if(digitalRead(cpThreeBP))
    {
      dpd.write(180);
     // Serial.println("DPD");
    }
  }
}
