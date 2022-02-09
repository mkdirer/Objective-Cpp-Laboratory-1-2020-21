#include "MyArray.h"

 MyArray::MyArray(int n)
 {
   tab = new int[n];
   _size = n;
   for(int i=0; i<n; i++)
   {
     tab[i]=0;
   }
 }
  void MyArray::print(string sth) const
  {
    std::cout<<sth<<" = [ ";
    if(_size>0)
    {
    std::cout<<tab[0];
    for(int i=1; i<_size; i++)
    {
      std::cout<<", "<<tab[i];
    }
    }
    std::cout<<"]"<<std::endl;
    
  }
  int MyArray::size()
  {
    return _size;
  }
  
  
  int & MyArray::operator[](unsigned int n) const
  {
    return tab[n];
  }

std::ostream &operator<<(std::ostream &s, const MyArray &k)
{

  s<<"[ "<<k.tab[0];
    for(int i=1; i<k._size; i++)
    {
      s<<", "<<k.tab[i];
    }
  s<<"]"<<std::endl;
  return s;
}

  void MyArray::operator++()
  {
    for(int i=0; i<_size; i++)
    {
      tab[i]= tab[i] + 1;
    }
  }

  MyArray::MyArray(const MyArray &k)
  {
    _size = k._size;
    tab= new int[k._size];
    for(int i=0; i<k._size; i++)
    {
      tab[i]=k.tab[i];
    }
  }

  MyArray &MyArray::operator=(MyArray &k)
  {
    if( &k == this)
    {
      return *this;
    }
    _size = k._size;
    tab = new int[_size];
    for(int i=0; i<k._size; i++)
    {
      tab[i]=k.tab[i];
    }
    return *this;
  }
  MyArray::MyArray(MyArray &&k): _size(std::exchange(k._size,0)), tab(std::exchange(k.tab,nullptr)){}

  MyArray::~MyArray()
  {
    delete [] tab;
    _size=0;
    std::cout<<"Usuwam tablicę"<<std::endl;
  }
