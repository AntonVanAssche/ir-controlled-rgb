#define redPin 9
#define greenPin 10
#define bluePin 11

void setup() {
   Serial.begin(9600);

   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
}

void loop() {
   // Red
   Serial.println("Red");
   analogWrite(redPin, 255);
   analogWrite(greenPin, 0);
   analogWrite(bluePin, 0);
   delay(1000);

   // Green
   Serial.println("Green");
   analogWrite(redPin, 0);
   analogWrite(greenPin, 255);
   analogWrite(bluePin, 0);
   delay(1000);

   // Blue
   Serial.println("Blue");
   analogWrite(redPin, 0);
   analogWrite(greenPin, 0);
   analogWrite(bluePin, 255);
   delay(1000);

   // Orange
   Serial.println("Orange");
   analogWrite(redPin, 255);
   analogWrite(greenPin, 165);
   analogWrite(bluePin, 0);
   delay(1000);

   // Yellow
   Serial.println("Yellow");
   analogWrite(redPin, 255);
   analogWrite(greenPin, 255);
   analogWrite(bluePin, 0);
   delay(1000);

   // Aqua
   Serial.println("Aqua");
   analogWrite(redPin, 0);
   analogWrite(greenPin, 255);
   analogWrite(bluePin, 255);
   delay(1000);

   // Purple
   Serial.println("Purple");
   analogWrite(redPin, 159);
   analogWrite(greenPin, 0);
   analogWrite(bluePin, 255);
   delay(1000);

   // Magenta
   Serial.println("Magenta");
   analogWrite(redPin, 255);
   analogWrite(greenPin, 0);
   analogWrite(bluePin, 255);
   delay(1000);

   // white
   Serial.println("White");
   analogWrite(redPin, 255);
   analogWrite(greenPin, 255);
   analogWrite(bluePin, 255);
   delay(1000);

   // Off (Black)
   Serial.println("Off");
   analogWrite(redPin, 0);
   analogWrite(greenPin, 0);
   analogWrite(bluePin, 0);
   delay(1000);

}
