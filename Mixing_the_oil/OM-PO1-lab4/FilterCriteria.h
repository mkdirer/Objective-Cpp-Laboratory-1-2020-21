#pragma once 
#include <iostream>
#include <functional>
#include <vector>


//klasa kontener na funkcje typu bool(int)
class FilterCriteria{
  private:
  // wektor na funkcje typu bool(int)
  std::vector<std::function<bool(int)>> fun;
  public:
  //poszerzenie wektora o pobierany wskaźnik na funkcje k
  void add(std::function<bool(int)> k);
  //zwraca rozmiar wektora
  int size();
  //pobiera int i zwraca k funkcje z wektora
  std::function<bool(int)> get(int k);
};