#ifndef ESTABLISHMENT_H
#define ESTABLISHMENT_H

#include <iostream>
#include <string>
using namespace std;

class Establishment {
public:
	Establishment();
	Establishment(string name, string color, string type, string effect, int activation, int range, int cost);
	Establishment(string name, string color, string type, string effect, int activation, int cost);
	string GetName();
	string GetColor();
	string GetType();
	string GetEffect();
	int GetActivation();
	int GetActivationRange();
	int GetCost();
	void SetName(string name);
	void SetColor(string color);
	void SetType(string type);
	void SetEffect(string effect);
	void SetActivation(int activation);
	void SetActivationRange(int range);
	void SetCost(int cost);
	void Print(int num);
private:
	string m_name;
	string m_color;
	string m_type;
	string m_effect;
	int m_activation;
	int m_activationRange;
	int m_cost;
};

#endif