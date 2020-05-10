#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <array>
#include <string>
#include <sstream>


//#include <openssl/sha.h>
//#include <openssl/md5.h>
//#include <Wincrypt.h>
using namespace std;

string encodingStrings(int key, string name);
char encodingChars(int key, char character);
int encodingInts(int key, int value);
double encodingDoubles(int key, double var);
void encodingDoubleArray(int key, double doublearray[], double newArray[]);
void encoder(double XP, int doubloons, string characterName, string villainName, char combatRating, char npcStanding, int numOfLives, double distanceTraveled, int enemiesSlain, double enc_Arr[]);
void writeDefaults(double enc_Arr[]);
string readDefaults();
bool valueChecker(double newDouble, int newInt, char newChar);

string masterString = "";
stringstream ss;
double enc_XP;
double enc_doubloons;
string enc_charName;
string enc_Villain;
char enc_combatRating;
char enc_npcStanding;
int enc_numOfLives;
double enc_distance;
int enc_slain;

int main()
{
	double levelComplete[10] = { 90.9, 23.2, 45.2, 100, 56.3, 0, 65.5, 0, 10.7, 32.4 };
	double enc_Arr[10];
	double XP = 32.7;
	int doubloons = 7001;
	string characterName = "LEROY JENKINS";
	string villainName = "THANOS";
	char combatRating = 'B';
	char npcStanding = 'F';
	int numOfLives = 2;
	double distanceTraveled = 356.98;
	int enemiesSlain = 1500;

	cout << "Would you like to store the default values in a file?" << endl << "w to write to defaults.txt" << endl;
	string write;
	cin >> write;

	if (write == "W" || write == "w") {
		encodingDoubleArray(5672, levelComplete, enc_Arr);
		encoder(XP, doubloons, characterName, villainName, combatRating, npcStanding, numOfLives, distanceTraveled, enemiesSlain, enc_Arr);
		writeDefaults(enc_Arr);
		cout << "You can now close the program and try editing defaults.txt" << endl;
	}

	cout << "Levels Completeness: " << endl;
	encodingDoubleArray(5672, levelComplete, enc_Arr);
	encoder(XP, doubloons, characterName, villainName, combatRating, npcStanding, numOfLives, distanceTraveled, enemiesSlain, enc_Arr);

	cout << "Would you like to change some values in the program?" << endl << "y to change values" << endl;
	string input;
	cin >> input;

	if (input == "y" || input == "Y") {
		XP = 9999.99;
		cout << "\nChanged XP: " << XP << endl;
		doubloons = 99999;
		cout << "Changed doubloons: " << doubloons << endl;
		combatRating = 'S';
		cout << "Changed combatRating: " << combatRating << endl;
		if (valueChecker(XP, doubloons, combatRating)) {
			cout << "\nThe values have been changed and must be reset to default!" << endl;
			XP = encodingDoubles(5672, enc_XP);
			doubloons = encodingInts(5672, enc_doubloons);
			combatRating = encodingChars(13, enc_combatRating);
			cout << "The values have been reset to default: " << endl;
			cout << "\nDefault XP: " << XP << endl;
			cout << "Default Doubloons: " << doubloons << endl;
			cout << "Default Combat Rating: " << combatRating << endl;
		}
		writeDefaults(enc_Arr);
		cout << "masterString: " << masterString << endl;

	}
	string checker;
	checker = readDefaults();
	if (checker == masterString) {
		cout << "The file has not been altered! " << endl;
	}
	else {
		cout << "The file has been altered! defaults.txt will now be overwritten:  " << endl;
		writeDefaults(enc_Arr);
	}
	cout << "checker: " << checker << endl;

}

void writeDefaults(double enc_Arr[]) {//, double levelComplete[], double XP, int doubloons, string characterName, string villainName, char combatRating, char npcStanding, int numOfLives, double distanceTraveled, int enemiesSlain) {
	ofstream defaults;
	defaults.open("defaults.txt");

	for (int i = 0; i < 10; i++)
	{
		defaults << enc_Arr[i] << " ";
	}
	defaults << endl;
	defaults << enc_XP << endl;

	defaults << enc_doubloons << endl;

	defaults << enc_charName << endl;

	defaults << enc_Villain << endl;

	defaults << enc_combatRating << endl;

	defaults << enc_npcStanding << endl;

	defaults << enc_numOfLives << endl;

	defaults << enc_distance << endl;

	defaults << enc_slain << endl;

	defaults.close();
}

