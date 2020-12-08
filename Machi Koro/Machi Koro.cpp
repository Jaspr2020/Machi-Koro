// Machi Koro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Player.h"
#include "Establishment.h"
#include "Landmark.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

void generateDecks(vector<vector<Establishment>> &decks);
void fillMarkets(vector<vector<Establishment>> &decks, vector<Establishment> &m1, vector<int> &m1Sizes, vector<Establishment> &m2, vector<int> &m2Sizes, vector<Establishment> &m3, vector<int> &m3Sizes);
void addEstablishment(Establishment establishment, vector<Establishment> &market, vector<int> &marketAmounts);
void getPlayers(int &numPlayers, vector<Player> &players);
void turnOrder(Player &turn, vector<Player> &players, int numPlayers);
void takeTurn(Player &player, vector<Player> &players);
int rollingPhase(int numRolls);
void incomePhase(int roll, Player &player, vector<Player> &players);
int activateEstablishment(Establishment establishment, Player &player, Player &roller, int numTimes, int shoppingMallBonus);
int uniqueEntries(vector<Establishment> cards);
void printMarket(vector<Establishment> market, vector<int> amounts);
void activateReds(int roll, Player &player, vector<Player> &players);
void activateGreens(int roll, Player &player);
void activateBlues(int roll, Player &player, vector<Player> &players);
void activatePurples(int roll, Player &player);
void giveCoins(Player &player, int numCoins);
void giveCoins(Player &playerRecieving, Player &playerGiving, int numCoins);
int FUCKYOU();

int main()
{
	srand(time(NULL));

	//Before gameplay
	vector<Establishment> oneToSix;
	vector<Establishment> sevenAndUp;
	vector<Establishment> majorEstablishments;
	vector<vector<Establishment>> allDecks = { oneToSix, sevenAndUp, majorEstablishments };
	//During gameplay
	int numPlayers;
	vector<Player> players;
	Player turn;
	vector<Establishment> oneToSixMarket;
	vector<int> oneToSixAmounts;
	vector<Establishment> sevenAndUpMarket;
	vector<int> sevenAndUpAmounts;
	vector<Establishment> majorEstablishmentsMarket;
	vector<int> majorEstablishmentsAmounts;

	generateDecks(allDecks);
	fillMarkets(allDecks, oneToSixMarket, oneToSixAmounts, sevenAndUpMarket, sevenAndUpAmounts, majorEstablishmentsMarket, majorEstablishmentsAmounts);

	getPlayers(numPlayers, players);
	turnOrder(turn, players, numPlayers);

	cout << endl;
	takeTurn(turn, players);

	//for (unsigned int i = 0; i < oneToSixMarket.size(); i++) {
	//	oneToSixMarket.at(i).Print(oneToSixAmounts.at(i));
	//}

	//Player p1("Jacob");
	////p1.PrintLandMarks();

	//vector <Establishment> cards = generateDecks();
	//for (unsigned int i = 0; i < cards.size(); i++) {
	//	cards.at(i).Print();
	//}
}

