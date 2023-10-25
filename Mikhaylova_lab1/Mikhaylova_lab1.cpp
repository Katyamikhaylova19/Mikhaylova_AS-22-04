#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Utilities.h"
#include "Pipe.h"
#include "CompressorStation.h"

using namespace std;

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
		{
			cout << "[ Add pipe ]" << endl;
			Pipe newPipe;
			pipes.push_back(newPipe.AddPipe());
			break;
		}
		case 2:
		{
			cout << "[ Add compressor station ]" << endl;
			CompressorStation newCS;
			compressorStations.push_back(newCS.AddCompressorStation());
			break;
		}
		case 3:
			cout << "[ View all objects ]" << endl;

			if (pipes.size() == 0)
				cout << "Pipe not found." << endl;
			for (const auto& pipe : pipes)
				pipe.ShowPipe(pipe);

			if (compressorStations.size() == 0)
				cout << "Compressor station not found." << endl;
			for (const auto& compressorStation : compressorStations)
				compressorStation.ShowCompressorStation(compressorStation);
			break;
		case 4:
		{
			cout << "[ Edit pipe ]" << endl;
			Pipe pipe = SelectElement(pipes);
			pipe.EditPipe(pipe);
			break;
		}
		case 5:
		{
			cout << "[ Edit compressor station ]" << endl;
			CompressorStation compressorStation = SelectElement(compressorStations);
			compressorStation.EditCompressorStation(compressorStation);
			break;
		}
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
					pipe.SavePipe(pipe, fout);
				fout << compressorStations.size() << endl;
				for (const auto& compressorStation : compressorStations)
					compressorStation.SaveCompressorStation(compressorStation, fout);
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
					pipe.LoadPipe(pipe, fin);

				int compressorStationSize;
				fin >> compressorStationSize;
				if (compressorStationSize == 0)
					cout << "Compressor stations not found." << endl;
				compressorStations.resize(compressorStationSize);
				for (auto& compressorStation : compressorStations)
					compressorStation.LoadCompressorStation(compressorStation, fin);

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