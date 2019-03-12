#include "Arduino.h"
#include "Body.h"
#include <math.h>
//NOTE: sin is in radians, NOT degrees 

Body::Body()
{}

void Body::Setup()
{
	//parameters are: pin, min, max, initialPosition.	
	FR_Leg.SetHorizJoint(8, 50, 130, 90);
	FR_Leg.SetVertJoint(9, 50, 130, 90);
	//Bounds checked:
	FR_Leg.SetReachJoint(10, 0, 120, 90);

}



void Body::ToStanding()
{
	FR_Leg.MoveJoints(90, 70, 30);
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
		h = d_NumScale(cos(legCounter), -1, 1, FR_Leg.GetHMin(), FR_Leg.GetHMax());
		v = d_NumScale(sin(legCounter), -1, 1, FR_Leg.GetVMin(), FR_Leg.GetVMax());
		FR_Leg.MoveJoints(
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

