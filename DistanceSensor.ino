int minvalueArea1 = 0;
int maxvalueArea1 = 10;
int minvalueArea2 = 10;
int maxvalueArea2 = 20;

const int trigPin = 2;
const int echoPin = 3;
long duration;
int distance = 0;

int area = 0; 
int prevarea;

void setupSensor() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void readSensor() {
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);

  if(distance >= minvalueArea1 && distance < maxvalueArea1) {
    area = 1;
  } else if(distance >= minvalueArea2 && distance < maxvalueArea2) {
    area = 2; 
  } else {
    area = 255;
  }

  if(area != prevarea) {
    Serial.print("newArea");
    Serial.println(area);  
    prevarea =  area;
    setMusicArea(area);
  }
}

