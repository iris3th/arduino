unsigned long eighthours = 28800000UL; // 8 hours
unsigned long fourhours = 14400000UL; // 4 hours
unsigned long twohours = 7200000; // 2 hours
unsigned long ninetymin = 5400000UL; //1.5 hours (90 minutes)
unsigned long hour = 3600000UL; //1 hour
unsigned long halfhour = 1800000UL; // 30 min
unsigned long fifteenmin = 900000UL; // 15 min
unsigned long fivemin = 300000UL; // 5 min
unsigned long minute = 60000UL; // 1 min


const int buttonPin = 12;
const int led1 = 9;
const int led2 = 8;
const int led3 = 5;
const int relay1 = 10;

unsigned long startMillis;
unsigned long previousMillis = 0;

int counter = 0;
void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(relay1, OUTPUT);
}


void loop()
{
  unsigned long currentMillis = millis();
  int buttonState;
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(150);
  }

  if (counter == 0)
  {
    currentMillis = millis();
    previousMillis = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(relay1, LOW);
  }
  
   else if (counter == 1)
  {
    currentMillis = millis();
    previousMillis = 0;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
//    delay (5000);
    digitalWrite(relay1, HIGH);
    if (currentMillis - previousMillis >= twohours) {
    counter = 0;
    previousMillis = currentMillis;
    }
  }
   else if (counter == 2)
  {
    currentMillis = millis();
    previousMillis = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(relay1, HIGH);
    if (currentMillis - previousMillis >= ninetymin) {
    counter = 0;
    previousMillis = currentMillis;
    }  
  }
    else if (counter == 3)
  {
    currentMillis = millis();
    previousMillis = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(relay1, HIGH);
    if (currentMillis - previousMillis >= hour) {
    counter = 0;
    previousMillis = currentMillis;
    }  
  }
    else if (counter == 4)
  {
    currentMillis = millis();
    previousMillis = 0;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(relay1, HIGH);
    if (currentMillis - previousMillis >= halfhour) {
    counter = 0;
    previousMillis = currentMillis;
    }  
  }
     else if (counter == 5)
  {
    currentMillis = millis();
    previousMillis = 0;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(relay1, HIGH);
    if (currentMillis - previousMillis >= fifteenmin) {
    counter = 0;
    previousMillis = currentMillis;
    }  
  }
     else if (counter == 6)
  {
    currentMillis = millis();
    previousMillis = 0;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(relay1, HIGH);
    if (currentMillis - previousMillis >= minute) {
    counter = 0;
    previousMillis = currentMillis;
    }  
  }
  else
  {
    counter = 0;
  }
}
