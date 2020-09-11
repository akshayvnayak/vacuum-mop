bool moveDistance(float distance)
{
  float noOfSteps = distanceToSteps(distance);
  int error = 0;
  int pidError = 0;
  int lastError = 0;
  int integral = 0;
  int difference = 0;
  
  leftCompletedSteps = 0;
  rightCompletedSteps = 0;
  
  setMotorSpeed(regularSpeed, regularSpeed);
  straight();
  
  while (leftCompletedSteps < noOfSteps || rightCompletedSteps < noOfSteps)
  {
    //    if (checkObstruction())
    //    {
    //      Serial.println("Obstruction");
    //      halt();
    //      return 0;
    //    }

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
  halt();
  return 1;
}
