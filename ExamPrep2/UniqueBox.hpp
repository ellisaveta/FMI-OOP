#pragma once
#include <iostream>

template <typename T>
class UniqueBox
{
	T* objs;
	int size;
	bool a;
	bool isItThere(const T&) const;
public:
	UniqueBox();
	void operator +=(const T&);
	T& operator[](const int&) const;
	int get_size() const;
	~UniqueBox();
};

template<typename T>
inline bool UniqueBox<T>::isItThere(const T & obj) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (objs[i] == obj)
		{
			return true;
		}
	}
	return false;
}

template <typename T>
UniqueBox<T>::UniqueBox()
{
	objs = new T[1];
	size = 1;
	a = true;
}

template<typename T>
void UniqueBox<T>::operator+=(const T & obj)
{
	if (!isItThere(obj))
	{
		if (size == 1 && a)
		{
			objs[0] = obj;
			a = false;
			return;
		}
		T* temp = new T[size];
		for (size_t i = 0; i < size; ++i)
		{
			temp[i] = objs[i];
		}
		delete[] objs;
		objs = new T[size + 1];
		for (size_t i = 0; i < size; ++i)
		{
			objs[i] = temp[i];
		}
		objs[size] = obj;
		size++;
		delete[] temp;
		return;
	}
	std::cout << "Object already in UniqueBox!\n";
}

template<typename T>
inline T & UniqueBox<T>::operator[](const int & index) const
{
	if (size != 1)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Invalid index\n";
		}
		return objs[index];
	}
	return objs[0];
}

template <typename T>
int UniqueBox<T>::get_size() const
{
	return size;
}

template <typename T>
UniqueBox<T>::~UniqueBox()
{
	delete[] objs;
	size = 0;
}
