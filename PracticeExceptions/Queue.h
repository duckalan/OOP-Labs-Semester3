#pragma once

#include <stdexcept>
#include "QueueNode.h"

template <class T, size_t size>
class Queue
{
	// ОФОРМИТЬ КАК ПРАКТИЧЕСКУЮ РАБОТУ №2
private:
	QueueNode<T>* head_ = nullptr;
	QueueNode<T>* tail_ = nullptr;
	size_t headIndex_ = 0;
	size_t tailIndex_ = 0;

public:
	void Enqueue(T data)
	{
		if (tailIndex_ >= size - 1)
		{
			throw std::runtime_error("Невозможно добавить элемент в полную очередь");
		}

		if (head_ == nullptr)
		{
			head_ = new QueueNode<T>(data, nullptr);
			tail_ = head_;
		}
		else
		{
			auto newTail = new QueueNode<T>(data, tail_);
			tail_ = newTail;
			tailIndex_++;
		}
	}

	T Dequeue()
	{

		if (head_ == nullptr)
		{
			throw std::runtime_error("Невозможно извлечь элемент из пустой очереди");
		}
		QueueNode<T>* newHead = tail_;

		// Node before new head
		while (newHead != nullptr && newHead->Next() != head_)
		{
			newHead = newHead->Next();
		}

		T returnData = head_->Data();
		//head_->next_ = nullptr;
		delete head_;
		head_ = newHead;
		if (head_ != nullptr)
		{
			head_->next_ = nullptr;
		}
		headIndex_++;

		return returnData;
	}

	void PrintAll()
	{
		QueueNode<T>* next = tail_;
		while (next != nullptr)
		{
			std::cout << next->Data() << " ";
			next = next->Next();
		}
		std::cout << '\n';
	}
};
