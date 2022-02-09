#pragma once
#include <iostream>

// klasa reprezentuj�ca samoch�d o konkretnej marce
class Car
{
private:
	// marka samochodu
	std::string mName;
public:
	// konstruktor domy�lny
	Car() = default;
	// konstruktor przypisuj�cy nazw� marki
	Car(std::string name) : mName(name) {}
	// funkcja wypisuj�ca mark� samochodu
	void print() const
	{
		std::cout << "Car: " << mName << std::endl;
	}
};