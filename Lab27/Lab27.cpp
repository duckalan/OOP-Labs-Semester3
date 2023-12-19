#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::list;

/*Текст помощи для некоторой программы организован в виде списка.
Каждая компонента текста помощи содержит термин(слово) и текст, содержащий пояснение
к этому термину. Количество строк текста, относящихся к одному термину, составляет от
одного до пяти.
Написать программу, которая обеспечивает:
   начальное формирование текста помощи;
   вывод текста помощи;
   вывод поясняющего текста для заданного термина.
Программа должна обеспечивать диалог с помощью меню и контроль ошибок при вводе.
Для хранения данных использовать контейнерный класс list из STL.*/

void InsertTermWithDescription(const string& term, const string& description, list<string>& helpText)
{
	helpText.push_back(term);
	helpText.push_back(description);
}

list<string> InitializeHelpText()
{
	list<string> helpText;

	int termCount = 0;
	while (true)
	{
		try
		{
			cout << "Введите количество терминов (положительное число): ";
			cin >> termCount;
			if (termCount < 1 || cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::exception("Ошибка при вводе количества терминов. Введите положительное число\n");
			}

			break;
		}
		catch (const std::exception& e)
		{
			cout << e.what() << '\n';
		}
	}

	string term;
	string description;
	for (size_t i = 0; i < termCount; i++)
	{
		cout << "\n------Термин №" << i + 1 << "------\n";
		cout << "Введите название термина: ";
		cin >> term;
		cout << "Введите описание термина: ";
		cin >> description;

		InsertTermWithDescription(term, description, helpText);
	}

	return helpText;
}

void PrintHelpText(const list<string>& helpText)
{
	int termCount = helpText.size() / 2;
	auto currentElementIterator = helpText.begin();

	cout << "\n------Текст помощи------";
	for (size_t i = 0; i < termCount; i++)
	{
		cout << "\n------Термин №" << i + 1 << "------\n";
		cout << "Название термина: " << *(currentElementIterator++) << '\n';
		cout << "Описание термина: " << *(currentElementIterator++) << '\n';
	}
}

void PrintDescriptionForTerm(const string& term, const list<string>& helpText)
{
	auto foundIt = std::find(helpText.begin(), helpText.end(), term);

	if (foundIt == helpText.end())
	{
		cout << "Термин " << term << " не был найден в тексте помощи\n";
	}
	else
	{
		cout << "Описание для термина " << term << ": " << *(++foundIt) << '\n';
	}
}

void PrintMenu()
{
	cout
		<< "\nВыберите действие (введите число): \n"
		<< "	1 - начальное формирование текста помощи;\n"
		<< "	2 - вывод текста помощи;\n"
		<< "	3 - вывод поясняющего текста для заданного термина;\n"
		<< "	0 - выход из программы.\n";
}

int main()
{
	/*
	 Порядок хранения текста помощи следующий:
	 каждый чётный элемент (начиная с 0) - термин,
	 каждый нечётный элемент (начиная с 1) - описание термина.
	 Каждому чётному термину соответствует своё нечётное описание,
	 например 0 и 1, 2 и 3, ...
	*/
	list<string> helpText;

	bool isTerminated = false;
	while (!isTerminated)
	{
		int userChoise = 0;
		PrintMenu();
		cin >> userChoise;

		switch (userChoise)
		{
		// Начальное формирование текста помощи
		case 1:
			helpText = InitializeHelpText();
			break;

		// Вывод текста помощи
		case 2:
			PrintHelpText(helpText);
			break;

		// Вывод поясняющего текста для заданного термина
		case 3:
		{
			string term;
			cout << "Введите термин: ";
			cin >> term;
			PrintDescriptionForTerm(term, helpText);
			break;
		}
		// Выход из программы
		case 0:
			isTerminated = true;
			break;

		default:
			break;
		}
	}

	system("pause");
}