
inline void attachInterrupts()
{
  attachInterrupt(digitalPinToInterrupt(leftMotorEncoder), leftInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(rightMotorEncoder), rightInterrupt, FALLING);
}

inline void detachInterrupts()
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
