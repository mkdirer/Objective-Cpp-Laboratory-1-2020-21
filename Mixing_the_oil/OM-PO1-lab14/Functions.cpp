#include <iostream>
#include "Functions.h"
#include <cmath>

using namespace std;

void Fun::licz(double k) const
{
  cout<<"";
}

void DivideBy::licz(double k) const
{
  cout<<"Obliczmy: DivideBy("<<k<<")"<<endl;
  if(k==0)
  {
    throw range_error("divide by zero!"); //("nie dzielimy przez zero!");
  }
  cout<<"-> Wynik: "<<zm/k<<endl;
}

void Log10::licz(double k) const
{
  cout<<"Obliczmy: log10("<<k<<")"<<endl;
  if(k<0)
  {
    throw range_error("wrong argument of log10"); //("logarytm z liczby mniejszej od zera nie istnieje !");
  }
  cout<<"-> Wynik: "<<log10(k)<<endl;
}

void Asin::licz(double k) const
{
  std::cout<<"Obliczmy: arcsin("<<k<<")"<<std::endl;
  if(!(k>=(-1) && k<=1))
  {
    throw range_error("wrong argument of arcsin"); //("argument funkcji musi zawierac się w przedziale x=[-1;1]");
  }
  cout<<"-> Wynik: "<<asin(k)<<endl;
}

