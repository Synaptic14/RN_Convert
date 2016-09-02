#pragma once
#ifndef rn_convert_h
#define rn_convert_h

#include <string>
std::string getInput();
int convertNumerals(std::string rnInput);
bool isPlayingAgain();
void outputConversion(int num, std::string originalInput);

namespace roman_numerals
{
	const int M = 1000;
	const int D = 500;
	const int C = 100;
	const int L = 50;
	const int X = 10;
	const int V = 5;
	const int I = 1;
}

#endif
