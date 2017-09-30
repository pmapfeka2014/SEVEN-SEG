//4NUMBERS SEVEN SEG DISPLAY

int outputenable=3;
int data=2;
int storeclk=4;
int shiftclk=5;
int SSD_Decode(int number);
void displaynum(int x);
int v;
 int y;
 


int singledigitarray[4];

void singledigits(int number);
void displaynum(int x);
int SSD_Decode(int number);//decoder
void initarray();




void setup() {
  // put your setup code here, to run once:
int x;
for (x=0;x<7;x++)
{
  pinMode(x,OUTPUT);
  
}

digitalWrite(storeclk,LOW);
digitalWrite(outputenable,LOW);//ACTIVE LOW




}

void displaynum(int x)
{
  initarray();//INITIALIZE DISPLAY ARRAY
  singledigits(x);//MAX 4 NUMBERS

  int looper;
  for (looper=3;looper>-1;looper--)
  {
 y=SSD_Decode(singledigitarray[looper]);
 shiftOut(data, shiftclk, MSBFIRST,y);

 digitalWrite(storeclk,HIGH);

 digitalWrite(storeclk,LOW);
  }
 
 
}

void loop() {
  // put your main code here, to run repeatedly:

for(v=0;v<9999;v++)
{

displaynum(v);
delay(2000);



}
}

int SSD_Decode(int number)//decoder
{
  
  int x=0;
  switch (number)
  {
     case 0:
    x= 132;
    break;
    case 1:
    x=246;
    break;
    case 2:
    x=76;
     break;

      case 3:
    x=100;
     break;
      case 4:
  x=54;
     break;
      case 5:
   x=37;
     break;
      case 6:
   x=5;
     break;
      case 7:
    x=244;
     break;
      case 8:
x=4;
     break;
      case 9:
     x=36;
     break;
    


     
     
}
return x;
}
void singledigits(int number)
{
  int numbercopy=number;
int remainder=4;
int saveindex=0;


while(numbercopy!=0)
{
 remainder=numbercopy%10;
  numbercopy=numbercopy/10;
  singledigitarray[saveindex]=remainder;
  saveindex++;
 
}
  
}
void initarray()
{
  int x;
  for(x=0;x<4;x++)
  {
    singledigitarray[x]=0;
    
  }
}

