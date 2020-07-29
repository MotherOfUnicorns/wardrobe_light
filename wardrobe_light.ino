const int switchPin = 6;
const int lightPin = 4;
const bool switchAlwaysOn = false;
const long lightDelay = 1000L;// * 60 * 5;


int switchState = 0;

void setup() {
    pinMode(switchPin, INPUT);
    pinMode(lightPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    switchState = digitalRead(switchPin);  
    Serial.println(switchState);

    if (switchState != switchAlwaysOn){
        digitalWrite(lightPin, HIGH);
        Serial.println("light on");
        delay(lightDelay);
    } else {
        digitalWrite(lightPin, LOW);
        Serial.println("light off");
    }

}
