#define SensorLED   13
//Connect LED with 330 ohm resistor to Arduino digital pin 13
//Connect the sensor to digital Pin 3 which is Interrupts 1.
//to experimen drop the DFRobot sensor DFR0027 a couple of inches to turn on the LED
//if you do not have an external LED, the Arduino onboard LED will  turn on
// Sketch introduces interupt  function
#define SensorINPUT  3
unsigned char state = 0;

void setup() {
  pinMode(SensorLED, OUTPUT);
  pinMode(SensorINPUT, INPUT);
  //Trigger the blink function when the falling edge is detected
  attachInterrupt(1, blink, FALLING);
}

void loop() {
  if (state != 0) {
    state = 0;
    digitalWrite(SensorLED, HIGH);
    delay(500);
  }
  else
    digitalWrite(SensorLED, LOW);
}

//Interrupts function 
void blink() {
    state++;
}
