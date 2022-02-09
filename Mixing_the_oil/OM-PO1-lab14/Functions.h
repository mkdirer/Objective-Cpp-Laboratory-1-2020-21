#pragma once 
#include <iostream>
#include <cmath>

/**
klasa odwołań do funkcji
*/
class Fun
{
  public:
  /**
  konstruktor domyślny klasy
  */
  Fun()=default;
  /**
  obliczanie wartosci funkcji 
  @param argument funkcji 
  */
  virtual void licz(double k) const;
};

class DivideBy: public Fun
{
  double zm;

  public:
  /**
  konstruktor domyślny klasy
  */
  DivideBy()=default;
  /**
  konstruktor klasy DivideBy 
  @param licznik  
  */
  DivideBy(double k): zm(k){};
  /**
  obliczanie wartosci dzielenia 
  @param argument funkcji 
  */
  void licz(double k) const override;
};

class Log10: public Fun
{
  public:
  /**
  konstruktor domyślny klasy
  */
  Log10()=default;
  /**
  obliczanie wartosci funkcji log10 
  @param argument funkcji 
  */
  void licz(double k) const override;

};

class Asin: public Fun
{
  public:
  /**
  konstruktor domyślny klasy
  */
  Asin()=default;
  /**
  obliczanie wartosci funkcji arcsin 
  @param argument funkcji 
  */
  void licz(double k) const override;
  
};



