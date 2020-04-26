//-------------------------------------
// class Player
//-------------------------------------
// Creates a class "Player" with all the needed information
//-------------------------------------

#pragma once
#include<string>
#include "Statistic.h"
const int maxNumGames = 15;



class Player {
private:
	std::string playerName;
	int jerseyNum;
	int numGames; // Max should be 15 & Same for every player!!!

	Statistic num3points[maxNumGames];
	Statistic num2points[maxNumGames];
	Statistic numFreeThrows[maxNumGames];
	int TotalGamePoints[maxNumGames];

	Statistic Total3Stat; //Stat -- 3 points made in game/ Total 3 points attempted in all games
	Statistic Total2Stat; //Stat -- 2 points made in game/ Total 2 points attempted in all games
	Statistic TotalFTStat; //Stat -- FT points made in game/ Total FT points attempted in all games
	int TotalOverallPoints;

	void ThreePtCalc();
	void TwoPtCalc();
	void FTCalc();
	void OverallPtCalc();
	
	void TotalGamePoints_calc();

public:
	Player();

	std::string Get_playerName();
	int Get_jerseyNum();
	int Get_numGames();

	Statistic Get_num3points(int index);
	Statistic Get_num2points(int index);
	Statistic Get_numFreeThrows(int index);



	void Set_playerName(std::string name);
	void Set_jerseyNum(int jNum);

	void addGame(Statistic threept, Statistic twopt, Statistic freept);

	void print();

};
