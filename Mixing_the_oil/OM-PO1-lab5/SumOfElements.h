#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Operation.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
/**
klasa reprezentująsa sume liczba
*/
class SumOfElements: public Operation{
  public:
  SumOfElements(double *a,int b,char c='+'): Operation(a,b,c){}
};