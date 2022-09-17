#include <IRremote.h>       // IRremote library for IR receiver.

// Define the digital I/O pins.
#define redPin 9            // The pin where the red cathode is connected to.
#define greenPin 10         // The pin where the green cathode is connected to.
#define bluePin 11          // The pin where the blue cathode is connected to.
#define irPin 12            // The pin where the IR receiver is connected to.

// Define HEX codes for the remote control (Change these to match your remote control).
// You can use ir-remote-test.ino to find the HEX codes for your remote control.
#define button0 0xFF9867    // 0
#define button1 0xFFA25D    // 1
#define button2 0xFF629D    // 2
#define button3 0xFFE21D    // 3
#define button4 0xFF22DD    // 4
#define button5 0xFF02FD    // 5
#define button6 0xFFC23D    // 6
#define button7 0xFFE01F    // 7
#define button8 0xFFA857    // 8
#define button9 0xFF906F    // 9

IRrecv irrecv(irPin);       // Create a new instance of receiver.
decode_results results;     // Create a new instance of results.

// Define color structure for rgb.
struct color {
   int red;
   int green;
   int blue;
};

typedef struct color Color; // Define color as a new type.

void setup() {
   // Start serial communication at 9600 baud.
   Serial.begin(9600);

   // Print a start message on the serial monitor.
   Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

   // Define the pins of the RGB LED as output.
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);

   irrecv.enableIRIn(); // Start the receiver.
}

/**
   * Creates a new color when the c.redresponding button is pressed.
   * Returns Color structure with rgb values.
   * For example, when the 1 key is pressed, the color will be red.
   */
Color translateIR() {
   int key = results.value; // Get the value of the pressed button.
   Color c;

   switch (key) {
      case button1:
         // Red
         setColor(&c, 255, 0, 0);
         break;
      case button2:
         // Green
         setColor(&c, 0, 255, 0);
         break;
      case button3:
         // Blue
         setColor(&c, 0, 0, 255);
         break;
      case button4:
         // Orange
         setColor(&c, 255, 165, 0);
         break;
      case button5:
         // Purple
         setColor(&c, 159, 0, 255);
         break;
      case button6:
         // Aqua
         setColor(&c, 0, 255, 255);
         break;
      case button7:
         // Yellow
         setColor(&c, 255, 255, 0);
         break;
      case button8:
         // Magenta
         setColor(&c, 255, 0, 255);
         break;
      case button9:
         // White
         setColor(&c, 255, 255, 255);
         break;
      case button0:
         // Off (black)
         setColor(&c, 0, 0, 0);
         break;
      default:
         break;
   }

   return c;
}

/***
   * Sets the color of the RGB LED.
   * @param c The color to set.
   * @param r The red value.
   * @param g The green value.
   * @param b The blue value.
   */
void setColor(Color *c, int red, int green, int blue) {
   c->red = red;
   c->green = green;
   c->blue = blue;
}

/**
   * Powers the RGB LED with the given color.
   * @param c The color to display.
   */
void displayColor(Color c) {
   analogWrite(redPin, c.red);   // Set the red cathode to the red value.
   analogWrite(greenPin, c.green); // Set the green cathode to the green value.
   analogWrite(bluePin, c.blue);  // Set the blue cathode to the blue value.
}

/**
   * Prints the color to the serial monitor.
   * Especially useful for debugging.
   * @param c The color to print.
   */
void printColor(Color c) {
   Serial.print("R: ");
   Serial.print(c.red);
   Serial.print(" G: ");
   Serial.print(c.green);
   Serial.print(" B: ");
   Serial.println(c.blue);
}

void loop() {
   // If the receiver has received a new value.
   if (irrecv.decode(&results)) {
      Color nc = translateIR(); // Get the new color.
      printColor(nc); // Print the new color to the serial monitor.
      displayColor(nc); // Display the new color on the RGB LED.
      delay(100);      // Wait 100ms.
      irrecv.resume(); // Receive the next value.
   }
}

