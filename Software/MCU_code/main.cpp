#include <Servo.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int grip1_pos0 = 24;
int grip2_pos0 = 29;
int grip3_pos0 = 31;
int grip4_pos0 = 20-10-5;

Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;
int pos = 0;

const int buttonPin = 10;
int buttonState = HIGH;
int lastButtonState = HIGH;
int patternNumber = 1;

void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
  myservo7.attach(8);
  myservo8.attach(9);
  
  myservo1.write(25+10);
  myservo2.write(25);
  myservo3.write(25+10);
  myservo4.write(25);
  myservo5.write(grip1_pos0);
  myservo6.write(grip2_pos0);
  myservo7.write(grip3_pos0);
  myservo8.write(grip4_pos0);

  lcd.print("Initializing...");
  delay(800);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Varun");
  lcd.setCursor(0, 1);
  lcd.print("2023UEC2506");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Jayavardhan");
  lcd.setCursor(0, 1);
  lcd.print("2023UEC2531");
  delay(1100);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Utpal");
  lcd.setCursor(0, 1);
  lcd.print("2023UEC2534");
  delay(1000);
  lcd.clear();

  lcd.print("Rubik's Cube");
  lcd.setCursor(0, 1);
  lcd.print("Controller Robot");
  delay(1000);
  lcd.clear();

  lcd.print("Waiting for input...");
  pinMode(buttonPin, INPUT_PULLUP);  
}


void arm1_front(){
  myservo1.write(25+10);
  delay(500);
}
void arm1_back() {
  myservo1.write(90);
  delay(500);
}

void arm2_front(){
  myservo2.write(25);
  delay(500);
}
void arm2_back() {
  myservo2.write(70);
  delay(500);
}

void arm3_front(){
  myservo3.write(25+10);
  delay(500);
}
void arm3_back() {
  myservo3.write(90);
  delay(500);
}

void arm4_front(){
  myservo4.write(25);
  delay(500);
}
void arm4_back() {
  myservo4.write(90);
  delay(500);
}

void expand(){
  myservo1.write(90);
  delay(100);
  myservo2.write(70);
  delay(100);
  myservo3.write(90);
  delay(100);
  myservo4.write(90);
  delay(100);
}

void hold1() {
  arm1_front();
  arm3_front();
  delay(1000);
  arm2_back();
  arm4_back();
  delay(500);
}

void hold2() {
  arm2_back();
  arm4_back();
  delay(1000);
  arm1_back();
  arm3_back();
  delay(500);
  }

void hold_all() {
  arm1_front();
  arm3_front();
  delay(3000);
  arm2_front();
  arm4_front();
  }


void check_arm1(){
for(int i=0;i<=5;i++){
  arm1_back();
  delay(1000);
  arm1_front();
  delay(1000); 
}
}

void check_arm2(){
  for(int i=0;i<=5;i++){
    arm2_back();
  delay(1000);
  arm2_front();
  delay(1000);
  }
}

void check_arm3(){
  for(int i=0;i<=5;i++){
    arm3_back();
  delay(1000);
  arm3_front();
  delay(1000);
  }
}

void check_arm4(){
  for(int i=0;i<=5;i++){
    arm4_back();
  delay(1000);
  arm4_front();
  delay(1000);
  }
}

void check_all_arm(){
arm1_back();
delay(1000);
arm1_front();
delay(1000);
arm2_back();
delay(1000);
arm2_front();
delay(1000);
arm3_back();
delay(1000);
arm3_front();
delay(1000);
arm4_back();
delay(1000);
arm4_front();
delay(1000);
}

//grip 1 horizontal mean position
void grip_1_clock(){
  arm1_back();
  myservo5.write(122);
  delay(500);
}

//grip 1 vertical mean position
void grip_1_anticlock(){
  arm1_back();
  myservo5.write(24);
  delay(500);
}

void grip_1_adjust(){
  grip_1_anticlock();
  arm1_front();
}

void front_clock(){
  grip_1_adjust();
  myservo5.write(133-10);//grip 1 clock rotation
  delay(1000);
  grip_1_adjust();
}

void front_anticlock(){
  grip_1_clock();
  arm1_front();
  myservo5.write(18);//grip 1 anticlock rotation
  delay(1000);
  grip_1_adjust();
}

