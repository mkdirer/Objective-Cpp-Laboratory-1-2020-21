#pragma once
#include "Persons.h"
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include <algorithm>


class VectorQ{
  public:

  VectorQ()=default;

  void add(std::unique_ptr<Person> a)
  {
    _tab.push_back(std::move(a));
  }

  void print(std::string a) const
  {
    std::cout<<a<<std::endl;
    std::for_each(_tab.begin(), _tab.end(), [](const std::unique_ptr<Person>& b){b->print();});
    std::cout<<std::endl;
  }

  std::vector<Woman*> getWomen()
  {
    std::vector<Woman*> p;
    for(auto &el: _tab)
    {
      if(dynamic_cast<Woman*>(el.get()))
      {
        p.push_back(dynamic_cast<Woman*>(el.get()));
      }
    }
    return p;
  }

  void countNames()
  {
    std::vector<std::string> name;
    for(auto &el: _tab)
    {
      std::string a=el->name();
      bool b=true;
      for(auto &e: name)
      {
        if(e==a)
        {
          b=false;
        }
      }
      int i=0;
      if(b=true)
      {
        name.push_back(a);
        for(auto &ele: _tab)
        {
          if(ele->name()==a)
          {
            i++;
          }
        }
        std::cout<<a<<": "<<i<<std::endl;
      }
    }
  }

  void haircut(std::string a)
  {
    for(auto &el: _tab)
    {
      if(el->name()==a)
      {
        el->haircut();
        break;
      }
    }
  }

  void haircut()
  {
    _tab[0]->haircut();
  }

  void shave(std::string a)
  {
    for(auto &el: _tab)
    {
      if(el->name() == a)
      {
        el->shave();
        break;
      }
    }
  }

  void shave()
  {
    _tab[0]->shave();
  }

  private:
  std::vector<std::unique_ptr<Person>> _tab;
  
};