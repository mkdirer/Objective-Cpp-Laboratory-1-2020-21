#pragma once 
#include "Person.h"

class Woman : public Person
{
  public:
  explicit Woman(std::string name, bool iswoman = true, bool hair = true): Person(name, iswoman, hair){};
  ~Woman()=default;

  void print() const
  {
    std::cout<<name()<<" nieobcieta i nieumalowana"<<std::endl;
  }

  void makeup()
  {
    _makeup=true;
  }

  void shave() {};

  private:
  bool _makeup=false;

};

class Man : public Person
{
  public:
  explicit Man(std::string name, bool iswoman = true, bool hair = true):Person(name, iswoman, hair){};

  void print() const
  {
    std::cout<<name()<<" nieobciety i nieogolony"<<std::endl;
  }

  void makeup() {}

  void shave()
  {
    _shave=true;
  }

  private:
  bool _shave=false;

};