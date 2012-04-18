#include <SoftwareSerial.h>
#define rxpin 2
#define txpin 3
SoftwareSerial myserial(rxpin, txpin);
String inputstring = "";
String sensorstring = "";
boolean input_stringcomplete = false;
boolean sensor_stringcomplete = false;

void setup(){
  Serial.begin(38400);
  myserial.begin(38400);
  inputstring.reserve(5);
  sensorstring.reserve(30);
}

void serialEvent() {
  char inchar = (char)Serial.read();
  inputstring += inchar;
  if(inchar == '\r') {
    input_stringcomplete = true;
  }
}
void loop(){
  if (input_stringcomplete){
    myserial.print(inputstring);
    inputstring = "";
    input_stringcomplete = false;
  }
  while (myserial.available()) {
    char inchar = (char)myserial.read();
    sensorstring += inchar;
    if (inchar == '\r') {
      sensor_stringcomplete = true;
    }
  }
  if (sensor_stringcomplete){
    Serial.print(sensorstring);
    sensorstring = "";
    sensor_stringcomplete = false;
  }
}

