#include <iostream>
#include <fstream>
#include "Performance.h"
#include "Student.h"
#include "LinkedList.h"

using std::cout;
using std::cin;

void Lab25Part1()
{
    std::ifstream input("C:\\Users\\Duck\\Desktop\\a.txt");

    std::string s1;
    std::string s2;

    while (!input.eof())
    {
        input >> s1;
        input >> s2;

        cout << s2 << ' ' << s1 << ' ';
    }

    cout << '\n';
}

void PrintMenu() 
{
	cout << "Выберите действие: \n"
		<< "0 - завершение программы;\n"
		<< "1 - инициализировать список данными из текстового файла;\n"
		<< "2 - добавить студента;\n"
		<< "3 - удалить студента;\n"
		<< "4 - найти студентов по ФИО;\n"
		<< "5 - найти студентов по дате рождения;\n"
		<< "6 - найти студентов по успеваемости;\n"
		<< "7 - отсортировать список по ФИО;\n"
		<< "8 - отсортировать список по дате рождения;\n"
		<< "9 - отсортировать список по успеваемости;\n"
		<< "10 - вывод списка;\n"
		<< "11 - запись списка в файл.\n"
		<< "12 - чтение бинарного файла\n";
}

int main()
{
	bool isTerminated = false;
	int userChoice;
	LinkedList list;

	while (!isTerminated)
	{
		PrintMenu();
		cin >> userChoice;

		switch (userChoice)
		{
		case 0:
			isTerminated = true;
			break;
		case 1:
		{
			char filePath[255] = "C:\\Users\\Duck\\source\\repos\\duckalan\\OOP-Labs-Semester3\\Lab25\\";
			char fileName[255]{};
			cout << "Введите название файла: ";
			cin >> fileName;
			strcat(filePath, fileName);
			list.InitFromFileTextMode(filePath);
			cout << "Инициализированный список:\n";
			list.Print();
			break;
		}
		case 2:
		{
			size_t addIndex;
			cout << "Введите индекс для добавления студента в диапазоне "
				<< "[0;" << list.GetLength() << "]: ";
			cin >> addIndex;

			Student s = Student::CreateFromUserInput();

			list.InsertAt(addIndex, s);
			cout << "Изменённый список:\n";
			list.Print();
			break;
		}
		case 3:
		{
			size_t deleteIndex;
			cout << "Введите индекс удаляемого студента в диапазоне"
				<< "[0;" << list.GetLength() - 1 << "]: ";
			cin >> deleteIndex;
			list.DeleteAt(deleteIndex);
			cout << "Изменённый список:\n";
			list.Print();
			break;
		}
		case 4:
		{
			char fullName[Student::FullNameLength]{};
			cout << "Введите искомое ФИО длиной до " << Student::FullNameLength - 1
				<< " в формате: <Фамилия> <Инициалы>: ";
			std::cin.get();
			cin.getline(fullName, Student::FullNameLength);

			LinkedList n = list.FindByFullName(fullName);
			if (n.GetLength() == 0)
			{
				cout << "Ни один студент с ФИО " << fullName << " не был найден";
			}
			else
			{
				cout << "Найденные студенты:\n";
				n.Print();
			}
			break;
		}
		case 5:
		{
			char birthDate[Student::FullNameLength]{};
			cout << "Введите искомую дату рождения в формате:"
				<< " ДД.ММ.ГГГГ: ";
			cin >> birthDate;

			LinkedList b = list.FindByBirthDate(birthDate);
			if (b.GetLength() == 0)
			{
				cout << "Ни один студент с датой рождения " << birthDate
					<< " не был найден";
			}
			else
			{
				cout << "Найденные студенты:\n";
				b.Print();
			}
			break;
		}
		case 6:
		{
			int performance;
			cout << "Введите искомую успеваемовть в формате числа от 2 до 5: ";
			cin >> performance;

			LinkedList p = list.FindByPerformance((Performance)performance);
			if (p.GetLength() == 0)
			{
				cout << "Ни один студент с оценкой " << performance
					<< " не был найден";
			}
			else
			{
				cout << "Найденные студенты:\n";
				p.Print();
			}
			break;
		}
		case 7:
			list.SortByFullName();
			cout << "Отсортированный по ФИО список:\n";
			list.Print();
			break;
		case 8:
			list.SortByBirthDate();
			cout << "Отсортированный по дате рождения список:\n";
			list.Print();
			break;
		case 9:
			list.SortByPerformance();
			cout << "Отсортированный по успеваемости список:\n";
			list.Print();
			break;
		case 10:
			list.Print();
			break;
		case 11:
		{
			char filePath[255] = "C:\\Users\\Duck\\source\\repos\\duckalan\\OOP-Labs-Semester3\\Lab25\\";
			char fileName[255]{};
			cout << "Введите название файла: ";
			cin >> fileName;
			strcat(filePath, fileName);

			list.WriteToFileTextMode(filePath, list.GetLength());
			break;
		}
		case 12:
		{
			char filePath[255] = "C:\\Users\\Duck\\source\\repos\\duckalan\\OOP-Labs-Semester3\\Lab25\\";
			char fileName[255]{};
			cout << "Введите название файла: ";
			cin >> fileName;
			strcat(filePath, fileName);
			list.InitFromFileBinaryMode(filePath);
			cout << "Инициализированный список:\n";
			list.Print();
			break;
		}
		default:
			isTerminated = true;
			break;
		}

		cout << std::endl;
	}

	system("pause");
}
