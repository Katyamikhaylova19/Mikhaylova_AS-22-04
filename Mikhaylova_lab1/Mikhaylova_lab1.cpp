#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Utilities.h"
#include "Pipe.h"
#include "CompressorStation.h"
#include "logger.h"

using namespace std;

template <typename T>
T& SelectElement(unordered_map <int, T>& elements)
{
	int Id;
	cout << "Enter number: ";
	InputCorrectNumber(Id);
	while (elements.find(Id) == elements.end())
	{
		cout << "Error!\nThe number exceeds the number of elements." << endl
			<< "Number of elements: " << elements.size() << endl
			<< "Please enter correct data: ";
		InputCorrectNumber(Id);
	}
	return elements[Id];
}

void SearchPipes(unordered_map <int, Pipe>& pipes) {
	while (true)
	{
		int commandNumber;
		cout << "By what criteria do you want to find a pipe?" << endl
			<< "1. Name" << endl
			<< "2. Is repairing or not" << endl
			<< "3. Back" << endl
			<< "Your choice: ";
		InputCorrectNumber(commandNumber);
		switch (commandNumber)
		{
		case 1:
		{
			string name;
			cout << "Name: ";
			cin.ignore();
			getline(cin, name);
			vector<Pipe*> editPipes;
			for (auto& pair : pipes) {
				if (pair.second.GetName().find(name) != string::npos)
				{
					cout << pair.second << endl;
					editPipes.push_back(&(pair.second));
				}
			}
			if (editPipes.empty())
				cout << "Pipe with this name not found." << endl;
			else
				EditPipes(editPipes);
		}
		break;
		case 2:
		{
			bool isRepairing;
			cout << "Is the pipe being repaired? (1 - Yes, 0 - No) ";
			InputCorrectNumber(isRepairing, true);

			vector<Pipe*> editPipes;
			for (auto& pair : pipes) {
				if (pair.second.GetStatus() == isRepairing)
				{
					cout << pair.second << endl;
					editPipes.push_back(&(pair.second));
				}
			}
			if (editPipes.empty())
				cout << "Pipe with this name not found." << endl;
			else
				EditPipes(editPipes);
		}
		break;
		case 3:
			return;
		default:
			cout << "Error! Please enter correct data" << endl;
			break;
		}
	}
}

void SearchCompressorStations(unordered_map <int, CompressorStation>& compressorStations) {
	while (true)
	{
		int commandNumber;
		cout << "By what criteria do you want to find a Compressor Station?" << endl
			<< "1. Name" << endl
			<< "2. Percent of active worskshops" << endl
			<< "3. Back" << endl
			<< "Your choice: ";
		InputCorrectNumber(commandNumber);
		switch (commandNumber)
		{
		case 1:
		{
			string name;
			cout << "Name: ";
			cin.ignore();
			getline(cin, name);
			vector<CompressorStation*> editCompressorStations;
			for (auto& pair : compressorStations) {
				if (pair.second.GetName().find(name) != string::npos)
				{
					cout << pair.second << endl;
					editCompressorStations.push_back(&(pair.second));
				}
			}
			if (editCompressorStations.empty())
				cout << "Compressor Station with this name not found." << endl;
			else
				EditCompressorStations(editCompressorStations);
		}
		break;
		case 2:
		{
			int percent;
			cout << "Enter the percent of active workshops (0-100) +-5%: ";
			InputCorrectNumber(percent, true);

			vector<CompressorStation*> editCompressorStations;
			for (auto& pair : compressorStations) {
				if (pair.second.GetPercentOfActiveWorkshops() > percent - 5 && pair.second.GetPercentOfActiveWorkshops() < percent + 5)
				{
					cout << pair.second << endl;
					editCompressorStations.push_back(&(pair.second));
				}
			}
			if (editCompressorStations.empty())
				cout << "Compressor Station with this name not found." << endl;
			else
				EditCompressorStations(editCompressorStations);
		}
		break;
		case 3:
			return;
		default:
			cout << "Error! Please enter correct data" << endl;
			break;
		}
	}
}


