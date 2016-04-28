/*
	vector.h
 */

#ifndef VECTOR_H_
#define VECTOT_H_
#include <iostream>
namespace VECTOR{
	class Vector{
	public:
		enum Mode {RECT,POL};//直角坐标模式 和 极坐标模式
	private:
		double x; //horizontal value 水平值
		double y; //vertical value 
		double mag;//length of vertor
		double ang;//direction of vector in degrees：
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval()const{
			return x;
		}
		double yval()const{
			return y;
		}
		double magval()const{
			return mag;
		}
		double angval()const{
			return ang;
		}
		void polar_mode();
		void rect_mode();
		//operator overloading
		Vector operator+(const Vector &b)const;
		Vector operator-(const Vector &b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		//friend
		friend Vector operator*(double n, const Vector & a){
			return a * n;
		}
		friend std::ostream &operator<<(std::ostream & os,Vector & v)const;


	};
}



#endif
