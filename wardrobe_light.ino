const int switchPin[2] = {6, A0};
const int lightPin[2] = {4, 8};
const bool switchNormallyOn[2] = {false, false};
const long second = 1000;
const long lightDelay = 10; // in seconds

long timeCounter[2] = {0, 0}; // in seconds
int switchState[2] = {0, 0};

void setup() {
    for (int i = 0; i < 2; i++) {
        pinMode(switchPin[i], INPUT);
        pinMode(lightPin[i], OUTPUT);
    }
    Serial.begin(9600);
}


void updateLightState(int n) {
    if (switchState[n] == switchNormallyOn[n]) {
        digitalWrite(lightPin[n], LOW);
        Serial.print("Light #");
        Serial.print(n);
        Serial.println(": off");
        timeCounter[n] = 0;
    } else if (timeCounter[n] < lightDelay) {
        digitalWrite(lightPin[n], HIGH);
        Serial.print("Light #");
        Serial.print(n);
        Serial.println(": on");
        timeCounter[n]++;
    } else {
        digitalWrite(lightPin[n], LOW);
        Serial.print("Light #");
        Serial.print(n);
        Serial.println(": off");
    }
}


void loop() {
    for (int i = 0; i < 2; i++) {
        switchState[i] = digitalRead(switchPin[i]);
        Serial.print("Light #");
        Serial.print(i);
        Serial.print(" time counter: ");
        Serial.println(timeCounter[i]);
    }

    for (int i = 0; i < 2; i++) {
        updateLightState(i);
    }
    delay(second);
}