void generateDecks(vector<vector<Establishment>> &decks)
{
	vector<Establishment> allCards;
	decks.at(0).clear();
	decks.at(1).clear();
	decks.at(2).clear();

	for (int i = 0; i < 6; i++) {
		allCards.push_back(Establishment("Wheat Field", "Blue", "Wheat", "You get 1 coin from the bank, on anyone's turn.", 1, 1));
		allCards.push_back(Establishment("Ranch", "Blue", "Cow", "Get one coin from the bank on anyone's turn.", 2, 1));
		allCards.push_back(Establishment("Flower Orchard", "Blue", "Wheat", "You get 1 coin from the bank, on anyone's turn.", 4, 2));
		allCards.push_back(Establishment("Forest", "Blue", "Gear", "Get 1 coin from the bank, on anyone's turn.", 5, 3));
		allCards.push_back(Establishment("Mackerel Boat", "Blue", "Boat", "If you have a Harbor, get 3 coins from the bank on anyone's turn.", 8, 2));
		allCards.push_back(Establishment("Apple Orchard", "Blue", "Wheat", "Get 3 coins from the bank, on anyone's turn.", 10, 3));
		allCards.push_back(Establishment("Tuna Boat", "Blue", "Boat", "On anyone's Turn: The current player rolls 2 dice. If you have a harbor you get as many coins as the dice total.", 12, 2, 5));
		allCards.push_back(Establishment("General Store", "Green", "Bread", "If you have less than 2 constructed landmarks, get 2 coins from the bank, on your turn only.", 2, 0));
		allCards.push_back(Establishment("Bakery", "Green", "Bread", "Get 1 coin from the bank, on your turn only.", 2, 1, 1));
		allCards.push_back(Establishment("Demolition Company", "Green", "Suitcase", "If possible, you must demolish one of your constructed landmarks by turning it back over to its unconstructed side. When you do get 8 coins from the bank, on your turn only.", 4, 2));
		allCards.push_back(Establishment("Flower Shop", "Green", "Bread", "Get 1 coin from the bank for each Flower Garden you own. (your turn only)", 6, 1));
		allCards.push_back(Establishment("Cheese Factory", "Green", "Factory", "Get 3 coins from the bank for each (Cow) establishment that you own, on your turn only.", 7, 5));
		allCards.push_back(Establishment("Furniture Factory", "Green", "Factory", "Get 3 coins from the bank for each (Gear) establishment that you own, on your turn only.", 8, 3));
		allCards.push_back(Establishment("Moving Company", "Green", "Suitcase", "You must give a non-(Major) building that you own to another player. When you do, get 4 coins from the bank, on your turn only.", 9, 1, 2));
		allCards.push_back(Establishment("Soda Bottling Plant", "Green", "Factory", "Get 1 coin from the bank for every (Cup) owned by all players, on your turn only.", 11, 5));
		allCards.push_back(Establishment("Fruit and Vegetable Market", "Green", "Fruit", "Get 2 coins from the bank for each (Wheat) establishment that you own, on your turn only.", 11, 1, 2));
		allCards.push_back(Establishment("Sushi Bar", "Red", "Cup", "If you have a harbor, you get 3 coins from the player who rolled the dice.", 1, 2));
		allCards.push_back(Establishment("Café", "Red", "Cup", "Get 1 coin from the player who rolled the dice.", 3, 2));
		allCards.push_back(Establishment("French Restaurant", "Red", "Cup", "If the player who rolled this number has 2 or more constructed landmarks, get 5 coins from the player who rolled the dice.", 5, 3));
		allCards.push_back(Establishment("Pizza Joint", "Red", "Cup", "Get 1 coin from the player who rolled the dice.", 7, 1));
		allCards.push_back(Establishment("Family Restaurant", "Red", "Cup", "Get 2 coins from the player who rolled the dice.", 9, 1, 3));
		allCards.push_back(Establishment("Member's Only Club", "Red", "Cup", "If the player who rolled this number has 3 or more constructed landmarks, get all of their coins.", 12, 2, 4));
	}
	for (int i = 0; i < 5; i++) {
		allCards.push_back(Establishment("Stadium", "Purple", "Major", "Get 2 coins from all players, on your turn only.", 6, 6));
		allCards.push_back(Establishment("Publisher", "Purple", "Major", "Take 1 coin from each opponent for each (Cup) and (Bread) establishment they own. (your turn only)", 7, 5));
		allCards.push_back(Establishment("Tax Office", "Purple", "Major", "From each opponent, who has 10+ coins, take half of their coins, rounded down. (your turn only)", 8, 1, 4));
		allCards.push_back(Establishment("Business Center", "Purple", "Major", "Trade One Non (Major) establishment with another player, on your turn only.", 6, 8));
		allCards.push_back(Establishment("Tech Startup", "Purple", "Major", "At the end of each of your turns, you may place 1 coin on this card. The total placed here is your investment. When activated, get an amount equal to your investment from all player, on your turn only.", 10, 1));
	}

	for (vector<Establishment>::iterator it = allCards.begin(); it != allCards.end(); it++) {
		if ((*it).GetColor() == "Purple") {
			decks.at(2).push_back(*it);
			allCards.erase(it--);
		}
	}

	for (vector<Establishment>::iterator it = allCards.begin(); it != allCards.end(); it++) {
		if ((*it).GetActivation() >= 7) {
			decks.at(1).push_back(*it);
			allCards.erase(it--);
		}
	}

	decks.at(0) = allCards;

	random_shuffle(decks.at(2).begin(), decks.at(2).end());
	random_shuffle(decks.at(1).begin(), decks.at(1).end());
	random_shuffle(decks.at(0).begin(), decks.at(0).end());

}

