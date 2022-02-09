#pragma once

// klasa reprezentuj�ca fabryk� przedmiot�w r�nych typ�w
class Factory
{
private:
	// struktura pozwalaj�ca na przetrzymywanie obiektu dowolnego typu, jako osobnej instancji klasy oraz informacji o tym, czy zosta� utworzony
	template<typename T>
	struct Item
	{
		static T item;
		static bool isFilled;
	};

public:
	// utworzenie obiektu dowolnego typu o podanej warto�ci
	template <typename T>
	void prototype(T value) const;

	// funkcja wypisuj�ca warto�� stworzonego obiektu
	template<typename T>
	T manufacture() const;
};

// przypisanie warto�ci do zmiennej statycznej, mo�liwe poniewa� konstruktor domy�lny Car() istnieje
template<typename T>
T Factory::Item<T>::item = T();

// przypisanie warto�ci do kolejnej zmiennej statycznej, domy�lnie obiekt nie jest utworzony
template<typename T>
bool Factory::Item<T>::isFilled = false;

template <typename T>
void Factory::prototype(T value) const
{
	// przypisanie warto�ci
	Item<T>::item = value;
	// okre�lenie stanu utworzenia
	Item<T>::isFilled = true;
}

template<typename T>
T Factory::manufacture() const
{
	// sprawdzam, czy obiekt zosta� ju� utworzony ( prototype() )
	if (Item<T>::isFilled)
		return Item<T>::item;
	// je�li nie rzucam wyj�tek
	throw std::runtime_error("no prototype for this type");
}