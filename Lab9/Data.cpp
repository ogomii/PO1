#include "Data.h"

void Data::print() const
{
  std::cout<< _name << ":" << std::setw(5);
  std::for_each(_vec.begin(), _vec.end(), [](const double& val)
  { std::cout<< val << std::setw(6);});
  std::cout << std::endl;
}

double Data::sum() const
{
  return std::accumulate(_vec.begin(), _vec.end(), 0.);
}

double Data::operator[](int col) const
{
  if((unsigned)col <= _vec.size()) return _vec[col];
  else return -1;
}

int Data::size() const
{
  return _vec.size();
}