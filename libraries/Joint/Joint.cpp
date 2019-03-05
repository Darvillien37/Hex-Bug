#include "Arduino.h"
#include "Joint.h"

Joint::Joint()
{}

void Joint::SetUp(int pin, int min, int max, int initialPos) {
	_softMinAngle = min;
	_softMaxAngle = max;
	_idlePos = initialPos;
	_joint.attach(pin);
	ReadServo();
}

void Joint::MoveTo(int newPos) {
	this->BoundCheck(newPos);
	_joint.write(newPos);
	ReadServo();
}

int Joint::GetPos()
{
	return _currentPos;
}

void Joint::MoveOneDegTo(int newVal)
{
	if (_currentPos < newVal) {
		this->MoveTo(_currentPos + 1);
	}
	else 
	{
		this->MoveTo(_currentPos - 1);
	}
	
}

int Joint::BoundCheck(int value)
{
	if (value < _softMinAngle)
		return _softMinAngle;
	if (value > _softMaxAngle)
		return _softMaxAngle;
	return value;
}

void Joint::ReadServo()
{
	_currentPos = _joint.read();
}

void Joint::ToIdle() {
	this->MoveTo(this->_idlePos);
}

int Joint::GetSoftMin()
{
	return _softMinAngle;
}

int Joint::GetSoftMax()
{
	return _softMaxAngle;
}

