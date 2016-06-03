// Robert Miller
// TEI3M 2016 Final Exam
// Subway Station LED Board


int dataPin = 50;
int latchPin = 52;
int clockPin = 51;

byte leds = 0;

void setup()  {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  leds = 0;
  updateShiftRegisters();
  delay(500);
  case1();
  case2();
}


void case2() {

 for (int i = 13; i > 0; i--) {
    bitSet(leds, i);
    updateShiftRegisters();
    delay(2000);
  }
  
}

void case1() {

 for (int i = 0; i < 13; i++) {
    bitSet(leds, i);
    updateShiftRegisters();
    delay(2000);
  }
  
}

void updateShiftRegisters() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
