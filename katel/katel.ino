#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8
#define TEMPERATURE_PRECISION 11
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//DeviceAddress tankBottom, tankMiddle, tankUpper;
DeviceAddress tankBottom = { 0x28, 0x43, 0x7A, 0x26, 0x00, 0x00, 0x80, 0x17 };
DeviceAddress tankMiddle = { 0x28, 0xFF, 0x85, 0x79, 0xB0, 0x16, 0x04, 0xF1 };
DeviceAddress tankUpper = { 0x28, 0xFF, 0xFF, 0x9F, 0xA7, 0x16, 0x05, 0x0F };



void setup() {
  Serial.begin(9600);
  sensors.begin();

  sensors.setResolution(tankBottom, TEMPERATURE_PRECISION);
  sensors.setResolution(tankMiddle, TEMPERATURE_PRECISION);
  sensors.setResolution(tankUpper, TEMPERATURE_PRECISION);

}

void loop() {
  sensors.requestTemperatures();
  Serial.print(sensors.getTempC(tankBottom));
  Serial.print(",");
  Serial.print(sensors.getTempC(tankMiddle));
  Serial.print(",");
  Serial.println(sensors.getTempC(tankUpper));
  delay(1000);


}

void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print("Temp C: ");
  Serial.println(tempC);

}
