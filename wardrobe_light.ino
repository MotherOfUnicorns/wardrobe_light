const int switchPin = 6;
const int lightPin = 4;


int switchState = 0;

void setup() {
    pinMode(switchPin, INPUT);
    pinMode(lightPin, OUTPUT);
}

void loop() {
    switchState = digitalRead(switchPin);  
    digitalWrite(lightPin, !switchState);
}
