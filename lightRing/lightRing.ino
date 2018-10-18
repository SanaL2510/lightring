/*
 * The following code block is for a ring that detects room 
 * lighting and sends an LED notification if 
 * it is too dark. It is powered by an ATTiny85 and a button cell, 
 * a photosensor, and LEDs. 
 * 
 * NOTE: the serial monitor settings are commented out because the 
 * ATTiny85 doesn't take Serial feedback. That said, if the code 
 * was uncommented and uploaded to an Arduino Uno R3, the code 
 * would produce the same behavior, but with Serial feedback.
 */

// set input and output pin numbers
const int PHOTOSENSOR_IN = A2;
const int SWITCH = 3;
const int LED_OUT = 2;

// set lighting threshold and timer variable
const int LIGHTING_THRESH = 150;

void setup() {
// set up the pin modes
pinMode(PHOTOSENSOR_IN, INPUT_PULLUP);
pinMode(LED_OUT, OUTPUT);
pinMode(SWITCH, INPUT);

// set up serial monitor for debugging purposes 
// Serial.begin(9600);
}

void loop() {
  // check if the system is supposed to be on
  bool power = digitalRead(SWITCH);
  // Serial.print("system is on? ");
  // Serial.println(power);

  // if the system is on, proceed with light checking
  if (power != LOW) {
    // read the room lighting
    int room_lighting = analogRead(PHOTOSENSOR_IN);
    //Serial.println(room_lighting);
    
    // if it's too dark, turn on the LEDs
    if (room_lighting > LIGHTING_THRESH) {
      digitalWrite(LED_OUT, HIGH);
      //Serial.println("it's too dark!");
      } 
    
    else {
      digitalWrite(LED_OUT, LOW);
      //Serial.println("great lighting for work!");
      }
    }
}
