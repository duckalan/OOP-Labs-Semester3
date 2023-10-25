#include <iostream>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include "Array.h"

using std::cout;
using std::cin;

void PrintMenu()
{
	cout << "�������� ��������:\n";
	cout
		<< "1 - ����� ����� ��������;\n"
		<< "2 - ����� �������� ��������;\n"
		<< "3 - �������� ��������;\n"
		<< "4 - ��������� ��������;\n"
		<< "5 - ��������� �������� �� ������;\n"
		<< "6 - ������� �������� �� ������;\n"
		<< "9 - ����� �� ���������.\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Array<int, 5> a1{ 5, 0, 3, 4, 6 };
	Array<int, 5> a2{ 6, 2, 2, 1, 7 };

	cout << "�������� ��� �������: \n";
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
		// ����� ����� ��������
		case 1:
			a1.PrintAll();
			a2.PrintAll();

			cout << '\n';
			break;

		// ����� �������� ��������
		case 2:
		{
			int i = 0;
			cout << "������� ����� �������� (0, 1, 2, 3, 4): ";
			cin >> i;

			a1.PrintByIndex(i);
			a2.PrintByIndex(i);

			cout << '\n';
			break;
		}

		// �������� ��������
		case 3:
		{
			cout << "��������� ��������: \n";
			(a1 + a2).PrintAll();
			break;
		}

		// ��������� ��������
		case 4:
		{
			int arrayIndex = 0;
			cout << "������� ����� ������������ ������� (0, 1): ";
			cin >> arrayIndex;

			cout << "��������� ���������: \n";
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

		// ��������� �������� �� ������
		case 5:
		{
			int scalar = 0;
			cout << "������� ������ ���� �� ����, ��� � �������� ��������:\n";
			cin >> scalar;
			
			cout << "��������� ��������� �������� �� ������:\n";
			(a1 * scalar).PrintAll();
			(a2 * scalar).PrintAll();
			break;
		}

		// ������� �������� �� ������
		case 6:
		{
			int scalar = 0;
			cout << "������� ������ ���� �� ����, ��� � �������� ��������:\n";
			cin >> scalar;

			cout << "��������� ������� �������� �� ������:\n";
			(a1 / scalar).PrintAll();
			(a2 / scalar).PrintAll();
			break;
		}

		// ����� �� ���������
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