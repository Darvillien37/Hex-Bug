#include "Arduino.h"
#include "Body.h"
#include <math.h>
//NOTE: sin is in radians, NOT degrees 

Body::Body()
{}

void Body::Setup()
{
	//parameters are: pin, min, max, initialPosition.	
	FL_Leg.SetHorizJoint(8, 50, 130, 90);
	FL_Leg.SetVertJoint(9, 50, 130, 90);
	FL_Leg.SetReachJoint(10, 50, 130, 90);

}



void Body::ToStanding()
{
	FL_Leg.MoveJoints(90, 125, 70);
}


float legCounter = PI;


void Body::StepFoward(int steps)
{
	int h;
	int v;
	legCounter = PI;
	int stepsTaken = 0;
	while (stepsTaken < steps)
	{
		h = d_NumScale(sin(legCounter), -1, 1, FL_Leg.GetHMin(), FL_Leg.GetHMax());
		v = d_NumScale(cos(legCounter), -1, 1, FL_Leg.GetVMin(), FL_Leg.GetVMax());
		FL_Leg.MoveJoints(
			h,
			v,
			-1);
		legCounter += 0.1;

		//Serial.print("Moving:  H: ");
		//Serial.print(h);
		//Serial.print(" V: ");
		//Serial.println(v);

		if (legCounter > 3 * PI)
		{
			stepsTaken++;
			legCounter = PI;
		}
		delay(10);
	}

	this->ToStanding();
}

//A function to scale the 'value' between 'inputA' and 'inputA', to the scaled number between 'outputB' and 'outputB'.
double Body::d_NumScale(double value, double inputMin, double inputMax, double outputMin, double outputMax) {
	double scaledVal;
	scaledVal = (((outputMax - outputMin) * (value - inputMin)) / (inputMax - inputMin)) + outputMin;
	return scaledVal;
}

