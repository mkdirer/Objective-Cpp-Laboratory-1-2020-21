#include "File.h"

File::File(string n, int k): Element(n), sth(k) {}
  File::File(const File& k): Element(k.getnazwa()), sth(k.sth){}
  File::~File()
  {
    cout<<"---Destrukotr File: "<<getnazwa()<<endl;
    setnazwa("");
  }
  void File::print(ostream& s, unsigned int k) const
  {
    for(unsigned int i=0; i<k; i++)
      s<<'\t';
    s<<getnazwa()<<" ("<<sth<<")"<<endl;
  }