void front_clock_twice(){
  front_clock();
  delay(500);
  front_clock();
  delay(500);
}

void front_anticlock_twice(){
  front_anticlock();
  delay(500);
  front_anticlock();
  delay(500);
}



//grip 2 horizontal mean position
void grip_2_clock(){
  arm2_back();
  myservo6.write(128);
  delay(500);
}

//grip 2 vertical mean position
void grip_2_anticlock(){
  arm2_back();
  myservo6.write(29);
  delay(500);
}

void grip_2_adjust(){
  grip_2_anticlock();
  arm2_front();
}

void left_down(){
  grip_2_adjust();
  myservo6.write(139-15);//grip 2 clock rotation
  delay(1000);
  grip_2_adjust();
}

void left_up(){
  grip_2_clock();
  arm2_front();
  myservo6.write(20);//grip 2 anticlock rotation
  delay(1000);
  grip_2_adjust();
}

void left_up_twice(){
  left_up();
  delay(500);
  left_up();
  delay(500);
}

void left_down_twice(){
  left_down();
  delay(500);
  left_down();
  delay(500);
}


//grip 3 horizontal mean position
void grip_3_clock(){
  arm3_back();
  myservo7.write(126);
  delay(500);
}

//grip 3 vertical mean position
void grip_3_anticlock(){
  arm3_back();
  myservo7.write(31);
  delay(500);
}

void grip_3_adjust(){
  grip_3_anticlock();
  arm3_front();
}

void back_clock(){
  grip_3_adjust();
  myservo7.write(137-15);//grip 3 clock rotation
  delay(1000);
  grip_3_adjust();
}

void back_anticlock(){
  grip_3_clock();
  arm3_front();
  myservo7.write(24);//grip 3 anticlock rotation
  delay(1000);
  grip_3_adjust();
}

void back_clock_twice(){
  back_clock();
  delay(500);
  back_clock();
  delay(500);
}

void back_anticlock_twice(){
  back_anticlock();
  delay(500);
  back_anticlock();
  delay(500);
}


//grip 4 horizontal mean position
void grip_4_clock(){
  arm4_back();
  myservo8.write(118);
  delay(500);
}

//grip 4 vertical mean position
void grip_4_anticlock(){
  arm4_back();
  myservo8.write(20-10-5);
  delay(500);
}

void grip_4_adjust(){
  grip_4_anticlock();
  arm4_front();
}

void right_up(){
  grip_4_adjust();
  myservo8.write(132-22);//grip 4 clock rotation
  delay(1000);
  grip_4_adjust();
}

void right_down(){
  grip_4_clock();
  arm4_front();
  myservo8.write(12);//grip 4 anticlock rotation
  delay(1000);
  grip_4_adjust();
}

void right_up_twice(){
  right_up();
  delay(500);
  right_up();
  delay(500);
}

void right_down_twice(){
  right_down();
  delay(500);
  right_down();
  delay(500);
}


void rotate_cube_clock(){
  grip_3_clock();
  arm3_front();
  
  arm2_back();
  arm4_back();
   
  myservo7.write(32);
  myservo5.write(120);
  delay(500); 
  
  myservo2.write(30);
  delay(500);
  myservo4.write(30);
  delay(500);
  
  grip_1_adjust();
  grip_3_adjust();
  grip_2_adjust();
  grip_4_adjust();
 }

void rotate_cube_anticlock(){
  grip_1_clock();
  arm1_front();
  
  arm2_back();
  arm4_back(); 

  myservo5.write(26);
  myservo7.write(134);
  delay(500);

  myservo2.write(30);
  delay(500);
  myservo4.write(30);
  delay(500);
  
  grip_1_adjust();
  grip_3_adjust();
  grip_2_adjust();
  grip_4_adjust();    
}



