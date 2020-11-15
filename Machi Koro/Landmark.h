#ifndef LANDMARK_H
#define LANDMARK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Landmark {
public:
	Landmark();
	Landmark(string name, string effect, bool constructed, int cost);
	string GetName();
	string GetEffect();
	bool GetConstructed();
	int GetCost();
	void SetName(string name);
	void SetEffect(string effect);
	void SetConstructed(bool constructed);
	void SetCost(int cost);
	void Print();
	friend ostream& operator<<(ostream& os, Landmark& lm);
private:
	string m_name;
	string m_effect;
	bool m_constructed;
	int m_cost;
};

#endif