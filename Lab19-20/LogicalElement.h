#pragma once

#include <vector>
#include "Element.h"

class LogicalElement : public Element
{
private:
	bool* inputValues_;

public:
	static const uint32_t OutputCount = 1;

	LogicalElement(const char* name, uint32_t inputCount);
	~LogicalElement();
	
	void SetInputValues(bool* inputValues);

	bool CheckInput(uint32_t index) const;

	bool CalculateOutput() const;
};

