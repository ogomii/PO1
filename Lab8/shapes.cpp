#include "shapes.h"

std::ostream& operator<<(std::ostream& out, const Point& obj)
{
  out<< "(" << obj.getX() << ", " <<obj.getY() << ") ";
  return out;
}


Point::Point(double x, double y): _x(x), _y(y){}

void Point::shift(double dx, double dy)
{
  _x += dx;
  _y += dy;
}



void Circle::draw() const
{
  std::cout << "Rysujemy kolo o srodku " << _p <<" i promieniu "<< _r <<std::endl;
}

double Circle::length() const
{
  return 2.0 * 3.14*_r;
}

void Circle::shift(double dx, double dy)
{
  _p.shift(dx,dy);
}

double Circle::area() const 
{
  return 3.14*_r*_r;
}




void Section::draw() const
{
  std::cout <<"Rysujemy odcinek od " << _p1 <<" do " << _p2 <<std::endl;
}

double Section::length() const
{
  return sqrt( pow( (_p1.getX() - _p2.getX()),2) + pow( (_p1.getY() - _p2.getY()),2) );
}

void Section::shift(double dx, double dy)
{
  _p1.shift(dx,dy);
  _p2.shift(dx,dy);
}




Deltoid::Deltoid(Section s1, Section s2): _p1(s1.retp1()),_p2(s2.retp1()),
_p3(s1.retp2()),_p4(s2.retp2()){}

Deltoid::Deltoid(Point p1, Point p2, Point p3, Point p4): _p1(p1),
_p2(p2),_p3(p3),_p4(p4){}

void Deltoid::draw() const
{
  std::cout << "Rysujemy deltoid o wierzcholkach "<< _p1 << _p2 << _p3 << _p4 << std::endl;
}

double Deltoid::length() const
{
  return Section(_p1,_p2).length() +
  Section(_p2,_p3).length() +
  Section(_p3,_p4).length() +
  Section(_p4,_p1).length();  
}

void Deltoid::shift(double dx, double dy)
{
  _p1.shift(dx,dy);
  _p2.shift(dx,dy);
  _p3.shift(dx,dy);
  _p4.shift(dx,dy);
}

double Deltoid::area() const
{
  return Section(_p1,_p3).length() * Section(_p2,_p4).length(); 
}