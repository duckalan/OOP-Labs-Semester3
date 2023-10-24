#include "Memory.h"

Memory::Memory()
	: Element("", InputCount, OutputCount)
{
}

Memory::Memory(const char* name)
	: Element(name, InputCount, OutputCount)
{
}

void Memory::SetInputValues(int r, int d, int c, int s)
{
	oldC_ = inputValues_[IndexC];

	inputValues_[IndexR] = r;
	inputValues_[IndexD] = d;
	inputValues_[IndexC] = c;
	inputValues_[IndexS] = s;
}

bool Memory::GetStraightOutput() const
{
	return straightOutput_;
}

bool Memory::GetInversedOutput() const
{
	return inversedOutput_;
}

bool Memory::CheckInput(uint32_t index) const
{
	if (index >= InputCount)
	{
		throw std::exception("Индекс выходит за границы массива");
	}

	return inputValues_[index];
}

void Memory::CalculateState()
{
	if ((inputValues_[IndexS] == 0 && inputValues_[IndexR] == 0)
		&& oldC_ == 0 && inputValues_[IndexC] == 1)
	{
		straightOutput_ = inputValues_[IndexD];
		inversedOutput_ = !straightOutput_;
	}
	else if (inputValues_[IndexS] != inputValues_[IndexR])
	{
		straightOutput_ = inputValues_[IndexS];
		inversedOutput_ = !straightOutput_;
	}
}

bool Memory::operator==(const Memory& other) const
{
	return straightOutput_ == other.straightOutput_
		   && oldC_ == other.oldC_;
}
