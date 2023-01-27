#pragma once

template <typename T, typename S>
class Tuple
{
	T first;
	S second;
public:
	Tuple();
	Tuple(const T&, const S&);
	Tuple(const Tuple<T, S>&);
	Tuple<T, S>& operator=(const Tuple<T, S>&);
	T get_first() const;
	S get_second() const;
	void set_first(const T&);
	void set_second(const S&);
	Tuple<S, T> swap() const; //смених декларацията да не се връща по референция
	bool operator==(const Tuple&) const;
	bool operator!=(const Tuple&) const;
	~Tuple();
};

template<typename T, typename S>
Tuple<T, S>::Tuple()
{
}

template<typename T, typename S>
Tuple<T, S>::Tuple(const T & f, const S & s) : first(f), second(s){}

template<typename T, typename S>
Tuple<T, S>::Tuple(const Tuple<T, S>& other)
{
	this->first = other.get_first();
	this->second = other.get_second();
}

template<typename T, typename S>
Tuple<T, S> & Tuple<T, S>::operator=(const Tuple<T, S>& other)
{
	if (this != &other)
	{
		this->first = other.get_first();
		this->second = other.get_second();
	}
	return *this;
}

template<typename T, typename S>
T Tuple<T, S>::get_first() const
{
	return first;
}

template<typename T, typename S>
S Tuple<T, S>::get_second() const
{
	return second;
}

template<typename T, typename S>
void Tuple<T, S>::set_first(const T & f)
{
	first = f;
}

template<typename T, typename S>
void Tuple<T, S>::set_second(const S & s)
{
	second = s;
}


/*
 Тук ако създаваш обекти в heap-а и никъде не ги триеш, затова тук се получава memory leak

template<typename T, typename S>
Tuple<S, T>& Tuple<T, S>::swap() const
{
	Tuple<S, T>* newTuple = new Tuple<S, T>(this->get_second(), this->get_first());
	return *newTuple;
}
*/

// ето версия без memory leak
template<typename T, typename S>
Tuple<S, T> Tuple<T, S>::swap() const
{
	Tuple<S, T> newTuple(this->get_second(), this->get_first());
	return newTuple;
}


template<typename T, typename S>
bool Tuple<T, S>::operator==(const Tuple & other) const
{
	return this->first == other.get_first() && this->second == other.get_second();
}

template<typename T, typename S>
bool Tuple<T, S>::operator!=(const Tuple & other) const
{
	return this->first != other.get_first() || this->second != other.get_second();
}

template<typename T, typename S>
Tuple<T, S>::~Tuple()
{
}