#pragma once
#include "Header.h"
ostream& shapka(ostream& stream)//��������� ��������� ��������
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << "|" << setw(9) << "����� ������" << setw(4) << "|" << setw(9) << "�������� �����������" << setw(4) << "|"
		<< setw(15) << "������� ���������" << setw(8) << "|" << setw(13) << "������� ����������" << setw(3) << "|"
		<< setw(12) << "��� ����������" << setw(3) << "|" << setw(11) << "1-� ������" << setw(3) << "|" << setw(11) << "2-� ������" << setw(3) << "|" << setw(11)
		<< "3-� ������" << setw(3) << "|" << setw(7) << "�����" << setw(3) << "|";
	stream << endl << FinishL;
	return stream;
}
ostream& FinishL(ostream& stream)//������� ��������������� �����
{
	stream << setfill('-') << setw(156) << '|' << setfill(' ');
	return stream;
}

ostream& shapka2(ostream& stream)//��������� ��������� ��������
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL2 << endl;
	stream << "|" << setw(9) << "����� ������" << setw(4) << "|" << setw(9) << "�������� �����������" << setw(4) << "|"
		<< setw(15) << "������� ���������" << setw(8) << "|" << setw(13) << "������� ����������" << setw(3) << "|"
		<< setw(12) << "��� ����������" << setw(3) << "|" << setw(11) << "1-� ������" << setw(3) << "|" << setw(11) << "2-� ������" << setw(3) << "|" << setw(11)
		<< "3-� ������" << setw(3) << "|" << setw(7) << "�����" << setw(3) << "|";
	stream << endl << FinishL2;
	return stream;
}
ostream& FinishL2(ostream& stream)//������� ��������������� �����
{
	stream << setfill('=') << setw(156) << '|' << setfill(' ');
	return stream;
}
