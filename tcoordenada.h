#include <iostream>

using namespace std;

class TCoordenada{
	public:
		int getX();
		int getY();
		int getZ();
		void setX(int);
		void setY(int);
		void setZ(int);
		void imprimir();
	private:
		int x, y, z;
};

