#include "IntegerOperation.hpp"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


void IntegerOperation::copy(const IntegerOperation & intOp)
{
	if (intOp.data != nullptr)
	{
		size = sizeof(intOp.data) / sizeof(intOp.data[0]);
		data = new int[size];
		for (int i = 0; i < size; ++i)
		{
			data[i] = intOp.data[i];
		}
	}
	data = nullptr;
	size = 0;
}

void IntegerOperation::Free()
{
	delete[] data;
	size = 0;
}

IntegerOperation::IntegerOperation()
{
	data = nullptr;
	result = 0;
	size = 0;
}

IntegerOperation::IntegerOperation(const IntegerOperation & intOp)
{
	copy(intOp);
	result = intOp.get_result();
}

IntegerOperation & IntegerOperation::operator=(const IntegerOperation & intOp)
{
	if (this != &intOp)
	{
		Free();
		copy(intOp);
		result = intOp.get_result();
	}
	return *this;
}

IntegerOperation::~IntegerOperation()
{
	Free();
}

void IntegerOperation::insert(const int el)
{
	int* temp = new int[size];
	for (int i = 0; i < size; ++i)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = new int[size + 1];
	for (int i = 0; i < size; ++i)
	{
		data[i] = temp[i];
	}
	data[size] = el;
	++size;
	delete[] temp;
}

int IntegerOperation::get_result() const
{
	return result;
}

void IntegerOperation::sum()
{
	result = 0;
	for (int i = 0; i < size; ++i)
	{
		result += data[i];
	}
}

void IntegerOperation::sub()
{
	result = 0;
	for (int i = 0; i < size; ++i)
	{
		result -= data[i];
	}
}

void IntegerOperation::multiply()
{
	result = 1;
	for (int i = 0; i < size; ++i)
	{
		result *= data[i];
	}
}

int IntegerOperation::operator+(IntegerOperation & intOp)
{
	sum();
	intOp.sum();
	return result + intOp.get_result();
}

int IntegerOperation::operator-(IntegerOperation & intOp)
{
	sub();
	intOp.sub();
	return result - intOp.get_result();
}

int IntegerOperation::operator*(IntegerOperation & intOp)
{
	multiply();
	intOp.multiply();
	return result * intOp.get_result();
}

