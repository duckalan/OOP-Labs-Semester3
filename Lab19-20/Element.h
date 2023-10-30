#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstdint>
#include <string.h>

class Element
{
protected:
	char* name_;
	uint32_t inputCount_;
	uint32_t outputCount_;

public:
	Element(const char* name, uint32_t inputCount, uint32_t outputCount);
	~Element();

	void SetName(const char* name);
};

