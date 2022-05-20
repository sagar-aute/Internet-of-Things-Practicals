
const int green_led  = 0;
const int red_led    = 1;
const int yellow_led = 2;

void setup()
{
  // put your setup code here, to run once:
//Serial.begin(38400);  
}

unsigned  char key=0;  
void loop() 
{
Serial.begin(19200);
while(1)
{
  key = Serial.read();
  if((key == 'g')||(key == 'G')) break;
  if((key == 'r')||(key == 'R')) break;
  if((key == 'y')||(key == 'Y')) break;
  delay(100);
}
Serial.end();
delay(200);

  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);

if((key == 'g')||(key == 'G'))
{
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,LOW);
  digitalWrite(red_led,HIGH);
  delay(5000);
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,HIGH);
  key = 0;
  }

else if((key == 'y')||(key == 'Y'))
{
  digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,HIGH);
  delay(5000);
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,HIGH);
  key = 0;
  }

else if((key == 'r')||(key == 'R'))
{
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,LOW);
  delay(5000);
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,HIGH);
  key = 0;
  }

}

