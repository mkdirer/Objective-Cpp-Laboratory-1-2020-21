#pragma once 
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Element.h"

using namespace std;

class Dir final: public Element{
  private:
  vector<Element*> tab;

  public:

  Dir(string n);
  Dir(const Dir& k);
  ~Dir();
  void operator +=(Element *k);
  void operator -=(string k);
  void print(ostream& s, unsigned int k=0) const override;
  Dir* getDir(string n);
  Element* get(string n);
  void copy(Element* k);  

};