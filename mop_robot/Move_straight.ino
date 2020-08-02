
bool moveDistance(float distance)
{
  unsigned long previousTime = 0;
  int flag = 0;
  int Flag = 0;
  int rotationNumber = 0;
  int RotationNumber = 0;
  float noOfRotation = noOfStripesPass(distance);
  straight();
  while (rotationNumber < noOfRotation)
  {
    if(checkObstruction())
    {
      halt(); 
      return 0;
    }
    if (millis() > previousTime + 10)
    {
      if (flag == 0 && digitalRead(leftMotorEncoder) == 1)
        rotationNumber++;
      if (Flag == 0 && digitalRead(rightMotorEncoder) == 1)
        RotationNumber++;
      flag = digitalRead(leftMotorEncoder);
      Flag = digitalRead(rightMotorEncoder);
      
      previousTime = millis();
    Serial.println(rotationNumber);
    }
//    Serial.println(flag);
  }
  halt();
  return 1;
}
