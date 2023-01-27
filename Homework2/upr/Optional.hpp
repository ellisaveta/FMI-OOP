#pragma once
#include <iostream>

template <typename T>

class Optional {
	T* valuePrt;
public:
	Optional();
	Optional(const T& value);

	Optional(const Optional&);

	Optional& operator=(const Optional&);

	bool is_none() const;
	T get_value() const;

	void SetValue(const T&);

	~Optional();
};

template<typename T>
inline Optional<T>::Optional()
{
	valuePrt = nullptr;
}

template<typename T>
inline Optional<T>::Optional(const T & value)
{
	this->valuePrt = new T(value);
}

template<typename T>
inline Optional<T>::Optional(const Optional & op)
{
	this->valuePrt = new T(op.get_value());
}

template<typename T>
inline Optional<T> & Optional<T>::operator=(const Optional & other)
{
	if (this != &other)
	{
		delete this->valuePrt;
		if (other.valuePrt == nullptr)
		{
			this->valuePrt = nullptr;
		}
		else
		{
			valuePrt = new T(other.get_value());
		}
	}
	return *this;
}

template<typename T>
inline bool Optional<T>::is_none() const
{
	return valuePrt==nullptr;
}

template<typename T>
inline T Optional<T>::get_value() const
{
	if (is_none())
	{
		std::cout << "No set value!\n";
		return T();
	}
	return *valuePrt;
}

template<typename T>
inline void Optional<T>::SetValue(const T & v)
{
	delete valuePrt;
	this->valuePrt = new T(v);
}

template<typename T>
inline Optional<T>::~Optional()
{
	delete valuePrt;
}
