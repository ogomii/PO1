#pragma once
#include "Data.h"

/** klasa przechowujaca sume wartosci*/
class Sum
{
  public:
  /**konstruktor przyjmujący wartość sumy jako argument*/
  Sum(double sum): _sum(sum){}

  /** zwraca wartość sumy*/
  double value() const {return _sum;}
  /** dodaje do sumy wartość przekazaną jako @param toSum*/
  void operator()(double toSum) {_sum += toSum;}

  private:
  /**przechowuje wartość sumy jako double*/
  double _sum;
};

/**zwraca i tworzy obiekt Sum z suma uzyskaną z @param data*/ 
Sum sumData(const Data& data)
{
  Sum temp(data.sum());
  return temp;
}
