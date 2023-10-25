#include "Pipe.h"


void Pipe::PrintPipeStatus()
{
	cout << (isRepairing ? "Pipe is under repair" : "Pipe is in work") << endl;
}


Pipe Pipe::AddPipe()
{
	Pipe newPipe;
	cout << "Enter kilometer mark: ";
	cin.ignore();
	getline(cin, newPipe.kilometerMark);
	cout << "Enter the pipe length (in kilometers): ";
	InputCorrectNumber(newPipe.length);
	cout << "Enter the pipe diameter (in millimeters): ";
	InputCorrectNumber(newPipe.diameter);
	cout << "Is the pipe being repaired? (1 - Yes, 0 - No) ";
	InputCorrectNumber(newPipe.isRepairing, true);
	return newPipe;
}


void Pipe::ShowPipe(const Pipe& newPipe) const
{
	cout << endl << "Kilometer mark: " << newPipe.kilometerMark << endl;
	cout << "Pipe length: " << newPipe.length << " km" << endl;
	cout << "Pipe diameter: " << newPipe.diameter << " mm" << endl;
	if (newPipe.isRepairing)
		cout << "Pipe under repair." << endl << endl;
	else
		cout << "Pipe is in work." << endl << endl;
}

void Pipe::EditPipe(Pipe& editPipe)
{
	int commandNumber;
	if (editPipe.length == 0)
	{
		cout << "Pipe not found." << endl;
	}
	else
	{
		editPipe.PrintPipeStatus();
		cout << endl << "What to change this?" << endl
			<< "1. Yes" << endl
			<< "2. No" << endl
			<< "Your choice: ";
		InputCorrectNumber(commandNumber);
		switch (commandNumber)
		{
		case 1:
			editPipe.isRepairing = !editPipe.isRepairing;
			editPipe.PrintPipeStatus();
			break;
		case 2:
			return;
		default:
			cout << "Error! Please enter correct data " << endl;
			break;
		}
	}
}

void Pipe::SavePipe(const Pipe& savePipe, ofstream& fout) const
{
	fout << savePipe.length << endl;
	fout << savePipe.kilometerMark << endl;
	fout << savePipe.diameter << endl;
	fout << savePipe.isRepairing << endl;
	cout << "Pipe data successfully saved to file!" << endl;
}

void Pipe::LoadPipe(Pipe& loadPipe, ifstream& fin)
{
	fin >> loadPipe.length;
	fin.ignore();
	getline(fin, loadPipe.kilometerMark);
	fin >> loadPipe.diameter;
	fin >> loadPipe.isRepairing;
	cout << "Pipe data loaded successfully!" << endl;
}