#include "String.h"

void String::InitByCharArray(const char* str)
{
	length_ = strlen(str);

	// _length + 1, т.к. strlen не считает символ '\0'
	internalChars_ = CopyCharArray(str, length_ + 1);
}

void String::InitByString(const String& string)
{
	length_ = string.length_;

	// _length + 1, т.к. строка хранит длину без учёта символа '\0'
	internalChars_ = CopyCharArray(string.internalChars_, length_ + 1);
}

char* String::CopyCharArray(const char* arrayToCopy, size_t arrayLength) const
{
	char* temp = new char[arrayLength] {};
	strcpy_s(temp, arrayLength, arrayToCopy);
	return temp;
}

String::String() : length_(0),
				   internalChars_(nullptr) {}

String::String(const char* str)
{
	InitByCharArray(str);
}

String::String(const String& other)
{
	InitByString(other);
}

String::~String()
{
	delete[] internalChars_;
}

String String::operator=(const char* str)
{
	InitByCharArray(str);
	return *this;
}

String String::operator=(const String& other)
{
	InitByString(other);
	return *this;
}

String String::operator+(const String& other) const
{
	// + 1, т.к. длины строк не учитывают символ '\0'
	size_t resultLength = length_ + other.length_ + 1;

	char* result = CopyCharArray(internalChars_, resultLength);
	strcat_s(result, resultLength, other.internalChars_);

	return String(result);
}

bool String::operator==(const String& other) const
{
	if (length_ != other.length_)
	{
		return false;
	}

	if (strcmp(internalChars_, other.internalChars_) != 0)
	{
		return false;
	}

	return true;
}

bool String::operator!=(const String& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& ostream, String& str)
{
	std::cout << str.internalChars_;

	return ostream;
}

std::ostream& operator<<(std::ostream& ostream, String&& str)
{
	std::cout << str.internalChars_;

	return ostream;
}