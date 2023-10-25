#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Pipe
{
	string kilometerMark = "";
	double length = 0;
	int diameter = 0;
	bool isRepairing;

	void PrintPipeStatus()
	{
		cout << (isRepairing ? "Pipe is under repair" : "Pipe is in work")<< endl;
	}
};

struct CompressorStation
{
	string name = "";
	int workshopCount = 0;
	int activeWorkshopCount = 0;
	string efficiency = "A";
};

template <typename T>
void InputCorrectNumber(T& var, bool canEqualToZero = false)
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

void AddPipe(vector<Pipe>& pipes)
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

	pipes.push_back(newPipe);
;
}

void AddCompressorStation(vector<CompressorStation>& compressorStations)
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
		cout << "Error! The number of active workshops cant be more than the total number of workshops"<<endl
			<<"Please enter correct data: ";
		InputCorrectNumber(newCompressorStation.activeWorkshopCount, true);
	}
	cout << "Enter efficiency from A to G: ";
	cin >> newCompressorStation.efficiency;
	while (!(newCompressorStation.efficiency >= "A" && newCompressorStation.efficiency <= "G" && newCompressorStation.efficiency.length() == 1))
	{
		cout << "Error! Please enter correct data: ";
		cin >> newCompressorStation.efficiency;
	}
	compressorStations.push_back(newCompressorStation);
}

void ShowPipes(const vector<Pipe>& pipes)
{
	if (pipes.size() == 0)
	{
		cout << "Pipe not found." << endl;
		return;
	}
	for (const auto& newPipe : pipes) {
		cout << endl << "Kilometer mark: " << newPipe.kilometerMark << endl;
		cout << "Pipe length: " << newPipe.length << " km" << endl;
		cout << "Pipe diameter: " << newPipe.diameter << " mm" << endl;
		if (newPipe.isRepairing)
			cout << "Pipe under repair." << endl << endl;
		else
			cout << "Pipe is in work." << endl << endl;
	}
}

void ShowCompressorStations(const vector<CompressorStation>& compressorStations)
{
	if (compressorStations.size() == 0)
	{
		cout << "Compressor station not found." << endl;
		return;
	}
	for (const auto& newCompressorStation : compressorStations) {
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
		editPipe.PrintPipeStatus();
		cout <<endl<< "What to change this?"<<endl
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

void SavePipe(const Pipe& savePipe, ofstream& fout)
{
	fout << savePipe.length << endl;
	fout << savePipe.kilometerMark << endl;
	fout << savePipe.diameter << endl;
	fout << savePipe.isRepairing << endl;
	cout << "Pipe data successfully saved to file!" << endl;
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

template <typename T>
T& SelectElement(vector <T>& elements)
{
	int number;
	cout << "Enter number: ";
	InputCorrectNumber(number);
	while (number > elements.size())
	{
		cout << "Error!\nThe number exceeds the number of elements." << endl
			<< "Number of elements: " << elements.size() << endl
			<< "Please enter correct data: ";
		InputCorrectNumber(number);
	}
	return elements[number - 1];
}

int main()
{
	vector <Pipe> pipes = {};
	vector <CompressorStation> compressorStations = {};

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
		InputCorrectNumber(commandNumber, true);
		switch (commandNumber)
		{
		case 0:
			cout << "[ Exit the program ]" << endl;
			return 0;
			break;
		case 1:
			cout << "[ Add pipe ]"<<endl;
			AddPipe(pipes);
			break;
		case 2:
			cout << "[ Add compressor station ]"<<endl;
			AddCompressorStation(compressorStations);
			break;
		case 3:
			cout << "[ View all objects ]"<<endl;
			ShowPipes(pipes);
			ShowCompressorStations(compressorStations);
			break;
		case 4:
			cout << "[ Edit pipe ]"<<endl;
			EditPipe(SelectElement(pipes));
			break;
		case 5:
			cout << "[ Edit compressor station ]"<<endl;
			EditCompressorStation(SelectElement(compressorStations));
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
				fout << pipes.size() << endl;
				for (const auto& pipe : pipes)
					SavePipe(pipe, fout);
				fout << compressorStations.size() << endl;
				for (const auto& compressorStation : compressorStations)
					SaveCompressorStation(compressorStation, fout);
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
				int pipeSize;
				fin >> pipeSize;
				if (pipeSize == 0)
					cout << "Pipes not found." << endl;
				pipes.resize(pipeSize);
				for (auto& pipe : pipes)
					LoadPipe(pipe, fin);

				int compressorStationSize;
				fin >> compressorStationSize;
				if (compressorStationSize == 0)
					cout << "Compressor stations not found." << endl;
				compressorStations.resize(compressorStationSize);
				for (auto& compressorStation : compressorStations)
					LoadCompressorStation(compressorStation, fin);

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

