#include "tcoordenada.h"

using namespace std;

void TCoordenada::setX(int x){
	this->x=x;
}

void TCoordenada::setY(int y){
	this->y=y;
}

void TCoordenada::setZ(int z){
	this->z=z;
}

int TCoordenada::getX(){
	return x;
}

int TCoordenada::getY(){
	return y;
}

int TCoordenada::getZ(){
	return z;
}

void TCoordenada::imprimir(){
	cout << "Coordenada x: " << x << endl;
	cout << "Coordenada y: " << y << endl;
	cout << "Coordenada z: " << z << endl;
}
