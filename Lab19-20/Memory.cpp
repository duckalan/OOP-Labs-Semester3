#include "Memory.h"

Memory::Memory(std::string name) noexcept
	: Element(name, InputCount, OutputCount)
{
	inputValues_ = std::array<bool, InputCount>();
	straightOutput_ = false;
	inversedOutput_ = true;
	oldC_ = 0;
}

void Memory::SetInputValues(uint32_t r, uint32_t d, uint32_t c, uint32_t s) noexcept
{
	oldC_ = inputValues_[IndexC];

	inputValues_[IndexR] = r;
	inputValues_[IndexD] = d;
	inputValues_[IndexC] = c;
	inputValues_[IndexS] = s;
}

bool Memory::GetStraightOutput() const noexcept
{
	return straightOutput_;
}

bool Memory::GetInversedOutput() const noexcept
{
	return inversedOutput_;
}

bool Memory::CheckInput(uint32_t index) const
{
	return inputValues_[index];
}

void Memory::CalculateState() noexcept
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
