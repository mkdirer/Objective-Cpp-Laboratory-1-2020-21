#include "Operation.h"

void operator>>=(string t,const Operation& obj)
{
	cout << t;
  if (obj.znak=='+')
  {
    for (int i=0;i<obj.n-1;i++)
    {
      cout<<obj.tab[i]<<obj.znak;
    }
    cout<<obj.tab[obj.n-1];
  }
  else
  {
    cout<<obj.tab[0]<<obj.znak<<obj.tab[1];
  }
	cout << t <<endl;
}
void Operation::print() const
{
  if (znak=='+')
  {
    for (int i=0;i<n-1;i++)
    {
      cout<<tab[i]<<znak;
    }
    cout<<tab[n-1];
  }
  else
  {
    cout<<tab[0]<<znak<<tab[1];
  }
}
double Operation::eval() const
{
  if (znak=='+')
  {
    double sum=0;
    for (int i=0;i<n;i++)
    {
      sum+=tab[i];
    }
    return sum;
  }
  else if (znak=='/')
  {
    return tab[0]/tab[1];
  }
  else
  {
    return pow(tab[0],tab[1]);
  }
}