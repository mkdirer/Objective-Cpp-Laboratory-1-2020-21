#include "Dir.h"

 Dir::Dir(string n): Element(n){}

  
  Dir::Dir(const Dir& k): Element(k.getnazwa())
  {
    for(unsigned int i=0; i<k.tab.size();i++)
    {
      Element* zm= new Element(*k.tab[i]);
      tab.push_back(zm);
    }
  }

  Dir::~Dir()
  {
    cout<<"Destruktor Dir "<<getnazwa()<<endl;
    for(unsigned int i=0;i<tab.size();i++)
      delete tab[i];
    tab.clear();
  }

  void Dir::operator +=(Element *k)
  {
    tab.push_back(k);
  }

  void Dir::operator -=(string k)
  {
    for(vector<Element*>::iterator i=tab.begin(); i!=tab.end();i++){
      if((*i)->getnazwa()==k)
      {
        delete *i;
        tab.erase(i);
        break;
      }
    }
  }

  void Dir::print(ostream& s, unsigned int k) const
  {
    for(unsigned int i=0; i<k; i++)
      s<<'\t';
    s<<getnazwa()<<" (dir)"<<endl;
    for(unsigned int i=0; i<tab.size(); i++)
      tab[i]->print(s,k+1);
  }

  Dir* Dir::getDir(string n)
  {
    for(unsigned int i=0; i<tab.size(); i++)
    {
      Dir* tmp;
      if((tmp=dynamic_cast<Dir*>(tab[i])))
      {
        if(tmp->getnazwa()==n)
        {
          return tmp;
        }
        Dir* tmp2=tmp->getDir(n);
        if(tmp2 != nullptr)
        {
          return tmp2;
        }

      }
    }
    return nullptr;
  }
  Element* Dir::get(string n)
  {
    for(unsigned int i=0; i<tab.size(); i++)
    {
      if(tab[i]->getnazwa()==n)
      {
        return tab[i];
      }
      Dir* tmp;
      if((tmp=dynamic_cast<Dir*>(tab[i])))
      {
        Element* tmp2=tmp->get(n);
        if(tmp2!=nullptr)
        {
          return tmp2;
        }
      }
    }
    return nullptr;
  }
  void Dir::copy(Element* k)
  {
    Element *tmp=new Element(*k);
    *this+=tmp;
  }