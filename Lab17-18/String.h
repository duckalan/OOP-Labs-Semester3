#pragma once

#include <iostream>
#include <string.h>

class String
{
private:
	size_t _length = 0;
	const char* _internalChars = nullptr;

	void InitByCharArray(const char* str);

	void InitByString(const String& string);

	char* CopyCharArray(const char* arr, int arrLength) const;

public:
	String();

	String(const char* str);

	String(const String& other);

	~String();

	size_t GetLength() const;

	const char* ToCharArray() const;

	String operator =(const char* str);

	String operator =(const String& other);

	String operator +(const String& other) const;

	bool operator ==(const String& other) const;

	bool operator !=(const String& other) const;

	friend std::ostream& operator <<(std::ostream& ostream, String& str);
};

