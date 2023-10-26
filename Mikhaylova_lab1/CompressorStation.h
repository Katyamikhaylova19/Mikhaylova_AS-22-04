#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Utilities.h"

using namespace std;

class CompressorStation
{
	static int maxId;
	int Id;
	string name = "";
	int workshopCount = 0;
	int activeWorkshopCount = 0;
	string efficiency = "A";
public:
	int GetId();
	friend void EditCompressorStation(CompressorStation& editCompressorStation);
	friend ostream& operator << (ostream& out, const CompressorStation& CS);
	friend istream& operator >> (istream& in, CompressorStation& CS);
	friend ofstream& operator << (ofstream& fout, const CompressorStation& CS);
	friend ifstream& operator >> (ifstream& fin, CompressorStation & CS);
};

