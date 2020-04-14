String output1, output2, output3;
bool isLight1 = false;
bool isLight2 = false;
//bool isLight3 = false;


unsigned long start_time = 0;
unsigned long time_interval = 15000;
unsigned long check_interval = 1000;
unsigned long check_time = 0;


unsigned long on_test = 0;
unsigned long off_test = 0;
int RELAY1 = 13;
int RELAY2 = 11;
int RELAY3 = 10;
int RELAY4 = 9;
int RELAY5 = 8;
int RELAY6 = 7;
int RELAY7 = 6;
int RELAY8 = 5;
int RELAY9 = 4;
int RELAY10 = 3;
int RELAY11 = 2;
int RELAY12 = 14;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello world");
   pinMode(RELAY1, OUTPUT);
   pinMode(RELAY2, OUTPUT);
   pinMode(RELAY3, OUTPUT);
   pinMode(RELAY4, OUTPUT);
   pinMode(RELAY5, OUTPUT);
   pinMode(RELAY6, OUTPUT);
   pinMode(RELAY7, OUTPUT);
   pinMode(RELAY8, OUTPUT);
   pinMode(RELAY9, OUTPUT);
   pinMode(RELAY10, OUTPUT);
   pinMode(RELAY11, OUTPUT);
   pinMode(RELAY12, OUTPUT);
  //RELAY1 = HIGH;
   unsigned long x = 5000;
   /*
    * pinMode  pin ----->>>
    */
 
}
void resetall(){
  isLight1 = false;
  //isLight2 = false;
 // isLight3 = false;
}
void count_down(unsigned long time_interval,bool light,int pin){             // function count time back to zero
  start_time = millis();
  unsigned long countdown = time_interval/1000;
  Serial.println("ON");
  while(millis() - time_interval != start_time&& light == true){     // loop for ON - OFF pin Mode
      //digitalWrite(pin,light); // led pin out
      analogWrite(pin,1024);
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
 // digitalWrite(pin,light);  // led stopp blink
  analogWrite(pin,0);
  //digitalWrite(pin,HIGH); // relay high no active
    Serial.println("OFF");
}
void loop() {
  
  unsigned int x = 60;
  String test = "";
  if (Serial.available()>0) {
    test = Serial.readStringUntil('\n');
    if (test == "12345") {
      Serial.println("OUTPUT 1 ");  
      resetall();
      isLight1 = true;
      count_down(time_interval,isLight1,RELAY12);
    }
    if(test == "147"){
      Serial.println("OUTPUT 2 ");
      resetall();
      isLight1 = true;
       count_down(time_interval,isLight1,RELAY5);
    }
    if(test == "13579"){
      Serial.println("OUTPUT 3 ");
      resetall();
      isLight1 = true;
      count_down(time_interval,isLight1,RELAY2);
    }

  }


  
 
 
  
 
}
