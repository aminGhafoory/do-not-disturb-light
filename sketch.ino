const int buttonPin = 8;  
const int redPin = 7;
const int greenPin = 6;
const int bluePin = 5;

int ledState = 0;  // 0: Off, 1: Red, 2: Yellow, 3: Green
bool buttonPressed = false;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
    if (digitalRead(buttonPin) == LOW) {  
        if (!buttonPressed) {  
            buttonPressed = true;
            ledState = (ledState + 1) % 4;
            updateLED();
            delay(300);
        }
    } else {
        buttonPressed = false;
    }
}

void updateLED() {
    switch (ledState) {
        case 0:  setColor(0, 0, 0); break;    // Off
        case 1:  setColor(255, 0, 0); break;  // Red
        case 2:  setColor(255, 255, 0); break;// Yellow
        case 3:  setColor(0, 255, 0); break;  // Green
    }
}

void setColor(int r, int g, int b) {
    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
}
