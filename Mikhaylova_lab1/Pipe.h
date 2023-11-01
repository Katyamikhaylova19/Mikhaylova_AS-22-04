#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
	string GetName() const;
	bool GetStatus();
	void PrintPipeStatus();
	friend void EditPipes(vector <Pipe*>& pipes);
	friend void EditPipe(Pipe& pipe);
	friend ostream& operator << (ostream& out, const Pipe& pipe);
	friend istream& operator >> (istream& in, Pipe& pipe);
	friend ofstream& operator << (ofstream& fout, const Pipe& pipe);
	friend ifstream& operator >> (ifstream& fin, Pipe& pipe);
}; 

