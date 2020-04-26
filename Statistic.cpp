#include<iostream>
#include "Statistic.h"	

const int zero = 0;

Statistic::Statistic() { int numPoints = 0; int numAttempt = 0; }

void Statistic::Set_numPoints(int numINpoints) {
	numPoints = numINpoints;
}

void Statistic::Set_numAttempts(int numINattempt) {
	numAttempt = numINattempt;
}

int Statistic::Get_numPoints(){
	return numPoints;
}

int Statistic::Get_numAttempt() {
	return numAttempt;
}

int Statistic::getPercent() {
	
	if (numAttempt == 0) {
		return zero;
	}
	else {
		int percent = ((1.0 * numPoints) / (1.0 * numAttempt)) * 100;
		return percent;
	}
}


