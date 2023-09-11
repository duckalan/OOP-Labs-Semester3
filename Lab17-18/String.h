#pragma once

#include <iostream>
#include <string.h>

class String
{
private:
	size_t length_;
	const char* internalChars_;

	void InitByCharArray(const char* str);

	void InitByString(const String& string);

	char* CopyCharArray(const char* arr, size_t arrLength) const;

public:
	String();

	String(const char* str);

	String(const String& other);

	~String();

	String operator =(const char* str);

	String operator =(const String& other);

	String operator +(const String& other) const;

	bool operator ==(const String& other) const;

	bool operator !=(const String& other) const;

	friend std::ostream& operator <<(std::ostream& ostream, String& str);

	friend std::ostream& operator <<(std::ostream& ostream, String&& str);
};

