#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

#include <ESP8266WiFi.h>
#include <WiFiServer.h>

#define motorRightDir  0//D2
#define motorRightSpeed 5//D1

const char* ssid = "ABB_Gym_IOT"; // Replace with your Wi-Fi network name (SSID)
const char* password = "Welcome2abb"; // Replace with your Wi-Fi password
WiFiServer server(80);

const byte servopin = 14;
const byte servo2pin = 12;
Servo servo;
Servo servo2;

const byte encoder = 0;

int pos; 

String receivedChar;
boolean newData = false;

void recvOneChar();
void showNewData();

int motorspeed, servorotation;

void setup()
{
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi");

  // Print ESP8266 IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
  
  Wire.begin();
  pinMode(motorRightDir, OUTPUT);
  pinMode(motorRightSpeed, OUTPUT);
  
  servo.attach(servopin, 544, 2400);
  servo.write(90);
  servo2.attach(servo2pin, 544, 2400);
  servo2.write(90);
  
  Serial.begin(115200);
  Serial.println("<Arduino is ready>");
}

void drive (int mdir,int dirspeed, int mspeed) {
  digitalWrite(mdir, mspeed>0);
  analogWrite(dirspeed, abs(mspeed));
}

void steer (int degree){
  servo.write(degree);
  servo2.write(180-degree);
}

void loop()
{
  WiFiClient client = server.available();
  while (client) { 
    char datarcv;
    String content = "";
    if (Serial.available()) // now we have at least one character in the Serial input buffer
    {
      delay(20); // just wait a little bit for more characters to arrive
      while(Serial.available()) // look for all characters in the input buffer
      {
        datarcv = Serial.read();
        content.concat(datarcv);
      }
      //Serial.println(content);
      int len = content.length() + 1;
      char maixdata[len];
      content.toCharArray(maixdata,len);
      char * strtokIndx; // this is used by strtok() as an index
  
  strtokIndx = strtok(maixdata,",");      // get the first part - the string
  motorspeed = atoi(strtokIndx);
  
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  servorotation = atoi(strtokIndx);     // convert this part to an integer

  Serial.print("Motor speed: ");
  Serial.println(motorspeed);
  Serial.print("Servo rotation: ");
  Serial.println(servorotation);
  drive(motorRightDir, motorRightSpeed, motorspeed);
  steer(servorotation);

  float data[2] = {motorspeed, servorotation};

  client.write(reinterpret_cast<uint8_t*>(&data), sizeof(data)); // send values as binary data
  newData = false;
    }
  
    if (content != "") {
         content = "";
    }
  }
}

void recvOneChar()
{
  char datarcv;
  String content = "";
  if (Serial.available()) // now we have at least one character in the Serial input buffer
  {
    delay(20); // just wait a little bit for more characters to arrive
    while(Serial.available()) // look for all characters in the input buffer
    {
      datarcv = Serial.read();
      content.concat(datarcv);
    }
    //Serial.println(content);
    showNewData(content);
  }

  if (content != "") {
       content = "";
  }
}

void showNewData(String recvChar)
{
    int len = recvChar.length() + 1;
    char maixdata[len];
    recvChar.toCharArray(maixdata,len);
    parseData(maixdata);
    newData = false;
}

void parseData(char* receivedChars) {
  
  char * strtokIndx; // this is used by strtok() as an index
  
  strtokIndx = strtok(receivedChars,",");      // get the first part - the string
  motorspeed = atoi(strtokIndx);
  
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  servorotation = atoi(strtokIndx);     // convert this part to an integer

  Serial.print("Motor speed: ");
  Serial.println(motorspeed);
  Serial.print("Servo rotation: ");
  Serial.println(servorotation);
  drive(motorRightDir, motorRightSpeed, motorspeed);
  steer(servorotation);
  Serial.println(analogRead(encoder));

  
  /*client.print(motorspeed);
  client.print(' ');
  client.println(servorotation);*/
  
}