void fillMarkets(vector<vector<Establishment>> &decks, vector<Establishment> &m1, vector<int> &m1Sizes, vector<Establishment> &m2, vector<int> &m2Sizes, vector<Establishment> &m3, vector<int> &m3Sizes)
{
	//Until each market has the correct number of unique cards or the deck is empty
	//1. Pick a random number from 0 to the number of cards left in the deck
	//2. Create a copy of the establishment at that spot
	//3. Erase that establishment from the total array
	//4. Add the copy to the market

	while (m1.size() < 5 && decks.at(0).size() > 0) {
		int ran = rand() % decks.at(0).size();
		Establishment temp = decks.at(0).at(ran);
		decks.at(0).erase(decks.at(0).begin() + ran);
		addEstablishment(temp, m1, m1Sizes);
		//m1.push_back(temp);
	}
	while (m2.size() < 5 && decks.at(1).size() > 0) {
		int ran = rand() % decks.at(1).size();
		Establishment temp = decks.at(1).at(ran);
		decks.at(1).erase(decks.at(1).begin() + ran);
		addEstablishment(temp, m2, m2Sizes);
		//m2.push_back(temp);
	}
	while (m3.size() < 2 && decks.at(2).size() > 0) {
		int ran = rand() % decks.at(2).size();
		Establishment temp = decks.at(2).at(ran);
		decks.at(2).erase(decks.at(2).begin() + ran);
		addEstablishment(temp, m3, m3Sizes);
		//m3.push_back(temp);
	}
}

void addEstablishment(Establishment establishment, vector<Establishment> &market, vector<int> &marketAmounts)
{
	unsigned int i;
	for (i = 0; i < market.size(); i++) {
		if (market.at(i).GetName() == establishment.GetName()) {
			break;
		}
	}
	if (i == market.size()) {
		market.push_back(establishment);
		marketAmounts.push_back(1);
	}
	else {
		marketAmounts.at(i)++;
	}
}

void getPlayers(int &numPlayers, vector<Player> &players) {
	cout << "How many people are playing?" << endl;
	cin >> numPlayers;
	while (cin.fail() || numPlayers < 2 || numPlayers > 5) {
		cout << "Please enter a valid number." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> numPlayers;
	}

	cout << endl << "What are the player's names?" << endl;
	for (int i = 0; i < numPlayers; i++) {
		cout << "Player " << i + 1 << ": ";
		string name = "";
		if (cin.peek() == '\n') cin.ignore();
		getline(cin, name);
		players.push_back(Player(name));
	}
}

