#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Utilities.h"

using namespace std;

class Pipe
{
public:
	string kilometerMark = "";
	double length = 0;
	int diameter = 0;
	bool isRepairing;

	void PrintPipeStatus();
	Pipe AddPipe();
	void ShowPipe(const Pipe& newPipe) const;
	void EditPipe(Pipe& editPipe);
	void SavePipe(const Pipe& savePipe, ofstream& fout) const;
	void LoadPipe(Pipe& loadPipe, ifstream& fin);
};

