#include "List.h"

void List::insert(int k)
{
  tab.push_back(k);
}

void List::print(string k) const
{
  std::cout<<k<<"[ ";
  for(unsigned int i =0; i<tab.size(); i++)
  {
    cout<<tab[i]<<" ";

  }
  cout<<"]"<<endl;
}

int& List::operator[](int k)
{
  return tab[k];
}
List List::filter(std::function<bool(int)> k)
{
  List tmp;
  for (unsigned int i = 0; i<tab.size(); i++)
  {
    if(k(tab[i]))
    {
      tmp.insert(tab[i]);
    }
  }
  return tmp;
}