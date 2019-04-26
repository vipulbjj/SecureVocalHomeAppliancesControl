#include <SoftwareSerial.h>

const int rxPin = 2;
const int txPin = 3;               
SoftwareSerial mySerial(rxPin, txPin);

int ac=4;
int light=5;
int fan=6;
int tv=7;
String data;

void setup() 
{
   Serial.begin(9600);
   mySerial.begin(9600);
   
   pinMode(ac, OUTPUT);
   pinMode(light, OUTPUT);
   pinMode(fan, OUTPUT);
   pinMode(tv, OUTPUT);
 
   digitalWrite(ac, LOW);
   digitalWrite(light, LOW);
   digitalWrite(fan, LOW);
   digitalWrite(tv, LOW);
}

void loop() 
{
    int i=0;
    char ch=0;
    data="";
while(1)
{ 
      while(mySerial.available()<=0)
      {
        data="";
      }
      ch = mySerial.read();
      data+=ch;
    
   Serial.println(data);
    
    if(data=="turn on light")
    { 
      digitalWrite(ac,HIGH);
      Serial.println("ac on");
      break;
    }
    else if(data=="turn off light")
    {
      digitalWrite(ac,LOW);
      Serial.println("ac off");
      break;
    }
    else if(data=="turn on LED")
    {
      digitalWrite(light,HIGH);
      Serial.println("light on");
      break;
    }
    else if(data=="turn off LED")
    {
      digitalWrite(light,LOW);
      Serial.println("light off");
      break;
    }
    else if(data=="turn on motor")
    {
      digitalWrite(fan,HIGH);
      Serial.println("fan on");
    }
    else if(data=="turn off motor")
    {
      digitalWrite(fan,LOW);
      Serial.println("fan off");
      break;
    }
    else if(data=="turn on fan")
    {
      digitalWrite(tv,HIGH);
      Serial.println("tv on");
      break;
    }
    else if(data=="turn off fan")
    {
      digitalWrite(tv,LOW);
      Serial.println("tv off");
      break;
    }
    else if(data=="turn on all")
    {
      digitalWrite(ac,HIGH);
      digitalWrite(light,HIGH);
      digitalWrite(fan,HIGH);
      digitalWrite(tv,HIGH);
      Serial.println("all on");
      break;
    }
    else if(data=="turn off all")
    {
      digitalWrite(ac,LOW);
      digitalWrite(light,LOW);
      digitalWrite(fan,LOW);
      digitalWrite(tv,LOW);
      Serial.println("all off");
      break;
    
    }
}
    
}
