#pragma once 

#include <iostream>
#include "Functions.h"
#include <cmath>

using namespace std;

namespace SecureCalc
{
  /** funkcja do obliczania 
  @param klasa dzilania
  @param argument funkcji z klasy
  */
  void run(const Fun &f, double x)
  {
    try
    {
      f.licz(x);
    }
    catch(const range_error &error)
    {
      cout<<"-> Error: "<<error.what()<<endl;
    }
  }
}