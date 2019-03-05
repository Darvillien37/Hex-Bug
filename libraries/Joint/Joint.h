#ifndef Joint_h
#define Joint_h

#include "Arduino.h"
#include "Servo.h"

class Joint
{

public:
	Joint();
	void SetUp(int pin, int min, int max, int initialPos);
	void MoveTo(int newPos);
	int GetPos();
	void MoveOneDegTo(int newVal);
	void ToIdle();

	int GetSoftMin();
	int GetSoftMax();
	

private:
	Servo _joint;

	int _idlePos;
	int _currentPos;

	const int MIN_ANGLE = 0;
	const int MAX_ANGLE = 180;
	int _softMinAngle;
	int _softMaxAngle;
	


	int BoundCheck(int value);

	void ReadServo();
};
#endif