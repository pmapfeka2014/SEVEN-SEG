//4NUMBERS SEVEN SEG DISPLAY

int outputenable=3;
int data=2;
int storeclk=4;
int shiftclk=5;
int SSD_Decode(int number);

int v;
int y;
 

int parsefloat(float efx);

int singledigitarray[4];
void adddot();
void singledigits(int number);
void displaynum(float x);
int SSD_Decode(int number);//decoder
void initarray();
void blankleading();

float f =3.456;
int ff=0;
int fg=0;
int parsedint=0;
int decimalpoint=0;


void setup() {
  // put your setup code here, to run once:
int x;
for (x=0;x<7;x++)
{
  pinMode(x,OUTPUT);
  
}


digitalWrite(storeclk,LOW);
digitalWrite(outputenable,LOW);//ACTIVE LOW
Serial.begin(9600);



}

void adddot()
{
  singledigitarray[decimalpoint]+=20;//decoder deflection
  
}
void displaynum(float x)
{
  decimalpoint=parsefloat(x);
  initarray();//INITIALIZE DISPLAY ARRAY
  singledigits(parsedint);//MAX 4 NUMBERS

  if (decimalpoint!=0)
  {
  adddot();//order with blanking??
  }
  blankleading();
  

  int looper;
  for (looper=3;looper>-1;looper--)
  {
 y=SSD_Decode(singledigitarray[looper]);
 shiftOut(data, shiftclk, MSBFIRST,y);

 
  }
 digitalWrite(storeclk,HIGH);
 digitalWrite(storeclk,LOW);
 
}

void loop() {
  // put your main code here, to run repeatedly:



/*for(v=0;v< 100;v++)
{

displaynum(v);
delay(100);



}*/
displaynum(0.890);
delay(1000);
Serial.println(decimalpoint);


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
     
    case 10: //blanking character
    x=255;
    break;

    //--------------------dotted numbers----------------------//

 case 20:
    x= 128;
    break;
    case 21:
    x=242;
    break;
    case 22:
    x=72;
     break;

      case 23:
    x=96;
     break;
      case 24:
  x=50;
     break;
      case 25:
   x=33;
     break;
      case 26:
   x=1;
     break;
      case 27:
    x=240;
     break;
      case 28:
x=0;
     break;
      case 29:
     x=32;
     break;
     
    case 30: //blanking character
    x=251;
    break;

     //------------------------------------------------------------------------------
     
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

void blankleading()
{
//-----------------------------------------------------------------
  bool nonzero=false;
  int index=3;
  int looper;
  
  //TREAT ZERO AS SPECIAL CASE TO AVOID INFINITE LOOP
if ((singledigitarray[0]==0)&&(singledigitarray[1]==0)&&(singledigitarray[2]==0)&&(singledigitarray[3]==0))//if number to be displayed is zero
{
  singledigitarray[3]=10;
   singledigitarray[2]=10;
    singledigitarray[1]=10;
    nonzero=true;
}

 
  while(nonzero==false)
  {
    if (singledigitarray[index]!=0)
    {
      nonzero=true;
      index++;
    }
    index--;
  }

if (nonzero==true)
{
for (looper=3;looper>index;looper--)
{
  singledigitarray[looper]=10;//blanking all leading zeros
  
}
  
}
}

int parsefloat(float efx)
{
  int count=0;
  float num=efx;
  float truncfloat=floor(efx);
  float result=num-truncfloat;

while (result>0.001)
{
  num=num*10;
  truncfloat=floor(num);
  result=num-truncfloat;
   Serial.println(result);
   count++;
  Serial.println(count);
   Serial.println(num);
   Serial.println(truncfloat);
}
  parsedint=int(num);
 return count;
  
}



