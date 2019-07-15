
// defines pins numbers

const int buzzer = 3; //buzzer to arduino pin 2
const int led = 9;//LED TO ARDUINO PIN 9

const int ProxSensor=A0;
const int ldr=A1;
const int nmcu1=12;
int inputVal = 0;

const int trigPin1 = 2;
const int echoPin1 = 4;

const int trigPin2 = 5;
const int echoPin2 = 6;

long duration1,duration2;
int distance1,distance2,data;
void setup() {
  
pinMode(buzzer, OUTPUT); // Set buzzer - pin 3 as an output
pinMode(led,OUTPUT);//Sets the led pin as output
pinMode(nmcu1,OUTPUT);//Send ldr output for node mcu
    
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output1
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input1

pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output2
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input2



Serial.begin(9600); // Starts the serial communication
}
void loop() {

//ULTRASONIC PART
// Clears the trigPin1
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin1 on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin1, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance1
distance1= duration1*0.034/2;
// Prints the distance1 on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);




// Clears the trigPin2
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin2 on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin2, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance2
distance2= duration2*0.034/2;
// Prints the distance2 on the Serial Monitor
Serial.print("Distance2: ");
Serial.println(distance2);


//FOR ALL THE THREE SENSORS
if (distance1<=50 && distance2<=50)
{
 tone(buzzer, 6000); // Send 4KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(250);        // ...for 1 sec
  Serial.println("DANGER ALL");
}
else
{
  if(distance1<=50)
  {
    tone(buzzer, 500); // Send 1KHz sound signal...
    delay(250);        // ...for 1/4 sec
    noTone(buzzer);     // Stop sound...
    delay(250);        // ...for 1/4 sec
    Serial.println("DANGER1");
  }


  if(distance2<=50)
  {
   tone(buzzer, 2000); // Send 1.5KHz sound signal...
   delay(250);        // ...for 1/4 sec
   noTone(buzzer);     // Stop sound...
   delay(250);      // ...for 1/4 sec
   Serial.println("DANGER2");
  }
}
 //END OF ULTRASONIC


// POTHOLE DETECTION USING IR
 inputVal = analogRead(ProxSensor);

if(inputVal<100)
{
  tone(buzzer, 8000); // Send 4KHz sound signal...
  delay(125);        // ...for 1/8 sec
  noTone(buzzer);     // Stop sound...
  delay(125);        // ...for 1/8 sec
  Serial.println("POTHOLE");
  
  }
Serial.print("IR READING:");
Serial.println(inputVal);
delay(1000);              // wait for a second
//END OF POTHOLE DETECTION

//LDR DETECTION
 data= analogRead(ldr);
 Serial.println("LDR value");
 Serial.println(data);

if (data > 100){
Serial.println("LED light on");
digitalWrite(led,HIGH);
delay(1000);
digitalWrite(nmcu1, HIGH);
}
else
{
Serial.println("OFF");
digitalWrite(nmcu1, LOW);
digitalWrite(led,LOW);
}
//END OF LDR DETECTION
}
