#include "CompressorStation.h"

CompressorStation CompressorStation::AddCompressorStation()
{
	CompressorStation newCompressorStation;
	cout << "Enter the name of the Compressor station: ";
	cin.ignore();
	getline(cin, newCompressorStation.name);
	cout << "Enter the number of workshops: ";
	InputCorrectNumber(newCompressorStation.workshopCount);
	cout << "Enter the number of active workshops: ";
	InputCorrectNumber(newCompressorStation.activeWorkshopCount, true);
	while (newCompressorStation.workshopCount < newCompressorStation.activeWorkshopCount)
	{
		cout << "Error! The number of active workshops cant be more than the total number of workshops" << endl
			<< "Please enter correct data: ";
		InputCorrectNumber(newCompressorStation.activeWorkshopCount, true);
	}
	cout << "Enter efficiency from A to G: ";
	cin >> newCompressorStation.efficiency;
	while (!(newCompressorStation.efficiency >= "A" && newCompressorStation.efficiency <= "G" && newCompressorStation.efficiency.length() == 1))
	{
		cout << "Error! Please enter correct data: ";
		cin >> newCompressorStation.efficiency;
	}
	return newCompressorStation;
}

void CompressorStation::ShowCompressorStation(const CompressorStation& newCompressorStation) const
{
	cout << endl << "Name of the compressor station: " << newCompressorStation.name << endl;
	cout << "Number of workshops: " << newCompressorStation.workshopCount << endl;
	cout << "Number of active workshops: " << newCompressorStation.activeWorkshopCount << endl;
	cout << "Efficiency: " << newCompressorStation.efficiency << endl << endl;
}

void CompressorStation::EditCompressorStation(CompressorStation& editCompressorStation)
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

void CompressorStation::SaveCompressorStation(const CompressorStation& saveCompressorStation, ofstream& fout) const
{
	fout << saveCompressorStation.name << endl;
	fout << saveCompressorStation.workshopCount << endl;
	fout << saveCompressorStation.activeWorkshopCount << endl;
	fout << saveCompressorStation.efficiency << endl;
	cout << "Compressor station data successfully saved to file!" << endl;
}

void CompressorStation::LoadCompressorStation(CompressorStation& loadCompressorStation, ifstream& fin)
{
	fin.ignore();
	getline(fin, loadCompressorStation.name);
	fin >> loadCompressorStation.workshopCount;
	fin >> loadCompressorStation.activeWorkshopCount;
	fin >> loadCompressorStation.efficiency;
	cout << "Compressor station data loaded successfully!" << endl;
}