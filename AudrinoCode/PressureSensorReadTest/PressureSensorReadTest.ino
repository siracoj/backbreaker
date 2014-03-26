#include <SD.h>

//Audrino code to read in the six sensors
//Reads data every 100ms
int sensorValues[2];
void setup()
{
  //start Serial
  Serial.begin(9600);
}

void loop()
{
  //reading in sensor data from 6 analog sensors

  sensorValues[0] = analogRead(A2);
  sensorValues[1] = analogRead(A3);
  
  /*
  if(SD.begin()){ //Writing data to the SD card
    File data = SD.open("sensordata.csv", FILE_WRITE);
    String row = "";
    for(int i = 0; i < 5; i++)
    {
      row = row + sensorValues[i] + ","; //creating a comma separated file
    }
    row = row + sensorValues[5] + "\n";
    char writeData[row.length()];
    row.toCharArray(writeData, row.length()); //conversion to char array
    data.write(writeData);
    data.close();
  }*/
  Serial.print(sensorValues[0]);
  Serial.print(" | ");
  Serial.println(sensorValues[1]);
  delay(1000); //wait 100ms
    
}
