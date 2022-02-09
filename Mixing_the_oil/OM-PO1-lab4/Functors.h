#pragma once 
#include <iostream>
#include <functional>
#include <vector>


//klasa sprawdzajaca podzielnosc w postaci funkora
class DivisibleBy{
  private:
  int n;
  
  public:
  //konstruktor z listą iniclalizacyjna, pczypisanie n wartosc k
  DivisibleBy(int k=0): n(k) {}
  //sprawdzenie czy podany parametr k jest podzielny przez zmienną prywatna n za pomocą operator()
  bool operator()(int k) {return k%n==0;}
};

// klasa sprawdzajaca czy podane parametry sa mniejsze niż zmienna prywatna
class LowerThan{
  private:
  int n;

  public:
  //konstruktor z listą iniclalizacyjna, pczypisanie n wartosc k
  LowerThan(int k): n(k) {}
  //sprawdzenie czy podany parametr k jest mniejszy niż zmienna prywatna n za pomocą operator()
  bool operator()(int k) {return k<n;}
};