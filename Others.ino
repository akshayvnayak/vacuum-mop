inline float distanceToSteps(int distance)
{
  return noOfPulsesPerRevolution * ((float)distance / (PI * wheelDiameter));
}

inline bool checkObstruction()
{
  return !digitalRead(obstructionSensor);
}

//void setMotorSpeed(int leftMotorSpeed, int rightMotorSpeed)
//{
//  analogWrite(leftMotorEnable, leftMotorSpeed < minSpeed ? minSpeed : (leftMotorSpeed > 255) ? 255 : leftMotorSpeed);
//  analogWrite(rightMotorEnable, rightMotorSpeed < minSpeed ? minSpeed : (rightMotorSpeed > 255) ? 255 : rightMotorSpeed);
////  Serial.print("\t\t\t\t\t\t\t\t\t");
////  Serial.print(leftMotorSpeed < minSpeed ? minSpeed : (leftMotorSpeed > 255) ? 255 : leftMotorSpeed);
////  Serial.print("\t");
////  Serial.println(rightMotorSpeed < minSpeed ? minSpeed : (rightMotorSpeed > 255) ? 255 : rightMotorSpeed);
//}


inline void setMotorSpeed ( int leftMotorSpeed, int rightMotorSpeed)
{
  analogWrite( leftMotorEnable, leftMotorSpeed);
  analogWrite(rightMotorEnable, rightMotorSpeed);
  
  Serial.print("Speed : ");
  Serial.print(leftMotorSpeed);
  Serial.print("\t");
  Serial.println(rightMotorSpeed);
}
