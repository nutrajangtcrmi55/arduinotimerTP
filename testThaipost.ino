//Data barcode for use scan

String surin = "32000";
String surat = "57000";
String sakon = "78000";
String mahanakorn = "87232";
String utaitanee = "12400";
String sungaikolog = "32129";
String sena = "12921";
String narathiwat = "91320";
String chiangmai = "12091";
String udtaradit = "12132";
String payap = "13912";
String taksin = "13291";



// Set output with state of isLight1 
// init state with false
// if data barcode match with String compare to
// mcu will set isLight1 to true and send as argument to countdown function

bool isLight1 = false;




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
int RELAY_PIN[] = {2,3,4,5,6,7,8,9,10,11,12,13};



void setup() {

  //begin transmition with 9600
  Serial.begin(9600);
  Serial.println("welcome to serting box");

  //set pin either 12 pin as OUTPUT pin
 for(int i = 0 ;i<= 12; i++){
  pinMode(RELAY_PIN[i],OUTPUT);
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

void testPin(){
  for(int i = 0; i <= 12; i++){
    digitalWrite(RELAY_PIN[i],HIGH);
    delay(100);
    digitalWrite(RELAY_PIN[i],LOW);
  }

  for(int i = 12; i >= 0; i--){
    digitalWrite(RELAY_PIN[i],HIGH);
    delay(100);
    digitalWrite(RELAY_PIN[i],LOW);
  }
}




void resetall(){

  // use for when data barcode was check before countdown function have ended process or until end process
  // it will set output either 12 pin to false
  for(int i = 0; i<= 12; i++){
    digitalWrite(RELAY_PIN[i],false);
  }
}
void count_down(bool light,int pin){             // function count time back to zero
  start_time = millis();
  unsigned long countdown = time_interval/1000;
  Serial.println("ON");
  while(millis() - time_interval != start_time&& light == true){     // loop for ON - OFF pin Mode
      //digitalWrite(pin,light); // led pin out
      analogWrite(pin,light);
    //  digitalWrite(pin,LOW);  relay low active
    if(millis() >= check_time){
      Serial.println(countdown);
      countdown--;
      check_time = millis()+check_interval;
    }
    if(Serial.available()||(millis() - time_interval) == start_time){                                           // if Data was sent from serial port, must out of function 
      light = false;
    }
  }
 digitalWrite(pin,light);  // led stopp blink
  //analogWrite(pin,0);
  //digitalWrite(pin,HIGH); // relay high no active
    Serial.println("OFF");
}
void loop() {
  
  unsigned int x = 60;
  String test = "";
  if (Serial.available()>0) {
    test = Serial.readStringUntil('\n');
    if (test == surin) {
      Serial.println("OUTPUT 1 ");  
      resetall();
      isLight1 = true;
      count_down(isLight1,RELAY_PIN[0]);
    }
    if(test == "147"){
      Serial.println("OUTPUT 2 ");
      resetall();
      isLight1 = true;
       count_down(isLight1,RELAY_PIN[1]);
    }
    if(test == "13579"){
      Serial.println("OUTPUT 3 ");
      resetall();
      isLight1 = true;
      count_down(isLight1,RELAY_PIN[2]);
    }

  }


  
 
 
  
 
}
