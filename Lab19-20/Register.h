#pragma once

#include "Element.h"
#include "Memory.h"

// Отчёт по перегрузке взять
class Register : Element
{
public:
	static const int MemorySize = 10;
	static const int InputCount = MemorySize * Memory::InputCount;
	static const int OutputCount = MemorySize * Memory::OutputCount;

private:
	bool resetInput_ = 0;
	bool setInput_ = 0;

	Memory triggers_[MemorySize]{};
	int inputValues_[MemorySize][Memory::InputCount]{};

public:
	Register(const char* name);

	/// <summary>
	/// В следующем порядке: R - сброс, D - информационный вход 
	/// C - синхронизация S - установка значения.
	/// Для каждого из десяти триггеров
	/// </summary>
	void SetInputValues(int** inputValues);

	void SetTriggersState(bool* states);

	bool CheckStraightOutput(int triggerIndex) const;

	void CalculateState();
};

