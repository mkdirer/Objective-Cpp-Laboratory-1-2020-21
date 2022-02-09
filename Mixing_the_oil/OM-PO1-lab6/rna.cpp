#include"rna.h"

RNA & RNA::mutate ()
{
  Nukleotyp temp=chain[0];
  for(unsigned i=0;i<chain.size();i++)
  {
    chain[i]=chain[i+1];
  }
  chain[chain.size()-1]=temp;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const RNA & seq_)
{
  for(unsigned i=0;i<seq_.chain.size();i++)
  {
    out<<static_cast<char>(seq_.chain[i])<<" ";
  }
  out<<std::endl;
  return out;
}