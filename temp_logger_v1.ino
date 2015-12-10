/* YourDuino Electronic Brick Test
Temperature Sensor DS18B20
- Connect cable to Arduino Digital I/O Pin 2
terry@yourduino.com 
*/

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 

/* Set up a oneWire instance to communicate with any OneWire device*/
OneWire ourWire(ONE_WIRE_BUS);

/* Tell Dallas Temperature Library to use oneWire Library */
DallasTemperature sensors(&ourWire);

void setup() 
{
  Serial.begin(9600);
  delay(1000);

  /*-( Start up the DallasTemperature library )-*/
  sensors.begin();
}

void loop() 
{
  Serial.println();
  sensors.requestTemperatures(); // Send the command to get temperatures

  Serial.print(sensors.getTempFByIndex(0));
  delay(300000);
}
