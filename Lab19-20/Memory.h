#pragma once

#include <array>
#include "Element.h"

class Memory : public Element
{
	// R D C S
public:
	static const uint32_t InputCount = 4;

private:
	std::array<bool, InputCount> inputValues_;
	bool straightOutput;
	bool inversedOutput;

public:
	Memory(std::string name, uint32_)
};

