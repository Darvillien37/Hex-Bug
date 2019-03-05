#ifndef Body_h
#define Body_h

#include "Arduino.h"
#include "Leg.h"

class Body
{
  public:
	  Body();
	  void Setup();

	  void StepFoward(int steps);
	  
	  void ToStanding();

	  //Might not use these:
	  enum SpiderMode { IDLE, FOWARD, BACK, TESTING };
	  void SetMode(SpiderMode newMode);

	
  private:
	  double d_NumScale(double value, double minA, double maxA, double minB, double maxB);
	  SpiderMode _currentMode = IDLE;
	  
	  //Legs:
	  //Left
	  Leg FL_Leg;//Front
	  Leg ML_Leg;//Middle
	  Leg BL_Leg;//Back
	  //Right
	  Leg FR_Leg;//Front
	  Leg MR_Leg;//Middle
	  Leg BR_Leg;//Back
	  

};

#endif