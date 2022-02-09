#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Operation.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Division: public Operation{

  public:
  Division(double a=0 ,double b=0,char c='/'): Operation(a,b,c){}
};
