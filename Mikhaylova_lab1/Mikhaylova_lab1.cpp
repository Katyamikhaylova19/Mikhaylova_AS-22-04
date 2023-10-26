#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Utilities.h"
#include "Pipe.h"
#include "CompressorStation.h"

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

int main()
{
	unordered_map <int, Pipe> pipes = {};
	unordered_map <int, CompressorStation> compressorStations = {};

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
			Pipe pipe;
			cin >> pipe;
			pipes.insert(make_pair(pipe.GetId(), pipe));
			break;
		}
		case 2:
		{
			cout << "[ Add compressor station ]" << endl;
			CompressorStation CS;
			cin >> CS;
			compressorStations.insert(make_pair(CS.GetId(), CS));
			break;
		}
		case 3:
			cout << "[ View all objects ]" << endl;

			if (pipes.size() == 0)
				cout << "Pipe not found." << endl;
			for (const auto& pair : pipes)
				cout << pair.second;

			if (compressorStations.size() == 0)
				cout << "Compressor station not found." << endl;
			for (const auto& pair : compressorStations)
				cout << pair.second;
			break;
		case 4:
		{
			cout << "[ Edit pipe ]" << endl;
			Pipe pipe = SelectElement(pipes);
			EditPipe(pipe);
			break;
		}
		case 5:
		{
			cout << "[ Edit compressor station ]" << endl;
			CompressorStation compressorStation = SelectElement(compressorStations);
			EditCompressorStation(compressorStation);
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
				for (const auto& pair : pipes)
					fout << pair.second;
				fout << compressorStations.size() << endl;
				for (const auto& pair : compressorStations)
					fout << pair.second;
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
		}
		break;
		default:
			cout << "Error! Please enter correct data: " << endl;
			break;
		}
	}
}