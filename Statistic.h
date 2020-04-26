//-------------------------------------
// class Statistic
//-------------------------------------
// Creates a data structure class with two ints - Points made and attempted points
//-------------------------------------

#pragma once


class Statistic {
private:
	int numPoints;
	int numAttempt;



public:
	Statistic();
	int Get_numPoints();
	int Get_numAttempt();
	void Set_numPoints(int numPoints);
	void Set_numAttempts(int numPoints);

	
	int getPercent();
};