void turnOrder(Player &turn, vector<Player> &players, int numPlayers) {
	string whoGoesFirst = "";
	do {
		cout << endl << "Who would you like to go first?" << endl;
		cout << "1) The game picks for us." << endl;
		cout << "2) We can pick." << endl;

		getline(cin, whoGoesFirst);
	} while (whoGoesFirst != "1" && whoGoesFirst != "2");

	if (whoGoesFirst == "1") {
		turn = players.at(rand() % numPlayers);
		cout << endl << turn.GetName() << " is going first!" << endl;
	}
	else if (whoGoesFirst == "2") {
		cout << endl << "Who would you like to go first?" << endl;
		do {
			string goesFirst = "";
			if (cin.peek() == '\n') cin.ignore();
			getline(cin, goesFirst);

			for (unsigned int i = 0; i < players.size(); i++) {
				if (players.at(i).GetName() == goesFirst) {
					turn = players.at(i);
				}
			}
			if (turn.GetName() == "Default") {
				cout << "Please enter a valid player name." << endl;
			}
		} while (turn.GetName() == "Default");
	}
}

void takeTurn(Player &player, vector<Player> &players)
{
	int numRolls = 1;
	int diceRoll = 0;

	cout << player.GetName() << "'s Turn!" << endl;

	cout << endl << "Dice rolling phase:" << endl;
	//TODO: Check if they can roll multiple dice
	diceRoll = rollingPhase(numRolls);
	cout << "Your total is: " << diceRoll << endl;

	cout << endl << "Income phase: " << endl;
	incomePhase(2, player, players);
}

int rollingPhase(int numRolls)
{
	vector<int> diceRolls;
	int diceTotal = 0;

	//Randomize the rolls and tell the user what they rolled
	cout << "You rolled: ";
	for (int i = 0; i < numRolls; i++) {
		diceRolls.push_back(rand() % 6 + 1);
		cout << diceRolls.at(i) << ((i < numRolls - 1) ? ", " : " ");
		diceTotal += diceRolls.at(i);
	}
	//Return the total when 1 or 2 dice were rolled
	if (numRolls == 1 || numRolls == 2) {
		cout << endl;
		return diceTotal;
	}
	else {
		//When the player rolls 3 dice and drops one
		while (true) {
			//Promp the user for a roll they want to drop until they answer in a propper format
			int dropValue;
			cout << endl << "Which value would you like to drop: ";
			cin >> dropValue;
			while (cin.fail() || dropValue < 1 || dropValue > 6) {
				cout << "Please enter a valid roll." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> dropValue;
			}
			//Checks to see if the provided roll was actuall rolled
			for (unsigned int i = 0; i < diceRolls.size(); i++) {
				//If the provided roll was a real roll
				if (diceRolls.at(i) == dropValue) {
					//Remove the roll and tell the user their new rolls
					cout << "You rolled: ";
					diceRolls.erase(diceRolls.begin() + i);
					for (unsigned int i = 0; i < diceRolls.size(); i++) {
						cout << diceRolls.at(i) << ((i < diceRolls.size() - 1) ? ", " : " ");
					}
					//Return the old total minus the dropped value
					cout << endl;
					return diceTotal - dropValue;
				}
			}
			//Let the user know that their number was invalid and start over
			cout << "That number was not rolled.";
		}
	}
}

void incomePhase(int roll, Player &player, vector<Player> &players)
{
	activateReds(roll, player, players);
	activateGreens(roll, player);
	activateBlues(roll, player, players);
	activatePurples(roll, player);
}

