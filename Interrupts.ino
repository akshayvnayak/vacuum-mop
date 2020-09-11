
void attachInterrupts()
{
  attachInterrupt(digitalPinToInterrupt(leftMotorEncoder), leftInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(rightMotorEncoder), rightInterrupt, FALLING);
}

void detachInterrupts()
{
  detachInterrupt(digitalPinToInterrupt(leftMotorEncoder));
  detachInterrupt(digitalPinToInterrupt(rightMotorEncoder));
}

void leftInterrupt()
{
  leftCompletedSteps++;
}

void rightInterrupt()
{
  rightCompletedSteps++;
}
