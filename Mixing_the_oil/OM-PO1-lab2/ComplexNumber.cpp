#include "ComplexNumber.h"

std::ostream & operator<<(std::ostream &s, const ComplexNumber &k)
{
  //2 + 8i
    s<<k.re<<" + "<<k.im<<"i";
  return s;
}
  ComplexNumber::operator double(){
    return double(re);
  }
  ComplexNumber ComplexNumber::operator+(const ComplexNumber &z) const
  {
    ComplexNumber tmp = *this;
    tmp.re += z.re;
    tmp.im += z.im;
    return tmp;
  }
  ComplexNumber operator+(int n,const ComplexNumber &z)
  {
    ComplexNumber tmp = z;
    tmp.re += n;
    return tmp;
  }

  ComplexNumber ComplexNumber::operator*(const ComplexNumber &z) const
  {
    //(A1 + i*A2)*(B1 + i*B2) = A1*B1 - A2*B2 + i*(A1*B2 + A2*B1)
    ComplexNumber temp;
	  temp.re=re*z.re-im*z.im;
	  temp.im=re*z.im+z.re*im;
	  return temp;
  }

  void ComplexNumber::operator*=(int n)
  {
    re=re*n;
    im=im*n;
  }

  ComplexNumber ComplexNumber::operator-(const ComplexNumber &z)
  {
    re -= z.re;
    im -= z.im;
    return *this;
  }

  ComplexNumber ComplexNumber::operator++(int n)
  {
    ComplexNumber tmp = *this;
    ++re;
    return tmp;
  }

  ComplexNumber &ComplexNumber::operator++()
  {
    ++re;
    return *this;
  }

  double &ComplexNumber::operator[](int n)
  {
    return (n==0)? re : im;
  }

  bool ComplexNumber::operator<(const ComplexNumber &z) const
  {
    double R1 = re*re + im*im;
    double R2 = z.re*z.re + z.im*z.im;
    return R1<R2;
  }