int activateEstablishment(Establishment establishment, Player &player, Player &roller, int numTimes, int shoppingMallBonus)
{
	if (numTimes == 1) {
		cout << player.GetName() << "'s " << establishment.GetName() << " activated!" << endl;
	}
	else if (numTimes == 2) {
		cout << "Both of " << player.GetName() << "'s " << establishment.GetName() << "s activated!" << endl;
	}
	else {
		cout << player.GetName() << "'s " << numTimes << " " << establishment.GetName() << "s activated!" << endl;
	}

	if (shoppingMallBonus == 1) {
		cout << "Your harbor is active, +1 coin for each instance of the card." << endl;
	}

	establishment.Print(numTimes);

	if (establishment.GetColor() == "Blue") {
		if (establishment.GetName() == "Wheat Field" || establishment.GetName() == "Ranch" || establishment.GetName() == "Flower Orchard" || establishment.GetName() == "Forest") {
			//These cards all have the same effect
			return 1;
		}
		else if (establishment.GetName() == "Mackerel Boat") {
			bool hasHarbor = player.GetLandmarks().at(1).GetConstructed();
			if (hasHarbor) {
				return 3;
			}
			else {
				cout << "But " << player.GetName() << " does not have a Harbor." << endl;
				return -1;
			}
		}
		else if (establishment.GetName() == "Apple Orchard") {
			return 3;
		}
		else if (establishment.GetName() == "Tuna Boat") {
			cout << roller.GetName() << " has to roll 2 dice." << endl;
			cout << roller.GetName() << " rolled: ";
			int diceTotal = 0;
			for (int i = 0; i < 2; i++) {
				int roll = rand() % 6 + 1;
				cout << roll << ((i < 1) ? ", " : " ");
				diceTotal += roll;
			}
			cout << endl;
			return diceTotal;
		}
	}
	else if (establishment.GetColor() == "Green") {
		if (establishment.GetName() == "General Store") {
			int count = -1;
			for (int i = 0; i < player.GetLandmarks().size(); i++) {
				if (player.GetLandmarks().at(i).GetConstructed()) {
					count++;
				}
			}
			if (count < 2) {
				return 2;
			}
			else {
				cout << "But you have more than 2 landmarks constructed." << endl;
				return -1;
			}
		}
		else if (establishment.GetName() == "Bakery") {
			return 1;
		}
		else if (establishment.GetName() == "Demolition Company") {
			int count = -1;
			for (int i = 0; i < player.GetLandmarks().size(); i++) {
				if (player.GetLandmarks().at(i).GetConstructed()) {
					count++;
				}
			}
			if (count >= 1) {
				if (numTimes > count) {
					cout << "You only have " << count << " landmarks constructed. Demolition Company only activates " << count << ((count == 1) ? " time." : " times.") << endl;
					numTimes = count;
				}
				for (int i = 0; i < numTimes; i++) {
					string lm = "";
					do {
						cout << "Which landmark would you like to destroy? ";
						for (int j = 0; j < player.GetLandmarks().size(); j++) {
							if (player.GetLandmarks().at(j).GetConstructed() && player.GetLandmarks().at(j).GetName() != "City Hall") {
								cout << "(" << player.GetLandmarks().at(j).GetName() << ") ";
							}
						}
						cout << endl;
						getline(cin, lm);
					} while (lm != "Harbor" && lm != "Train Station" && lm != "Shopping Mall" && lm != "Amusement Park" && lm != "Moon Tower" && lm != "Airport");

					bool wasConstructed = false;
					for (int j = 0; j < player.GetLandmarks().size(); j++) {
						if (player.GetLandmarks().at(j).GetName() == lm) {
							cout << lm << endl;
							wasConstructed = player.GetLandmarks().at(j).GetConstructed();
							player.ChangeLandmarkStatus(lm, false);
						}
					}
					if (!wasConstructed) {
						cout << "That landmark is not constructed, select another." << endl;
						i--;
					}
				}
				return 8;
			}
			else {
				cout << "But you do not have any landmarks constructed." << endl;
			}
		}
		else if (establishment.GetName() == "Flower Shop") {
			int numFlowerGardens = 0;
			unsigned int i = 0;
			for (i = 0; i < player.GetEstablishments().size(); i++) {
				if (player.GetEstablishments().at(i).GetName() == "Flower Orchard") {
					break;
				}
			}
			if (i < player.GetEstablishments().size()) {
				numFlowerGardens = player.GetEstablishmentNums().at(i);
			}
			if (numFlowerGardens == 0) {
				cout << "You have no Flower Orchards." << endl;
			}
			else if (numFlowerGardens == 1) {
				cout << "You have one Flower Orchard." << endl;
			}
			else {
				cout << "You have " << numFlowerGardens << " Flower Orchards." << endl;
			}
			return numFlowerGardens;
		}
		else if (establishment.GetName() == "Cheese Factory") {
			int numCows = 0;
			for (int i = 0; i < player.GetEstablishments().size(); i++) {
				if (player.GetEstablishments().at(i).GetType() == "Cow") numCows += player.GetEstablishmentNums().at(i);
			}
			if (numCows == 0) {
				cout << "You have no Cow establishments." << endl;
			}
			else if (numCows == 1) {
				cout << "You have one Cow establishment." << endl;
			}
			else {
				cout << "You have " << numCows << " Cow establishments." << endl;
			}
			return numCows;
		}
		else if (establishment.GetName() == "Furniture Factory") {
			int numGears = 0;
			for (int i = 0; i < player.GetEstablishments().size(); i++) {
				if (player.GetEstablishments().at(i).GetType() == "Cow") numGears += player.GetEstablishmentNums().at(i);
			}
			if (numGears == 0) {
				cout << "You have no Gear establishments." << endl;
			}
			else if (numGears == 1) {
				cout << "You have one Gear establishment." << endl;
			}
			else {
				cout << "You have " << numGears << " Gear establishments." << endl;
			}
			return numGears;
		}
		else if (establishment.GetName() == "Moving Company") {

		}
		else if (establishment.GetName() == "Soda Bottling Plant") {

		}
		else if (establishment.GetName() == "Fruit and Vegetable Market") {

		}
	}
	else if (establishment.GetColor() == "Red") {
		if (establishment.GetName() == "Sushi Bar") {

		}
		else if (establishment.GetName() == "Café") {

		}
		else if (establishment.GetName() == "French Restaurant") {

		}
		else if (establishment.GetName() == "Pizza Joint") {

		}
		else if (establishment.GetName() == "Family Restaurant") {

		}
		else if (establishment.GetName() == "Member's Only Club") {

		}
	}
	else if (establishment.GetColor() == "Purple") {
		if (establishment.GetName() == "Stadium") {

		}
		else if (establishment.GetName() == "Publisher") {

		}
		else if (establishment.GetName() == "Tax Office") {

		}
		else if (establishment.GetName() == "Business Center") {

		}
		else if (establishment.GetName() == "Tech Startup") {

		}
	}
}

