const int switchPin = 6;
const int lightPin = 4;
const bool switchNormallyOn = false;
const long second = 1000;
const long lightDelay = 10; // in seconds

long timeCounter = 0; // in seconds
int switchState = 0;

void setup() {
    pinMode(switchPin, INPUT);
    pinMode(lightPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    switchState = digitalRead(switchPin);  
    Serial.println(timeCounter);

    if (switchState == switchNormallyOn){
        digitalWrite(lightPin, LOW);
        Serial.println("light off");
        delay(second);
        timeCounter = 0;
    } else if (timeCounter < lightDelay) {
        digitalWrite(lightPin, HIGH);
        Serial.println("light on");
        delay(second);
        timeCounter++;
    } else {
        digitalWrite(lightPin, LOW);
        Serial.println("light off");
        delay(second);
    }

}
