#include "Player.h"
#include "Player.h"
#include "Player.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Player::Player() {
	SetName("Default");
	SetCoins(3);
	AddEstablishment(Establishment("Wheat Field", "Blue", "Wheat", "You get 1 coin from the bank, on anyone's turn.", 1, 1));
	AddEstablishment(Establishment("Bakery", "Green", "Bread", "Get 1 coin from the bank, on your turn only.", 2, 1, 1));
	FillLandmarks();
}

Player::Player(string name) {
	cout << m_name;
	SetName(name);
	SetCoins(3);
	AddEstablishment(Establishment("Wheat Field", "Blue", "Wheat", "You get 1 coin from the bank, on anyone's turn.", 1, 1));
	AddEstablishment(Establishment("Bakery", "Green", "Bread", "Get 1 coin from the bank, on your turn only.", 2, 1, 1));
	FillLandmarks();
}

string Player::GetName() {
	return m_name;
}

int Player::GetCoins() {
	return m_numCoins;
}

vector<Establishment> Player::GetEstablishments()
{
	return m_establishments;
}

vector<Landmark> Player::GetLandmarks()
{
	return m_landmarks;
}

vector<int> Player::GetEstablishmentNums()
{
	return m_numEstablishments;
}

void Player::SetName(string name) {
	m_name = name;
}

void Player::SetCoins(int numCoins) {
	m_numCoins = numCoins;
}

void Player::FillLandmarks() {
	m_landmarks.push_back(Landmark("City Hall", "Immediately before buying establishments, if you have 0 coins, get 1 from the bank.", true, 0));
	m_landmarks.push_back(Landmark("Harbor", "If the dice total is 10 or more, you may add 2 to the total, on your turn only.", false, 2));
	m_landmarks.push_back(Landmark("Train Station", "You may roll 1 or 2 dice.", false, 4));
	m_landmarks.push_back(Landmark("Shopping Mall", "Recieve 1 more coin from each of your (Cup) and (Bread) Establishments", false, 10));
	m_landmarks.push_back(Landmark("Amusement Park", "If you roll doubles, take another turn after this one.", false, 16));
	m_landmarks.push_back(Landmark("Moon Tower", "You may roll 3 dice on your turn. If you do, then remove one of the dice after rolling, and only count the remaining two.", false, 22));
	m_landmarks.push_back(Landmark("Airport", "If you build nothing on your turn, you get 10 coins from the bank.", false, 30));
}

void Player::PrintLandmarks()
{
	for (unsigned int i = 0; i < GetLandmarks().size(); i++) {
		GetLandmarks().at(i).Print();
	}
}

void Player::PrintEstablishments()
{
	for (unsigned int i = 0; i < GetEstablishments().size(); i++) {
		GetEstablishments().at(i).Print(m_numEstablishments.at(i));
	}
}

void Player::AddEstablishment(Establishment establishment)
{
	unsigned int i;
	for (i = 0; i < m_establishments.size(); i++) {
		if (m_establishments.at(i).GetName() == establishment.GetName()) {
			break;
		}
	}
	if (i == m_establishments.size()) {
		m_establishments.push_back(establishment);
		m_numEstablishments.push_back(1);
	}
	else {
		m_numEstablishments.at(i)++;
	}
}

void Player::ChangeLandmarkStatus(string name, bool value)
{
	for (int i = 0; i < m_landmarks.size(); i++) {
		if (m_landmarks.at(i).GetName() == name) {
			m_landmarks.at(i).SetConstructed(value);
		}
	}
}

void Player::Print()
{
	cout << GetName() << endl;
	cout << "Coins: " << GetCoins() << endl;
	cout << "Establishments: " << endl;
	for (unsigned int i = 0; i < GetEstablishments().size(); i++) {
		GetEstablishments().at(i).Print(m_numEstablishments.at(i));
	}
	cout << "Constructed Landmarks: " << endl;
	for (unsigned int i = 0; i < GetLandmarks().size(); i++) {
		if (GetLandmarks().at(i).GetConstructed()) {
			GetLandmarks().at(i).Print();
		}
	}
}
