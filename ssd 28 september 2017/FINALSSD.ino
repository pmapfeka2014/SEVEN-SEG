int outputenable=3;
int data=2;
int storeclk=4;
int shiftclk=5;


void setup() {
  // put your setup code here, to run once:
int x;
for (x=0;x<7;x++)
{
  pinMode(x,OUTPUT);
  
}

digitalWrite(storeclk,LOW);
digitalWrite(outputenable,LOW);//ACTIVE LOW
int v;
for(v=0;v<2;v++)
{
shiftOut(data, shiftclk, MSBFIRST,54); 
shiftOut(data, shiftclk, MSBFIRST,37); 

}

digitalWrite(storeclk,HIGH);
digitalWrite(storeclk,LOW);
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
