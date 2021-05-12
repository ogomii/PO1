#pragma once
#include "Data.h"

/**klasa przechowujaca wektor obiektow Data*/
class Table
{
  public:
  /**konstruktor bezargumentowy*/
  Table() = default;

  /**operator służący do dodawania kolejnych obiektów @param data do
  wektora _database*/ 
  void operator+=(const Data& data);
  /**wypisuje wszystkie obiekty w _database*/
  void print() const;
  /**sortuje _database wedle kolumny @param columnToSortBy*/
  Table& sort(int columnToSortBy);
  /**sortuje używając podanej jako @param fun funkcji */
  Table& sortBy(bool (*fun)(const Data& d1, const Data& d2));

  private:
  /**przechowuje obiekty typu Data*/
  std::vector<Data> _database;
};