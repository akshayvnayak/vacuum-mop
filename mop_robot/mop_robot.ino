# define wheelDiameter 7
# define noOfStripesInWheel 4
# define DistanceBetweenWheels 31.5


const int leftMotorEncoder=2;
const int rightMotorEncoder = 3;

const int obstructionSensor = 4;

const int leftMotorF =8;  // 7 of l293d
const int leftMotorB =9;  // 2 of l293d

const int rightMotorF =10;  // 15 of l293d
const int rightMotorB =11;  // 10 of l293d

const int leftMotorSpeed = 5;
const int rightMotorSpeed = 6;


void setup() {
  Serial.begin(9600);
  pinMode(leftMotorEncoder, INPUT_PULLUP);
  pinMode(rightMotorEncoder, INPUT);

  pinMode(obstructionSensor, INPUT);

  pinMode(leftMotorF,OUTPUT);
  pinMode(leftMotorB,OUTPUT);
  pinMode(rightMotorF,OUTPUT);
  pinMode(rightMotorB,OUTPUT);
  pinMode(leftMotorSpeed,OUTPUT);
  pinMode(rightMotorSpeed,OUTPUT);
  analogWrite(leftMotorSpeed,255);
  analogWrite(rightMotorSpeed,255);

  delay(2000);
}

void loop() {
 
}
