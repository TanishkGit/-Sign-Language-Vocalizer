#include <SoftwareSerial.h>

// initialize the library with the numbers of the interface pins
SoftwareSerial mySerial(8,9); //  RX, TX 
int ledPin=13;//led on pin 13 is ON except when transmitter is parallel to the ground
int i = 0,j = 0,k = 0;
void setup() 
{
  Serial.begin(9600);//Initialise the serial connection debugging
  
  mySerial.begin(9600);
  
  pinMode(ledPin,OUTPUT);
  
  Serial.println(" Start... ");
  mySerial.println(" Welcome To The Project ");
  
  digitalWrite(ledPin,1);
  delay(700);
  digitalWrite(ledPin,0);
  delay(700);
  digitalWrite(ledPin,1);
  delay(700);
  digitalWrite(ledPin,0);

}

void loop() 
{

    int f1 = analogRead(A0); 
   delay(10);
    int f2 = analogRead(A1); 
   delay(10);
    int f3 = analogRead(A2); 
   delay(10); 
   
    int x = analogRead(A5); 
   delay(10); 
    int y = analogRead(A4); 
   delay(10); 


   Serial.print(f1);
   Serial.print(", ");
   Serial.print(f2);
   Serial.print(", ");
   Serial.print(f3);
   Serial.print(", ");
   Serial.print(x);
   Serial.print(", ");
   Serial.println(y);

  if(f1 > 870)
  {
    i = 1;
  }
  else
  {
    i = 0;
  }
  
  if(f2 > 870)
  {
    j = 1;
  }
  else
  {
    j = 0;
  }
  
  if(f3 > 870)
  {
    k = 1;
  }
  else
  {
    k = 0;
  }

  if((x < 310) || (y < 310) || (x > 360) || (y > 360))
  { 
  
     if ((i == 0) && (j == 0) && (k == 0))
    {
      digitalWrite(ledPin,HIGH);

      
      mySerial.println("I NEED HELP ");
      Serial.println("I NEED HELP ");
      delay(2000);
      
    }
    
    else if ((i == 0) && (j == 0) && (k == 1))
    {
      digitalWrite(ledPin,HIGH);
          
      mySerial.println("I NEED WATER ");
      Serial.println("I NEED WATER ");
      delay(2000);
  
    }
    else if ((i == 0) && (j == 1) && (k == 0))
    {
      digitalWrite(ledPin,HIGH);
      
      mySerial.println("I NEED FOOD ");
      Serial.println("I NEED FOOD ");
      delay(2000);
      
    }
    
    else if ((i == 0) && (j == 1) && (k == 1))
    {
      digitalWrite(ledPin,HIGH);
      mySerial.println("I NEED MEDICINE ");
      Serial.println("I NEED MEDICINE ");
      delay(2000);
      
     }
     
    else if ((i == 1) && (j == 0) && (k == 0))
    {
      digitalWrite(ledPin,HIGH);
      mySerial.println("I NEED COFFEE ");
      Serial.println("I NEED COFFEE ");
      delay(2000);
      
     }
     
    else if ((i == 1) && (j == 0) && (k == 1))
    {
      digitalWrite(ledPin,HIGH);
      mySerial.println("I NEED BED SHEET ");
      Serial.println("I NEED BED SHEET ");
      delay(2000);
      
     }
     
    else if ((i == 1) && (j == 1) && (k == 0))
    {
      digitalWrite(ledPin,HIGH);
      mySerial.println("I NEED TO USE WASHROOM ");
      Serial.println("I NEED TO USE WASHROOM ");
      delay(2000);
      
     }
     
    else if ((i == 1) && (j == 1) && (k == 1))
    {
      digitalWrite(ledPin,HIGH);
      mySerial.println("I NEED TO GO OUT");
      Serial.println("I NEED TO GO OUT");
      delay(2000);
      
     }
  }
     
  digitalWrite(ledPin,LOW);
  delay(300);
  
}
