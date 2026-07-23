/*
  Photoresistor -- modified from Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  1. Potentiometer
  - one leg of photoresistor connected to analog pin 0. Same leg is connected to +5V
  - other leg of the photoresistor is connected to a 10 kOhm resistor
  - Other end of the 10 kOhm resistor is connected to ground
  2. Thermistor
  - one leg of thermistor connected to analog pin 1. Same leg is connected to +5V
  - other leg of the photoresistor is connected to a 10 kOhm resistor
  - Other end of the 10 kOhm resistor is connected to ground
  3. LED 
  - Uses onboard LED (Pin 13)
  4. DHT11
  - Left leg connects to 5V
  - Middle leg connects to Digital Pin 2
  - Right leg connects to Gnd

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe
  modified July 2026 by Jay Brodeur

  This example code is in the public domain.
Wiring example: 
https://docs.arduino.cc/built-in-examples/analog/AnalogInput/
*/
// Include libraries
#include <math.h> // include the math library
// DHT11 REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
#include "DHT.h"

// These constants won't change. They're used to give names to the pins used:
const int PrPin = A0;  // Analog input pin that the photoresistor is attached to
const int ThPin = 1;  // Analog input pin that the thermistor is attached to
const int analogOutPin = 13;  // Analog output pin that the LED is attached to
#define DHTPIN 2     // Digital pin connected to the DHT sensor

// intermediate variables (for thermistor temperature calculation): 
float vcc = 4.91;                       // only used for display purposes, if used set to the measured Vcc.
float pad = 9850;                       // balance/pad resistor value, set this to the measured resistance of your pad resistor
float thermr = 10000;                   // thermistor nominal resistance

// create variables for output:
int sensorValue_PR = 0;  // value read from the photoresistor
float temp = 0;  // temperature
int outputValue = 0;  // value output to the PWM (analog out)

// A function to measure and calculate temperature =====
float Thermistor(int RawADC) {
  long Resistance;  
  float Temp;  // Dual-Purpose variable to save space.

  Resistance=pad*((1024.0 / RawADC) - 1);
  Temp = log(Resistance); // Saving the Log(resistance) so not to calculate  it 4 times later
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;  // Convert Kelvin to Celsius                      

  // BEGIN- Remove these lines for the function not to display anything
  //Serial.print("ADC: ");
  //Serial.print(RawADC);
  //Serial.print("/1024");                           // Print out RAW ADC Number
  //Serial.print(", vcc: ");
  //Serial.print(vcc,2);

  //Serial.print(", pad: ");
  //Serial.print(pad/1000,3);
  //Serial.print(" Kohms, Volts: ");
  //Serial.print(((RawADC*vcc)/1024.0),3);  
  //Serial.print(", Resistance: ");
  //Serial.print(Resistance);
  //Serial.print(" ohms, ");
  // END- Remove these lines for the function not to display anything

  // Uncomment this line for the function to return Fahrenheit instead.
  //temp = (Temp * 9.0)/ 5.0 + 32.0;                  // Convert to Fahrenheit
  return Temp;                                      // Return the Temperature
}
// =====================================================

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // Start the DHT
  Serial.println(F("DHT11 test!"));
  dht.begin();
}

void loop() {
  // %%% Photoresistor code 
  // read the analog in value:
  sensorValue_PR = analogRead(PrPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue_PR, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // %%% Read from Thermistor
  temp=Thermistor(analogRead(ThPin));       // read ADC and  convert it to Celsius

  // Read from DHT
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read relative humidity as % 
  float dht_hum = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float dht_temp = dht.readTemperature();
 // Compute heat index in Celsius (isFahreheit = false)
  float dht_hi = dht.computeHeatIndex(t, h, false);


  // print the results to the Serial Monitor:
  Serial.print("photoresistor = ");
  Serial.print(sensorValue_PR);
  //Serial.print("\t LED output intensity = ");
  //Serial.print(outputValue);
  Serial.print(" | Thermistor temperature (deg C)= ");
  Serial.print(temp);
  Serial.print(" |  DHT temperature (deg C)= ");
  Serial.print(dht_temp);
  Serial.print(" | DHT relative humidity (%)= ");
  Serial.print(dht_hum);
  Serial.print(" | DHT humidex (dec C)= ");
  Serial.println(dht_hi);

  // wait 100 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2000);
}
