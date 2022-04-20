const int n = 8;
const int btnPins[n] = {30,32,34,36,38,40,42,44};
const int ledPins[n] = {31,33,35,37,39,41,43,45};
int prev;
int on;
int curr;

void setup() {
  randomSeed(analogRead(0));
  on = random(n);
  prev = (on + 1) % 8;
  curr = 0;
  
  for (int i = 0; i < n; i++) {
      pinMode(btnPins[i], INPUT);
      pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
  
  digitalWrite(ledPins[on], HIGH);
}

void loop() {
  if (curr != prev && digitalRead(btnPins[curr]) == HIGH) {
    writeTo(curr);
    if (curr == on) {
      digitalWrite(ledPins[on], LOW);
      prev = on;
      on = next(curr);
      digitalWrite(ledPins[on], HIGH);
    } 
  }
  curr = (curr + 1) % 8;
}

void writeTo(int pressed) {
  Serial.println(millis());
  Serial.println(on);
  Serial.println(pressed);
}

int next(int curr) {
  on = random(n);
  while(curr == on) {
    on = random(n);
  }
  return on;
}
