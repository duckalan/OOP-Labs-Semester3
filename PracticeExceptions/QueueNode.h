#pragma once

template <class T>
class QueueNode 
{
private:
	T data_;

public:
	QueueNode* next_;

	QueueNode(T data, QueueNode* next)
	{
		data_ = data;
		next_ = next;
	}

	T Data() const
	{
		return data_;
	}

	T& Data()
	{
		return data_;
	}

	/*const QueueNode* Next() const 
	{
		return next_;
	}*/

	QueueNode* Next() 
	{
		return next_;
	}
};
