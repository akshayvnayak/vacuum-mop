# define wheelDiameter 6.85
# define noOfPulsesPerRevolution 420
# define DistanceBetweenWheels 31.5


# define regularSpeed 255
//# define minSpeed 100

# define Kp 3
# define Ki 1
# define Kd 3

const int leftMotorEncoder = 2;
const int rightMotorEncoder = 3;

const int obstructionSensor = 4;

const int leftMotorF = 9; // 7 of l293d
const int leftMotorB = 8; // 2 of l293d

const int rightMotorF = 10; // 15 of l293d
const int rightMotorB = 11; // 10 of l293d

const int leftMotorEnable = 5;
const int rightMotorEnable = 6;

int leftCompletedSteps = 0;
int rightCompletedSteps = 0;

//////////////Path planning

char layout[100][100];



void setup() {
  Serial.begin(9600);
  pinMode(leftMotorEncoder, INPUT_PULLUP);
  pinMode(rightMotorEncoder, INPUT_PULLUP);

  pinMode(obstructionSensor, INPUT);

  pinMode(leftMotorF, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(rightMotorF, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);
  setMotorSpeed(regularSpeed, regularSpeed);
  attachInterrupts();
  delay(1000);
  moveDistance(110);
}

void loop() {

}

void leftInterrupt()
{
  leftCompletedSteps++;
}

void rightInterrupt()
{
  rightCompletedSteps++;
}
