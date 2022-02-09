#include "MyArray.h"

MyArray::MyArray(int n)
{
  tab = new int [n];
  _rozmiar=n;
  for(int i=0; i<_rozmiar; i++)
  {
    tab[i]=0;
  }
}
  
  
  MyArray::MyArray(const MyArray &k)
  {
    _rozmiar=k._rozmiar;
    tab=new int[_rozmiar];
    for(int i=0; i<k._rozmiar; i++)
    {
      tab[i]=k.tab[i];
    }
    next=k.next;
  }
  
  
  MyArray::MyArray(MyArray &&k)
  {
    _rozmiar=std::exchange(k._rozmiar,0);
    tab=std::exchange(k.tab,nullptr);
    next=std::exchange(k.next, nullptr);
  }
 

  MyArray::~MyArray()
  {
    delete [] tab;
    _rozmiar=0;
    tab=nullptr;
    next=nullptr;
  }
  
  
  int& MyArray::operator[](int i)
  {
    if(i<_rozmiar) return tab[i]; else return (*next)[i-_rozmiar];
  }
  
  
  std::ostream& operator<<(std::ostream &o, const MyArray k)
  {
    if(k._rozmiar==0)
    {
      return o;
    }
    o<<"[";
    for(int i=0; i<k._rozmiar-1; i++)
    {
      o<<(k.tab[i]);
      o<<", ";
    }
    o<<(k.tab[k._rozmiar-1]);
    o<<"]";
    return o;
  }
  
  
  const int& MyArray::operator[](int i) const
  {
    if(i<_rozmiar) return tab[i]; else return (*next)[i-_rozmiar];
  }
  
  
  void MyArray::print(string k)
  {
    cout<<k<<"[";
    for(int i=0; i<_rozmiar-1; i++)
    {
      cout<<(tab[i]);
      cout<<", ";

    }
    cout<<(tab[_rozmiar-1]);
    cout<<"]";
    if(next!=nullptr) 
      next->print("");
  }

  int MyArray::size()
  {
    return _rozmiar;
  }
  

  MyArray& MyArray::getNext()
  {
    return *next;
  }

  MyArray MyArray::operator++(int)
  {
    MyArray tmp=MyArray(*this);
    for(int i=0; i<_rozmiar; i++)
    {
      tab[i]++;
    }
    return tmp;
  }

  MyArray& MyArray::operator--()
  {
    for(int i=0; i<_rozmiar; i++)
    {
      tab[i]--;
    }
    return *this;
  }

  MyArray& MyArray::operator=(const MyArray& k)
  {
    if(&k==this)
    return *this;

    _rozmiar = k._rozmiar;
    delete [] tab;
    tab = new int[_rozmiar];
    for(int i=0; i<_rozmiar; i++)
    {
      tab[i]=k.tab[i];
    }
    next=k.next;
    return *this;
  }

  void MyArray::operator+=(MyArray& k)
  {
    if(next==nullptr) next=&k; else *next+=k;
  }

  void MyArray::operator+=(MyArray&& k)
  {
    int *tmp=new int [_rozmiar+k._rozmiar];
    for(int i=0; i<_rozmiar; i++)
    {
      tmp[i]=tab[i];
    }
    for(int i=0; i<k._rozmiar;i++)
    {
      tmp[i+_rozmiar]=k.tab[i];
    }
    _rozmiar+=k._rozmiar;
    delete [] tab;
    tab=tmp;
  }