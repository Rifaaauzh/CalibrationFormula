#include <math.h>

double offset= 0.02612915;
double calculateExpectedValue(double measured) {
    // Compute log10(y) - subtract 0.0
    
    double log10X = log10(measured) - offset;
    // Calculate x =10^log10X
    double x = pow(10, log10X);
    return x;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
        // Read the incoming value from the serial monitor
        double y = Serial.parseFloat();

       if (y != 0) { 
            double x = calculateExpectedValue(y); 

            Serial.print("You entered y = ");
            Serial.println(y); 
            Serial.print("Calculated x value: ");
            Serial.println(x,3); 
        }
    }

}
