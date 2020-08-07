#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

# define wheelDiameter 7
# define noOfStripesOnWheel 8
# define DistanceBetweenWheels 31.5


# define regularSpeed 200
# define minSpeed 100

# define Kp 20
# define Ki 1
# define Kd 20

const int leftMotorEncoder = 2;
const int rightMotorEncoder = 3;

const int obstructionSensor = 4;

const int leftMotorF = 9; // 7 of l293d
const int leftMotorB = 8; // 2 of l293d

const int rightMotorF = 11; // 15 of l293d
const int rightMotorB = 10; // 10 of l293d

const int leftMotorEnable = 5;
const int rightMotorEnable = 6;



//////////////Path planning

char layout[100][100];



void setup() {
    Serial.begin(9600);
    pinMode(leftMotorEncoder, INPUT_PULLUP);
    pinMode(rightMotorEncoder, INPUT);

    pinMode(obstructionSensor, INPUT);

    pinMode(leftMotorF, OUTPUT);
    pinMode(leftMotorB, OUTPUT);
    pinMode(rightMotorF, OUTPUT);
    pinMode(rightMotorB, OUTPUT);
    pinMode(leftMotorEnable, OUTPUT);
    pinMode(rightMotorEnable, OUTPUT);
    setMotorSpeed(regularSpeed, regularSpeed);

    delay(1000);
    moveDistance(100);
}

void loop() {

}
