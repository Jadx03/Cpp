#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include "Statistic.h"
#include "Player.h"
#include "Team.h"

const int not_found = -1;

Team::Team() { NumPlayers = 0; NumGames = 0; }

//------------SET METHODS------------
void Team::SetNumGames(int num_game) {
	NumGames = num_game;
}
void Team::SetNumPLayers(int num_play) {
	NumPlayers = num_play;
}

//-----------------GET METHODS------------
int Team::GetNumGames() {
	return NumGames;
}
int Team::GetNumPlayers() {
	return NumPlayers;
}


//-----------"READ" TO READ DATA FROM INPUT FILE-------------
void Team::read() {
	
	std::ifstream f;

	f.open("bballin.txt");

	if (f.fail()) {
		std::cout << "Failed to open the fail. " << std::endl;
	}
	else {
		//std::cout << " OPEN!!!!!!!!!!!" << std::endl;
		int tempgame;
		int tempplay;
		int jerseynum;
		std::string name;
		
		f >> tempplay >> tempgame;

		//std::cout << tempplay << "........" << tempgame << std::endl;

		SetNumPLayers(tempplay);
		SetNumGames(tempgame);

		for (int i = 0; i < tempplay; i++) {
			f >> jerseynum;
			std::getline(f, name);

			PlayerArr[i].Set_jerseyNum(jerseynum);
			PlayerArr[i].Set_playerName(name);
			

			for (int j = 0; j < tempgame; j++) {
				int md3,att3,md2,att2,mdft,attft;
				Statistic pt3, pt2, ptft;
				
				f >> md3 >> att3 >> md2 >> att2 >> mdft >> attft;

				pt3.Set_numPoints(md3);
				pt3.Set_numAttempts(att3);
				pt2.Set_numPoints(md2);
				pt2.Set_numAttempts(att2);
				ptft.Set_numPoints(mdft);
				ptft.Set_numAttempts(attft);

				PlayerArr[i].addGame(pt3, pt2, ptft);
				
			}
		}
	
	}
	f.close();
}

// ---------PRINT METHOD---------------------
void Team::print() {
	
	for (int i = 0; i < NumPlayers; i++) {
		PlayerArr[i].print();
	}
	std::cout << std::endl;
}

//-----------METHOD TO ADD A GAME----------------
void Team::addGame() {
	
	for (int i = 0; i < NumPlayers; i++) {
		int md_3, att_3, md_2, att_2, md_ft, att_ft;
		Statistic pt_3, pt_2, pt_ft;

		std::cout << "Enter stats for " << PlayerArr[i].Get_playerName() << " [" << PlayerArr[i].Get_jerseyNum() << "]" << std::endl;
		std::cout << "3 Pointers (made attempted) ";
		std::cin >> md_3 >> att_3;
		std::cout << "2 Pointers (made attempted) ";
		std::cin >> md_2 >> att_2;
		std::cout << "FreeThrows (made attempted) ";
		std::cin >> md_ft >> att_ft;
	
		pt_3.Set_numPoints(md_3);
		pt_3.Set_numAttempts(att_3);
		pt_2.Set_numPoints(md_2);
		pt_2.Set_numAttempts(att_2);
		pt_ft.Set_numPoints(md_ft);
		pt_ft.Set_numAttempts(att_ft);

		PlayerArr[i].addGame(pt_3, pt_2, pt_ft);
	}

}

//----------SEARCH------------
int Team::searchPlayer() {
	int usrin_jerseyNUm;
	int temp;

	std::cout << "Enter the jersey number to search for: ";
	std::cin >> usrin_jerseyNUm;

	for (int i = 0; i < NumPlayers; i++) {
		if (PlayerArr[i].Get_jerseyNum() == usrin_jerseyNUm) {
			return i;
		}
	}
	return not_found;
	
}

//-------------DISPLAY-----------------
void Team::displayPlayer() {
	int index_temp = searchPlayer();

	if (index_temp == not_found) {
		std::cout << "Player not found. " << std::endl;
	}
	else {
		PlayerArr[index_temp].print();
	}
}

//---------------REMOVE PLAYER----------
void Team::removePlayer() {
	int index_temp = searchPlayer();

	if (index_temp == not_found) {
		std::cout << "Player not found. " << std::endl;
	}
	else {
		Player rem = PlayerArr[index_temp];
		NumPlayers--;
		for (int i = index_temp; i < NumPlayers; i++) {
			PlayerArr[i] = PlayerArr[i + 1];
		}
	}
}

//------SORT BY NAME----------
void Team::sortByName() {
	//std::cout << NumPlayers << std::endl;

	for (int i = 0; i < NumPlayers - 1 ; i++) {
		for (int j =i ; j < NumPlayers; j++) {
			if (PlayerArr[j].Get_playerName() < PlayerArr[i].Get_playerName()) {
				Player temp = PlayerArr[i];
				PlayerArr[i] = PlayerArr[j];
				PlayerArr[j] = temp;
			}
		}
	}
}

//---------SORT BY JERSEY NUMBER-------------
void Team::sortByJersey() {
	
	for (int i = 0; i < NumPlayers - 1; i++) {
		for (int j = i + 1; j < NumPlayers; j++) {
			if (PlayerArr[j].Get_jerseyNum() < PlayerArr[i].Get_jerseyNum()) {
				Player temp = PlayerArr[i];
				PlayerArr[i] = PlayerArr[j];
				PlayerArr[j] = temp;
			}
		}
	}

}

//--------------"WRITE" TO WRITE THE DATA TO THE OUPTUT FILE-------------
void Team::write() {
	
	std::ofstream g;

	g.open("bbalout.txt");

	g << NumPlayers << " " << NumGames << std::endl;
	for (int i = 0; i < NumPlayers; i++) {
		g << PlayerArr[i].Get_jerseyNum() << " " << PlayerArr[i].Get_playerName() << std::endl;
		for (int j = 0; j < NumGames; j++) {
			Statistic point3, point2, pointft;
			point3 = PlayerArr[i].Get_num3points(j);
			point2 = PlayerArr[i].Get_num2points(j);
			pointft = PlayerArr[i].Get_numFreeThrows(j);

			g << point3.Get_numPoints() << " " << point3.Get_numAttempt() << " "
				<< point2.Get_numPoints() << " " << point2.Get_numAttempt() << " "
				<< pointft.Get_numPoints() << " " << pointft.Get_numAttempt() << std::endl;
				
		}
		g << std::endl;
	}

	g.close();
}
