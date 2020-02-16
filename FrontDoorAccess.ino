#include <SoftwareSerial.h>

SoftwareSerial blueToothSerial(10, 11);


int val = 0;
int fval = 0;
int fbtn = 6;
int bbtn = 4;



boolean ffound = false;

void setup() {
  // put your setup code here, to run once:
 


    blueToothSerial.begin(9600);
  Serial.begin(9600);
  while (!Serial);
  pinMode(4, INPUT);
   pinMode(6, INPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);




}

void loop() {
  // put your main code here, to run repeatedly:
  blueToothSerial.listen();
  String rd = "";
  while (blueToothSerial.available()) {
    delay(3); 
  
    char mc = blueToothSerial.read();
    rd += mc;
     if (mc == '\r') {
    //  fp.listen();
     }
    
  }


  val = digitalRead(bbtn);
    fval = digitalRead(fbtn);


  // Serial.println(rd);
  if ((rd.indexOf("opendoor") != -1) || val > 0 || fval > 0) {
    //opened from website
    openDoor();
  } else {

  }




}

void openDoor() {
  Serial.println("opened");
  digitalWrite(5, HIGH);
  tone(9, 2000, 100);
  delay(200);
  tone(9, 2000, 100);
  digitalWrite(5, LOW);
  val = 0;
  fval = 0;
}

// returns -1 if failed, otherwise returns ID #


