#pragma once 
#include <iostream>
#include <utility>
#include <cstring>

using namespace std;
//dołaczanie bibliotek


class MyArray
{
  private:
  int _rozmiar=0;
  //rozmiar tablicy

  int *tab=nullptr;
  // tablica na zmienne

  MyArray* next=nullptr;
  //wskaźnik do następnej tablicy 
  
  public:
  
  MyArray(int n);
  //konstruktor domyslny
  
  MyArray(const MyArray &k);
  //konstruktor kopiujacy
  
  MyArray(MyArray &&k);
  //konstruktor przenoszacy

  ~MyArray();
  //destruktor
  
  int& operator[](int i);
  //operator nawiasów kwadratowych 
  
  friend std::ostream& operator<<(std::ostream &o, const MyArray k);
  //operator wypisywania
  
  const int& operator[](int i) const;
  //zwracajacy const double operator nawiasów kwadratowych
  
  void print(string k);
  //metoda wypisujaca nasza tablicę z początkowym napisem konstruktor

  int size();
  //metoda metoda zwracajaca rozmiar tabicy 

  MyArray& getNext();
  //metoda zwracajaca wskaźnik na następny MyArray

  MyArray operator++(int);
  //operator inkrementacji wartości w tablicy

  MyArray& operator--();
  //operator dekrementacji wartosci w tablicy

  MyArray& operator=(const MyArray& k);
  //operator przypisania 

  void operator+=(MyArray& k);
  // dopisywanie tablicy

  void operator+=(MyArray&& k);
  //operator dopisywania tabicy z przenoszeniem 

};