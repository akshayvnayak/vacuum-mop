bool moveDistance(float distance)
{



  unsigned long previousTime = 0;
  bool leftMotorFlag = 1;
  bool rightMotorFlag = 1;
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
    if (millis() > previousTime + 5)
    {
      count++;
      if (leftMotorFlag == 0 && digitalRead(leftMotorEncoder) == 1)
        leftCompletedSteps++;
      if (rightMotorFlag == 0 && digitalRead(rightMotorEncoder) == 1)
        rightCompletedSteps++;
      error = leftCompletedSteps - rightCompletedSteps;
      if(error>0)
        analogWrite(leftMotorEnable,regularSpeed - error * Kp );
      if(error<0)
        analogWrite(rightMotorEnable,regularSpeed + error * Kp );

      setMotorSpeed( regularSpeed - error * Kp, regularSpeed + error * Kp);

      //      if (count > -1)
      //      {
      //        count = 0;
      //        error = leftCompletedSteps - rightCompletedSteps;
      //        integral += error;
      //        difference = error - lastError;
      //        pidError = error * Kp + integral * Ki + difference * Kd;
      //        lastError = error;
      //        //        if (pidError > 0)
      //        setMotorSpeed( regularSpeed - pidError, regularSpeed + pidError);
      //        //        else
      //        //          setMotorSpeed( 255, 255 + pidError);
      //      }
      leftMotorFlag = digitalRead(leftMotorEncoder);
      rightMotorFlag = digitalRead(rightMotorEncoder);

      previousTime = millis();
            Serial.print(leftCompletedSteps);
            Serial.print("\t");
//            Serial.print(pidError);
//            Serial.print("\t");
            Serial.println(rightCompletedSteps);
    }
  }
  halt();
  return 1;
}
