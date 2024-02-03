#include "Header.h"
#include <windows.h>
char fname[20] = "file1.bin";
int len = sizeof(SPR);
char menu()
{
	setlocale(LC_ALL, "rus");
	cout << endl << "\n\t1-> Добавить запись"
		<< endl << "\t2-> Чтение всех записей"
		<< endl << "\t3-> Чтение записи с N номером"
		<< endl << "\t4-> Пометить на удаление"
		<< endl << "\t5-> Снять пометку на удаление"
		<< endl << "\t6-> Удалить выбранную запись"
		<< endl << "\t7-> Лучший результат фигуриста среди мужчин и женщин в заданной возрастной категории"
		<< endl << "\t0-> EXIT" << endl;
	char s;
	cin >> s;
	return s;
}
void main()
{
	fstream p(fname, ios::app);
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (p)
	{
		p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
		p.close();
	}
	int n, i = 0;
	readPos(p, i);
	do
	{
		char s = menu();
		int kat;
		switch (s)
		{
		case '1':
			cout << "Введите запись: ";
			i++;
			writeNnote(p, i);
			break;
		case '2':
			readAll(p);
			break;
		case '3':
			int nom;
			cout << "\nВведите номер записи: ";
			cin >> nom;
			readN(p, nom);
			break;
		case '4':
			int a, number;
			cout << "\n\tВведите номер записи: ";
			cin >> number;
			a = metkaDel(p, number);
			if (a == 0) cout << "\n\tНет такой записи!";
			break;
		case '5':
			cout << "\n\tВведите номер записи: ";
			cin >> nom;
			cin.ignore(256, '\n');
			UNmetkaDel(p, nom);
			break;
		case '6':
			Delete(p, i);
			cout << ("\n\tГотово!");
			break;
		case '7':
			cout << "\n\tВыберите возрастную категорию : "
				"\n\t1-> 16-18 лет"
				"\n\t2-> 18-25 лет"
				"\n\t3-> 25-45 лет";
			cin >> kat;
			cin.ignore(256, '\n');
			cout << endl << shapka2;
			spiski(p, kat);
			cout << endl << FinishL2;
			break;
		case '0':
			exit(0);
		}
	} while (1);
}

