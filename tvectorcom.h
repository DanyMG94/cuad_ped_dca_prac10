#ifndef _TVECTORCOM_H
#define _TVECTORCOM_H
#include "tcomplejo.h"

class TVectorCom{
	friend ostream& operator<<(ostream &, const TVectorCom &);
	private:
		TComplejo *c;
		int tamano;
		TComplejo error;
	public:
		TVectorCom();
		TVectorCom(int);
		TVectorCom(const TVectorCom &);
		~TVectorCom();
		TVectorCom& operator=(const TVectorCom &);
		bool operator==(const TVectorCom &) const;
		bool operator!=(const TVectorCom &) const;
		int Tamano() const;
		bool ExisteCom(const TComplejo &) const;
		int Ocupadas() const;
		TComplejo operator[](int) const;
		TComplejo& operator[](int);
		void MostrarComplejos(double) const;
		bool Redimensionar(int);
};

#endif
