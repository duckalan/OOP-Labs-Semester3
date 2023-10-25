#include <iostream>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include "Array.h"

using std::cout;
using std::cin;

void PrintMenu()
{
	cout << "Выберите действие:\n";
	cout
		<< "1 - вывод обоих массивов;\n"
		<< "2 - вывод элемента массивов;\n"
		<< "3 - сложение массивов;\n"
		<< "4 - вычитание массивов;\n"
		<< "5 - умножение массивов на скаляр;\n"
		<< "6 - деление массивов на скаляр;\n"
		<< "9 - выход из программы.\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Array<int, 5> a1{ 5, 0, 3, 4, 6 };
	Array<int, 5> a2{ 6, 2, 2, 1, 7 };

	cout << "Исходные два массива: \n";
	a1.PrintAll();
	a2.PrintAll();
	cout << '\n';

	bool isContinue = true;
	int userChoise = 0;

	while (isContinue)
	{
		PrintMenu();
		cin >> userChoise;

		switch (userChoise)
		{
		// вывод обоих массивов
		case 1:
			a1.PrintAll();
			a2.PrintAll();

			cout << '\n';
			break;

		// вывод элемента массивов
		case 2:
		{
			int i = 0;
			cout << "Введите номер элемента (0, 1, 2, 3, 4): ";
			cin >> i;

			a1.PrintByIndex(i);
			a2.PrintByIndex(i);

			cout << '\n';
			break;
		}

		// сложение массивов
		case 3:
		{
			cout << "Результат сложения: \n";
			(a1 + a2).PrintAll();
			break;
		}

		// вычитание массивов
		case 4:
		{
			int arrayIndex = 0;
			cout << "Введите номер уменьшаемого массива (0, 1): ";
			cin >> arrayIndex;

			cout << "Результат вычитания: \n";
			if (arrayIndex == 0)
			{
				(a1 - a2).PrintAll();
			}
			else
			{
				(a2 - a1).PrintAll();
			}
			break;
		}

		// умножение массивов на скаляр
		case 5:
		{
			int scalar = 0;
			cout << "Введите скаляр того же типа, что и элементы массивов:\n";
			cin >> scalar;
			
			cout << "Результат умножения массивов на скаляр:\n";
			(a1 * scalar).PrintAll();
			(a2 * scalar).PrintAll();
			break;
		}

		// деление массивов на скаляр
		case 6:
		{
			int scalar = 0;
			cout << "Введите скаляр того же типа, что и элементы массивов:\n";
			cin >> scalar;

			cout << "Результат деления массивов на скаляр:\n";
			(a1 / scalar).PrintAll();
			(a2 / scalar).PrintAll();
			break;
		}

		// выход из программы
		case 9:
			isContinue = false;
			break;
		default:
			break;
		}

		cout << '\n';
	}

	system("pause");
}