string readDefaults() {
	ifstream defaults("defaults.txt");
	string in;
	string input = "";
	if (defaults.is_open()) {
		while (getline(defaults, in)) {
			input += in;
		}
		defaults.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}
	//defaults.close();
	return input;
}



bool valueChecker(double newDouble, int newInt, char newChar) {
	double oldDouble = encodingDoubles(5672, newDouble);
	int oldInt = encodingInts(5672, newInt);
	char oldChar = encodingChars(13, newChar);

	if (oldDouble != enc_XP)
	{
		return true;
	}
	if (oldInt != enc_doubloons)
	{
		return true;
	}
	if (oldChar != enc_combatRating)
	{
		return true;
	}
	return false;
}



void encoder(double XP, int doubloons, string characterName, string villainName, char combatRating, char npcStanding, int numOfLives, double distanceTraveled, int enemiesSlain, double enc_Arr[]) {
	for (int i = 0; i < 10; i++)
	{
		ss << enc_Arr[i] << " ";
	}
	//encode XP
	enc_XP = encodingDoubles(5672, XP);
	ss << enc_XP;
	//encode doubloons
	enc_doubloons = encodingInts(5672, doubloons);
	ss << enc_doubloons;

	//encode character name
	enc_charName = encodingStrings(13, characterName);
	ss << enc_charName;

	//encode villian name
	enc_Villain = encodingStrings(13, villainName);
	ss << enc_Villain;

	//encode combat rating Standing
	enc_combatRating = encodingChars(13, combatRating);
	ss << enc_combatRating;

	// encode NPC Standing
	enc_npcStanding = encodingChars(13, npcStanding);
	ss << enc_npcStanding;

	//encode number of lives
	enc_numOfLives = encodingInts(5672, numOfLives);
	ss << enc_numOfLives;

	//encode distance Traveled
	enc_distance = encodingDoubles(5672, distanceTraveled);
	ss << enc_distance;

	//encode enemies slain
	enc_slain = encodingInts(5672, enemiesSlain);
	ss << enc_slain;

	masterString = ss.str();
	//Printing for testing purposes:
	cout << "\nXP: " << enc_XP << endl;
	cout << "doubloons: " << enc_doubloons << endl;
	cout << "Character Name: " << enc_charName << endl;
	cout << "Villian: " << enc_Villain << endl;
	cout << "Combat Rating; " << enc_combatRating << endl;
	cout << "npcStanding: " << enc_npcStanding << endl;
	cout << "Number of Lives: " << enc_numOfLives << endl;
	cout << "Distance Traveled: " << enc_distance << endl;
	cout << "Enemies Slain: " << enc_slain << endl;
}

double encodingDoubles(int key, double var)
{
	int castedVar = var * 100;
	double newVar = castedVar ^ key;
	newVar = newVar / 100;
	return newVar;
}

void encodingDoubleArray(int key, double doublearray[], double newArray[])
{
	double castedArrayVal;
	for (int i = 0; i < 10; i++)
	{
		castedArrayVal = encodingDoubles(key, doublearray[i]);
		newArray[i] = castedArrayVal;
		//Printing for testing
		cout << newArray[i] << " ";
	}
	return;
}

int encodingInts(int key, int value)
{
	int newValue = value ^ key;
	return newValue;
}

string encodingStrings(int key, string name)
{
	string newName = name;
	char letters[52] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z' };
	for (int i = 0; i < int(name.length()); i++)
	{
		for (int k = 0; k < 26; k++)
		{
			if (name.at(i) == letters[k])
			{
				newName.at(i) = letters[((k + key) % 26)];
				break;
			}
		}
	}
	return newName;
}

char encodingChars(int key, char character)
{
	char newChar = character;
	char letters[52] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z' };

	for (int k = 0; k < 26; k++)
	{
		if (character == letters[k])
		{
			newChar = letters[((k + key) % 26)];
			break;
		}
	}
	return newChar;
}

//https://www.technical-recipes.com/2014/using-openssl-sha-256-in-visual-c/