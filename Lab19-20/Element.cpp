#include "Element.h"

Element::Element(const char* name, uint32_t inputCount, uint32_t outputCount)
	: inputCount_(inputCount), outputCount_(outputCount)
{
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

Element::~Element()
{
	delete[] name_;
}

void Element::SetName(const char* name)
{
	delete[] name_;
	name_ = new char[strlen(name + 1)];
	strcpy(name_, name);
}
