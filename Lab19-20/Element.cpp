#include "Element.h"

Element::Element(std::string name, uint32_t inputCount, uint32_t outputCount) noexcept
	: name_(std::move(name)),
	  inputCount_(inputCount),
	  outputCount_(outputCount)
{
}

void Element::SetName(std::string name) noexcept
{
	name_ = std::move(name);
}
