#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Data.h"


class Sum
{
  public:
  /** kostruktor defaultowy
  */
  Sum()=default;
  /**przeciążenie operatora() który dodaje do naszej zmiennej kolejnye argumnety 
  @param argument dodawany do sumy
  */
  void operator()(double k) {_tab += k;}
  /**
  */
  double value()
  {
    return _tab;
  }


  private:
  /**przechwywanie wartości sumy
  */
  double _tab;

};

Sum sumData(Data day)
{
  Sum s= std::for_each(std::begin(day.gettab()), std::end(day.gettab()), Sum());
  std::cout<<s.value();
  return s;
}