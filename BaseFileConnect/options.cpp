#include "Header.h"
#include <windows.h>
void writeNnote(fstream& p, int k) // записать n-ое кол-во записей
{
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	p.clear();
	p.seekg(0, ios::end); //запись в конец
	SPR note;
	note = vvod(k);
	write(p, note);
	p.close();
}
void write(fstream& p, SPR note, int num)//функция записи данных из объекта в файл
{
	p.clear(); //очистка потока
	if (num)
		p.seekg((num - 1) * len, ios::beg);
	p.write((char*)&note, len);
}
SPR vvod(int i)//функция ввода данных с клавиатуры в объект структуры
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int T = 0;
	setlocale(LC_ALL, "rus");
	SPR note;
	cin.clear();
	note.number = i;
	cin.ignore(256, '\n');
	cout << endl << "Введите название организации \t";
	cin.clear();
	cin.get(note.name, 20, '\n');
	cin.ignore(256, '\n');
	cout << endl << "Введите фамилию фигуриста \t";
	cin.clear();
	cin.get(note.famil, 20, '\n');
	cin.ignore(256, '\n');
	cout << endl << "Введите возраст спортсмена\t";
	cin >> note.age;
	cin.ignore(256, '\n');
	cout << endl << "\tВыберите пол спортсмена"
		<< endl << "\t1-> мужской"
		<< endl << "\t2-> женский" << endl;
	cin >> T;
	if (T == 1) strcpy_s(note.sex, "мужской");
	else if (T == 2) strcpy_s(note.sex, "женский");
	cout << endl << "Введите первую оценку (от 0 до 10) \t";
	cin.clear();
	cin >> note.b1;
	cin.ignore(256, '\n');
	cout << endl << "Введите вторую оценку (от 0 до 10) \t";
	cin.clear();
	cin >> note.b2;
	cin.ignore(256, '\n');
	cout << endl << "Введите третью оценку (от 0 до 10) \t";
	cin.clear();
	cin >> note.b3;
	cin.ignore(256, '\n');
	strcpy_s(note.metka, "+");
	return note;
}
fstream& read(fstream& p, SPR& note, int num)//считывает данные из 1 строки файла в объект структуры SPR
{
	p.clear(); //очистка потока
	if (num) //позиционирование
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&note, len);
	return p;
}
void print(SPR note)//Вывод всех атрибутов структуры в консоль 
{
	cout << endl << "|" << setw(4) << note.number << setw(12) << "|" << setw(20) << note.name << setw(4) << "|"
		<< setw(15) << note.famil << setw(10) << "|" << setw(3) << note.age << setw(18) << "|"
		<< setw(12) << note.sex << setw(5) << "|" << setw(2) << note.b1 << setw(12) << "|" << setw(2) << note.b2 << setw(12) << "|" << setw(2) << note.b3 << setw(12) << "|" << note.metka << setw(9) << "|" << endl;
}
void readAll(fstream& p)//Считывает все строки файла и выводит их в консоль с помощью функции  Print
{
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	p.clear();
	p.seekg(0, ios::beg);
	SPR note; // куда читать
	cout << shapka;
	while (read(p, note))
		print(note);
	cout << endl << FinishL;
	p.close();
}
void readPos(fstream& p, int& i) {
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	p.clear();
	p.seekg(0, ios::beg);
	SPR note; // куда читать
	while (read(p, note)) i++;
	p.close();
}
void readN(fstream& p, int N)//считывает данные из n-ой строки в файле, передает их в объект структуры SPR , а этот объект передает функции print для вывода на консоль
{
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	p.clear();
	p.seekg(0, ios::beg);
	SPR note; // куда читать
	if (read(p, note, N))
	{
		cout << shapka;
		print(note);
		cout << endl << FinishL;
	}
	else
		cout << endl << "Такой записи нет!";
	p.close();
}
void UNmetkaDel(fstream& p, int i) {//Снятие метки на удаление
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	p.clear();
	SPR note;
	read(p, note, i);
	if (!strcmp(note.metka, "-"))
	{
		strcpy_s(note.metka, "+");
		write(p, note, i);
	}
	p.close();
}
int metkaDel(fstream& p, int number)//находит строку по номеру и ставит метку для удаления
{
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	p.clear();
	SPR note;
	int kol = 0;
	for (int i = 1; read(p, note, i); i++)
	{
		if (note.number == number)
		{
			strcpy_s(note.metka, "-");
			write(p, note, i);
			kol++;
		}
	}
	p.close();
	return kol;
}
void Delete(fstream& p, int& i)//Удаление строк, помеченных меткой
{
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	fstream p1("temp.txt", ios::app);
	p.clear();
	SPR note;
	int kol = 0;
	for (int i = 1; read(p, note, i); i++)
	{
		if (strcmp(note.metka, "+") == 0)
		{
			kol++;
			note.number = kol;
			write(p1, note);
		}
	}
	p.close();
	p1.close();
	remove(fname);
	rename("temp.txt", fname);
	p.close();
	i = kol;
}
void spiski(fstream& p, int kat)//Находит фигуристов с лучшим средним баллом среди женских и мужских
//возрастных категорий
{
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	SPR note[2], note1;
	int t[] = { 0, 0 };
	p.clear();
	p.seekg(0, ios::beg);
	int k = 0;
	int srb = 0, srb1;
	if (kat == 1) {
		for (int i = 1; read(p, note1, i); i++)
		{
			srb1 = ((note1.b1 + note1.b2 + note1.b3) / 3);
			if (srb1 > srb && strcmp(note1.sex, "мужской") == 0 && note1.age >= 16 && note1.age < 18)
			{
				note[k] = note1;
				srb = srb1;
				t[0] = 1;
			}
		}
		k++;
		srb = 0, srb1 = 0;
		for (int i = 1; read(p, note1, i); i++)
		{
			srb1 = ((note1.b1 + note1.b2 + note1.b3) / 3);
			if (srb1 > srb && strcmp(note1.sex, "женский") == 0 && note1.age >= 16 && note1.age < 18)
			{
				note[k] = note1;
				srb = srb1;
				t[1] = 1;
			}
		}
	}

	else if (kat == 2) {
		for (int i = 1; read(p, note1, i); i++)
		{
			srb1 = ((note1.b1 + note1.b2 + note1.b3) / 3);
			if (srb1 > srb && strcmp(note1.sex, "мужской") == 0 && note1.age >= 18 && note1.age < 25)
			{
				note[k] = note1;
				srb = srb1;
				t[0] = 1;
			}
		}
		k++;
		srb = 0, srb1 = 0;
		for (int i = 1; read(p, note1, i); i++)
		{
			srb1 = ((note1.b1 + note1.b2 + note1.b3) / 3);
			if (srb1 > srb && strcmp(note1.sex, "женский") == 0 && note1.age >= 18 && note1.age < 25)
			{
				note[k] = note1;
				srb = srb1;
				t[1] = 1;
			}
		}
	}
	else if (kat == 3) {
		for (int i = 1; read(p, note1, i); i++)
		{
			srb1 = ((note1.b1 + note1.b2 + note1.b3) / 3);
			if (srb1 > srb && strcmp(note1.sex, "мужской") == 0 && note1.age >= 25 && note1.age < 45)
			{
				note[k] = note1;
				srb = srb1;
				t[0] = 1;
			}
		}
		k++;
		srb = 0, srb1 = 0;
		for (int i = 1; read(p, note1, i); i++)
		{
			srb1 = ((note1.b1 + note1.b2 + note1.b3) / 3);
			if (srb1 > srb && strcmp(note1.sex, "женский") == 0 && note1.age >= 25 && note1.age < 45)
			{
				note[k] = note1;
				srb = srb1;
				t[1] = 1;
			}
		}
	}
	for (int i = 0; i <= 1; i++) if (t[i]) print(note[i]);
	p.close();
}



