#pragma once

#include <array>
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
	std::array<bool, InputCount> inputValues_;

	bool oldC_;
	bool straightOutput_;
	bool inversedOutput_;

public:
	Memory(std::string name) noexcept;

	/// <summary>
	/// В следующем порядке: R - сброс, D - информационный вход 
	/// C - синхронизация S - установка значения
	/// </summary>
	void SetInputValues(uint32_t r, uint32_t d, uint32_t c, uint32_t s) noexcept;

	bool GetStraightOutput() const noexcept;

	bool GetInversedOutput() const noexcept;

	bool CheckInput(uint32_t index) const;

	void CalculateState() noexcept;

	bool operator ==(const Memory& other) const;
};

