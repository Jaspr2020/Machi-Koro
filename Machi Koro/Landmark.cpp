#include "Landmark.h"
#include <iostream>
#include <string>
using namespace std;

Landmark::Landmark() {
	m_name = "Default";
	m_effect = "Default";
	m_constructed = false;
	m_cost = 0;
}

Landmark::Landmark(string name, string effect, bool constructed, int cost) {
	m_name = name;
	m_effect = effect;
	m_constructed = constructed;
	m_cost = cost;
}

string Landmark::GetName() {
	return m_name;
}

string Landmark::GetEffect() {
	return m_effect;
}

bool Landmark::GetConstructed() {
	return m_constructed;
}

int Landmark::GetCost() {
	return m_cost;
}

void Landmark::SetName(string name) {
	m_name = name;
}

void Landmark::SetEffect(string effect) {
	m_effect = effect;
}

void Landmark::SetConstructed(bool constructed) {
	m_constructed = constructed;
}

void Landmark::SetCost(int cost) {
	m_cost = cost;
}

void Landmark::Print() {
	cout << "---------------------------------" << endl;
	cout << "| " << GetName() << endl;
	cout << "| " << (GetConstructed() ? "Constructed " : "Not Constructed ") << endl;
	if (!GetConstructed()) cout << "| Cost: " << GetCost() << endl;
	cout << "| Effect: " << GetEffect() << endl;
	cout << "---------------------------------" << endl;
}

ostream& operator<<(ostream& os, Landmark& lm) {
	os << "---------------------------------" << endl;
	os << "| " << lm.GetName() << endl;
	os << "| " << (lm.GetConstructed() ? "Constructed " : "Not Constructed ") << endl;
	if (!lm.GetConstructed()) cout << "| Cost: " << lm.GetCost() << endl;
	os << "| Effect: " << lm.GetEffect() << endl;
	os << "---------------------------------" << endl;
	return os;
}