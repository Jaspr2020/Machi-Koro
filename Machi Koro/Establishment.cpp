#include "Establishment.h"
#include <iostream>
#include <string>
using namespace std;

string colorDescription(string color);

Establishment::Establishment() {
	m_name = "Default";
	m_color = "Default";
	m_type = "Default";
	m_effect = "Default";
	m_activation = 0;
	m_cost = 0;
}

Establishment::Establishment(string name, string color, string type, string effect, int activation, int range, int cost)
{
	m_name = name;
	m_color = color;
	m_type = type;
	m_effect = effect;
	m_activation = activation;
	m_activationRange = range;
	m_cost = cost;
}

Establishment::Establishment(string name, string color, string type, string effect, int activation, int cost) {
	m_name = name;
	m_color = color;
	m_type = type;
	m_effect = effect;
	m_activation = activation;
	m_activationRange = 0;
	m_cost = cost;
}

string Establishment::GetName() {
	return m_name;
}

string Establishment::GetColor() {
	return m_color;
}

string Establishment::GetType() {
	return m_type;
}

string Establishment::GetEffect() {
	return m_effect;
}

int Establishment::GetActivation() {
	return m_activation;
}

int Establishment::GetActivationRange()
{
	return m_activationRange;
}

int Establishment::GetCost() {
	return m_cost;
}

void Establishment::SetName(string name) {
	m_name = name;
}

void Establishment::SetColor(string color) {
	m_color = color;
}

void Establishment::SetType(string type) {
	m_type = type;
}

void Establishment::SetEffect(string effect) {
	m_effect = effect;
}

void Establishment::SetActivation(int activation) {
	m_activation = activation;
}

void Establishment::SetActivationRange(int range)
{
	m_activationRange = range;
}

void Establishment::SetCost(int cost) {
	m_cost = cost;
}


void Establishment::Print(int num)
{
	//Holds the width of the card
	int lineLength = 40;
	
	//Create a string with a bar for the number of times this card is stacked
	string bars = "";
	for (int i = 0; i < num; i++)  bars += "|";

	//Create a string with '-' the number fo times as width of the card
	string border = "";
	for (int i = 0; i < lineLength; i++) border += "-";

	//Prints the top border and then each item before the description, with bars in front of each
	cout << border << endl;
	cout << bars << " " << GetName() << endl;
	if (GetActivationRange() > 0) cout << bars << " " << GetActivation() << "-" << GetActivation() + GetActivationRange() << endl;
	else cout << bars << " " << GetActivation() << endl;
	cout << bars << " " << GetColor() << " - " << colorDescription(GetColor()) << endl;
	cout << bars << " (" << GetType() << ")" << endl;

	//Print the effect and loop onto the next line if it is too long
	string effect = GetEffect();
	int i = 0;
	while (i < effect.length()) {
		//Print bars
		cout << bars << " ";
		//Print the line until the text goes beyond the end of the card
		for (int j = i; j < i + (lineLength - 2) - (num - 1) && j < effect.length(); j++) {
			if (j == i && effect[j] == ' ') {}
			else {
				//If it is the last character or it's not a space
				if (j == i + ((lineLength - 2) - 1) - (num - 1) && effect[j + 1] != ' ') {
					//If the next character is not a space
					if (effect[j - 1] != ' ' && /*effect[j] != ' ' &&*/ effect[j - 1] != ')' && effect[j + 1] != '\n') {
						//If the character before is not a space, a parenthesis and the next character is not a newline character, print out a dash
						cout << "-";
					}
					else {
						//Print a space
						cout << " ";
					}
					//Iterate back a character
					i--;
					break;
				}
				//Print the character
				cout << effect[j];
			}
		}
		cout << endl;
		i += (lineLength - 2) - (num - 1);
	}

	//Print the rest of the card
	cout << bars << " Cost: " << GetCost() << endl;
	cout << border << endl;
}

string colorDescription(string color) {
	if (color == "Blue") return "Primary Industry";
	else if (color == "Green") return "Secondary Industry";
	else if (color == "Red") return "Restaurant";
	else if (color == "Purple") return "Major Establishment";
}