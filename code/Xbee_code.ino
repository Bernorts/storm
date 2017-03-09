#define xbeePin
#include <Servo.h>

Servo servo_dir, servo_dep, servo_buoy;
byte inByte[3];
char inString[6];
int stringPos = 0; 
int lastValue = 0;

int power;
//Motor1
int motor_power = 8;
int motor_pin1 = 7;
int motor_pin2 = 6;
//Motor2
int motor_pin3 = 5;
int motor_pin4 = 4;

void setup() 
{
  Serial.begin(9600);
  servo_dir.attach(10);
  servo_dep.attach(9);
  servo_buoy.attach(11);

  servo_dir.write(90);
  servo_dep.write(90);
  servo_buoy.write(90); 

  //activer motor ?

  //profondeur drone
  servo_dep.write(170);
  delay(5000);
  servo_dep.write(0);

}

void loop() 
{ 
  //information emise par Android
  byte tab[3]={0,0,0};
  for(int i=0; i<3; i++)
  {
    tab[i]=Serial.read();
  }
  int spd = (int) tab[0];
  int dir = (int) tab[1];
  int buoy = (int) tab[2];
  
  //module rescue ServoX
  if (buoy != 0)
  {
     servo_buoy.write(170);
  }
  //Speed Controle
  power = map(spd, 0, 10, 0, 255);
  analogWrite(motor_power, power);
  digitalWrite(motor_pin1, 0);
  digitalWrite(motor_pin2, 1);
  digitalWrite(motor_pin3, 0);
  digitalWrite(motor_pin4, 1);
  //Direction Controle
  if (dir = 1)
  {
    servo_dir.write(30);
  }
  else if (dir = 2)
  {
    servo_dir.write(150);
  }
  else
  {
    servo_dir.write(90);
  }
}

