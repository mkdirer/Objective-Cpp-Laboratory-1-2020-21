#include "FilterCriteria.h"

void FilterCriteria::add(std::function<bool(int)> k)
{
  fun.push_back(k);
}

int FilterCriteria::size()
{
  return fun.size();
}

std::function<bool(int)> FilterCriteria::get(int k) // funkcja get(int) zwraca funktor
{
  if(k<size()) return fun[k];
  else return nullptr;
}