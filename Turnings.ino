int rightTurn(int degree)
{
  int noOfTurns = distanceToSteps(degree * (PI / 180) * DistanceBetweenWheels);
  unsigned long previousTime = 0;
  int flag = 0;
  int rotationNumber = 0;
  right();
  while (rotationNumber < noOfTurns)
  {
    if (millis() > previousTime + 10)
    {
      if (flag == 0 && digitalRead(leftMotorEncoder) == 1)
        rotationNumber++;
      flag = digitalRead(leftMotorEncoder);
      previousTime = millis();
    }
    Serial.print(flag);
    Serial.println(rotationNumber);
  }
  halt();
  return 1;
}

int leftTurn(int degree)
{
  int noOfTurns = distanceToSteps(degree * (PI / 180) * DistanceBetweenWheels);
  unsigned long previousTime = 0;
  int flag = 0;
  int rotationNumber = 0;
  left();
  while (rotationNumber < noOfTurns)
  {
    if (millis() > previousTime + 10)
    {
      if (flag == 0 && digitalRead(rightMotorEncoder) == 1)
        rotationNumber++;
      flag = digitalRead(rightMotorEncoder);
      previousTime = millis();
    }
    Serial.print(flag);
    Serial.println(rotationNumber);
  }
  halt();
  return 1;
}
