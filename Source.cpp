#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);//кодировка, чтобы выводился рус яз из файла
	SetConsoleOutputCP(1251);
	fstream x,y,z;
	x.exceptions(ifstream::failbit|ifstream::badbit);//инфа об ошибках
	y.exceptions(ifstream::failbit | ifstream::badbit);
	z.exceptions(ifstream::failbit | ifstream::badbit);
	string answers, question, canswer, otvet;
	int shet=0;
	
	try
	{
		x.open("test.txt", fstream::in);//открывам файл c вопросами
		y.open("answers.txt", fstream::in);
		z.open("Correct answers.txt", fstream::in);
		for (int i = 1; i < 11; i++)
		{
			getline(x, question);//получаем всю строку из файла
			cout << question << endl;//выводим в консоль вопрос
			getline(y, answers);
			cout << answers << endl;//выводим в консоль ответы
			cout << "Введите номер ответа: ";
			cin >> otvet;
			getline(z, canswer);
			if (canswer == otvet)
			{
				shet++;
			}
		}
		/*
		y.open("Correct answers.txt", fstream::in);//файл с ответами
		for (int i = 1; i < 11; i++)
		{
			getline(x, question);//получаем всю строку из файла
			cout << question << endl;//выводим в консоль вопрос
			cout << "Введите ответ: ";
			cin >> answer;//вводим ответ без пробела
			getline(y, canswer);//считываем строки из файла с верными ответами
			if (canswer == answer)//проверяем правильный ответ и наш ответ
			{
				chet++;//увеличиваем колво баллов.
			}
		}
		*/
		/*
		while (!x.eof())//пока не конец файла
		{
			getline(x,question);//получаем всю строку из файла
			cout << question<<endl;
		}
		*/
	}
	catch (const ifstream::failure& ex)//вбрасываем информацию об ошибке, если не получилось выполнить то, что в try
	{
		return 0;
	}
	if (shet == 1)
	{
		cout << "\nВы набрали " << shet << " балл.";
	}
	else if (shet > 1 && shet < 5)
	{
		cout << "\nВы набрали " << shet << " баллa.";
	}
	else
	{
		cout << "\nВы набрали " << shet << " баллов.";
	}
	x.close();
	y.close();
}