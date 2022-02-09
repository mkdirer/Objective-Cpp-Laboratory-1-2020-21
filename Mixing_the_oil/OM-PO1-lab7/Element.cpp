#include "Element.h"
 
Element::Element(string n): nazwa(n){}

  Element::Element(const Element &k): nazwa(k.nazwa){}
  Element::~Element()
  {
    
  }

  void Element::print(ostream& s, unsigned int k) const
  {
    for(unsigned int i=0;i<k;i++)
      s<<'\t';
    s<<nazwa<<endl;
  }
  string Element::getnazwa() const
  {
    return nazwa;
  }
  void Element::setnazwa(string k)
  {
    nazwa=k;
  }
  ostream& operator<<(ostream& s, const Element& k)
  {
    k.print(s);
    return s;
  }