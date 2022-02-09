#pragma once

#include <iostream>
#include <math.h>

///Klasy abstrakcyjne
//--------------------------------------------

///Definiuje metodę rysowania obiektu oraz liczenia jego obwodu/ długości
class Drawable{
	public:
		Drawable(){}
		virtual void draw() const = 0;
		virtual double length() const = 0;
};

///Definiuje metodę przesunięcia o x y
class Transformable{
	public:
		Transformable(){}
		virtual void shift(double x, double y) = 0;
};

///Definiuje metode liczenia pola zamnkniętej figury
class ClosedShape{
	public:
		ClosedShape(){}
		virtual double area() const = 0;
};

//--------------------------------------------

///Klasy kształtów

class Point : public Transformable{

	public:
		Point(double x, double y):_x(x),_y(y){}

		friend std::ostream& operator<<(std::ostream& out, const Point& point){
			out << "(" << point._x << ", " << point._y << ")";
			return out;
		}

		void shift(double x, double y){
			_x+=x;
			_y+=y;
		}

		double getX() const {
			return _x;
		}

		double getY() const{
			return _y;
		}

	private:
		double _x;
		double _y;
};

class Circle : public Drawable, public Transformable, public ClosedShape{
	public:
		Circle(Point p, double radius):_c(p),_r(radius){}

		void draw() const {
			std::cout <<"Rysujemy kolo o srodku " << _c << " i promieniu " << _r << std::endl;
		}

		double length() const {
			return 2*M_PI*_r;
		} 

		void shift(double x, double y){
			_c.shift(x,y);
		}

		double area() const{
			return M_PI*_r*_r;
		}
	private:
		Point _c;
		double _r;
};

class Section : public Drawable, public Transformable{
	public:
		Section(Point a, Point b):_a(a),_b(b){}
		Section(double ax, double ay, double bx, double by):_a(Point(ax,ay)),_b(Point(bx,by)){}

		void draw() const{
			std::cout << "Rysujemy odcinek od " << _a << " do " << _b << std::endl;
		}

		double length() const{
			double dx = abs(_a.getX() - _b.getX());
			double dy = abs(_a.getY() - _b.getY());
			return sqrt(dx*dx + dy*dy);
		}

		void shift(double x, double y){
			_a.shift(x,y);
			_b.shift(x,y);
		}

		Point getP1() const{
			return _a;
		}

		Point getP2() const{
			return _b;
		}

	private:
		Point _a;
		Point _b;
};

class Deltoid : public Drawable, public Transformable, public ClosedShape{
	public:
		Deltoid(Point a, Point b, Point c, Point d):_a(a),_b(b),_c(c),_d(d){}
		Deltoid(Section e, Section f):_a(e.getP1()),_b(f.getP1()),_c(e.getP2()),_d(f.getP2()){}

		void draw() const {
			std::cout << "Rysujemy deltoid o wierzchołkach " << _a << ", " << _b << ", " << _c << ", " << _d << std::endl;
		}

		double length() const{
			Section d1(_a,_b);
			double s1 = d1.length();
			Section d2(_c,_d);
			double s2 = d2.length();

			return 2*s1 + 2*s2;
		}

		void shift(double x, double y){
			_a.shift(x,y);
			_b.shift(x,y);
			_c.shift(x,y);
			_d.shift(x,y);
		}

		double area() const{
			Section e(_a,_c);
			Section f(_b,_d);

			double el = e.length();
			double fl = f.length();
			
			return el*fl/2;
		}

	private:
		Point _a;
		Point _b;
		Point _c;
		Point _d;
};

void draw(Drawable * item){
	item->draw();
}
