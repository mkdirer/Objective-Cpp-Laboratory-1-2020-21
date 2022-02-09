#pragma once 
#include <iostream>
#include <functional>
#include <vector>

using std::cout;
using std::endl;
using std::string;
//przestrzenie nazw cout, endl i string oraz deklaruje potrzebne biblioteki 

// klasa o tablicy intów  
class List{
  private:
  //wektor do przechowywania wartosci typu int
  std::vector<int> tab;

  public:
  //nie ma konstruktora kopiującego bo filter zwraca List nie ma bezpośredniego przypisania typu l2=l1
  //nie ma przeciązenia operator= bo nie przypisujemy np. wartości do obiektu 
  //konstruktor 
  List()= default;
  //motoda dokładania kolejnej wartosci
  void insert(int k);
  //wypisywanie poczatkowej frazy string i wektora 
  void print(string k="") const;
  //zwracanie referencji do danego elementu w wektorze przy pomocy operatora [] który przyjmuje parametr k
  int& operator[](int k); 
  //przefiltrowanie listy zgodnie z funkcja k i zwracanie elementu typu LIsta
  List filter(std::function<bool(int)> k);
};