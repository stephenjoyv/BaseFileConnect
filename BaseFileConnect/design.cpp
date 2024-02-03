#pragma once
#include "Header.h"
ostream& shapka(ostream& stream)//формирует заголовки столбцов
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << "|" << setw(9) << "Номер записи" << setw(4) << "|" << setw(9) << "Название организации" << setw(4) << "|"
		<< setw(15) << "Фамилия фигуриста" << setw(8) << "|" << setw(13) << "Возраст спортсмена" << setw(3) << "|"
		<< setw(12) << "Пол спортсмена" << setw(3) << "|" << setw(11) << "1-я оценка" << setw(3) << "|" << setw(11) << "2-я оценка" << setw(3) << "|" << setw(11)
		<< "3-я оценка" << setw(3) << "|" << setw(7) << "Метка" << setw(3) << "|";
	stream << endl << FinishL;
	return stream;
}
ostream& FinishL(ostream& stream)//выводит ограничительные линии
{
	stream << setfill('-') << setw(156) << '|' << setfill(' ');
	return stream;
}

ostream& shapka2(ostream& stream)//формирует заголовки столбцов
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL2 << endl;
	stream << "|" << setw(9) << "Номер записи" << setw(4) << "|" << setw(9) << "Название организации" << setw(4) << "|"
		<< setw(15) << "Фамилия фигуриста" << setw(8) << "|" << setw(13) << "Возраст спортсмена" << setw(3) << "|"
		<< setw(12) << "Пол спортсмена" << setw(3) << "|" << setw(11) << "1-я оценка" << setw(3) << "|" << setw(11) << "2-я оценка" << setw(3) << "|" << setw(11)
		<< "3-я оценка" << setw(3) << "|" << setw(7) << "Метка" << setw(3) << "|";
	stream << endl << FinishL2;
	return stream;
}
ostream& FinishL2(ostream& stream)//выводит ограничительные линии
{
	stream << setfill('=') << setw(156) << '|' << setfill(' ');
	return stream;
}
