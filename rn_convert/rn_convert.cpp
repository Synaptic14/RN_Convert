#include "stdafx.h"
#include <iostream>
#include <string>
#include "rn_convert.h"

int main() {
	bool playAgain = false;
	do {
		system("cls");
		std::string rnInput = getInput();
		int numValue = convertNumerals(rnInput);
		outputConversion(numValue, rnInput);
		playAgain = isPlayingAgain();
	} while (playAgain);
	return 0;
}

bool isPlayingAgain()
{
	using namespace std;
	cout << "\n\n";
	cout << "Would you like to convert another Roman Numeral? (Y/N): ";
	string playingAgain = "";
	getline(cin, playingAgain);
	return(playingAgain[0] == 'y' || playingAgain[0] == 'Y');
}

std::string getInput()
{
	using namespace std;
	string roman = "";
	cout << " Enter the Roman Numeral Value: ";
	getline(cin, roman);
	return roman;
}

int getValue(char romanNumeral)
{
	using namespace roman_numerals;
	int rnValue = 0;
	switch (romanNumeral)
	{

	case 'M':
	case 'm':
		rnValue += M;
		break;
	case 'D':
	case 'd':
		rnValue += D;
		break;
	case 'C':
	case 'c':
		rnValue += C;
		break;
	case 'L':
	case 'l':
		rnValue += L;
		break;
	case 'X':
	case 'x':
		rnValue += X;
		break;
	case 'V':
	case 'v':
		rnValue += V;
		break;
	case 'I':
	case 'i':
		rnValue += I;
		break;
	}
	return rnValue;
}


int convertNumerals(std::string rnInput)
{
	int nextCharValue;
	int charValue;
	int numValue = 0;
	size_t i = 0;
	size_t nextIndex = 0;
	while (i < rnInput.length())
	{
		nextIndex = i + 1;
		charValue = getValue(rnInput.at(i));
		if (i >= rnInput.length() - 1)
		{
			 nextCharValue = 0;
		}
		else
		{
				nextCharValue = getValue(rnInput.at(nextIndex));
		}

		if (charValue < nextCharValue)
		{
			numValue += nextCharValue - charValue;
			i += 2;

		} else {
			numValue += charValue;
			i++;
		}
	}
	return numValue;
}

void outputConversion(int num, std::string originalInput)
{
	using namespace std;
	cout << "\n";
	cout << originalInput << " converts to: " << num << endl;
}