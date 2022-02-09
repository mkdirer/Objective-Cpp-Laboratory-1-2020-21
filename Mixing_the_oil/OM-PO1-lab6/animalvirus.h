#pragma once 

#include <iostream>
#include <utility>
#include <memory>
#include <functional>
#include <string>
#include <vector>
#include "rna.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
/**
  klassa reprezentujaca zrwierze z chroba i rna
*/
class AnimalVirus: public Virus{
  public:
  /**
    konstruktor dla AAnimlaVirus
  */
  AnimalVirus(string a,string b,std::vector< Nukleotyp > c): Virus(a)
  {
    nos=b;
    set_RNA(c);
  }

  AnimalVirus():Virus("")
  {
    nos="";
  }
  /**
    konstruktor kopiujący dla AAnimlaVirus
  */
  AnimalVirus(const AnimalVirus& a): Virus(a)
  {
    nos=a.nos;
  }
  AnimalVirus(AnimalVirus& a): Virus(a)
  {
    nos=a.nos;
  }
  /**
    konstruktor  przenoszący dla AAnimlaVirus
  */
  AnimalVirus(AnimalVirus &&a): Virus(std::move(a))
  {
    nos=std::move(a.nos);
  }

  AnimalVirus operator=(const AnimalVirus &a)
  {
    return AnimalVirus(a);
  }
  /**
    metoda zwracajaca nawze zwirezecia
  */
  string get_animal_host()
  {
    return nos;
  }
  private:
  /**
    string nazwy zwirezecia
  */
  string nos;
};
