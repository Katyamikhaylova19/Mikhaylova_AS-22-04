#include <iostream>
#include <string>
#include <vector>
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
	char efficiency = 'A';
};

void CheckInput(int& var)
{
	cin >> var;
	while (var <= 0)
	{
		cout << "Ошибка! Введите корректные данные: ";
		cin >> var;
	}
}
void CheckInput(double& var)
{
	cin >> var;
	while (var <= 0)
	{
		cout << "Ошибка! Введите корректные данные: ";
		cin >> var;
	}
}

Pipe AddPipe()
{
	Pipe newPipe;
	cout << "Введите километровую отметку: ";
	cin.ignore();
	getline(cin, newPipe.kilometerMark);
	cout << "Введите длину трубы (в километрах): ";
	CheckInput(newPipe.length);
	cout << "Введите диаметр трубы (в миллиметрах): ";
	CheckInput(newPipe.diameter);
	cout << "Труба в ремонте? (1 - в ремонте, 0 - не в ремонте) ";
	int input;
	cin >> input;
	while (!(input == 0 || input == 1))
	{
		cout << "Ошибка! Введите корректные данные: ";
		cin >> input;
	}
	newPipe.isRepairing = input == 1;

	return newPipe;
}

CompressorStation AddCompressorStation()
{
	CompressorStation newCompressorStation;
	cout << "Введите название компрессорной станции: ";
	cin.ignore();
	getline(cin, newCompressorStation.name);
	cout << "Введите количество цехов: ";
	CheckInput(newCompressorStation.workshopCount);
	cout << "Введите количество цехов в работе: ";
	CheckInput(newCompressorStation.activeWorkshopCount);
	while (newCompressorStation.workshopCount < newCompressorStation.activeWorkshopCount)
	{
		cout << "Ошибка! Количество цехов в работе не может превышать количество цехов."<<endl
			<<"Введите корректные данные :";
		cin >> newCompressorStation.activeWorkshopCount;
	}
	cout << "Введите эффективность от A до G: ";
	cin >> newCompressorStation.efficiency;
	while (!((int)newCompressorStation.efficiency >= 'A' && (int)newCompressorStation.efficiency <= 'G'))
	{
		cout << "Ошибка! Введите корректные данные: ";
		cin >> newCompressorStation.efficiency;
	}
	return newCompressorStation;
}

void ShowPipes(const Pipe& newPipe)
{
	if (newPipe.length == 0)
		cout << "Трубы нет." << endl;
	else
	{
		cout << endl << "Километровая отметка: " << newPipe.kilometerMark << endl;
		cout << "Длина трубы: " << newPipe.length << " км" << endl;
		cout << "Диаметр трубы: " << newPipe.diameter << " мм" << endl;
		if (newPipe.isRepairing)
			cout << "Труба в ремонте." << endl << endl;
		else
			cout << "Труба работает исправно." << endl << endl;
	}
}

void ShowCompressorStations(const CompressorStation& newCompressorStation)
{
	if (newCompressorStation.workshopCount == 0)
		cout << "Комрессорной станции нет." << endl;
	else 
	{
		cout << endl << "Название компрессорной станции: " << newCompressorStation.name << endl;
		cout << "Количество цехов: " << newCompressorStation.workshopCount << endl;
		cout << "Количество цехов в работе: " << newCompressorStation.activeWorkshopCount << endl;
		cout << "Эффективность: " << newCompressorStation.efficiency << endl << endl;
	}
}

int main()
{
	Pipe pipe;
	CompressorStation cs;

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
			<< "0. Выход из программы" << endl << endl
			<< "Что вы хотите сделать: ";
		cin >> commandNumber;
		switch (commandNumber)
		{
		case 0:
			cout << "Выход из программы" << endl;
			return 0;
			break;
		case 1:
			cout << "Добавление трубы"<<endl;
			pipe = AddPipe();
			break;
		case 2:
			cout << "Добавление КС"<<endl;
			cs = AddCompressorStation();
			break;
		case 3:
			cout << "Просмотр объектов"<<endl;
			ShowPipes(pipe);
			ShowCompressorStations(cs);
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
			cout << "Ошибка! Введите корректные данные" << endl;
			break;
		}
	}

}

