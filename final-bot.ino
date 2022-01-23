char val;
#define m11 3    // rear motor
#define m12 5
#define m21 4    // front motor
#define m22 6
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);


void setup()
{
   Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);  
  BTSerial.begin(38400);
  digitalWrite(A1,HIGH)
}


void loop()
{
  
 if(BTSerial.available())
  {
    val=BTSerial.read();
    Serial.print(val);

    if(val=='f')//Move front
    {
        digitalWrite(m11, HIGH);
       digitalWrite(m12, LOW);
       digitalWrite(m21, HIGH);
       digitalWrite(m22, LOW);
      Serial.print(val); 
    }

    if(val =='b')//Move back
    {
       digitalWrite(m11, LOW);
       digitalWrite(m12, HIGH);
       digitalWrite(m21, LOW);
       digitalWrite(m22, HIGH);
       
       Serial.print(val);
    }

    if(val=='s')//Stop
    {
       digitalWrite(m11, LOW);
       digitalWrite(m12, LOW);
       digitalWrite(m21, LOW);
       digitalWrite(m22, LOW);
       digitalWrite(12,LOW);  
    
       Serial.print(val);
    }

    if( val =='l')//left
    {
       digitalWrite(m11, HIGH);
       digitalWrite(m12, LOW);
       delay(100);
       digitalWrite(m21, LOW);
       digitalWrite(m22, HIGH);
       
       Serial.print(val);
    }

    if( val=='r')//right
    {
       digitalWrite(m11, LOW);
       digitalWrite(m12, HIGH);
       delay(100);
       digitalWrite(m21, HIGH);
       digitalWrite(m22, LOW);
       Serial.print(val);
      
    }
    
    if(val=='1')
    {
        digitalWrite(12,HIGH); 
        digitalWrite(A2,HIGH); 
    }

 }
}
