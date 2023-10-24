#include <format>
#include "LogicalElement.h"

LogicalElement::LogicalElement(const char* name, uint32_t inputCount)
	: Element(name, inputCount, OutputCount)
{
	inputValues_ = new bool[inputCount];
}

LogicalElement::~LogicalElement()
{
	delete[] inputValues_;
}

void LogicalElement::SetInputValues(bool* inputValues)
{
	memcpy(inputValues_, inputValues, inputCount_ * sizeof(bool));
}

bool LogicalElement::CheckInput(uint32_t index) const
{
	return inputValues_[index];
}

bool LogicalElement::CalculateOutput() const
{
	bool result = true;

	for (size_t i = 0; i < inputCount_; i++)
	{
		result &= inputValues_[i];
	}

	return result;
}
