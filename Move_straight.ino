bool moveDistance(float distance)
{



  unsigned long previousTime = 0;
  int leftMotorFlag = 0;
  int rightMotorFlag = 0;
  int leftCompletedSteps = 0;
  int rightCompletedSteps = 0;
  float noOfSteps = distanceToSteps(distance);
  int error = 0;
  int pidError = 0;
  int lastError = 0;
  int integral = 0;
  int difference = 0;
  int count = 0;
  setMotorSpeed(regularSpeed, regularSpeed);
  straight();
  while (leftCompletedSteps < noOfSteps || rightCompletedSteps < noOfSteps)
  {
    if (checkObstruction())
    {
      Serial.println("Obstruction");
      halt();
      return 0;
    }
    if (millis() > previousTime + 10)
    {
      count++;
      if (leftMotorFlag == 0 && digitalRead(leftMotorEncoder) == 1)
        leftCompletedSteps++;
      if (rightMotorFlag == 0 && digitalRead(rightMotorEncoder) == 1)
        rightCompletedSteps++;

      if (count > 3)
      {
        count = 0;
        error = leftCompletedSteps - rightCompletedSteps;
        integral += error;
        difference = error - lastError;
        pidError = error * Kp + integral * Ki + difference * Kd;
        lastError = error;
        //        if (pidError > 0)
        setMotorSpeed( regularSpeed - pidError, regularSpeed + pidError);
        //        else
        //          setMotorSpeed( 255, 255 + pidError);
      }
      leftMotorFlag = digitalRead(leftMotorEncoder);
      rightMotorFlag = digitalRead(rightMotorEncoder);

      previousTime = millis();
      Serial.print(leftCompletedSteps);
      Serial.print("\t");
      Serial.print(pidError);
      Serial.print("\t");
      Serial.println(rightCompletedSteps);
    }
  }
  halt();
  return 1;
}
