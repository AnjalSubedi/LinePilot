const int leftSensorPin = 2;
const int centerSensorPin = 3;
const int rightSensorPin = 4;
const int motorPin1 = 5;//to digital pin 5
const int motorPin2 = 6;//to digital pin 6 
const int trigPin = 7;
const int echoPin = 9;
const int enpin = 11; //both ena and enb pin to digital pin 11
long distance;
long duration;
void setup() {
  Serial.begin(9600);
  pinMode(enpin,OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(centerSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin1 , OUTPUT);
  pinMode(motorPin2 , OUTPUT);
  
}
void loop() {
  analogWrite(enpin,190);
  int leftSensorValue = digitalRead(leftSensorPin);
  int centerSensorValue = digitalRead(centerSensorPin);
  int rightSensorValue = digitalRead(rightSensorPin);
  int isLeft = leftSensorValue;
  int isRight = rightSensorValue;
  int iscenter = centerSensorValue;
digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
 duration = pulseIn(echoPin , HIGH);
 distance = duration*0.0322 /2;

 if(distance<20){
 Serial.println("Object is detected,stop!!");
  digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
 }
 else{
  if ((isLeft==0 && iscenter==0 && isRight==1)||(isLeft==0 && iscenter==1 && isRight==1)) {
     Serial.println("Left");
    digitalWrite(motorPin1,0);
     digitalWrite(motorPin2,1);
  }
  
  else if ((isLeft==1 && iscenter==0 && isRight==0)||(isLeft==1 && iscenter==1 && isRight==0)) {
  
Serial.println("Right");
  digitalWrite(motorPin1,1);
     digitalWrite(motorPin2,0);
     
  } 
  
      else if((isLeft==1 && iscenter==0 && isRight==1)){
    Serial.println("Straight");
    digitalWrite(motorPin1,1);
     digitalWrite(motorPin2,1);
    
  }
 }
}
