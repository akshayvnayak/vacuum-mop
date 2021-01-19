bool moveDistance(float distance)
{
  leftCompletedSteps = 0;
  rightCompletedSteps = 0;

  setMotorSpeed(regularSpeed, regularSpeed);
  straight();

  pidMovement(distanceToSteps(distance));
  
  halt();
  return 1;
}

int pidMovement(int noOfSteps)
{
  byte error = 0;
  byte pidError = 0;
  byte lastError = 0;
  byte integral = 0;
  byte difference = 0;
  
  while (leftCompletedSteps < noOfSteps || rightCompletedSteps < noOfSteps)
  {
        if (checkObstruction())
        {
          Serial.println("Obstruction");
          halt();
          return 0;
        }

    ////////////////////// PID
    error = leftCompletedSteps - rightCompletedSteps;
    integral += error;
    difference = error - lastError;
    pidError = error * Kp + integral * Ki + difference * Kd;
    lastError = error;
    if (pidError > 0)
      setMotorSpeed( regularSpeed - pidError, regularSpeed);
    if (pidError < 0)
      setMotorSpeed( regularSpeed, regularSpeed + pidError);

    Serial.print(leftCompletedSteps);
    Serial.print("\t");
    Serial.print(rightCompletedSteps);
    Serial.print("\t");
    Serial.println(pidError);
  }
}
