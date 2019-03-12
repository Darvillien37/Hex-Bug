#include<Body.h>


Body spider;
void setup() {
  Serial.begin(9600);
  Serial.print("Hello");
  Serial.println(" World");
  
  // put your setup code here, to run once:
  spider.Setup();
  delay(1000);
  spider.ToStanding();
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  spider.StepFoward(5);
  delay(1000);
  
}
