#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Utilities.h"

using namespace std;

class CompressorStation
{
public:
	string name = "";
	int workshopCount = 0;
	int activeWorkshopCount = 0;
	string efficiency = "A";

	CompressorStation AddCompressorStation();
	void ShowCompressorStation(const CompressorStation& newCompressorStation) const;
	void EditCompressorStation(CompressorStation& editCompressorStation);
	void SaveCompressorStation(const CompressorStation& saveCompressorStation, ofstream& fout) const;
	void LoadCompressorStation(CompressorStation& loadCompressorStation, ifstream& fin);
};

