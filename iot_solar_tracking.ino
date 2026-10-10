#include <Servo.h>
#define LDR1 A0
#define LDR2 A1
#define d 10
int angle=90;
Servo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(11);
  servo.write(angle);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);
  if((abs(ldr1 - ldr2)>d)) {
    if (ldr1 > ldr2) {
      angle = angle-5;
    }
    if (ldr1 < ldr2) {
      angle = 5+angle;
    }
  }
  servo.write(angle);
  delay(80);
}