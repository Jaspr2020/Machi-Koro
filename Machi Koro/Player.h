#ifndef PLAYER_H
#define PLAYER_H

#include "Establishment.h"
#include "Landmark.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
public:
	Player();
	Player(string name);
	string GetName();
	int GetCoins();
	vector<Establishment> GetEstablishments();
	vector<Landmark> GetLandmarks();
	vector<int> GetEstablishmentNums();
	void SetName(string name);
	void SetCoins(int numCoins);
	void FillLandmarks();
	void PrintLandmarks();
	void PrintEstablishments();
	void AddEstablishment(Establishment establishment);
	void ChangeLandmarkStatus(string name, bool value);
	void Print();
private:
	string m_name;
	int m_numCoins;
	vector <Establishment> m_establishments;
	vector <Landmark> m_landmarks;
	vector <int> m_numEstablishments;
};

#endif