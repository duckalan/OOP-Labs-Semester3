#pragma once

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::multimap;
using std::string;
using std::pair;

class Book
{
private:
	/// <summary>
	/// Фамилия и инициалы автора.
	/// </summary>
	string authorName_;

	/// <summary>
	/// Название книги.
	/// </summary>
	string title_;

	/// <summary>
	/// Год издания книги.
	/// </summary>
	size_t publicationYear_;

	/// <summary>
	/// Количество книг в библиотеке.
	/// </summary>
	size_t count_;

public:
	Book(string authorName, string title, size_t publicationYear, size_t count)
	{
		authorName_ = authorName;
		title_ = title;
		publicationYear_ = publicationYear;
		count_ = count;
	}

	string AuthorName() const
	{
		return authorName_;
	}

	string Title() const
	{
		return title_;
	}

	size_t PublicationYear()
	{
		return publicationYear_;
	}

	friend std::ostream& operator<<(std::ostream& ostream, Book& book)
	{
		cout
			<< "Название книги: " << book.title_ << '\n'
			<< "Автор книги: " << book.authorName_ << '\n'
			<< "Год издания: " << book.publicationYear_ << '\n'
			<< "Количество книг в библиотеке: " << book.count_ << '\n';

		return ostream;
	}
};

