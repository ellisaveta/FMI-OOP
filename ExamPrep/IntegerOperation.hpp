#pragma once
class IntegerOperation
{
	int* data;
	int result;
	int size;

	void copy(const IntegerOperation&);
	void Free();
public:
	IntegerOperation();
	IntegerOperation(const IntegerOperation&);
	IntegerOperation& operator=(const IntegerOperation&);
	~IntegerOperation();

	void insert(const int);
	int get_result() const;
	void sum();
	void sub();
	void multiply();

	int operator+(IntegerOperation&);
	int operator-(IntegerOperation&);
	int operator*(IntegerOperation&);

};

