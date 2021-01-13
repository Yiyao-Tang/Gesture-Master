#include <Adafruit_AM2320.h>
#include <Wire.h>
int showtemp = 0;
int showhumidity = 0;
int showlightness = 0;

#define PRESISTOR 4
Adafruit_AM2320 am2320 = Adafruit_AM2320();

void setup() {
  pinMode(PRESISTOR, INPUT);
  Serial.begin(9600);
  Wire.begin();
  am2320.begin();
}

void loop() {
  if (Serial.available() > 0){
  int ser = Serial.read();
  if (ser == 't'){
    showtemp = 1;
  }
  if (ser == 's'){
    showhumidity = 1;
  }
  if (ser == 'm'){
    showlightness = 1;
  }
  }
  show();
  delay (2000);
  showtemp = 0;
  showhumidity = 0;
  showlightness = 0;
}

void toggle(){
}

void show() {          
  if (showlightness == 1){
    Serial.print(" photoresistance: ");
    Serial.print(analogRead(PRESISTOR));
    Serial.println(" "); }
  if (showhumidity == 1){
    Serial.print(" Humidity = ");
    Serial.print(am2320.readHumidity());
    Serial.println("%");}
  if (showtemp == 1){
    Serial.print(" Temperature = ");
    Serial.print(am2320.readTemperature());
    Serial.println("*C");
  }
}
