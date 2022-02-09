#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <math.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
/**
klasa z której dziedziczymy Operation
*/

class Operation{
  public:

  Operation(double a=0 ,double b=0,char c=' ')
  {
    tab=new double [2];
    tab[0]=a;
    tab[1]=b;
    znak=c;
  }
  Operation(double *a=nullptr ,int b=0,char c=' ')
  {
    tab=new double [b];
    for(int i=0;i<b;i++)
    {
      tab[i]=a[i];
    }
    znak=c;
    n=b;
  }
  ~Operation()
  {
    delete tab;
  }
  void print() const;
  double eval() const;

  public:

  double *tab=nullptr;
  int n=2;
  char znak;

};
void operator>>=(string t,const Operation& obj);