const int ledPin = 2;

void setup() {
  // setup pin 2 as a digital output pin
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void toggle(){
   if( digitalRead(ledPin) == 0 )
   {
     digitalWrite(ledPin, 1);
   }
   else
   {
     digitalWrite(ledPin, 0);
   }
}

void loop() {
  if (Serial.available() > 0){
  if (Serial.read() == 'l'){
    toggle();
  }}
  if (Serial.read() == 'c'){
    digitalWrite(ledPin, 0);
  }
}
