#include "Vector4D.hpp"

Vector4D::Vector4D(double a, double b, double c, double d)
{
	vector = new double[4];
	this->vector[0] = a;
	this->vector[1] = b;
	this->vector[2] = c;
	this->vector[3] = d;
}

Vector4D::Vector4D(const Vector4D & other)
{
	vector = new double[4];
	for (int i = 0; i < 4; ++i)
	{
		this->vector[i] = other[i];
	}
}

Vector4D::~Vector4D()
{
	delete[]vector;
}

double & Vector4D::operator[](int i)
{
	return this->vector[i];
}

const double & Vector4D::operator[](int i) const
{
	return this->vector[i];
}

Vector4D & Vector4D::operator=(const Vector4D & other)
{
	for (int i = 0; i < 4; ++i)
	{
		this->vector[i] = other[i];
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D & other) const
{
	return vector[0] == other[0] && vector[1] == other[1] && vector[2] == other[2] && vector[3] == other[3];
}

bool Vector4D::operator!=(const Vector4D & other) const
{
	return vector[0] != other[0] || vector[1] != other[1] || vector[2] != other[2] || vector[3] != other[3];
}

Vector4D  Vector4D::operator+(const Vector4D & sec) const
{
	Vector4D vec(vector[0] + sec[0], vector[1] + sec[1], vector[2] + sec[2], vector[3] + sec[3]);
	return vec;
}

Vector4D & Vector4D::operator+=(const Vector4D & other)
{
	for (int i = 0; i < 4; ++i)
	{
		this->vector[i] += other[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D & sec) const
{
	Vector4D vec(vector[0] - sec[0], vector[1] - sec[1], vector[2] - sec[2], vector[3] - sec[3]);
	return vec;
}

Vector4D & Vector4D::operator-=(const Vector4D & other)
{
	for (int i = 0; i < 4; ++i)
	{
		this->vector[i] -= other[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D & other) const
{
	Vector4D vec(vector[0] * other[0], vector[1] * other[1], vector[2] * other[2], vector[3] * other[3]);
	return vec;
}

Vector4D Vector4D::operator*(const double & x) const
{
	Vector4D vec(vector[0] * x, vector[1] * x, vector[2] * x, vector[3] * x);
	return vec;
}

Vector4D & Vector4D::operator*=(const Vector4D & other)
{
	for (int i = 0; i < 4; ++i)
	{
		this->vector[i] *= other[i];
	}
	return *this;
}

Vector4D & Vector4D::operator*=(const double & x)
{
	for (int i = 0; i < 4; ++i)
	{
		this->vector[i] *= x;
	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D & other) const
{
	Vector4D vec(vector[0] / other[0], vector[1] / other[1], vector[2] / other[2], vector[3] / other[3]);
	return vec;
}

Vector4D & Vector4D::operator/=(const Vector4D & other)
{
	for (int i = 0; i < 4; ++i)
	{
		this->vector[i] /= other[i];
	}
	return *this;
}

bool Vector4D::operator<(const Vector4D & other) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (vector[i] != other[i])
		{
			return vector[i] < other[i];
		}
	}
	return false;
}

bool Vector4D::operator>(const Vector4D & other) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (vector[i] != other[i])
		{
			return vector[i] > other[i];
		}
	}
	return false;
}

bool Vector4D::operator<=(const Vector4D & other) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (vector[i] != other[i])
		{
			return vector[i] < other[i];
		}
	}
	return true;
}

bool Vector4D::operator>=(const Vector4D & other) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (vector[i] != other[i])
		{
			return vector[i] > other[i];
		}
	}
	return true;
}

bool Vector4D::operator!() const
{
	Vector4D vec(0, 0, 0, 0);
	return *this == vec;
}

Vector4D Vector4D::operator-() const
{
	Vector4D vec(-vector[0], -vector[1], -vector[2], -vector[3]);
	return vec;
}

