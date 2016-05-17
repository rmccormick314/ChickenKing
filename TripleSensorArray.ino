#include <math.h>

int sensorPin = A1;
int sensorPinTwo = A2;
int sensorPinThree = A3;
int lightPin = 12;
int tempLightPin = 11;
int tempLightPinTwo = 13;
int data;
int dataTwo;
int bleet = 10;
int tempTwo;
int voltage;

double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 273.15;
  Temp = (Temp * 9.0)/ 5.0 + 32.0;
  return Temp;
}

void setup(){
  Serial.begin(9600);
  pinMode(lightPin, OUTPUT);
  pinMode(tempLightPin, OUTPUT);
  pinMode(tempLightPinTwo, OUTPUT);
  pinMode(bleet, OUTPUT);
  digitalWrite(bleet, HIGH);
}

void loop(){
  int readVal=analogRead(sensorPin);
  double temp = Thermistor(readVal);
  Serial.print("Temperature: ");Serial.print(temp);Serial.println("F");
  if (temp > 75){
    digitalWrite(tempLightPin, HIGH);
  }
  else{
    digitalWrite(tempLightPin, LOW);
  }

  data = analogRead(sensorPinTwo);
  Serial.print("Light: ");Serial.println(data);
  if (data < 200){
    digitalWrite(lightPin, HIGH);
  }
  else{
    digitalWrite(lightPin, LOW);
  }

  dataTwo = analogRead(sensorPinThree);
  float voltage = (dataTwo/1024.0) * 5.0;
  float tempTwo = (voltage - 0.5) * 100;
  Serial.print("Temperature 2: ");Serial.print(tempTwo);Serial.println("C");
  if (tempTwo > 21){
    digitalWrite(tempLightPinTwo, HIGH);
  }
  else{
    digitalWrite(tempLightPinTwo, LOW);
  }
  
  delay (500);
}

