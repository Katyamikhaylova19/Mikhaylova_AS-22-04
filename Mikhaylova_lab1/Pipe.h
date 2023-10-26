#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Utilities.h"

using namespace std;

class Pipe
{
	static int maxId;
	int Id;
	string kilometerMark = "";
	double length = 0;
	int diameter = 0;
	bool isRepairing;
public:
	int GetId();
	void PrintPipeStatus();
	friend void EditPipe(Pipe& editPipe);
	friend ostream& operator << (ostream& out, const Pipe& pipe);
	friend istream& operator >> (istream& in, Pipe& pipe);
	friend ofstream& operator << (ofstream& fout, const Pipe& pipe);
	friend ifstream& operator >> (ifstream& fin, Pipe& pipe);
}; 

