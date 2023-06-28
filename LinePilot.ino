
const int leftSensorPin = 2;
const int centerSensorPin = 3;
const int rightSensorPin = 4;
const int motorPin3 = 10;
const int motorPin4 = 11;
const int motorPin1 = 5;
const int motorPin2 = 6;
const int trigPin = 7;
const int echoPin = 8;
long distance;
long duration;

void setup() {
  Serial.begin(9600);
  pinMode(leftSensorPin, INPUT);
  pinMode(centerSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin3 , OUTPUT);
  pinMode(motorPin4 , OUTPUT);
  
}

void loop() {
  
  int leftSensorValue = digitalRead(leftSensorPin);
  int centerSensorValue = digitalRead(centerSensorPin);
  int rightSensorValue = digitalRead(rightSensorPin);
  int isLeft = leftSensorValue;
  int isRight = rightSensorValue;
digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
 duration = pulseIn(echoPin , HIGH);
 distance = duration*0.034 / 2;
 Serial.print("Obstacle Distance: ");
  Serial.println(distance);
 if(distance<20){
  Serial.println("Object is detected!!");
  digitalWrite(motorPin3,LOW);
  digitalWrite(motorPin4,LOW);
 }
 else{
  if (isLeft==1 && isRight==0) {
    
    digitalWrite(motorPin3,HIGH);
     digitalWrite(motorPin4,LOW);
       digitalWrite(motorPin1,LOW);
     digitalWrite(motorPin4,HIGH);
  } else if (isLeft==0 && isRight==1) {
   
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
  } else {
    Serial.println("Straight");
    digitalWrite(motorPin3,HIGH);
     digitalWrite(motorPin4,LOW);
       digitalWrite(motorPin1,HIGH);
     digitalWrite(motorPin4,LOW);
    
  }
 }
  delay(1000); 
}