int main()
{
	unordered_map <int, Pipe> pipes = {};
	unordered_map <int, CompressorStation> compressorStations = {};
	Logger logger;
	logger.log("Start");

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
			<< "7. Load" << endl 
			<< "8. Search" << endl << endl
			<< "What do you want to do: ";
		InputCorrectNumber(commandNumber, true);
		switch (commandNumber)
		{
		case 0:
			cout << "[ Exit the program ]" << endl;
			logger.log("Exit");
			return 0;
			break;
		case 1:
		{
			cout << "[ Add pipe ]" << endl;
			logger.log("Add pipe start");
			Pipe pipe;
			cin >> pipe;
			pipes.insert(make_pair(pipe.GetId(), pipe));
			logger.log("Add pipe finish");
			break;
		}
		case 2:
		{
			cout << "[ Add compressor station ]" << endl;
			logger.log("Add compressor station start");
			CompressorStation CS;
			cin >> CS;
			compressorStations.insert(make_pair(CS.GetId(), CS));
			logger.log("Add compressor station finish");
			break;
		}
		case 3:
			cout << "[ View all objects ]" << endl;
			logger.log("Show all objects start");

			if (pipes.size() == 0)
				cout << "Pipe not found." << endl;
			for (const auto& pair : pipes)
				cout << pair.second;

			if (compressorStations.size() == 0)
				cout << "Compressor station not found." << endl;
			for (const auto& pair : compressorStations)
				cout << pair.second;
			logger.log("Show all objects finish");
			break;
		case 4:
		{
			cout << "[ Edit pipe ]" << endl;
			logger.log("Edit pipe start");
			Pipe pipe = SelectElement(pipes);
			EditPipe(pipe);
			logger.log("Edit pipe finish");
			break;
		}
		case 5:
		{
			cout << "[ Edit compressor station ]" << endl;
			logger.log("Edit compressor station start");
			CompressorStation compressorStation = SelectElement(compressorStations);
			EditCompressorStation(compressorStation);
			logger.log("Edit compressor station finish");
			break;
		}
		case 6:
		{
			cout << "[ Save ]" << endl;
			logger.log("Save start");
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
				for (const auto& pair : pipes)
					fout << pair.second;
				fout << compressorStations.size() << endl;
				for (const auto& pair : compressorStations)
					fout << pair.second;
			}
			fout.close();
			logger.log("Save finish");
		}
		break;
		case 7:
		{
			cout << "[ Load ]" << endl;
			logger.log("Load start");
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
				while (pipeSize-- > 0)
				{
					Pipe pipe;
					fin >> pipe;
					pipes.insert(make_pair(pipe.GetId(), pipe));
				}

				int compressorStationSize;
				fin >> compressorStationSize;
				if (compressorStationSize == 0)
					cout << "Compressor stations not found." << endl;
				while (compressorStationSize-- > 0)
				{
					CompressorStation CS;
					fin >> CS;
					compressorStations.insert(make_pair(CS.GetId(), CS));
				}

				fin.close();
			}
			logger.log("Load finish");
		}
		break;
		case 8:
		{
			bool isRunning = true;
			while (isRunning) {
				int commandNumber1;
				cout << "[ Search ]" << endl
					<< "What do you want to find?" << endl
					<< "1. Pipe" << endl
					<< "2. Compressor station" << endl
					<< "3. Back" << endl
					<< "Your choice: ";
				logger.log("Search start");
				InputCorrectNumber(commandNumber1);
				switch (commandNumber1)
				{
				case 1:
					cout << "[ Pipe ]" << endl;
					SearchPipes(pipes);
					break;
				case 2:
					cout << "[ Compressor station ]" << endl;
					SearchCompressorStations(compressorStations);
					break;
				case 3:
					isRunning = false;
					break;
				default:
					cout << "Error! Please enter correct data" << endl;
					break;
				}
				logger.log("Search finish");
			}
			break;
		}
		default:
			cout << "Error! Please enter correct data: " << endl;
			break;
		}
	}
	logger.log("Finish");
}