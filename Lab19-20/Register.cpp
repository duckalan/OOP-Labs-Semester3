#include "Register.h"
//#include "Register.h"
//
//Register::Register(std::string name) noexcept
//	: Element(name, InputCount, MemorySize * Memory::OutputCount)
//{
//}
//
//void Register::SetInputValues(std::array<int, InputCount> inputValues) noexcept
//{
//	inputValues_ = std::move(inputValues);
//
//	int inputValuesOffset = 0;
//	for (Memory& trigger: triggers_)
//	{
//		trigger.SetInputValues(
//			inputValues_[Memory::IndexR + inputValuesOffset],
//			inputValues_[Memory::IndexD + inputValuesOffset],
//			inputValues_[Memory::IndexC + inputValuesOffset],
//			inputValues_[Memory::IndexS + inputValuesOffset]);
//
//		inputValuesOffset += Memory::InputCount;
//	}
//}
//
//bool Register::CheckStraightOutput(int triggerIndex) const
//{
//	return triggers_[triggerIndex].GetStraightOutput();
//}
//
//void Register::CalculateState() noexcept
//{
//	for (Memory& trigger : triggers_)
//	{
//		trigger.CalculateState();
//	}
//}
//
//

Register::Register(const char* name)
	: Element(name, InputCount, OutputCount)
{
}

void Register::SetInputValues(int** inputValues)
{
	for (size_t i = 0; i < MemorySize; i++)
	{
		triggers_[i].SetInputValues(
			inputValues[i][Memory::IndexR],
			inputValues[i][Memory::IndexD],
			inputValues[i][Memory::IndexC],
			inputValues[i][Memory::IndexS]);
	}
}

bool Register::CheckStraightOutput(int triggerIndex) const
{
	return triggers_[triggerIndex].GetStraightOutput();
}

void Register::CalculateState()
{
	for (size_t i = 0; i < MemorySize; i++)
	{
		triggers_[i].CalculateState();
	}
}
