/*
original: http://www.instructables.com/id/Radar-Gun/
changed by Nicu FLORICA (niq_ro) - http://www.tehnic.go.ro

 HC-SR04 Sensor
   The circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pin 2
  * ECHO connection of the sensor attached to digital pin 4

 */
 
 /*
 This is a radar ping sensor that calcultates the speed of an 
 object traveling away or towards the sensor. I took some of this 
 code for the HC-SR04 Sensor implementation by Tautvidas Sipavicius. The rest
 is original code from me. I know that the seven segment display
 code is not the best to look at or the most optimized but it 
 serves its purpose just fine and is easy to understand.
 
 Written by Matthew Ladd
 */
 
const int trigPin = 2;
const int echoPin = 4;

/*
// common anode
#define APRINS LOW
#define STINS HIGH
*/

// common cathode
#define APRINS HIGH
#define STINS LOW

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  //First 7 segment (ones place)
  pinMode(30,OUTPUT);//F
  pinMode(31,OUTPUT);//G
  pinMode(32,OUTPUT);//E
  pinMode(33,OUTPUT);//D
  pinMode(34,OUTPUT);//C
  pinMode(35,OUTPUT);//B
  pinMode(36,OUTPUT);//A
  //Second 7 segment (tens place)
  pinMode(37,OUTPUT);//F
  pinMode(38,OUTPUT);//G
  pinMode(39,OUTPUT);//E
  pinMode(40,OUTPUT);//D
  pinMode(41,OUTPUT);//C
  pinMode(42,OUTPUT);//B
  pinMode(43,OUTPUT);//A

}
void zerofirst(){
  digitalWrite(30,APRINS);
  digitalWrite(31,STINS);
  digitalWrite(32,APRINS);
  digitalWrite(33,APRINS);
  digitalWrite(34,APRINS);
  digitalWrite(35,APRINS);
  digitalWrite(36,APRINS);
}
void onefirst(){
  digitalWrite(30,STINS);
  digitalWrite(31,STINS);
  digitalWrite(32,STINS);
  digitalWrite(33,STINS);
  digitalWrite(34,APRINS);
  digitalWrite(35,APRINS);
  digitalWrite(36,STINS);
}
void twofirst(){
  digitalWrite(30,STINS);//F
  digitalWrite(31,APRINS);//G
  digitalWrite(32,APRINS);//E
  digitalWrite(33,APRINS);//D
  digitalWrite(34,STINS);//C
  digitalWrite(35,APRINS);//B
  digitalWrite(36,APRINS);//A
}
void threefirst(){
  digitalWrite(30,STINS);//F
  digitalWrite(31,APRINS);//G
  digitalWrite(32,STINS);//E
  digitalWrite(33,APRINS);//D
  digitalWrite(34,APRINS);//C
  digitalWrite(35,APRINS);//B
  digitalWrite(36,APRINS);//A
}
void fourfirst(){
  digitalWrite(30,APRINS);//F
  digitalWrite(31,APRINS);//G
  digitalWrite(32,STINS);//E
  digitalWrite(33,STINS);//D
  digitalWrite(34,APRINS);//C
  digitalWrite(35,APRINS);//B
  digitalWrite(36,STINS);//A
}
void fivefirst(){
  digitalWrite(30,APRINS);//F
  digitalWrite(31,APRINS);//G
  digitalWrite(32,STINS);//E
  digitalWrite(33,APRINS);//D
  digitalWrite(34,APRINS);//C
  digitalWrite(35,STINS);//B
  digitalWrite(36,APRINS);//A
}
void sixfirst(){
  digitalWrite(30,APRINS);//F
  digitalWrite(31,APRINS);//G
  digitalWrite(32,APRINS);//E
  digitalWrite(33,APRINS);//D
  digitalWrite(34,APRINS);//C
  digitalWrite(35,STINS);//B
  digitalWrite(36,APRINS);//A
}
void sevenfirst(){
  digitalWrite(30,STINS);//F
  digitalWrite(31,STINS);//G
  digitalWrite(32,STINS);//E
  digitalWrite(33,STINS);//D
  digitalWrite(34,APRINS);//C
  digitalWrite(35,APRINS);//B
  digitalWrite(36,APRINS);//A
}
void eightfirst(){
  digitalWrite(30,APRINS);//F
  digitalWrite(31,APRINS);//G
  digitalWrite(32,APRINS);//E
  digitalWrite(33,APRINS);//D
  digitalWrite(34,APRINS);//C
  digitalWrite(35,APRINS);//B
  digitalWrite(36,APRINS);//A
}
void ninefirst(){
  digitalWrite(30,APRINS);//F
  digitalWrite(31,APRINS);//G
  digitalWrite(32,STINS);//E
  digitalWrite(33,STINS);//D
  digitalWrite(34,APRINS);//C
  digitalWrite(35,APRINS);//B
  digitalWrite(36,APRINS);//A
}
void zerosecond(){
  digitalWrite(37,APRINS);
  digitalWrite(38,STINS);
  digitalWrite(39,APRINS);
  digitalWrite(40,APRINS);
  digitalWrite(41,APRINS);
  digitalWrite(42,APRINS);
  digitalWrite(43,APRINS);
}
void onesecond(){
  digitalWrite(37,STINS);
  digitalWrite(38,STINS);
  digitalWrite(39,STINS);
  digitalWrite(40,STINS);
  digitalWrite(41,APRINS);
  digitalWrite(42,APRINS);
  digitalWrite(43,STINS);
}
void twosecond(){
  digitalWrite(37,STINS);//F
  digitalWrite(38,APRINS);//G
  digitalWrite(39,APRINS);//E
  digitalWrite(40,APRINS);//D
  digitalWrite(41,STINS);//C
  digitalWrite(42,APRINS);//B
  digitalWrite(43,APRINS);//A
}
void threesecond(){
  digitalWrite(37,STINS);//F
  digitalWrite(38,APRINS);//G
  digitalWrite(39,STINS);//E
  digitalWrite(40,APRINS);//D
  digitalWrite(41,APRINS);//C
  digitalWrite(42,APRINS);//B
  digitalWrite(43,APRINS);//A
}
void foursecond(){
  digitalWrite(37,APRINS);//F
  digitalWrite(38,APRINS);//G
  digitalWrite(39,STINS);//E
  digitalWrite(40,STINS);//D
  digitalWrite(41,APRINS);//C
  digitalWrite(42,APRINS);//B
  digitalWrite(43,STINS);//A
}
void fivesecond(){
  digitalWrite(37,APRINS);//F
  digitalWrite(38,APRINS);//G
  digitalWrite(39,STINS);//E
  digitalWrite(40,APRINS);//D
  digitalWrite(41,APRINS);//C
  digitalWrite(42,STINS);//B
  digitalWrite(43,APRINS);//A
}
void sixsecond(){
  digitalWrite(37,APRINS);//F
  digitalWrite(38,APRINS);//G
  digitalWrite(39,APRINS);//E
  digitalWrite(40,APRINS);//D
  digitalWrite(41,APRINS);//C
  digitalWrite(42,STINS);//B
  digitalWrite(43,APRINS);//A
}
void sevensecond(){
  digitalWrite(37,STINS);//F
  digitalWrite(38,STINS);//G
  digitalWrite(39,STINS);//E
  digitalWrite(40,STINS);//D
  digitalWrite(41,APRINS);//C
  digitalWrite(42,APRINS);//B
  digitalWrite(43,APRINS);//A
}
void eightsecond(){
  digitalWrite(37,APRINS);//F
  digitalWrite(38,APRINS);//G
  digitalWrite(39,APRINS);//E
  digitalWrite(40,APRINS);//D
  digitalWrite(41,APRINS);//C
  digitalWrite(42,APRINS);//B
  digitalWrite(43,APRINS);//A
}
void ninesecond(){
  digitalWrite(37,APRINS);//F
  digitalWrite(38,APRINS);//G
  digitalWrite(39,STINS);//E
  digitalWrite(40,STINS);//D
  digitalWrite(41,APRINS);//C
  digitalWrite(42,APRINS);//B
  digitalWrite(43,APRINS);//A
}
long distanceOverTime(long first,long second){
 return ((first-second)/.1)*.0223693629;//taking cm/s to mph
}

