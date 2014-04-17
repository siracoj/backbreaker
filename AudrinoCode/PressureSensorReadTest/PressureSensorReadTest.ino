//Audrino code to read in the six sensors
//Reads data every 100ms
float sensorValues[4];
float voltConvert = (5.0 / 1023.0);
void setup()
{
  //start Serial
  Serial.begin(9600);
}

void loop()
{
  //reading in sensor data from 4 analog sensors

  sensorValues[0] = analogRead(A2) * voltConvert;
  sensorValues[1] = analogRead(A3) * voltConvert;
  sensorValues[2] = analogRead(A4) * voltConvert;
  sensorValues[3] = analogRead(A5) * voltConvert;
 
 /* 
  if(!SD.begin(2)){ //Writing data to the SD card
    Serial.write("Failed to read SD\n");
  }else{
    File data = SD.open("sensordata.csv", FILE_WRITE);
    char row[9] = "";
    for(int i = 0; i < 7; i++)
    {
      row[i] = sensorValues[i];
      i++;
      row[i] = ','; //creating a comma separated file
    }
    row[7] = sensorValues[3]; 
    row[8] = '\n';
    data.write(row);
    Serial.write(data.read());
    data.close();
  }
  */
  Serial.print(sensorValues[0]);
  Serial.print(" ");
  Serial.print(sensorValues[1]);
  Serial.print(" ");
  Serial.print(sensorValues[2]);
  Serial.print(" ");
  Serial.println(sensorValues[3]); 
  delay(50); //wait 100ms

}
