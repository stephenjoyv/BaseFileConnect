#include "Header.h"
#include <windows.h>
char fname[20] = "file1.bin";
int len = sizeof(SPR);
char menu()
{
	setlocale(LC_ALL, "rus");
	cout << endl << "\n\t1-> �������� ������"
		<< endl << "\t2-> ������ ���� �������"
		<< endl << "\t3-> ������ ������ � N �������"
		<< endl << "\t4-> �������� �� ��������"
		<< endl << "\t5-> ����� ������� �� ��������"
		<< endl << "\t6-> ������� ��������� ������"
		<< endl << "\t7-> ������ ��������� ��������� ����� ������ � ������ � �������� ���������� ���������"
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
			cout << "������� ������: ";
			i++;
			writeNnote(p, i);
			break;
		case '2':
			readAll(p);
			break;
		case '3':
			int nom;
			cout << "\n������� ����� ������: ";
			cin >> nom;
			readN(p, nom);
			break;
		case '4':
			int a, number;
			cout << "\n\t������� ����� ������: ";
			cin >> number;
			a = metkaDel(p, number);
			if (a == 0) cout << "\n\t��� ����� ������!";
			break;
		case '5':
			cout << "\n\t������� ����� ������: ";
			cin >> nom;
			cin.ignore(256, '\n');
			UNmetkaDel(p, nom);
			break;
		case '6':
			Delete(p, i);
			cout << ("\n\t������!");
			break;
		case '7':
			cout << "\n\t�������� ���������� ��������� : "
				"\n\t1-> 16-18 ���"
				"\n\t2-> 18-25 ���"
				"\n\t3-> 25-45 ���";
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

