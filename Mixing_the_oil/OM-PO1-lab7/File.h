#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "Element.h"

using namespace std;

class File: public Element{
  private:
  int sth;

  public:

  File(string n, int k=0);
  File(const File& k);
  ~File();
  void print(ostream& s, unsigned int k=0) const override;

};