#pragma once 
#include <iostream>

using namespace std;

class ComplexNumber
{
  public:
  ComplexNumber(): re(0), im(0){};
  ComplexNumber(double r, double i): re(r), im(i){};
  explicit ComplexNumber(double r): re(r), im(0){}; // aby 28 działało, a po odkomentowaniu 19 już nie 
  friend std::ostream & operator<<(std::ostream &s, const ComplexNumber &k);
  operator double(); //33
  ComplexNumber operator+(const ComplexNumber &z) const; //36
  friend ComplexNumber operator+(int n,const ComplexNumber &z); //37
  //ComplexNumber &operator=(const ComplexNumber &z) const; // nie jest potrzbene bo używamy konstruktora kopiującego 
  ComplexNumber operator*(const ComplexNumber &z) const; //40 i 47
  void operator*=(int n);//44
  ComplexNumber operator-(const ComplexNumber &z);//47
  ComplexNumber operator++(int n); //S2++
  ComplexNumber &operator++(); //++S1
  ComplexNumber(const ComplexNumber &z): re(z.re), im(z.im){};
  double &operator[](int n);//51 i 55
  //void operator-=(int n); // nie jest potrzbene bo S3[1] zwraca double
  bool operator<(const ComplexNumber &z) const; //51 i 55

  private:

  double re;
  double im;
};

//std::ostream &operator<<(std::ostream s, const ComplexNumber &k);
