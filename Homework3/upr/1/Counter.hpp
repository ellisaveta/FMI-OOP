#pragma once
class Counter
{
protected:
	int total;
	unsigned step;

public:
	Counter();
	Counter(const int&);
	Counter(const int&, const unsigned&);

	virtual void increment();

	int getTotal() const;
	const unsigned getStep() const;
};

