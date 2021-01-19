# include <SoftwareSerial.h>

# define wheelDiameter 6.85
# define noOfPulsesPerRevolution 420
# define DistanceBetweenWheels 21.2

# define regularSpeed 255
//# define minSpeed 100

# define Kp 9 //9
# define Ki 2 //2
# define Kd 5 //5

const int leftMotorEncoder = 3;
const int rightMotorEncoder = 2;

const int obstructionSensor = 12;

const int leftMotorF = 10; // 7 of l293d
const int leftMotorB = 11; // 2 of l293d

const int rightMotorF = 9; // 15 of l293d
const int rightMotorB = 8; // 10 of l293d

const int leftMotorEnable = 6;
const int rightMotorEnable = 5;

volatile unsigned int leftCompletedSteps = 0;
volatile unsigned int rightCompletedSteps = 0;

//////////////Path planning


//class layout
//{
//    byte * a;
//    byte * b;
//  public:
//    layout(int x,int y)
//    {
//      a=new byte[x][y];
//      b= new byte[x][y];
//    }
//    
//
//};
//
//volatile char layout[53/8][31/8];
byte x = 0, y = 0;

byte currentDirection=0;
volatile bool layout[8][14];
SoftwareSerial MyBlue(2, 3);


void setup() {
  Serial.begin(9600);
  pinMode(leftMotorEncoder, INPUT_PULLUP);
  pinMode(rightMotorEncoder, INPUT_PULLUP);

  pinMode(obstructionSensor, INPUT_PULLUP);

  pinMode(leftMotorF, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(rightMotorF, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);
  setMotorSpeed(regularSpeed, regularSpeed);
  attachInterrupts();
  delay(1000);

  //  sharpRightTurn(180);
  moveDistance(100);

  designLayout();
}

void loop() {

}
