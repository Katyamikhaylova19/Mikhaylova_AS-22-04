#include "CompressorStation.h"

int CompressorStation::maxId = 0;

int CompressorStation::GetId()
{
	return Id;
}

void EditCompressorStation(CompressorStation& editCompressorStation)
{
	int commandNumber;
	if (editCompressorStation.workshopCount == 0)
		cout << "Compressor station not found." << endl;
	else
	{
		while (true)
		{
			cout << "Want to change the number of active workshops?" << endl
				<< "1. Yes" << endl
				<< "2. No" << endl
				<< "Your choice: ";
			InputCorrectNumber(commandNumber);
			switch (commandNumber)
			{
			case 1:
				cout << "Enter the number of active workshops: ";
				InputCorrectNumber(editCompressorStation.activeWorkshopCount, true);
				while (editCompressorStation.activeWorkshopCount > editCompressorStation.workshopCount)
				{
					cout << "Error!\n The number of active workshops cant be more than the total number of workshops." << endl
						<< "The number of workshops is " << editCompressorStation.workshopCount << endl
						<< "Please enter correct data: ";
					InputCorrectNumber(editCompressorStation.activeWorkshopCount, true);
				}
				return;
			case 2:
				return;
			default:
				cout << "Error! Please enter correct data: " << endl;
				break;
			}
		}
	}
}

ostream& operator<<(ostream& out, const CompressorStation& CS)
{
	out << endl << "Compressor station Id: " << CS.Id << endl;
	out << "Name of the compressor station: " << CS.name << endl;
	out << "Number of workshops: " << CS.workshopCount << endl;
	out << "Number of active workshops: " << CS.activeWorkshopCount << endl;
	out << "Efficiency: " << CS.efficiency << endl << endl;
	return out;
}

istream& operator>>(istream& in, CompressorStation& CS)
{
	CS.Id = ++CS.maxId;
	cout << "Id: " << CS.Id << endl;
	cout << "Enter the name of the Compressor station: ";
	in.ignore();
	getline(in, CS.name);
	cout << "Enter the number of workshops: ";
	InputCorrectNumber(CS.workshopCount);
	cout << "Enter the number of active workshops: ";
	InputCorrectNumber(CS.activeWorkshopCount, true);
	while (CS.workshopCount < CS.activeWorkshopCount)
	{
		cout << "Error! The number of active workshops cant be more than the total number of workshops" << endl
			<< "Please enter correct data: ";
		InputCorrectNumber(CS.activeWorkshopCount, true);
	}
	cout << "Enter efficiency from A to G: ";
	cin >> CS.efficiency;
	while (!(CS.efficiency >= "A" && CS.efficiency <= "G" && CS.efficiency.length() == 1))
	{
		cout << "Error! Please enter correct data: ";
		cin >> CS.efficiency;
	}
	return in;
}

ofstream& operator<<(ofstream& fout, const CompressorStation& CS)
{
	fout << CS.Id << endl;
	fout << CS.name << endl;
	fout << CS.workshopCount << endl;
	fout << CS.activeWorkshopCount << endl;
	fout << CS.efficiency << endl;
	cout << "Compressor station data successfully saved to file!" << endl;
	return fout;
}


ifstream& operator>>(ifstream& fin, CompressorStation& CS)
{
	fin >> CS.Id;
	CS.maxId = CS.Id;
	fin.ignore();
	getline(fin, CS.name);
	fin >> CS.workshopCount;
	fin >> CS.activeWorkshopCount;
	fin >> CS.efficiency;
	cout << "Compressor station data loaded successfully!" << endl;
	return fin;
}