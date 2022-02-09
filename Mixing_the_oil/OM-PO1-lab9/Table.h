#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <functional>
#import "Data.h"

using namespace std::placeholders;

class Table
{
  public:
  /**przeciążenie operator += który dodaje wydatki z danego dnia do jego tabeli
  @param wydztki z danego dnia
  */
  void operator +=(Data z)
  {
    _tabs.push_back(z);
  }
  /**Metoda wypisywania dnia
  */
  void print() const
  {
    for (auto i:_tabs)
    {
      i.print();
    }
  }
  /**metoda do sertowania dni w wektrorze według podanej kolumnie wydatków
  @return wskażnik *this
  */
  Table sort(int k)
  {
    for(auto i:_tabs)
    {
      if(i.getsize()<=k)
      {
        std::cout<<"Indeks "<<k<<" nieprawidlowy!"<<std::endl;
        return *this;
      }
    }
    auto t=std::bind(compare,_1,_2,k); // _1, _2 reprezentują przyszłe argumenty które zostaną zastąpione przy kolejnym wywołaniu t() na compare()
    std::sort(std::begin(_tabs), std::end(_tabs), t); //srtujemy według funkcji t() a dokładniej według compare()
    return *this;
  }
  /**Sortowanie po sumach wydatków 
   @return wskażnik *this
  */
  Table sortBy(std::function<bool(Data,Data)> f)
  {
    std::sort(std::begin(_tabs), std::end(_tabs), f);
    return *this;
  }

  private:
  /** zmienna do przechowywania wszystkich dni
  */
  std::vector<Data> _tabs;
};