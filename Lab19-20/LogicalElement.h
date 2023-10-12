#pragma once

#include <vector>
#include "Element.h"

const uint32_t OutputCount = 1;

class LogicalElement : public Element
{
private:
	std::vector<bool> inputValues_;

public:
	static const uint32_t OutputCount = 1;

	LogicalElement(std::string name, uint32_t inputCount) noexcept;
	
	void SetInputValues(std::vector<bool> inputValues);

	bool CheckInput(uint32_t index) const;

	bool CalculateOutput() const noexcept;
};

