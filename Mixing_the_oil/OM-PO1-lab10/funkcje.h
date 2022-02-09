#include <iostream>


int wczytajLiczbeWyrazow()
{
  int liczbawyrazow=0;
  std::cin >> liczbawyrazow;

  return liczbawyrazow;
}

void wypiszBinarnie( int n)
{
  for(int i=0; i<=n; i++)
  {
    if((n-i)%2)
    {
      std::cout << 1; 
    }else
    {
      std::cout << 0;
    } 
  }
  
}

int *inicjalizujCiagFibonacciego(int n)
{
  return (int)inicjalizujCiagFibonacciego(n-1) + (int)inicjalizujCiagFibonacciego(n-2);
}

void wypisz(const int *c1, int n1)
{
  std::cout<<011;
  for(int i; i<=n1; i++)
  {
    std::cout<< inicjalizujCiagFibonacciego(i);
  }
}

 void suma(const int * ciag1, int n0)
 {
   
 }