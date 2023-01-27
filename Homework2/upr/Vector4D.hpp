#pragma once

class Vector4D {

	double *vector;

public:

	Vector4D(double, double, double, double);

	Vector4D(const Vector4D&);
	~Vector4D();

	double& operator[](int);
	const double& operator[](int) const;
	Vector4D& operator=(const Vector4D&);
	bool operator==(const Vector4D&) const;
	bool operator!=(const Vector4D&) const;
	Vector4D operator+(const Vector4D&) const;
	Vector4D& operator+=(const Vector4D&);
	Vector4D operator-(const Vector4D&) const;
	Vector4D& operator-=(const Vector4D&);
	Vector4D operator*(const Vector4D&) const;
	Vector4D operator*(const double&) const;
	Vector4D& operator*=(const Vector4D&);
	Vector4D& operator*=(const double&);
	Vector4D operator/(const Vector4D&) const;
	Vector4D& operator/=(const Vector4D&);
	bool operator<(const Vector4D&) const;
	bool operator>(const Vector4D&) const;
	bool operator<=(const Vector4D&) const;
	bool operator>=(const Vector4D&) const;
	bool operator!() const;
	Vector4D operator-() const;
};