void up_clock(){
  rotate_cube_clock();
  delay(500);
  right_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void up_clock_twice(){
  rotate_cube_clock();
  delay(500);
  right_up();
  delay(1000);
  right_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}


void up_anticlock(){
  rotate_cube_clock();
  delay(500);
  right_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void up_anticlock_twice(){
  rotate_cube_clock();
  delay(500);
  right_down();
  delay(1000);
  right_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}



void down_clock(){
  rotate_cube_clock();
  delay(500);
  left_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void down_clock_twice(){
  rotate_cube_clock();
  delay(500);
  left_down();
  delay(1000);
  left_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}


void down_anticlock(){
  rotate_cube_clock();
  delay(500);
  left_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void down_anticlock_twice(){
  rotate_cube_clock();
  delay(500);
  left_up();
  delay(1000);
  left_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}


void adjust_all(){
  grip_1_adjust();
  grip_2_adjust();
  grip_3_adjust();
  grip_4_adjust();
}

void complete_check(){
  front_clock();
  delay(500);
  front_anticlock();
  delay(500);

  left_up();
  delay(500);
  left_down();
  delay(500);

  back_clock();
  delay(500);
  back_anticlock();
  delay(500);

  right_up();
  delay(500);
  right_down();
  delay(500);

  up_clock_twice();
  delay(500);
  up_anticlock_twice();
  delay(500);

  down_clock_twice();
  delay(500);
  down_anticlock_twice();
  delay(500);
}




 void execute(String form) {
  form.trim();              
  form.replace("\r", "");   
  form.replace("\n", "");   

  Serial.print("Processing command: ");
  Serial.println(form);

  if (form == "front_clock") {
    front_clock();
  } else if (form == "front_anticlock") {
    front_anticlock();
  } else if (form == "front_clock_twice") {
    front_clock_twice();
  } else if (form == "front_anticlock_twice") {
    front_anticlock_twice();
  } else if (form == "left_down") {
    left_down();
  } else if (form == "left_up") {
    left_up();
  } else if (form == "left_down_twice") {
    left_down_twice();
  } else if (form == "left_up_twice") {
    left_up_twice();
  } else if (form == "back_clock") {
    back_clock();
  } else if (form == "back_anticlock") {
    back_anticlock();
  } else if (form == "back_clock_twice") {
    back_clock_twice();
  } else if (form == "back_anticlock_twice") {
    back_anticlock_twice();
  } else if (form == "right_up") {
    right_up();
  } else if (form == "right_down") {
    right_down();
  } else if (form == "right_up_twice") {
    right_up_twice();
  } else if (form == "right_down_twice") {
    right_down_twice();
  } else if (form == "up_clock") {
    up_clock();
  } else if (form == "up_clock_twice") {
    up_clock_twice();
  } else if (form == "up_anticlock") {
    up_anticlock();
  } else if (form == "up_anticlock_twice") {
    up_anticlock_twice();
  } else if (form == "down_clock") {
    down_clock();
  } else if (form == "down_clock_twice") {
    down_clock_twice();
  } else if (form == "down_anticlock") {
    down_anticlock();
  } else if (form == "down_anticlock_twice") {
    down_anticlock_twice();
  } else if (form == "complete_check") {
    complete_check();}
    else if(form=="adjust_all"){
      adjust_all();
    
  } 
  else if(form=="expand"){
    expand();
  }  
  else if(form=="hold"){
  hold1();
  }
  else {
    Serial.println("Unidentified String");
  }
}

void helper(String &formula) { 
  Serial.print("Received formula: ");
  Serial.println(formula);
  int move = 0;
  String tmp = "";
  char delimiter = '+';

  for (size_t i = 0; i < formula.length(); i++) {
    char c = formula[i];
    if (c == delimiter) {
      move++;
      Serial.println("Processing move:");
      Serial.println(tmp);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(tmp);
      lcd.setCursor(0, 1);
      lcd.print("Move no.");
      lcd.print(move);
      execute(tmp);
      tmp = "";
    } else {
      tmp += c;
    }
  }

  
  if (tmp.length() > 0) {
    Serial.println("Processing final move:");
    Serial.println(tmp);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(tmp);
    lcd.setCursor(0, 1);
    move++;      
    lcd.print("Move no.");
    lcd.print(move);
    execute(tmp);
  }
}


void loop() {
  buttonState = digitalRead(buttonPin);  

 
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50);  
    if (digitalRead(buttonPin) == LOW) {  
      patternNumber++;
      if (patternNumber > 5) {
        patternNumber = 1;  
      }

      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pattern ");
      lcd.print(patternNumber);

     
      Serial.print("Pattern ");
      Serial.println(patternNumber);
    }
  }

  lastButtonState = buttonState;  
  if (Serial.available() > 0) {
    String formula = Serial.readString();
    Serial.println("Serial data received: " + formula);
    helper(formula);
  }
}

