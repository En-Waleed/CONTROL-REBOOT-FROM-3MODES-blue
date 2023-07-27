const int motor1speed = 9;
const int motor1Pin1 = 10; 
const int motor1Pin2 = 11;
const int motor2speed = 3;
const int motor2Pin1 = 4; 
const int motor2Pin2 = 5; 
const int sensor1 = 7 ;
const int sensor2 = 8;
const int trig = A5;
const int echo = A4;
char reading;
int sp = 128 ;
long int t ;
long int d ;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1speed, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2speed, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT); 
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {reading = Serial.read();}
  if (reading =='l'){
      analogWrite(motor1speed,sp);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      analogWrite(motor2speed,sp);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    
   if(digitalRead(sensor1)==1){
      analogWrite(motor1speed,sp);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);  
      analogWrite(motor2speed,0);}
    
    if (digitalRead(sensor2)==1){
      analogWrite(motor1speed,0);
      analogWrite(motor2speed,sp);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);}
      }
  
  else if(reading=='b') {
      analogWrite(motor1speed,SP);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      analogWrite(motor2speed,SP);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
        
      digitalWrite(trig,LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH); 
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      t = pulseIn (echo,HIGH);
      d = 0.0343*t/2;
    if (d<=30){
      analogWrite(motor1speed,SP);
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      analogWrite(motor2speed,SP);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(500);
      analogWrite(motor1speed,0);
      analogWrite(motor2speed,SP);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(500);}
  }
  
 else {    

  switch(reading) {
    case 'F':
      analogWrite(motor1speed,SP);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      analogWrite(motor2speed,SP);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      break;
    case 'B':
      analogWrite(motor1speed,SP);
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      analogWrite(motor2speed,SP);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      break;
    case 'L':
      analogWrite(motor1speed,SP);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);  
      analogWrite(motor2speed,0);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      break;
    case 'R':
      analogWrite(motor1speed,0);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      analogWrite(motor2speed,SP);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      break;
    case 'S':
      analogWrite(motor1speed,0);
      analogWrite(motor2speed,0);
      break;
  }}
  }



