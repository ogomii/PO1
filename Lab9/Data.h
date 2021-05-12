#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <numeric>

/**klasa przechowujaca nazwe i wartosci dla wybranego dnia*/
class Data
{
  public:
  /** konstruktor dwu parametrowy
  @param name nazwa dnia
  @param vec vector wartosci double w tym dniu*/  
  Data(std::string name, std::vector<double> vec): _name(name), _vec(vec){}

  /**wypisuje nazwe i wartosci obiektu*/
  void print() const;
  /**zwraca sume wartosci obiektu*/
  double sum() const;
  /**dostęp do wartosci _vec*/
  double operator[](int col) const;
  /** zrwaca ilosc danych w _vec*/
  int size() const;

  private:
  /** przechowuje nazwe jako string*/
  std::string _name;
  /**przechowuje wartosci w typie vector*/
  std::vector<double> _vec;
};

