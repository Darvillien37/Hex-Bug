#ifndef Leg_h
#define Leg_h

#include "Arduino.h"
#include "Joint.h"

class Leg
{
public:
	Leg();
	//Summary:
	//	Set up the corresponding leg.
	//Parameters:
	//	pin: the pin on the board to attach the joint/servo to.
	//	min: the minimum angle the joint is allowed to move to.
	//	max: the maximum angle the joint is allowed to move to.
	//	pos: the initial position the joint should be set to, 
	//			moves the joint to this position after set-up.
	void SetReachJoint(int pin, int min, int max, int pos);
	void SetHorizJoint(int pin, int min, int max, int pos);
	void SetVertJoint(int pin, int min, int max, int pos);
	
	//Summary:
	//	Move the joints to new positions. If a parameter is negative, the joint 
	//	will not change positions.
	//Parameters:
	//	h: the new position for the horizontal joint.
	//	v: the new position for the vertical joint.
	//	r: the new position for the reach joint.
	void MoveJoints(int h, int v, int r);

	int GetHMin();
	int GetHMax();
	int GetVMin();
	int GetVMax();
	int GetRMin();
	int GetRMax();


private:
	bool _posReached;
	Joint _reach;
	Joint _horiz;
	Joint _vert;


	int _hPin;
	int _vPin;
	int _ePin;

	int _hPos;
	int _vPos;
	int _ePos;


};

#endif