long holder;//store the cm from last time through loop.
long temp;//used to store the speed value after changes
int counter;

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
  int tens;
  int ones;
  long Speed;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Speed=distanceOverTime(holder,cm);
  holder=cm;//after speed caclulation so take the cm value for another calculation
  Speed=abs(Speed);
  if(Speed!=0 || counter==10){
    temp=Speed;
    counter=0;
  }else{
    counter++;
  }
  if(temp>=100){
   zerofirst();
   zerosecond(); 
  }else{
    ones=temp%10;
    tens=temp/10;
  }
  if(ones == 0){
    zerofirst();
  }else if(ones==1){
    onefirst();
  }else if(ones==2){
    twofirst();
  }else if(ones==3){
    threefirst();
  }else if(ones==4){
    fourfirst();
  }else if(ones==5){
    fivefirst();
  }else if(ones==6){
    sixfirst();
  }else if(ones==7){
    sevenfirst();
  }else if(ones==8){
    eightfirst();
  }else if(ones==9){
    ninefirst();
  }
  if(tens == 0){
    zerosecond();
  }else if(tens==1){
    onesecond();
  }else if(tens==2){
    twosecond();
  }else if(tens==3){
    threesecond();
  }else if(tens==4){
    foursecond();
  }else if(tens==5){
    fivesecond();
  }else if(tens==6){
    sixsecond();
  }else if(tens==7){
    sevensecond();
  }else if(tens==8){
    eightsecond();
  }else if(tens==9){
    ninesecond();
  }
  
  
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.print(" cm, ");
  Serial.print(Speed);
  Serial.print(" mph");
  Serial.println();
  
  delay(100);
}
 
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
