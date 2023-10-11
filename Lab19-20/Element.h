#pragma once

#include <cstdint>
#include <string>

class Element
{
protected:
	std::string name_;
	uint32_t inputCount_;
	uint32_t outputCount_;

public:
	Element(std::string name, uint32_t inputCount, uint32_t outputCount) noexcept;

	void SetName(std::string name) noexcept;
};

