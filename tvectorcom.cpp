#include "tvectorcom.h"

TVectorCom::TVectorCom(){
	c=NULL;
	tamano=0;
}

TVectorCom::TVectorCom(int tam){
	if(tam<0){
		TVectorCom();
	}
	else{
		tamano=tam;
		c=new TComplejo[tamano];
	}
}

TVectorCom::~TVectorCom(){
	delete[] c;
	tamano=0;
	c=NULL;
}

TVectorCom::TVectorCom(const TVectorCom &vec){
	if(vec.c==NULL){
		c=NULL;
		tamano=0;
	}
	else{
		tamano=vec.tamano;
		c=new TComplejo[tamano];
		for(int i=0;i<tamano;i++){
			c[i]=vec.c[i];
		}
	}
}

TVectorCom& TVectorCom::operator=(const TVectorCom &vec){
	if(this!=&vec){		//Comprobamos si no es el mismo objeto, en este caso vector
		(*this).~TVectorCom();
		tamano=vec.tamano;
		c=new TComplejo[tamano];
		for(int i=0;i<tamano;i++){
			c[i]=vec.c[i];
		}
	}
	return *this;
}

bool TVectorCom::operator==(const TVectorCom &vec) const{
	bool iguales=false;
	if(tamano==vec.tamano){
		iguales=true;
		for(int i=0;i<tamano && iguales;i++){
			if(c[i]!=vec.c[i]){
				iguales=false;
			}
		}
	}
	return iguales;
}

bool TVectorCom::operator!=(const TVectorCom &vec) const{
	return !(*this==vec);
}

int TVectorCom::Tamano() const{
	return tamano;
}

bool TVectorCom::ExisteCom(const TComplejo &com) const{
	bool encontrado=false;
	for(int i=0;i<tamano && !encontrado;i++){
		if(c[i]==com){
			encontrado=true;
		}
	}
	return encontrado;
}


int TVectorCom::Ocupadas() const{
	int contadorOcupadas=0;
	for(int i=0;i<tamano;i++){
		if(c[i].Re()!=0 || c[i].Im()!=0)
			contadorOcupadas++;
	}
	return contadorOcupadas;
}

TComplejo TVectorCom::operator[](int pos) const{
	if(pos>=1 && pos<=tamano){
		return c[pos-1];
	}
	return error;
}

TComplejo& TVectorCom::operator[](int pos){
	if(pos>=1 && pos<=tamano){
		return c[pos-1];
	}
	return error;
}

void TVectorCom::MostrarComplejos(double real) const{
	cout << "[";
	int contReales=0;
	for(int i=0;i<tamano;i++){
		if(c[i].Re()>=real){
			contReales++;
		}
	}
	int j=0;
	for(int i=0;i<tamano && j<contReales;i++){
		if(c[i].Re()>=real){
			cout << c[i];
			j++;
			if(j!=contReales){
				cout << ", ";
			}
		}
	}
	cout << "]";
}

bool TVectorCom::Redimensionar(int tam){
	bool redimensionado=false;
	int i;
	if(tam>0 && tamano!=tam){
		TComplejo *aux;
		TComplejo nuevo;
		aux=new TComplejo[tam];
		if(tam>tamano){
			for(i=0;i<tamano;i++){
				aux[i]=c[i];
			}
			for(int j=i;j<tam;j++){
				aux[i]=nuevo;
			}
			c=aux;
			tamano=tam;
		}
		else{
			//aux=new TComplejo[tam];
			for(i=0;i<tam;i++){
				aux[i]=c[i];
			}
			c=aux;
			tamano=tam;
		}
		redimensionado=true;
	}
	return redimensionado;
}

ostream& operator<<(ostream &o, const TVectorCom &obj){
	o << "[";
	if(obj.tamano>0){
		for(int i=0;i<obj.tamano;i++){
			cout << "(" << i+1 << ")";
			cout << " ";
			cout << obj.c[i];
			if(i!=obj.tamano-1){
				cout << ", ";
			}
		}
	}
	o << "]";
	return o;
}