int uniqueEntries(vector<Establishment> cards) {
	int numUnique = 1;
	
	//Loop through the vector
	for (unsigned int i = 1; i < cards.size(); i++) {
		//Loop through all of the previous cards
		unsigned int j;
		for (j = 0; j < i; j++) {
			//If the card matched some other card, exit early
			if (cards.at(i).GetName() == cards.at(j).GetName()) {
				break;
			}
		}
		//If the second loop made it back to the original spot (aka no repeats)
		if (i == j) {
			numUnique++;
		}
	}
	return numUnique;
}

void printMarket(vector<Establishment> market, vector<int> amounts)
{
	for (unsigned int i = 0; i < market.size(); i++) {
		market.at(i).Print(amounts.at(i));
	}
}

void activateReds(int roll, Player &player, vector<Player> &players) {
	//Red card phase (looping through all establishments of all players)
	for (unsigned int i = 0; i < players.size(); i++) {
		for (unsigned int j = 0; j < players.at(i).GetEstablishments().size(); j++) {
			Establishment curr = players.at(i).GetEstablishments().at(j);
			int numCurr = players.at(i).GetEstablishmentNums().at(j);
			if (curr.GetColor() == "Red") {
				if (roll >= curr.GetActivation() && roll <= curr.GetActivation() + curr.GetActivationRange()) {
					int shoppingMallBonus = 0;
					if (player.GetLandmarks().at(3).GetConstructed() && (curr.GetType() == "Cup" || curr.GetType() == "Bread")) {
						shoppingMallBonus = 1;
					}
					int numCoins = -1;
					numCoins = activateEstablishment(curr, players.at(i), player, numCurr, shoppingMallBonus);
					if (numCoins != -1) {
						giveCoins(player, (1 + shoppingMallBonus) * numCurr);
					}
				}
			}
		}
	}
}

