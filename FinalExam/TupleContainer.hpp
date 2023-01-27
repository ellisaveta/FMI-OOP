#pragma once
#include "Tuple.hpp"
#include <stdexcept>
template<typename T, typename S>
class TupleContainer
{
	Tuple<T, S>* tuples;
	int size;
public:
	TupleContainer();
	TupleContainer(const TupleContainer&);
	TupleContainer<T, S>& operator=(const TupleContainer<T, S>&);
	int get_count() const;
	void add_tuple(const Tuple<T, S>&);
	Tuple<T, S>& operator[](const int) const;
	bool operator==(const TupleContainer&) const;
	TupleContainer<S, T> swap() const; // тук смених декларацията да не връща по референция
	~TupleContainer();
};

template<typename T, typename S>
TupleContainer<T, S>::TupleContainer()
{
	tuples = nullptr;
	size = 0;
}

template<typename T, typename S>
inline TupleContainer<T, S>::TupleContainer(const TupleContainer & tc)
{
	// това нещо какво пресмята?
	// size = sizeof(tc) / sizeof(Tuple<T, S>);
	// нали и този обект, от който копираш си има променлива size, в която пази големината
	
	size = tc.size; // ПРАВИЛНО
	
	tuples = new Tuple<T, S>[size];
	for (size_t i = 0; i < size; ++i)
	{
		tuples[i] = tc.tuples[i];
	}
}

template<typename T, typename S>
TupleContainer<T, S> & TupleContainer<T, S>::operator=(const TupleContainer<T, S> & tc)
{
	if (this != &tc)
	{
		delete[] tuples;
		// също като в конструктора за копиране
		// size = sizeof(tc) / sizeof(Tuple<T, S>);
		
		size = tc.size;
		tuples = new Tuple<T, S>[size];
		for (size_t i = 0; i < size; ++i)
		{
			tuples[i] = tc.tuples[i];
		}
	}
	return *this;
}

template<typename T, typename S>
inline int TupleContainer<T, S>::get_count() const
{
	return size;
}

template<typename T, typename S>
void TupleContainer<T, S>::add_tuple(const Tuple<T, S> & el)
{
	Tuple<T, S>* temp = new Tuple<T, S>[size];
	for (size_t i = 0; i < size; ++i)
	{
		temp[i] = tuples[i];
	}
	delete[] tuples;
	tuples = new Tuple<T, S>[size + 1];
	for (size_t i = 0; i < size; ++i)
	{
		tuples[i] = temp[i];
	}
	tuples[size] = el;
	size++;
	delete[] temp;
}

template<typename T, typename S>
inline Tuple<T, S>& TupleContainer<T, S>::operator[](const int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Invalid Index");
	}
	return tuples[index];
}

template<typename T, typename S>
bool TupleContainer<T, S>::operator==(const TupleContainer & other) const
{
	if (size != other.get_count())
		return false;
	for (int i = 0; i < size; ++i)
	{
		if (tuples[i] != other.tuples[i])
		{
			return false;
		}
	}
	return true;
}


/* също като в Tuple 
template<typename T, typename S>
TupleContainer<S, T>& TupleContainer<T, S>::swap() const
{
	TupleContainer<S, T>* newTC= new TupleContainer<S, T>;
	for (int i = 0; i < size; ++i)
	{
		newTC->add_tuple(tuples[i].swap());
	}
	return *newTC;
}
*/

// ето я версията без memory leak
template<typename T, typename S>
TupleContainer<S, T> TupleContainer<T, S>::swap() const
{
	TupleContainer<S, T> newTC;
	for (int i = 0; i < size; ++i)
	{
		newTC.add_tuple(tuples[i].swap());
	}
	return newTC;
}

template<typename T, typename S>
TupleContainer<T, S>::~TupleContainer()
{
	delete[] tuples;
}
