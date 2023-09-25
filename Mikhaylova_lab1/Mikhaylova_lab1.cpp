#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pipe
{
	string kilometerMark = "";
	double length = 0;
	int diameter = 0;
	bool isRepairing = true;
};

struct CompressorStation
{
	string name = "";
	int workshopCount = 0;
	int activeWorkshopCount = 0;
	string efficiency = "A";
};

void InputInt(int& var, bool canEqualToZero = false)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n' || (canEqualToZero ? var < 0 : var <= 0))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		cin >> var;
	}
}

void InputDouble(double& var)
{
	cin >> var;
	while (cin.fail() || cin.peek()!='\n' || var <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		cin >> var;
	}
}

void InputBool(bool& var)
{
	cin >> var;
	while (cin.fail() || cin.peek()!='\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		cin >> var;
	}
}

Pipe AddPipe()
{
	Pipe newPipe;
	cout << "Enter kilometer mark: ";
	cin.ignore();
	getline(cin, newPipe.kilometerMark);
	cout << "Enter the pipe length (in kilometers): ";
	InputDouble(newPipe.length);
	cout << "Enter the pipe diameter (in millimeters): ";
	InputInt(newPipe.diameter);
	cout << "Is the pipe being repaired? (1 - Yes, 0 - No) ";
	InputBool(newPipe.isRepairing);

	return newPipe;
}

CompressorStation AddCompressorStation()
{
	CompressorStation newCompressorStation;
	cout << "Enter the name of the Compressor station: ";
	cin.ignore();
	getline(cin, newCompressorStation.name);
	cout << "Enter the number of workshops: ";
	InputInt(newCompressorStation.workshopCount);
	cout << "Enter the number of active workshops: ";
	InputInt(newCompressorStation.activeWorkshopCount, true);
	while (newCompressorStation.workshopCount < newCompressorStation.activeWorkshopCount)
	{
		cout << "Error! The number of active workshops cant be more than the total number of workshops"<<endl
			<<"Please enter correct data: ";
		InputInt(newCompressorStation.activeWorkshopCount, true);
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

void ShowPipes(const Pipe& newPipe)
{
	if (newPipe.length == 0)
	{
		cout << "Pipe not found." << endl;
	}
	else
	{
		cout << endl << "Kilometer mark: " << newPipe.kilometerMark << endl;
		cout << "Pipe length: " << newPipe.length << " km" << endl;
		cout << "Pipe diameter: " << newPipe.diameter << " mm" << endl;
		if (newPipe.isRepairing)
			cout << "Pipe under repair." << endl << endl;
		else
			cout << "Pipe is in work." << endl << endl;
	}
}

void ShowCompressorStations(const CompressorStation& newCompressorStation)
{
	if (newCompressorStation.workshopCount == 0)
	{
		cout << "Compressor station not found." << endl;
	}
	else 
	{
		cout << endl << "Name of the compressor station: " << newCompressorStation.name << endl;
		cout << "Number of workshops: " << newCompressorStation.workshopCount << endl;
		cout << "Number of active workshops: " << newCompressorStation.activeWorkshopCount << endl;
		cout << "Efficiency: " << newCompressorStation.efficiency << endl << endl;
	}
}

void EditPipe(Pipe& editPipe)
{
	int commandNumber;
	if (editPipe.length == 0)
	{
		cout << "Pipe not found." << endl;
	}
	else
	{
		while (editPipe.isRepairing == true)
		{
			cout << "The pipe is under repair. Want to change this?" << endl;
			cout << "1. Yes" << endl
				<< "2. No" << endl
				<< "Your choice: ";
			InputInt(commandNumber);
			switch (commandNumber)
			{
			case 1:
				editPipe.isRepairing = false;
				cout << "Pipe is in work." << endl;
				return;
				break;
			case 2:
				return;
				break;
			default:
				cout << "Error! Please enter correct data: " << endl;
				break;
			}
		}
		while (editPipe.isRepairing == false)
		{
			cout << "Pipe is in work. Want to change this?" << endl;
			cout << "1. Yes" << endl
				<< "2. No" << endl
				<<"Your choice: ";
			InputInt(commandNumber);
			switch (commandNumber)
			{
			case 1:
				editPipe.isRepairing = true;
				cout << "Pipe under repair." << endl;
				return;
				break;
			case 2:
				return;
				break;
			default:
				cout << "Error! Please enter correct data: " << endl;
				break;
			}
		}
	}
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
			InputInt(commandNumber);
			switch (commandNumber)
			{
			case 1:
				cout << "Enter the number of active workshops: ";
				InputInt(editCompressorStation.activeWorkshopCount, true);
				while (editCompressorStation.activeWorkshopCount > editCompressorStation.workshopCount)
				{
					cout << "Error!\n The number of active workshops cant be more than the total number of workshops." << endl
						<< "The number of workshops is " << editCompressorStation.workshopCount << endl
						<< "Please enter correct data: ";
					InputInt(editCompressorStation.activeWorkshopCount, true);
				}
				return;
				break;
			case 2:
				return;
				break;
			default:
				cout << "Error! Please enter correct data: " << endl;
				break;
			}
		}
	}
}