void activateGreens(int roll, Player &player) {
	//Green card phase (looping through all establishments of current player)
	for (unsigned int i = 0; i < player.GetEstablishments().size(); i++) {
		Establishment curr = player.GetEstablishments().at(i);
		int numCurr = player.GetEstablishmentNums().at(i);
		if (curr.GetColor() == "Green") {
			if (roll >= curr.GetActivation() && roll <= curr.GetActivation() + curr.GetActivationRange()) {
				int shoppingMallBonus = 0;
				if (player.GetLandmarks().at(3).GetConstructed() && (curr.GetType() == "Cup" || curr.GetType() == "Bread")) {
					shoppingMallBonus = 1;
				}
				int numCoins = -1;
				numCoins = activateEstablishment(curr, player, player, numCurr, shoppingMallBonus);
				if (numCoins != -1) {
					giveCoins(player, (1 + shoppingMallBonus) * numCurr);
				}
			}
		}
	}
}

void activateBlues(int roll, Player &player, vector<Player> &players) {
	//Blue card phase (looping through all establishments of all players)
	for (unsigned int i = 0; i < players.size(); i++) {
		for (unsigned int j = 0; j < players.at(i).GetEstablishments().size(); j++) {
			Establishment curr = players.at(i).GetEstablishments().at(j);
			int numCurr = players.at(i).GetEstablishmentNums().at(j);
			if (curr.GetColor() == "Blue") {
				if (roll >= curr.GetActivation() && roll <= curr.GetActivation() + curr.GetActivationRange()) {
					int shoppingMallBonus = 0;
					if (player.GetLandmarks().at(3).GetConstructed() && (curr.GetType() == "Cup" || curr.GetType() == "Bread")) {
						shoppingMallBonus = 1;
					}
					int numCoins = -1;
					numCoins = activateEstablishment(curr, players.at(i), player, numCurr, shoppingMallBonus);
					if (numCoins != -1) {
						giveCoins(player, (1 + shoppingMallBonus) * numCurr);
					}
				}
			}
		}
	}
}

void activatePurples(int roll, Player &player) {
	//Purple card phase (looping through all establishments of current player)
	for (unsigned int i = 0; i < player.GetEstablishments().size(); i++) {
		Establishment curr = player.GetEstablishments().at(i);
		int numCurr = player.GetEstablishmentNums().at(i);
		if (curr.GetColor() == "Purple") {
			if (roll >= curr.GetActivation() && roll <= curr.GetActivation() + curr.GetActivationRange()) {
				int shoppingMallBonus = 0;
				if (player.GetLandmarks().at(3).GetConstructed() && (curr.GetType() == "Cup" || curr.GetType() == "Bread")) {
					shoppingMallBonus = 1;
				}
				int numCoins = -1;
				numCoins = activateEstablishment(curr, player, player, numCurr, shoppingMallBonus);
				if (numCoins != -1) {
					giveCoins(player, (1 + shoppingMallBonus) * numCurr);
				}
			}
		}
	}
}

void giveCoins(Player &player, int numCoins)
{
	player.SetCoins(player.GetCoins() + numCoins);
	cout << player.GetName() << " recieved " << numCoins << ((numCoins == 1)? " coin" : " coins from the bank.") << endl;
}

void giveCoins(Player &playerRecieving, Player &playerGiving, int numCoins)
{
	int taken = playerGiving.GetCoins() - numCoins;
	playerGiving.SetCoins(playerGiving.GetCoins() - taken);

	playerRecieving.SetCoins(playerRecieving.GetCoins() + taken);
	cout << playerRecieving.GetName() << " recieved " << numCoins << ((numCoins == 1) ? " coin " : " coins ") << "from " << playerGiving.GetName() << "." << endl;
}