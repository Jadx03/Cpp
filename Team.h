#pragma once
#include "Player.h"
#include "Statistic.h""

const int max_play_arr = 100;
class Team {
private:
	Player PlayerArr[max_play_arr];
	int NumPlayers;
	int NumGames;
public:	
	Team();

	int GetNumPlayers();
	int GetNumGames();
	//Player GetPlayerArr();

	void SetNumPLayers(int num_players);
	void SetNumGames(int num_games);
	//void SetPlayerArr(Player arr[]);
	
	void read();
	void print();
	void addGame();
	int searchPlayer();
	void displayPlayer();
	void removePlayer();
	void sortByName();
	void sortByJersey();
	void write();



};