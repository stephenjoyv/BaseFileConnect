#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
extern int len;
extern char fname[20]; // ���������� ��� �������� �������� ������ �����
struct SPR
{
	int number = 0;//����� ������
	char name[20];//�������� �����������
	char famil[20];//������� ���������
	float age;//������� ���������
	char sex[8];// ��� ���������
	float b1;//������ ������
	float b2;//������ ������
	float b3;//������ ������
	char metka[2];//���� ��� �����

};
ostream& FinishL(ostream& stream);
ostream& FinishL2(ostream& stream);
ostream& shapka(ostream& stream);
ostream& shapka2(ostream& stream);
void write(fstream& p, SPR note, int num = 0);
void print(SPR note);
SPR vvod(int i);
void writeNnote(fstream& p, int k);
fstream& read(fstream& p, SPR& note, int num = 0);
void readAll(fstream& p);
void readN(fstream& p, int N);
int metkaDel(fstream& p, int number);
void UNmetkaDel(fstream& p, int n);
void spiski(fstream& p, int age);
void Delete(fstream& p, int& i);
void readPos(fstream& p, int& i);