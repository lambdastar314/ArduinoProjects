Serial.begin(9600) ;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600) ;
}

void loop() {
  // put your main code here, to run repeatedly:

  long x , y , z ;
  x = y = z = 0 ;
  x = analogRead(1)
  y = analogRead(2)
  z = analogRead(3)
  Serial.print("X:") ;
  Serial.print(x) ;
  Serial.print(" Y:") ;
  Serial.print(y) ;
  Serial.print(" Z:") ;
  Serial.println(z) ;
  
  delay(50) ;
}
}
