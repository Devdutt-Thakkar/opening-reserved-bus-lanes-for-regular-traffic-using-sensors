const int trigPin1 = 27;
const int echoPin1 = 25;
const int trigPin2 = 14;
const int echoPin2 = 26;
const int trigPin3 = 16;
const int echoPin3 = 33;
const int red3 = 19;
const int red2 = 18;
const int red1 = 15;
const int green1 = 5;
const int green2 = 22;
const int green3 = 21;
//define sound speed in cm/uS
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long checker = 1;
long duration1 = 100000000, duration2 = 100000000, duration3 = 100000000;
float distanceCm1 = 1000, distanceCm2 = 1000, distanceCm3 = 1000;


void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT);
  pinMode(red3, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(green1, OUTPUT);
}

void loop() {


  if (checker == 1) {
    // Clears the trigPin
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
//    digitalWrite(trigPin2, LOW);
//    delayMicroseconds(2);
//    digitalWrite(trigPin3, LOW);

//    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin1, HIGH);
//    delayMicroseconds(2);
//    digitalWrite(trigPin2, HIGH);
//    delayMicroseconds(2);
//    digitalWrite(trigPin3, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin1, LOW);
//    delayMicroseconds(10);
//    digitalWrite(trigPin2, LOW);
//    delayMicroseconds(10);
//    digitalWrite(trigPin3, LOW);
//    delayMicroseconds(10);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration1 = pulseIn(echoPin1, HIGH);
    delayMicroseconds(2);
//    duration2 = pulseIn(echoPin2, HIGH);
//    delayMicroseconds(2);
//    duration3 = pulseIn(echoPin3, HIGH);
//    delayMicroseconds(2);

    // Calculate the distance
    distanceCm1 = duration1 * SOUND_SPEED / 2;
    distanceCm2 = duration2 * SOUND_SPEED / 2;
    distanceCm3 = duration3 * SOUND_SPEED / 2;

    // Prints the distance in the Serial Monitor
    Serial.print("Distance (cm) of first ultra sonic sensor: ");
    Serial.println(distanceCm1);
    Serial.print("Distance (cm) of second ultra sonic sensor: ");
    Serial.println(distanceCm2);
    Serial.print("Distance (cm) of third ultra sonic sensor: ");
    Serial.println(distanceCm3);

    delayMicroseconds(1000);
    digitalWrite(red1, HIGH);
    digitalWrite(green2, LOW);
    digitalWrite(green3, HIGH);

    digitalWrite(red2, HIGH);
    digitalWrite(red3, LOW);
    digitalWrite(green1, LOW);
    
  }
  if (distanceCm1 <= 16 && distanceCm2 >= 16 && distanceCm3 >= 16) {
    // Clears the trigPin
//    digitalWrite(trigPin1, LOW);
//    delayMicroseconds(2);

    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
    digitalWrite(green1, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(green3, LOW);

    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
//    digitalWrite(trigPin3, LOW);

    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
//    digitalWrite(trigPin1, HIGH);
//    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
//    delayMicroseconds(2);
//    digitalWrite(trigPin3, HIGH);

    delayMicroseconds(10);

//    digitalWrite(trigPin1, LOW);
//    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(10);
//    digitalWrite(trigPin3, LOW);
//    delayMicroseconds(10);

    // Reads the echoPin, returns the sound wave travel time in microseconds
//    duration1 = pulseIn(echoPin1, HIGH);
//    delayMicroseconds(2);
    duration2 = pulseIn(echoPin2, HIGH);
    delayMicroseconds(2);
//    duration3 = pulseIn(echoPin3, HIGH);
//    delayMicroseconds(2);

    // Calculate the distance
    delay(2000);
    distanceCm2 = duration2 * SOUND_SPEED / 2;
    distanceCm3 = duration3 * SOUND_SPEED / 2;

    // Prints the distance in the Serial Monitor
    Serial.print("Distance (cm) of first ultra sonic sensor: ");
    Serial.println(distanceCm1);
    Serial.print("Distance (cm) of second ultra sonic sensor: ");
    Serial.println(distanceCm2);
    Serial.print("Distance (cm) of third ultra sonic sensor: ");
    Serial.println(distanceCm3);
    

    
    checker=0;
    
  }

  if (distanceCm1 <= 16 && distanceCm2 <= 16 && distanceCm3 >= 16) {
    // Clears the trigPin
//    digitalWrite(trigPin1, LOW);
//    delayMicroseconds(2);
//    digitalWrite(trigPin2, LOW);
//    delayMicroseconds(2);

    digitalWrite(red3, HIGH);
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(green3, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(trigPin3, LOW);

    delayMicroseconds(2000);
    // Sets the trigPin on HIGH state for 10 micro seconds
//    digitalWrite(trigPin1, HIGH);
//    delayMicroseconds(2);
//    digitalWrite(trigPin2, HIGH);
//    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);

    delayMicroseconds(10);

    delay(5000);

//    digitalWrite(trigPin1, LOW);
//    delayMicroseconds(10);
//    digitalWrite(trigPin2, LOW);
//    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(10);

//    // Reads the echoPin, returns the sound wave travel time in microseconds
//    duration1 = pulseIn(echoPin1, HIGH);
//    delayMicroseconds(2);
//    duration2 = pulseIn(echoPin2, HIGH);
//    delayMicroseconds(2);
    duration3 = pulseIn(echoPin3, HIGH);
    delayMicroseconds(2);

    // Calculate the distance
    distanceCm1 = duration1 * SOUND_SPEED / 2;
    distanceCm2 = duration2 * SOUND_SPEED / 2;
    distanceCm3 = duration3 * SOUND_SPEED / 2;

    // Prints the distance in the Serial Monitor
    Serial.print("Distance (cm) of first ultra sonic sensor: ");
    Serial.println(distanceCm1);
    Serial.print("Distance (cm) of second ultra sonic sensor: ");
    Serial.println(distanceCm2);
    Serial.print("Distance (cm) of third ultra sonic sensor: ");
    Serial.println(distanceCm3);
//    delayMicroseconds(3000);
    
    
  }
  if (distanceCm1 <= 16 && distanceCm2 <= 16 && distanceCm3 <= 16) {
    // Clears the trigPin

    digitalWrite(red1, LOW);
    digitalWrite(green2, HIGH);
    digitalWrite(green3, HIGH);

    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(green1, HIGH);
    delay(2000);
    digitalWrite(trigPin1, LOW);
//    delayMicroseconds(2);
//    digitalWrite(trigPin2, LOW);
//    delayMicroseconds(2);
//    digitalWrite(trigPin3, LOW);

    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin1, HIGH);
//    delayMicroseconds(2);
//    digitalWrite(trigPin2, HIGH);
//    delayMicroseconds(2);
//    digitalWrite(trigPin3, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin1, LOW);
    delayMicroseconds(10);
//    digitalWrite(trigPin2, LOW);
//    delayMicroseconds(10);
//    digitalWrite(trigPin3, LOW);
//    delayMicroseconds(10);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration1 = pulseIn(echoPin1, HIGH);
    delayMicroseconds(2);
//    duration2 = pulseIn(echoPin2, HIGH);
//    delayMicroseconds(2);
//    duration3 = pulseIn(echoPin3, HIGH);
//    delayMicroseconds(2);

    // Calculate the distance
    distanceCm1 = duration1 * SOUND_SPEED / 2;
    distanceCm2 = duration2 * SOUND_SPEED / 2;
    distanceCm3 = duration3 * SOUND_SPEED / 2;

    // Prints the distance in the Serial Monitor
    Serial.print("Distance (cm) of first ultra sonic sensor: ");
    Serial.println(distanceCm1);
    Serial.print("Distance (cm) of second ultra sonic sensor: ");
    Serial.println(distanceCm2);
    Serial.print("Distance (cm) of third ultra sonic sensor: ");
    Serial.println(distanceCm3);
    checker = 0;
  }
}
