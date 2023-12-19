#include <algorithm>
#include <vector>
#include "Book.h"

using std::vector;

typedef multimap<string, Book>::iterator iterator;

void AddBookWithUserInput(multimap<string, Book>& books)
{
	string authorName;
	string title;
	size_t publicationYear;
	size_t count;

	cout << "Введите имя автора книги: ";
	cin >> authorName;

	cout << "Введите название книги: ";
	cin >> title;

	cout << "Введите год издания книги: ";
	cin >> publicationYear;

	cout << "Введите количество книг в библиотеке: ";
	cin >> count;

	cout << '\n';

	Book book(authorName, title, publicationYear, count);
	books.insert(pair<string, Book>(authorName, book));
}

void DeleteBookWithUserInput(multimap<string, Book>& books)
{
	string authorName;
	string title;

	cout << "Введите имя автора удаляемой книги: ";
	cin >> authorName;

	cout << "Введите название удаляемой книги: ";
	cin >> title;

	auto beginAndEndItPair = books.equal_range(authorName);

	for (iterator it = beginAndEndItPair.first;
		it != beginAndEndItPair.second;
		++it)
	{
		if (it->second.Title() == title)
		{
			books.erase(it);
			break;
		}
	}
}

void PrintBooksSortedByAuthor(multimap<string, Book>& books)
{
	vector<Book> vecBooks;
	for (pair<string, Book> pair : books)
	{
		vecBooks.push_back(pair.second);
	}

	std::sort(vecBooks.begin(), vecBooks.end(), [](Book b1, Book b2) {
		return b1.AuthorName() < b2.AuthorName();
		});

	for (Book& book : vecBooks)
	{
		cout << book;
	}
}

void PrintBooksSortedPublicationYear(multimap<string, Book>& books)
{
	vector<Book> vecBooks;
	for (pair<string, Book> pair : books)
	{
		vecBooks.push_back(pair.second);
	}

	std::sort(vecBooks.begin(), vecBooks.end(), [](Book b1, Book b2) {
		return b1.PublicationYear() < b2.PublicationYear();
		});

	for (Book& book : vecBooks)
	{
		cout << book;
	}
}

void PrintMenu()
{
	cout
		<< "\nВыберите действие (введите число): \n"
		<< "	1 - добавить книгу автора;\n"
		<< "	2 - удалить книгу автора;\n"
		<< "	3 - выдача сведений о всех книгах, упорядоченных по авторам;\n"
		<< "	4 - выдача сведений о всех книгах, упорядоченных по годам издания;\n"
		<< "	0 - выход из программы.\n";
}

int main()
{
	multimap<string, Book> books;

	bool isTerminated = false;
	while (!isTerminated)
	{
		int userChoise = 0;
		PrintMenu();
		cin >> userChoise;

		switch (userChoise)
		{
		// Добавить книгу автора
		case 1:
			AddBookWithUserInput(books);
			break;

		// Удалить книгу автора
		case 2:
			DeleteBookWithUserInput(books);
			break;

		// Выдача сведений о всех книгах, упорядоченных по авторам
		case 3:
		{
			PrintBooksSortedByAuthor(books);
			break;
		}

		// Выдача сведений о всех книгах, упорядоченных по годам издания
		case 4:
			PrintBooksSortedPublicationYear(books);
			break;

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