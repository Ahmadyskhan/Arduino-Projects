// North-South Traffic Lights
const int nsRed = 10;
const int nsYellow = 9;
const int nsGreen = 8;

// East-West Traffic Lights
const int ewRed = 13;
const int ewYellow = 12;
const int ewGreen = 11;

void setup() {
  pinMode(nsRed, OUTPUT);
  pinMode(nsYellow, OUTPUT);
  pinMode(nsGreen, OUTPUT);
  
  pinMode(ewRed, OUTPUT);
  pinMode(ewYellow, OUTPUT);
  pinMode(ewGreen, OUTPUT);
}

void loop() {
  // Phase 1: NS is GREEN, EW is RED
  digitalWrite(nsRed, LOW);
  digitalWrite(nsYellow, LOW);
  digitalWrite(nsGreen, HIGH);
  
  digitalWrite(ewRed, HIGH);
  digitalWrite(ewYellow, LOW);
  digitalWrite(ewGreen, LOW);
  
  delay(5000); 

  // Phase 2: NS is YELLOW, EW RED
  digitalWrite(nsGreen, LOW);
  digitalWrite(nsYellow, HIGH);
  
  delay(2000); 

  // Phase 3: All red
  digitalWrite(nsYellow, LOW);
  digitalWrite(nsRed, HIGH);
  
  delay(1000); 

  // Phase 4: NS remains RED, EW is GREEN
  digitalWrite(ewRed, LOW);
  digitalWrite(ewGreen, HIGH);
  
  delay(5000); 

  // Phase 5: NS remains RED, EW is YELLOW
  digitalWrite(ewGreen, LOW);
  digitalWrite(ewYellow, HIGH);
  
  delay(2000); 
  
  // Phase 6: All red
  digitalWrite(ewYellow, LOW);
  digitalWrite(ewRed, HIGH);
  
  
  delay(1000); 
}