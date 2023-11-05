#include <Servo.h>
Servo bullet;
Servo jfkHead;
Servo dpd;
const int gunButtonPin=2;
const int cpOneBP=3;
const int cpTwoBP=4;
const int cpThreeBP=5;
const int lhoBP=6;
int shotCount=0;
void setup() 
{
  bullet.attach(9);
  jfkHead.attach(10);
  dpd.attach(11);
  pinMode(gunButtonPin, INPUT);
  pinModepinMode(cpOneBP, INPUT);
  pinMode(cpTwoBP, INPUT);
  pinMode(cpThreeBP, INPUT);
  pinMode(lhoBP, INPUT);

}

void loop() {
  if(digitalRead(lhoBP)==HIGH)
  {
    if(digitalRead(cpOneBP)==HIGH || digitalRead(cpTwoBP==HIGH))
    {
      if(gunButtonPin==HIGH)
      {
        bullet.write(180);
        shotCount++;
      }
      else
      {
        bullet.write(0);
      }
    }
    if(shotCount==3) 
    {
      jfkHead.write(90);
    }
    if(digitalRead(cpThreeBP==HIGH))
    {
      dpd.write(180);
    }
  }
}
