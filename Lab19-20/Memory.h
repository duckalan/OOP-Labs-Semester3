#pragma once

#include "Element.h"

class Memory : public Element
{
public:
	static const uint32_t InputCount = 4;
	static const uint32_t OutputCount = 2;

	/// <summary>
	/// Индекс входа сброса.
	/// </summary>
	static const uint32_t IndexR = 0;

	/// <summary>
	/// Индекс информационного входа.
	/// </summary>
	static const uint32_t IndexD = 1;

	/// <summary>
	/// Индекс синхронизирующего входа.
	/// </summary>
	static const uint32_t IndexC = 2;

	/// <summary>
	/// Индекс входа установки значения.
	/// </summary>
	static const uint32_t IndexS = 3;

private:
	bool inputValues_[InputCount] {};

	bool oldC_ = 0;
	bool straightOutput_ = 0;
	bool inversedOutput_ = 1;

public:
	Memory();

	Memory(const char* name);

	/// <summary>
	/// В следующем порядке: R - сброс, D - информационный вход 
	/// C - синхронизация S - установка значения
	/// </summary>
	void SetInputValues(int r, int d, int c, int s);

	void SetState(bool state);

	bool GetStraightOutput() const;

	bool GetInversedOutput() const;

	bool CheckInput(uint32_t index) const;

	void CalculateState();

	bool operator ==(const Memory& other) const;
};

