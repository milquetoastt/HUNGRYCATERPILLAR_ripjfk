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
  jfkHead.attach(10);
  dpd.attach(11);
  pinMode(gunButtonPin, INPUT);
  pinMode(cpOneBP, INPUT);
  pinMode(cpTwoBP, INPUT);
  pinMode(cpThreeBP, INPUT);
  pinMode(lhoBP, INPUT);

}

void loop() {

  if(digitalRead(cpOneBP)){
    Serial.println("1");
    bullet.write(180);
  }
  if(digitalRead(cpTwoBP)){
    Serial.println("2");
    bullet.write(0);
  }
  if(digitalRead(cpThreeBP)){
    Serial.println("3");
  }


  if(digitalRead(lhoBP)
  {
    
      if(shotCount<1&&digitalRead(gunButtonPin))
      {
        bullet.write(180);
        shotCount++;
        delay(300);
        bullet.write(0);
      }
    
     if(shotCount<3&&digitalRead(cpTwoBP))
     {
       bullet.write(180);
       shotCount++;
       delay(300);
       bullet.write(0);
     }
    
    if(shotCount==3) 
    {
      jfkHead.write(90);
    }
    if(digitalRead(cpThreeBP)
    {
      dpd.write(180);
    }
  }
}
