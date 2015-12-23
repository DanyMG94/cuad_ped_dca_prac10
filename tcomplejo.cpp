#include "tcomplejo.h"

using namespace std;

TComplejo::TComplejo(){
	re=0;
	im=0;
}

TComplejo::TComplejo(double real){
	re=real;
	im=0;
}

TComplejo::TComplejo(double real, double imaginaria){
	re=real;
	im=imaginaria;
}

TComplejo::TComplejo(const TComplejo &comp){
	Copia(comp);
}

void TComplejo::Copia(const TComplejo &comp){
	this->re=comp.re;
	this->im=comp.im;
}

TComplejo::~TComplejo(){
	re=im=0;
}

double TComplejo::Re() const{
	return re;
}

double TComplejo::Im() const{
	return im;
}

void TComplejo::Re(double re){
	this->re=re;
}

void TComplejo::Im(double im){
	this->im=im;
}

TComplejo& TComplejo::operator=(const TComplejo &comp){
	if(this!=&comp){
		(*this).~TComplejo();
		Copia(comp);
	}
	return *this;
}

TComplejo TComplejo::operator+(const TComplejo &comp) const{
	TComplejo suma;
	suma.re=re+comp.re;
	suma.im=im+comp.im;
	return suma;
}

TComplejo TComplejo::operator-(const TComplejo &comp) const{
	TComplejo resta;
	resta.re=re-comp.re;
	resta.im=im-comp.im;
	return resta;
}

TComplejo TComplejo::operator*(const TComplejo &comp) const{
	TComplejo mult;
	mult.re=(re*comp.re)-(im*comp.im);
	mult.im=(re*comp.im)-(im*comp.re);
	return mult;
}

TComplejo TComplejo::operator+(double comp) const{
	TComplejo suma;
	suma.re=re+comp;
	suma.im=im;
	return suma;
}

TComplejo TComplejo::operator-(double comp) const{
	TComplejo resta;
	resta.re=re-comp;
	resta.im=im;
	return resta;
}

TComplejo TComplejo::operator*(double comp) const{
	TComplejo mult;
	mult.re=re*comp;
	mult.im=im*comp;
	return mult;
}

TComplejo operator+(double complejo, const TComplejo &comp){
	TComplejo suma;
	suma.Re(complejo+comp.re);
	suma.Im(comp.im);
	return suma;
}

TComplejo operator-(double complejo, const TComplejo &comp){
	TComplejo resta;
	resta.Re(complejo-comp.re);
	resta.Im(-comp.im);
	return resta;
}

TComplejo operator*(double complejo, const TComplejo &comp){
	TComplejo mult;
	mult.Re(complejo*comp.re);
	mult.Im(comp.im*complejo);
	return mult;
}

bool TComplejo::operator==(const TComplejo &comp) const{
	bool iguales;
	if((*this).re==comp.re && (*this).im==comp.im)
		iguales=true;
	else
		iguales=false;
	return iguales;
}

bool TComplejo::operator!=(const TComplejo &comp) const{
	return !(*this==comp); 
}

double TComplejo::Mod() const{
	double mod=sqrt(pow(re,2.0)+pow(im,2.0));
	return mod;
}

double TComplejo::Arg() const{
	double arg=atan2(im,re);
	return arg;
}

ostream& operator<<(ostream &o, const TComplejo &obj){
	o << "(" << obj.re << " " << obj.im << ")";
	return o;
}
