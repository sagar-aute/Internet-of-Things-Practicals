
const int green_led  = 0;
const int yellow_led = 1;
const int red_led    = 2;

unsigned int counter;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,HIGH);
}

void loop() {
counter = counter+1;
delay(50);

if(counter <= 100)
{
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,LOW);
  digitalWrite(red_led,HIGH);
  }

else if((counter > 100)&& (counter <= 200))
{
  digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,HIGH);
  }

else if(counter > 200)
{
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,LOW);
  }

if (counter > 210) counter =0;  
}
