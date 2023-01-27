/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 1
* @compiler VC
*/

#pragma once
enum class TypeMaterial { herbs, ores, cloth, essence, Default };
class Materials
{
	TypeMaterial typeMaterial;
	int quantity;
public:
	Materials(const TypeMaterial& = TypeMaterial::Default, const int& = 0);
	TypeMaterial GetType() const;
	int GetQuantity() const;
	void SetType(const TypeMaterial&);
	void SetQuantity(const int&);
	void print() const;
};

