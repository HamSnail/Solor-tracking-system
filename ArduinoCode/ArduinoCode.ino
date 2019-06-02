#include <Servo.h> 

Servo horizontal; 
int servoh = 90;
Servo vertical; 
int servov = 90; 

int ldrlt = 0; //LDR top left
int ldrrt = 1; //LDR top rigt
int ldrld = 2; //LDR down left
int ldrrd = 3 ; //ldr down rigt

int a =0;
int b =0;
int c =0;
int d =0;

unsigned long servoMillis=0;
unsigned curMillis = millis();
void setup()
{
  horizontal.attach(3); 
  vertical.attach(5);
}

void loop() 
{
   unsigned curMillis = millis();
   
  int a = analogRead(ldrlt); 
  int b = analogRead(ldrrt);
  int c = analogRead(ldrld); 
  int d = analogRead(ldrrd);

  int avt = ((a + b) / 2)/10;
  int avd = ((c + d) / 2)/10; 
  int avl = ((a + c) / 2)/10; 
  int avr = ((b + d) / 2)/10;

if(curMillis-servoMillis>80)
{
  servoMillis=curMillis;
  if (avt > avd)
  {
    servov = --servov;
     if (servov < 0) 
     { 
      servov = 0;
     }
  }
  else if (avt < avd)
  {
    servov= ++servov;
    if (servov > 100)
  {
    servov = 100;
  }
  }
  vertical.write(servov);
 
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < 0)
    {
    servoh = 0;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > 100)
     {
     servoh = 100;
     }
  }
  horizontal.write(servoh);
}
}
