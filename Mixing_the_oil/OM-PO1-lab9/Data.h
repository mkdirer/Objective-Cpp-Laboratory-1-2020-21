#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


class Data
{
  public:
  /**konstruktor 
  */
  Data(std::string nazwa, std::vector<double> tab): _nazwa(nazwa), _tab(tab) {};
  /** metoda wypisująca dni
  */
  void print() const
  {
    std::cout<<_nazwa<<":";
    for(auto i:_tab)
    {
      std::cout<<std::setw(7)<<i;
    }
    std::cout<<std::endl;
  }
  /**metoda zwracająca referencję do tablicy typu double
  */
  std::vector<double>& gettab()
  {
    return _tab;
  }
  /** zwracanie rozmiaru tabicy
  */
  int getsize() const
  {
    return _tab.size();
  }
  

  private:
  /**nazwa dnia
  */
  std::string _nazwa;
  /** wszystkie wydatki w postaci wektora
  */
  std::vector<double> _tab;

};

bool compare(Data x, Data y, int n)
{
  return x.gettab()[n] < y.gettab()[n];
}