void SavePipe(const Pipe& savePipe, ofstream& fout)
{
	fout << savePipe.length << endl;
	fout << savePipe.kilometerMark << endl;
	fout << savePipe.diameter << endl;
	fout << savePipe.isRepairing << endl;
	cout << "Pipe data successfully saved to file!" << endl;
	fout.close();
}

void SaveCompressorStation(const CompressorStation& saveCompressorStation, ofstream& fout)
{
	fout << saveCompressorStation.name << endl;
	fout << saveCompressorStation.workshopCount << endl;
	fout << saveCompressorStation.activeWorkshopCount << endl;
	fout << saveCompressorStation.efficiency << endl;
	cout << "Compressor station data successfully saved to file!" << endl;
}

void LoadPipe(Pipe& loadPipe, ifstream& fin)
{
	fin >> loadPipe.length;
	fin.ignore();
	getline(fin, loadPipe.kilometerMark);
	fin >> loadPipe.diameter;
	fin >> loadPipe.isRepairing;
	cout << "Pipe data loaded successfully!" << endl;
}

void LoadCompressorStation(CompressorStation& loadCompressorStation, ifstream& fin)
{
	fin.ignore();
	getline(fin, loadCompressorStation.name);
	fin >> loadCompressorStation.workshopCount;
	fin >> loadCompressorStation.activeWorkshopCount;
	fin >> loadCompressorStation.efficiency;
	cout << "Compressor station data loaded successfully!" << endl;
}

int main()
{
	Pipe pipe;
	CompressorStation cs;

	int commandNumber;
	while (true)
	{
		cout << "MENU:" << endl
			<< "0. Exit the program" << endl
			<< "1. Add pipe" << endl
			<< "2. Add compressor station" << endl
			<< "3. View all objects" << endl
			<< "4. Edit pipe" << endl
			<< "5. Edit compressor station" << endl
			<< "6. Save" << endl
			<< "7. Load" << endl << endl
			<< "What do you want to do: ";
		InputInt(commandNumber, true);
		switch (commandNumber)
		{
		case 0:
			cout << "[ Exit the program ]" << endl;
			return 0;
			break;
		case 1:
			cout << "[ Add pipe ]"<<endl;
			pipe = AddPipe();
			break;
		case 2:
			cout << "[ Add compressor station ]"<<endl;
			cs = AddCompressorStation();
			break;
		case 3:
			cout << "[ View all objects ]"<<endl;
			ShowPipes(pipe);
			ShowCompressorStations(cs);
			break;
		case 4:
			cout << "[ Edit pipe ]"<<endl;
			EditPipe(pipe);
			break;
		case 5:
			cout << "[ Edit compressor station ]"<<endl;
			EditCompressorStation(cs);
			break;
		case 6:
		{
			cout << "[ Save ]" << endl;
			ofstream fout;
			string fileName;
			cout << "Enter file name: ";
			cin.ignore();
			getline(cin, fileName);
			fout.open(fileName);
			if (!fout.is_open())
			{
				cout << "File opening error!" << endl;
			}
			else
			{
				if (pipe.length == 0)
					fout << 0 << endl;
				else
				{
					fout << 1 << endl;
					SavePipe(pipe, fout);
				}
				if (cs.workshopCount == 0)
					fout << 0 << endl;
				else
				{
					fout << 1 << endl;
					SaveCompressorStation(cs, fout);
				}
			}
			fout.close();

		}
			break;
		case 7:
		{
			cout << "[ Load ]" << endl;
			ifstream fin;
			string fileName;
			int input;
			cout << "Enter file name: ";
			cin.ignore();
			getline(cin, fileName);
			fin.open(fileName);
			if (!fin.is_open())
			{
				cout << "File opening error!" << endl;
			}
			else
			{
				fin >> input;
				if (input == 1)
				{
					LoadPipe(pipe, fin);
				}
				else
				{
					cout << "Pipe not found." << endl;
				}
				fin >> input;
				if (input == 1)
				{
					LoadCompressorStation(cs, fin);
				}
				else
				{
					cout << "Compressor station not found." << endl;
				}
				fin.close();
			}
		}
			break;
		default:
			cout << "Error! Please enter correct data: " << endl;
			break;
		}
	}

}

