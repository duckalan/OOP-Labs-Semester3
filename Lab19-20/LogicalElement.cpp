#include <format>
#include "LogicalElement.h"

LogicalElement::LogicalElement(std::string name, uint32_t inputCount) noexcept
	: Element(name, inputCount, OutputCount)
{
	inputValues_ = std::vector<bool>(inputCount);
}

void LogicalElement::SetInputValues(std::vector<bool> inputValues)
{
	if (inputValues.size() != inputCount_)
	{
		throw std::exception("Заданное при создании число и переданное число входов не совпадают");
	}

	inputValues_ = std::move(inputValues);
}

bool LogicalElement::CheckInput(uint32_t index) const
{
	return inputValues_[index];
}

bool LogicalElement::CalculateOutput() const noexcept
{
	bool result = true;

	for (bool input : inputValues_)
	{
		result &= input;
	}

	return result;
}
