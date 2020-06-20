#include <Wire.h>
#include <LSM303.h>

LSM303 compass;

double xav = 0.0;
double yav = 0.0;
double zav = 0.0;
int tick = 0;

void setup(){
  Wire.begin();
  compass.init();
  compass.enableDefault();
  Serial.begin(9600) ;
}

void loop()
{
  compass.read();

  Serial.print("aX:") ;
  Serial.print(compass.a.x - xav) ;
  Serial.print(" aY:") ;
  Serial.print(compass.a.y - yav) ;
  Serial.print(" aZ:") ;
  Serial.print(compass.a.z - zav) ;

  if(tick < 1000){
  xav = (xav + compass.a.x) / 2;
  yav = (yav + compass.a.y) / 2;
  zav = (zav + compass.a.z) / 2;
  tick++;
  }
  
  Serial.print(" mX:") ;
  Serial.print(compass.m.x) ;
  Serial.print(" mY:") ;
  Serial.print(compass.m.y) ;
  Serial.print(" mZ:") ;
  Serial.println(compass.m.z) ;

  delay(50) ;
}
  
