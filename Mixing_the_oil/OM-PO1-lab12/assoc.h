#pragma once 
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <iterator>

using namespace std;

//string print(bool zm);
//string operator *(string zm, int zm2);
//string operator *(int zm2, string zm);

template<typename T1, typename T2> class Assoc{
  private:
  vector<T1> x;
  vector<T2> y;

  public:
  Assoc()=default;
  Assoc(const Assoc &zm);
  bool contains(T1 zm) const;
  T2& operator [](T1 zm);
  void print(string zm);
  T2 operator [](T1 zm) const;
  void insert(T1 zm, T2 zm2);

};

string print(bool zm)
{
  if(zm)
    return "Znaleziono";
  else
    return "Nie znaleziono";
}

string operator *(string zm, int zm2)
{
  string tmp="";
  for(int i=0; i<zm2; i++)
  {
    tmp+=zm;
  }
  return tmp;
}

string operator *(int zm2, string zm)
{
  string tmp="";
  for(int i=0; i<zm2; i++)
  {
    tmp+=zm;
  }
  return tmp;
}

template<typename T1, typename T2> Assoc<T1,T2>::Assoc(const Assoc<T1, T2>& zm)
{
  for(unsigned i=0; i<zm.x.size(); i++)
  {
    x.push_back(zm.x[i]);
    y.push_back(zm.y[i]);
  }
}

template<typename T1, typename T2> void Assoc<T1,T2>::insert(T1 zm, T2 zm2)
{
  x.push_back(zm);
  y.push_back(zm2);
}

template<typename T1, typename T2> 
void Assoc<T1,T2>::print(string zm)
{
  for(unsigned i=0; i<x.size(); i++ )
  {
    cout<<"---"<<zm<<"--- klucz: "<<x[i]<<" wartosc: "<<y[i]<<endl;
  }
}

template<typename T> T pustka(T zm)
{
  return 0;
}

string pustka(string zm)
{
  return "";
}

template<typename T1, typename T2> T2& Assoc<T1,T2>::operator[](T1 zm)
{
  for(unsigned i=0; i<x.size(); i++)
  {
    if(zm == x[i])
      return y[i];
  }
  x.push_back(zm);
  y.push_back(pustka(T2()));
  return y[y.size()-1];
}

template<typename T1, typename T2> bool Assoc<T1,T2>::contains(T1 zm) const
{
  for(unsigned i=0; i<x.size(); i++)
  {
    if(zm == x[i])
      return true;
  }
  return false;
}


template<typename T1, typename T2> T2 Assoc<T1,T2>::operator [](T1 zm) const
   {
    for(unsigned i=0; i<x.size(); i++)
    {
      if(zm == x[i])
        return y[i];
    }
    return 0;
  }