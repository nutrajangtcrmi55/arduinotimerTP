//Data barcode for use scan

String surin = "32140";
String surat = "47000";
String sakon = "10530";
String mahanakorn = "61000";
String utaitanee = "17200";
String sungaikolog = "32120";
String kawaosinarin = "12921";
String chiangmai = "50000";
String udtaradit = "53140";
String payap = "32130";
String taksin = "50140";
String srakaew = "72012";


// Set output with state of NotLight
// init state with false
// if data barcode match with String compare to
// mcu will set NotLight to true and send as argument to countdown function

bool NotLight = true;




// time for use millis
// start_time use for starting to count when data barcode match with String comapre
// time_interval  use for couting down time to set pin relay HIGH until LOW with time_interval
//      (15000/1000 = 15 sec.)

// check_time use for monitor time that are counting down from HIGH to LOW
// check_inteval use for show data when time check_interval has pass  each time

unsigned long start_time = 0;
unsigned long time_interval = 15000;
unsigned long check_interval = 1000;
unsigned long check_time = 0;



//init pin output for led either 12 pin
//from  D2 to D13
int RELAY_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};



void setup() {

  //begin transmition with 9600
  Serial.begin(9600);
  Serial.println("welcome to serting box");

  //set pin either 12 pin as OUTPUT pin
  for (int i = 0 ; i <= 12; i++) {
    pinMode(RELAY_PIN[i], OUTPUT);
  }
  //   pinMode(RELAY1, OUTPUT);
  //   pinMode(RELAY2, OUTPUT);
  //   pinMode(RELAY3, OUTPUT);
  //   pinMode(RELAY4, OUTPUT);
  //   pinMode(RELAY5, OUTPUT);
  //   pinMode(RELAY6, OUTPUT);
  //   pinMode(RELAY7, OUTPUT);
  //   pinMode(RELAY8, OUTPUT);
  //   pinMode(RELAY9, OUTPUT);
  //   pinMode(RELAY10, OUTPUT);
  //   pinMode(RELAY11, OUTPUT);
  //   pinMode(RELAY12, OUTPUT);

  // check each pin whether some pin cannot work
  testPin();

}

void testPin() {
  for (int i = 0; i <= 12; i++) {
    digitalWrite(RELAY_PIN[i], LOW);
    delay(100);
    digitalWrite(RELAY_PIN[i], HIGH);
  }

  for (int i = 12; i >= 0; i--) {
    digitalWrite(RELAY_PIN[i], LOW);
    delay(100);
    digitalWrite(RELAY_PIN[i], HIGH);
  }
}




void resetall() {

  // use for when data barcode was check before countdown function have ended process or until end process
  // it will set output either 12 pin to false
  for (int i = 0; i <= 12; i++) {
    digitalWrite(RELAY_PIN[i], true);
  }
}
void count_down(bool light, int pin) {           // function count time back to zero
  start_time = millis();
  unsigned long countdown = time_interval / 1000;
  Serial.println("ON");
  while (millis() - time_interval != start_time && light == false) {  // loop for ON - OFF pin Mode
    //digitalWrite(pin,light); // led pin out
    digitalWrite(pin, light);
    //  digitalWrite(pin,LOW);  relay low active
    if (millis() >= check_time) {
      Serial.print(countdown);Serial.print(" ");Serial.println(light);
      countdown--;
      check_time = millis() + check_interval;
       if(countdown < 1 ){
      light = true;
      break;
    }
    }
    if (Serial.available() || (millis() - time_interval) == start_time||countdown < 1) {                                       // if Data was sent from serial port, must out of function
      light = true;
    }
   
  }
  digitalWrite(pin, light); // led stopp blink
  //analogWrite(pin,0);
  //digitalWrite(pin,HIGH); // relay high no active
  Serial.print("status  :");Serial.print(light);
  Serial.println("   OFF");
}
void loop() {

  unsigned int x = 60;
  String test = "";
  if (Serial.available() > 0) {

    
    test = Serial.readStringUntil('\n');
    if (test == surin ) {
      Serial.println("OUTPUT 1 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[0]);
    }
    if (test == surat) {
      Serial.println("OUTPUT 2 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[1]);
    }
    if (test == sakon) {
      Serial.println("OUTPUT 3 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[2]);
    }
    if(test == mahanakorn)
    {
      Serial.println("OUTPUT 4");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[3]);
    }
    if (test == utaitanee) {
      Serial.println("OUTPUT 5 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[4]);
    }
    if (test == sungaikolog ) {
      Serial.println("OUTPUT 6 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[5]);
    }
    if(test == kawaosinarin)
    {
      Serial.println("OUTPUT 7");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[6]);
    }
    if (test == taksin ) {
      Serial.println("OUTPUT 8 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[7]);
    }
    if (test == chiangmai ) {
      Serial.println("OUTPUT 9 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[8]);
    }
    if(test == udtaradit )
    {
      Serial.println("OUTPUT 10");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[9]);
    }
    if (test == payap ) {
      Serial.println("OUTPUT 11 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[10]);
    }
    if (test == srakaew ) {
      Serial.println("OUTPUT 12 ");
      resetall();
      NotLight = false;
      count_down(NotLight, RELAY_PIN[11]);
    }
   





  }







}
