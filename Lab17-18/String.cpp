#include "String.h"

void String::InitByCharArray(const char* str)
{
	_length = strlen(str);

	// _length + 1, т.к. strlen не считает символ '\0'
	_internalChars = CopyCharArray(str, _length + 1ul);
}

void String::InitByString(const String& string)
{
	_length = string.GetLength();

	// _length + 1, т.к. строка хранит длину без учёта символа '\0'
	_internalChars = CopyCharArray(string.ToCharArray(), _length + 1ul);
}

char* String::CopyCharArray(const char* arrayToCopy, int arrayLength) const
{
	char* temp = new char[arrayLength] {};
	strcpy_s(temp, arrayLength, arrayToCopy);
	return temp;
}

String::String()
{
}

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
	if (_internalChars != nullptr)
	{
		delete[] _internalChars;
	}
}

size_t String::GetLength() const
{
	return _length;
}

const char* String::ToCharArray() const
{
	return _internalChars;
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
	int resultLength = _length + other.GetLength() + 1ul;

	char* result = CopyCharArray(_internalChars, resultLength);
	strcat_s(result, resultLength, other.ToCharArray());

	return String(result);
}

bool String::operator==(const String& other) const
{
	if (_length != other.GetLength())
	{
		return false;
	}

	auto otherCharArray = other.ToCharArray();

	if (strcmp(_internalChars, otherCharArray) != 0)
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
	std::cout << str.ToCharArray();

	return ostream;
}
