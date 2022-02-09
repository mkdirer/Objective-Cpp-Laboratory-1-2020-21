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
    klasa reprezentujaca wirusa
*/
class Virus{
  public:
  /**
    konstruktor dla virus
  */
  Virus(string a)
  {
    name=a;
    wiek=0;
    val=nullptr;
  }
  /**
    konstruktor kopijącu dla wirusa
  */
  
  Virus(const Virus &a)
  {
    name=a.name;
    wiek=0;
    set_RNA(a.val->get_RNA());
  }
  
  Virus(Virus &a)
  {
    name=a.name;
    wiek=0;
    a.wiek++;
    set_RNA(a.val->get_RNA());
  }
  
  /**
    konstrukotr przenoszący dla wirusa
  */
  
  Virus(Virus &&a)
  {
    name=std::move(a.name);
    wiek=std::exchange(a.wiek,0);
    val=std::exchange(a.val,nullptr);
    val->mutate();
  }
  
  ~Virus()
  {
    delete val;
  }
  
  Virus operator=(const Virus &a)
  {
    return Virus(a);
  }
  
  /**
    metoda zwracjaca nazwe wirusa
  */
  string get_name()
  {
    return name;
  }
  /**
    metoda zwracjąca wiek 
  */
  int get_age()
  {
    return wiek;
  }
  /**
    smetoda zrwacająca RNA wirusa
  */
  RNA* get_RNA()
  {
    return val;
  }
  /**
    @param vctor łacucha rna
    ustawia łańcuch rna dla wirusa
  */
  void set_RNA( const std::vector< Nukleotyp > seq_)
  {
    val=new RNA(seq_);
  }
  /**
    nazwa wirusa
  */
  private:
  string name;
  /**
    wiek wirusa
  */
  int wiek;
  /**
    łańcuch rna wirusa
  */
  RNA* val;
};