void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(0, HIGH);
  delay(100);
digitalWrite(1, HIGH);
  delay(100);
digitalWrite(2, HIGH);
  delay(100);
digitalWrite(4, HIGH);
  delay(200);
 digitalWrite(0, LOW);
  delay(100);
digitalWrite(1, LOW);
  delay(100);
digitalWrite(2, LOW);
  delay(100);
digitalWrite(4, LOW);
  delay(200);

  
}

