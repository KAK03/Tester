#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);//���������, ����� ��������� ��� �� �� �����
	SetConsoleOutputCP(1251);
	fstream x,y,z;
	x.exceptions(ifstream::failbit|ifstream::badbit);//���� �� �������
	y.exceptions(ifstream::failbit | ifstream::badbit);
	z.exceptions(ifstream::failbit | ifstream::badbit);
	string answers, question, canswer, otvet;
	int shet=0;
	
	try
	{
		x.open("test.txt", fstream::in);//�������� ���� c ���������
		y.open("answers.txt", fstream::in);
		z.open("Correct answers.txt", fstream::in);
		for (int i = 1; i < 11; i++)
		{
			getline(x, question);//�������� ��� ������ �� �����
			cout << question << endl;//������� � ������� ������
			getline(y, answers);
			cout << answers << endl;//������� � ������� ������
			cout << "������� ����� ������: ";
			cin >> otvet;
			getline(z, canswer);
			if (canswer == otvet)
			{
				shet++;
			}
		}
		/*
		y.open("Correct answers.txt", fstream::in);//���� � ��������
		for (int i = 1; i < 11; i++)
		{
			getline(x, question);//�������� ��� ������ �� �����
			cout << question << endl;//������� � ������� ������
			cout << "������� �����: ";
			cin >> answer;//������ ����� ��� �������
			getline(y, canswer);//��������� ������ �� ����� � ������� ��������
			if (canswer == answer)//��������� ���������� ����� � ��� �����
			{
				chet++;//����������� ����� ������.
			}
		}
		*/
		/*
		while (!x.eof())//���� �� ����� �����
		{
			getline(x,question);//�������� ��� ������ �� �����
			cout << question<<endl;
		}
		*/
	}
	catch (const ifstream::failure& ex)//���������� ���������� �� ������, ���� �� ���������� ��������� ��, ��� � try
	{
		return 0;
	}
	if (shet == 1)
	{
		cout << "\n�� ������� " << shet << " ����.";
	}
	else if (shet > 1 && shet < 5)
	{
		cout << "\n�� ������� " << shet << " ����a.";
	}
	else
	{
		cout << "\n�� ������� " << shet << " ������.";
	}
	x.close();
	y.close();
}