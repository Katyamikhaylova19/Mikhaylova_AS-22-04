#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pipe
{
	string kilometerMark;
	double length;
	int diameter;
	bool isRepairing;
};

struct CompressorStation
{
	string name;
	int workshopCount;
	int activeWorkshopCount;
	char efficiency;
};

void AddPipe(vector<Pipe>& pipes)
{
	Pipe newPipe;
	cout << "Введите километровую отметку: ";
	cin.ignore();
	getline(cin, newPipe.kilometerMark);
	cout << "Введите длину трубы: ";
	cin >> newPipe.length;
	cout << "Введите диаметр трубы: ";
	cin >> newPipe.diameter;
	cout << "Труба в ремонте? (1 - в ремонте, пр. - не в ремонте) ";
	int input;
	cin >> input;
	newPipe.isRepairing = input == 1;

	pipes.push_back(newPipe);
}

void AddCompressorStation(vector<CompressorStation>& compressorStations)
{
	CompressorStation newCompressorStation;
	cout << "Введите название компрессорной станции: ";
	cin.ignore();
	getline(cin, newCompressorStation.name);
	cout << "Введите количество цехов: ";
	cin >> newCompressorStation.workshopCount;
	cout << "Введите количество цехов в работе: ";
	cin >> newCompressorStation.activeWorkshopCount;
	cout << "Введите эффективность: ";
	cin >> newCompressorStation.efficiency;

	compressorStations.push_back(newCompressorStation);
}

void ShowPipes(const vector<Pipe>& pipes)
{
	for (const auto& pipe : pipes) //foreach
	{
		cout << endl << "Километрова отметка: " << pipe.kilometerMark << endl;
		cout << "Длина трубы: " << pipe.length << endl;
		cout << "Диаметр трубы: " << pipe.diameter << endl;
		if (pipe.isRepairing)
			cout << "Труба в ремонте." << endl << endl;
		else
			cout << "Труба работает исправно." << endl << endl;
	}
}

void ShowCompressorStations(const vector<CompressorStation>& compressorStations)
{
	for (const auto& compressorStation : compressorStations) //foreach
	{
		cout << endl << "Название компрессорной станции: " << compressorStation.name<< endl;
		cout << "Количество цехов: " << compressorStation.workshopCount << endl;
		cout << "Количество цехов в работе: " << compressorStation.activeWorkshopCount << endl;
		cout << "Эффективность: " << compressorStation.efficiency << endl;

	}
}

int main()
{
	vector<Pipe> pipes = {};
	vector<CompressorStation> compressorStations = {};

	int commandNumber;
	setlocale(LC_ALL, "Rus");//Устанавливаем русскоязычный ввод и вывод
	while (true)
	{
		cout << "МЕНЮ:" << endl
			<< "1. Добавить трубу" << endl
			<< "2. Добавить КС" << endl
			<< "3. Просмотр всех объектов" << endl
			<< "4. Редактировать трубу" << endl
			<< "5. Редактировать КС" << endl
			<< "6. Сохранить" << endl
			<< "7. Загрузить" << endl
			<< "0 и др. Выход из программы" << endl << endl
			<< "Что вы хотите сделать: ";
		cin >> commandNumber;
		switch (commandNumber)
		{
		case 1:
			cout << "Добавление трубы"<<endl;
			AddPipe(pipes);
			break;
		case 2:
			cout << "Добавление КС"<<endl;
			AddCompressorStation(compressorStations);
			break;
		case 3:
			cout << "Просмотр объектов"<<endl;
			ShowPipes(pipes);
			ShowCompressorStations(compressorStations);
			break;
		case 4:
			cout << "Редактирование трубы"<<endl;
			break;
		case 5:
			cout << "Редактирование КС"<<endl;
			break;
		case 6:
			cout << "Сохранение"<<endl;
			break;
		case 7:
			cout << "Загрузка"<<endl;
			break;

		default:
			return 0;
			break;
		}
	}

}

