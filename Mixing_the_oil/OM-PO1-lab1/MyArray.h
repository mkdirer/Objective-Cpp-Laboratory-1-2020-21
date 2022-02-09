#pragma once 
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class MyArray{

  public:

  MyArray(int n);
  void print(string sth) const;
  int size();

  int &operator[](unsigned int n) const;

  friend std::ostream &operator<<(std::ostream &s, const MyArray &k);
  void operator++(); ////
  MyArray(const MyArray &k);
  MyArray &operator=(MyArray &k);
  MyArray(MyArray &&k);
  ~MyArray();

  private:
  int _size;
  int *tab;

};

//int &operator=(int n);

std::ostream &operator<<(std::ostream &s, const MyArray &k);