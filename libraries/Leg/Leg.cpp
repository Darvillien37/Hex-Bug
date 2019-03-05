#include "Arduino.h"
#include "Leg.h"

Leg::Leg() {
	_posReached = true;
}

void Leg::SetReachJoint(int pin, int min, int max, int pos) 
{
	_reach.SetUp(pin, min, max, pos);
	_reach.ToIdle();
}

void Leg::SetHorizJoint(int pin, int min, int max, int pos)
{
	_horiz.SetUp(pin, min, max, pos);
	_horiz.ToIdle();
}

void Leg::SetVertJoint(int pin, int min, int max, int pos)
{
	_vert.SetUp(pin, min, max, pos);
	_vert.ToIdle();
}

void Leg::MoveJoints(int h, int v, int r)
{
	_posReached = false;

	if (h < 0)
		h = _horiz.GetPos();
	if (v < 0)
		v = _vert.GetPos();
	if (r < 0)
		r = _reach.GetPos();


	//Serial.print("Moving:  H: ");
	//Serial.print(h);
	//Serial.print(" V: ");
	//Serial.print(v);
	//Serial.print(" R: ");
	//Serial.println(r);

	while (!_posReached) {

		if (_horiz.GetPos() != h)
		{
			_horiz.MoveOneDegTo(h);
		}

		if (_vert.GetPos() != v)
		{
			_vert.MoveOneDegTo(v);
		}

		if (_reach.GetPos() != r)
		{
			_reach.MoveOneDegTo(r);
		}

		delay(1);

		if (_horiz.GetPos() == h &&
			_vert.GetPos() == v &&
			_reach.GetPos() == r)
		{
			_posReached = true;
		}
	}
	/*Serial.print("Moved:   H: ");
	Serial.print(_horiz.GetPos());
	Serial.print(" V: ");
	Serial.print(_vert.GetPos());
	Serial.print(" R: ");
	Serial.println(_reach.GetPos());*/


}

int Leg::GetHMin()
{
	return _horiz.GetSoftMin();
}
int Leg::GetHMax()
{
	return _horiz.GetSoftMax();
}

int Leg::GetVMin()
{
	return _vert.GetSoftMin();
}
int Leg::GetVMax()
{
	return _vert.GetSoftMax();
}

int Leg::GetRMin()
{
	return _reach.GetSoftMin();
}
int Leg::GetRMax()
{
	return _reach.GetSoftMax();
}

