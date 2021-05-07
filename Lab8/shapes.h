#pragma once
#include <iostream>
#include <math.h>

/** klasa wirtualna definiujaca akcje przesuniecia
na obiektach
void shift(double dx, double dy)
*/
class Transformable
{
  public:
  virtual void shift(double dx, double dy) = 0;
  virtual ~Transformable() = default;
};


/** klasa wirtualna definiujaca akcje rysowania 
void draw() const
i pobieranie dlugosci
double length() const
*/
class Drawable
{
  public:
  virtual void draw() const = 0;
  virtual double length() const = 0;
  virtual ~Drawable() = default;
};

/** klasa okreslajaca typ zamknietej figury, okresla
funkcje wyznaczania pola figur zamknietych
double area() const
*/
class ClosedShape: public Drawable, public Transformable
{
  public:
  virtual double area() const = 0;
  virtual ~ClosedShape() = default;
};

/** klasa przechowujaca dane o punkcie x i y w przestrzeni*/
class Point: public Transformable
{
  public:
  Point(double x, double y);
  double getX() const {return _x;}
  double getY() const {return _y;}
  void shift(double dx, double dy) override;

  protected:
  double _x;
  double _y;
};
std::ostream& operator<<(std::ostream& out, const Point& obj);


/**klasa okreslajaca figure kolo, ktora jest figura zakmnieta*/
class Circle: public ClosedShape
{
  public:
  Circle(Point p, double r): _p(p), _r(r){}
  void draw() const override;
  double length() const override;
  void shift(double dx, double dy) override;
  double area() const override;

  protected:
  Point _p;
  double _r;

};

/** Klasa definiujaca odcinekm nie jest to figura zamknieta*/
class Section: public Drawable, public Transformable
{
  public: 
  Section (Point p1, Point p2): _p1(p1), _p2(p2){}
  Point retp1() const {return _p1;}
  Point retp2() const {return _p2;}
  void draw() const override;
  double length() const override;
  void shift(double dx, double dy) override;

  protected:
  Point _p1;
  Point _p2;
};


/** klasa definiujaca deltoid, jest to figura zamknieta*/
class Deltoid: public ClosedShape
{
  public:
  Deltoid(Section s1, Section s2);
  Deltoid(Point p1, Point p2, Point p3, Point p4);
  void draw() const override;
  double length() const override;
  void shift(double dx, double dy) override;
  double area() const override;

  protected:
  Point _p1;
  Point _p2;
  Point _p3;
  Point _p4;  
};
