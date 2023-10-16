#pragma once

#include <array>
#include "Memory.h"

class Register
{
public:
	static const int MemoryWidth = 10;

private:
	bool resetInput_;

	bool setInput_;

	std::array<Memory, MemoryWidth> memory_;

	std::array<int, Memory::InputCount * MemoryWidth> inputValues_;

public:
	Register(std::string name);

	void SetInputValues(std::array<int, Memory::InputCount* MemoryWidth> inputValues);
};

