//Source code for simple Arduino alarm system.
//Made with an Arduino Uno
//By: Payton Long

//Global Scope:
const int buzzer = 9;
const int light = 8;

//Variables for ultrasonic sensor:
const int trigPin = 11;
const int echoPin = 12;
long duration, inches;

//Setup function:
void setup(){
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT); //Set alert buzzer pin 9 as an output
  pinMode(light, OUTPUT); //Set alert light to pin 8 as output
}

//Main Loop:
void loop(){
    //Implementation of sensor func:
    getData();
    //Implementation of alert func:
    if(inches <= 6){
      alert();
      Serial.println();
      Serial.print("Alarm triggered!");
    }
}

//Function prototypes:
void alert(){
    //This function triggers whenever the sensor senses movement:
    digitalWrite(light, HIGH); //Turn alert light on
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);
    noTone(buzzer);
    delay(1000);  
    digitalWrite(light, LOW);
}

void getData(){
    //Code to get data from ultrasonic sensor:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    inches = (duration/2) / 74;
    Serial.print(inches);
    Serial.print(" inches.");
    Serial.println();
    delay(250);
}


