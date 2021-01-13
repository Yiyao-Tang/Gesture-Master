// Declare Pins
int trigPin = 12;
int echoPin = 13;

int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

// Motor control parameters
const int freq = 10;
const int pwmChannel = 0; //there are 16 channels //2 groups with high-speed mode or low-speed mode
const int resolution = 8; //8 bits --> 256 discrete levels of speed

// Declare variables
long duration;  // time taken for impulse to travel back to the sensor
int distance;   // calculated distance
int spd;        // speed of motor

void setup() {
  // put your setup code here, to run once:
  
  // sets the pins as inputs or outputs:
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  // LED control (LEDC) peripheral is primarily designed to control the intensity of LEDs, although it can also be used to generate PWM signals for other purposes as well. 
  
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  spd = int(double(distance)/400*255); // calculate speed 
  
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  ledcWrite(pwmChannel, spd);   
  Serial.print("Duty cycle: "); //Duty cycle is the ratio of time a load or circuit is ON compared to the time the load or circuit is OFF.
  Serial.println(spd);
  delay(500);
}
