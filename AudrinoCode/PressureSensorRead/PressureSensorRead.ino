#include <SD.h>

//Audrino code to read in the six sensors
//Reads data every 100ms
int sensorValues[6];
void setup()
{
  //start Serial
  Serial.begin(9600);
}

void loop()
{
  //reading in sensor data from 6 analog sensors
  sensorValues[0] = analogRead(A0);
  sensorValues[1] = analogRead(A1);
  sensorValues[2] = analogRead(A2);
  sensorValues[3] = analogRead(A3);
  sensorValues[4] = analogRead(A4);
  sensorValues[5] = analogRead(A5);
  
  if(SD.begin()){ //Writing data to the SD card
    File data = SD.open("sensordata.csv", FILE_WRITE);
    String row = "";
    for(int i = 0; i < 5; i++)
    {
      row = row + sensorValues[i] + ",";
    }
    row = row + sensorValues[5] + "\n";
    char writeData[row.length()];
    row.toCharArray(writeData, row.length());
    data.write(writeData);
    data.close();
  }
    
}
