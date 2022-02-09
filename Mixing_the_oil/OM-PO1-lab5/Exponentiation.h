#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include "Operation.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;


class Exponentiation: public Operation{
  
  public:
  Exponentiation(double a=0 ,double b=0, char c='^'): Operation(a,b,c){}
};