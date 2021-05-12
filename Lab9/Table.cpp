#include "Table.h"

void Table::print() const
{
  std::for_each(_database.begin(), _database.end(), [](const Data& data)
  { data.print(); });
  std::cout<<std::endl;
}

void Table::operator+=(const Data& data) 
{
  _database.push_back(data);
}

Table& Table::sort(int columnToSortBy)
{
  std::vector<int> sizes;
  std::for_each(_database.begin(), _database.end(), [&sizes](const Data& data)
  { sizes.push_back(data.size()); });
  int min = sizes[1];
  std::for_each(sizes.begin(), sizes.end(), [&min](int& size)
  {
    if(min > size) min = size;
  });

  if(columnToSortBy < min)
  {
    std::sort(_database.begin(), _database.end(), [columnToSortBy]
    (const Data& data1, const Data& data2)
    {
      return data1[columnToSortBy] < data2[columnToSortBy];
    });
  }
  else 
  {
    std::cout << "Indeks " << columnToSortBy << " nieprawidlowy!" <<std::endl;
  }
  return *this;
}

Table& Table::sortBy(bool (*fun)(const Data& d1, const Data& d2))
{
  std::sort(_database.begin(), _database.end(), *fun);
  return *this;
}