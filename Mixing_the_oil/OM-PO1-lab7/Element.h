#pragma once
#include <iostream>
#include <sstream> //dzięki której możemy łatwo int zamienić na string
#include <string>
#include <cmath>

using namespace std;

class Element{
  private:
  string nazwa;

  public:

  Element(string n);
  Element(const Element &k);
  virtual ~Element();
  virtual void print(ostream& s, unsigned int k=0) const;
  string getnazwa() const;
  void setnazwa(string k);

};

ostream& operator<<(ostream& s, const Element& k);