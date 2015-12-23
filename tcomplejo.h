#ifndef _COMPLEJO_H
#define _COMPLEJO_H
#include <iostream>
#include <math.h>

using namespace std;

class TComplejo{
	friend ostream& operator<<(ostream &, const TComplejo &);
	friend TComplejo operator+(double, const TComplejo &);
	friend TComplejo operator-(double, const TComplejo &);
	friend TComplejo operator*(double, const TComplejo &);
	public:
		TComplejo();
		TComplejo(double);
		TComplejo(double,double);
		TComplejo(const TComplejo &);
		~TComplejo();
		double Re() const;
		double Im() const;
		void Re(double);
		void Im(double);
		TComplejo operator+(const TComplejo &) const;
		TComplejo operator-(const TComplejo &) const;
		TComplejo operator*(const TComplejo &) const;
		TComplejo operator+(double) const;
		TComplejo operator-(double) const;
		TComplejo operator*(double) const;
		TComplejo& operator=(const TComplejo &);
		bool operator==(const TComplejo &) const;
		bool operator!=(const TComplejo &) const;
		double Mod() const;
		double Arg() const;
	private:
		double re;
		double im;
		void Copia(const TComplejo &);
};

#endif
