void straight()
{
  Serial.println("Straight");
  digitalWrite(leftMotorB,LOW);
  digitalWrite(leftMotorF,HIGH);
  digitalWrite(rightMotorB,LOW);
  digitalWrite(rightMotorF,HIGH);
}

void backward()
{
  Serial.println("Backward");
  digitalWrite(leftMotorF,LOW);
  digitalWrite(leftMotorB,HIGH);
  digitalWrite(rightMotorF,LOW);
  digitalWrite(rightMotorB,HIGH);
}

void left()
{
  Serial.println("Left");
  digitalWrite(leftMotorF,LOW);
  digitalWrite(leftMotorB,LOW);
  digitalWrite(rightMotorB,LOW);
  digitalWrite(rightMotorF,HIGH);
}
void sharpLeft()
{
  Serial.println("Sharp Left");
  digitalWrite(leftMotorF,LOW);
  digitalWrite(leftMotorB,HIGH);
  digitalWrite(rightMotorB,LOW);
  digitalWrite(rightMotorF,HIGH);
}

void right()
{
  Serial.println("Right");
  digitalWrite(leftMotorB,LOW);
  digitalWrite(leftMotorF,HIGH);
  digitalWrite(rightMotorF,LOW);
  digitalWrite(rightMotorB,LOW);
}

void sharpRight()
{
  Serial.println("Sharp Right");
  digitalWrite(leftMotorB,LOW);
  digitalWrite(leftMotorF,HIGH);
  digitalWrite(rightMotorF,LOW);
  digitalWrite(rightMotorB,HIGH);
}
void halt()
{
  Serial.println("Halt");
  digitalWrite(leftMotorB,LOW);
  digitalWrite(leftMotorF,LOW);
  digitalWrite(rightMotorF,LOW);
  digitalWrite(rightMotorB,LOW); 
}
