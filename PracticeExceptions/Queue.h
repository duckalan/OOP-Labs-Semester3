#pragma once

#include <stdexcept>

template <class T, int maxSize>
class Queue
{
private:
	T queue_[maxSize]{};
	int headIndex_ = 0;
	int tailIndex_ = 0;
	int currentSize = 0;

public:
	void Enqueue(T data)
	{
		if (currentSize == maxSize)
		{
			throw std::runtime_error("Невозможно добавить элемент в переполненную очередь\n");
		}
		else
		{
			queue_[tailIndex_] = data;
			tailIndex_ = (tailIndex_ + 1) % maxSize;
			currentSize++;
		}
	}

	T Dequeue()
	{
		if (currentSize == 0)
		{
			throw std::runtime_error("Невозможно извлечь элемент из пустой очереди\n");
		}
		else
		{
			T returnData = queue_[headIndex_];
			headIndex_ = (headIndex_ + 1) % maxSize;
			currentSize--;

			return returnData;
		}
	}

	void PrintAll()
	{
		if (currentSize == 0)
		{
			std::cout << "Очередь пуста\n";
			return;
		}

		int currentIndex = tailIndex_ - 1;
		
		if (currentIndex < 0)
		{
			currentIndex = maxSize - 1;
		}

		while (currentIndex != headIndex_)
		{
			std::cout << queue_[currentIndex] << " ";

			currentIndex = (currentIndex - 1) % maxSize;

			if (currentIndex < 0)
			{
				currentIndex = maxSize - 1;
			}
		}

		std::cout << queue_[currentIndex] << " ";

		std::cout << '\n';
	}
};
