#include "tlistacom.h"

TListaNodo::TListaNodo(){
	anterior=NULL;
	siguiente=NULL;
}

TListaNodo::~TListaNodo(){
	anterior=NULL;
	siguiente=NULL;
}

TListaNodo::TListaNodo(const TListaNodo &lista){
	e=lista.e;
	anterior=lista.anterior;
	siguiente=lista.siguiente;
}

TListaNodo& TListaNodo::operator=(const TListaNodo &lista){
	(*this).~TListaNodo();
	e=lista.e;
	anterior=lista.anterior;
	siguiente=lista.siguiente;
	return *this;
}

TListaPos::TListaPos(){
	pos=NULL;
}

TListaPos::~TListaPos(){
	pos=NULL;
}

TListaPos::TListaPos(const TListaPos &lista){
	pos=lista.pos;
}

TListaPos& TListaPos::operator=(const TListaPos &lista){
	if(*this!=lista){
		(*this).~TListaPos();
		pos=lista.pos;
	}
	return *this;
}

bool TListaPos::operator==(const TListaPos &lista) const{
	bool iguales;
	if(pos==lista.pos)
		iguales=true;
	else
		iguales=false;
	return iguales;
}

bool TListaPos::operator!=(const TListaPos &lista) const{
	return !(*this==lista);
}

bool TListaPos::EsVacia() const{
	return (pos==NULL);
}

TListaPos TListaPos::Anterior() const{
	TListaPos aux;
	if(pos!=NULL){
		if(pos->anterior==NULL)
			return aux;
		else
			aux.pos=pos->anterior;
	}
	return aux;
}

TListaPos TListaPos::Siguiente() const{
	TListaPos aux;
	if(pos!=NULL){
		if(pos->siguiente==NULL)
			return aux;
		else
			aux.pos=pos->siguiente;
	}
	return aux;
}

TListaCom::TListaCom(){
	primero=ultimo=NULL;
}

TListaCom::TListaCom(const TListaCom &lista){
	primero=NULL;
	ultimo=NULL;
	//*this=lista;
	if(!lista.EsVacia()){
		TListaNodo *aux=lista.ultimo;
		while(aux!=NULL){
			InsCabeza(aux->e);
			aux=aux->anterior;
		}
	}
}


TListaCom::~TListaCom(){
	TListaNodo *punt;
	while(primero!=NULL){	//Cuando llegue al ultimo nodo, el puntero siguiente sera NULL
		punt=primero;	
		delete punt;	//Vamos borrando los nodos de la lista
		primero=primero->siguiente;	//primero apuntara al contenido que apunta el puntero siguiente (siguiente nodo de la lista)
	}
	ultimo=NULL;
}

bool TListaCom::EsVacia() const{
	return (primero==NULL && ultimo==NULL);
}

TListaPos TListaCom::Primera() const{
	TListaPos aux;
	if(!EsVacia())
		aux.pos=primero;	//Apunta al primer nodo de la lista
	return aux;
}

TListaPos TListaCom::Ultima() const{
	TListaPos aux;
	if(!EsVacia())
		aux.pos=ultimo;	//Apunta al ultimo nodo de la lista
	return aux;
}

int TListaCom::Longitud() const{
	TListaNodo *pA;
	int longitud=0;
	if(!EsVacia()){
		pA=primero;
		while(pA!=NULL){
			pA=pA->siguiente;
			longitud++;
		}
	}
	return longitud;
}

bool TListaCom::Buscar(const TComplejo &com) const{
	bool encontrado=false;
	TListaNodo *aux;
	aux=primero;
	while(aux!=NULL && !encontrado){
		if(aux->e==com){
			encontrado=true;
		}
		aux=aux->siguiente;
	}
	return encontrado;
}

TComplejo TListaCom::Obtener(const TListaPos &posicion) const{
	TComplejo complejo;
	bool encontrado=false;
	TListaNodo *aux;
	if(!posicion.EsVacia()){
		aux=primero;
		while(aux!=NULL && !encontrado){
			if(aux==posicion.pos){	//Si las dos posiciones coinciden
				encontrado=true;
				complejo=posicion.pos->e;	//Guardamos el complejo de esa posicion para devolverlo
			}
			aux=aux->siguiente;
		}
	}
	return complejo;
}

bool TListaCom::operator==(const TListaCom &lista) const{
	bool iguales=false;
	TListaNodo *l1, *l2;
	if(Longitud()==lista.Longitud()){	//Si no tienen la misma longitud, directamente no son iguales
		l1=primero;
		l2=lista.primero;
		iguales=true;
		while(l1!=NULL && iguales){
			if(l1->e!=l2->e)	//Si los dos complejos son distintos, ya no tienen los mismos elementos
				iguales=false;
			else{
				l1=l1->siguiente;
				l2=l2->siguiente;
			}
		}
	}
	return iguales;
}

bool TListaCom::operator!=(const TListaCom &lista) const{
	return !(*this==lista);
}

ostream& operator<<(ostream &o, const TListaCom &lista){
	TListaNodo *aux;
	o << "{";
	if(!lista.EsVacia()){
		int contadorNodos=0;
		int longitud=lista.Longitud();
		aux=lista.primero;
		while(aux!=NULL){
			contadorNodos++;
			if(contadorNodos!=longitud)
				o << aux->e << " ";
			else
				o << aux->e;
			aux=aux->siguiente;
		}
	}
	o << "}";
	return o;
}


bool TListaCom::InsCabeza(const TComplejo &com){
	bool insertado=false;
	TListaNodo *aux;
	aux=new TListaNodo;
	if(aux!=NULL){	//Si no se ha podido reservar memoria
		insertado=true;	//Se va a poder insertar como primer elemento (nodo) de la lista de complejos
		aux->siguiente=primero;	//EL puntero siguiente del nodo que vamos a insertar en cabeza
								//apunta al primer nodo antiguo que había
		if(!EsVacia())			//Si la lista tiene algún nodo
			primero->anterior=aux;	//El nodo que teníamos ya insertado como primero, su puntero anterior
									//apuntará al nodo que estamos insertando
		else  //Si la lista esta vacía
			ultimo=aux;	//Asignamos el puntero ultimo al elemento que acabamos de insertar (solo hay un nodo) 
		aux->e=com;	//Asignamos el complejo que nos pasan como parametro al del nodo que estamos insertando
		primero=aux; //El puntero primero apunta al nuevo nodo, es decir, ya es el primero
	}
	return insertado;
}

TListaCom& TListaCom::operator=(const TListaCom &lista){
	if(this!=&lista){	//Si no es la misma lista
		(*this).~TListaCom();	//'Destruimos' el contenido de la lista implícita
		TListaNodo *puntUlt=lista.ultimo;
		while(puntUlt!=NULL){	//Mientras que anterior siga apuntando algun nodo
			InsCabeza(puntUlt->e);	//Insertamos en cabeza el complejo del nodo actual
			puntUlt=puntUlt->anterior;
		}
	}
	return *this;
}

TListaCom TListaCom::operator+(const TListaCom &lista) const{
	TListaCom concatenacion(lista);	//Llamamos al constructor copia para que copie los elementos de la lista
									//que nos pasan como parametro en la que tenemos que devolver
	TListaNodo *aux=ultimo;			//Puntero que apunta al ultimo nodo de la lista implícita
	while(aux!=NULL){				//Mientras el puntero apunte a algun nodo
		concatenacion.InsCabeza(aux->e);	//Insertamos en cabeza de la lista resultante los elementos de
											//la lista implícita
		aux=aux->anterior;					//Decrementamos el puntero al anterior nodo
	}
	return concatenacion;
}


bool TListaCom::Borrar(const TComplejo &com){
	bool encontrado=false, borrado=false;
	if(Buscar(com))
		encontrado=true;
	if(encontrado){
		TListaNodo *aux, *ant, *sig;
		aux=primero;
		while(aux!=NULL && !borrado){
			if(aux->e==com){
				if(Longitud()==1){
					primero=NULL;
					ultimo=NULL;
				}
				else if(aux==ultimo){
					ultimo=aux->anterior;
					ultimo->siguiente=NULL;
				}
				else if(Longitud()>1 && aux==primero){
					primero=aux->siguiente;
					primero->anterior=NULL;
				}
				else{
					ant=aux->anterior;
					sig=aux->siguiente;
					
					ant->siguiente=sig;
					sig->anterior=ant;
				}
				borrado=true;
				delete aux;
			}
			aux=aux->siguiente;
		}
	}
	return borrado;
}

bool TListaCom::Borrar(const TListaPos &p){
	bool borrado=false, posencontrado=false;
	if(p.pos!=NULL){
		TListaNodo *aux, *ant, *sig;
		aux=primero;
		while(aux!=NULL && !posencontrado){
			if(aux==p.pos)
				posencontrado=true;
			else
				aux=aux->siguiente;
		}
		if(posencontrado){
				if(aux==p.pos){
					if(Longitud()==1){
						primero=NULL;
						ultimo=NULL;
					}
					else if(aux==ultimo){
						ultimo=aux->anterior;
						ultimo->siguiente=NULL;
					}
					else if(Longitud()>1 && aux==primero){
						primero=aux->siguiente;
						primero->anterior=NULL;
					}
					else{
						ant=aux->anterior;
						sig=aux->siguiente;
					
						ant->siguiente=sig;
						sig->anterior=ant;
					}
					borrado=true;
					delete aux;
				}
				aux=aux->siguiente;
		}
	}
	return borrado;
}

bool TListaCom::BorrarTodos(const TComplejo &com){
	bool borrados=false;
	if(!Buscar(com))
		borrados=false;
	else{
		while(Buscar(com)){
			Borrar(com);
		}
	}
	return borrados;
}

TListaCom TListaCom::operator-(const TListaCom &lista) const{
	TListaCom nueva;
	if(!lista.EsVacia()){
		TListaNodo *aux, *aux1;
		aux=ultimo;
		while(aux!=NULL){
			if(!lista.Buscar(aux->e))
				nueva.InsCabeza(aux->e);
			aux=aux->anterior;
		}
		return nueva;
	}
	else
		return *this;
}

bool TListaCom::InsertarI(const TComplejo &com, const TListaPos &p){
	bool insertado=false;
	if(!p.EsVacia()){	//Comprobamos que la posición apunta a un nodo, que no es NULL
		TListaNodo *nodo;
		nodo=new TListaNodo;	//Creamos el nodo que vamos a insertar a la izquierda
		if(nodo!=NULL){			//Si se ha podido reservar memoria
			if(p.pos==primero)	//Si la posición es la primera, insertaremos en cabeza directamente
								//ya que primero y ultimo apuntan al único nodo que hay
				insertado=InsCabeza(com);
			else{
				nodo->e=com;						//Le asignamos el nodo que se nos pasa como parámetro
				nodo->anterior=p.pos->anterior;		//El anterior del nodo apuntará al nodo de su izquierda
				nodo->siguiente=p.pos;				//El siguiente del nodo apuntará al nodo de la posición que nos
													//pasan como parámetro
				p.pos->anterior->siguiente=nodo;	//Ahora, el siguiente del nodo anterior al que hemos creado
													//apuntará al nodo que hemos introducido
				p.pos->anterior=nodo;				//La posición anterior del nodo, cuya posicion nos pasan,
													//apuntará a la del nodo
			}
			insertado=true;
		}
	}
	return insertado;
}

bool TListaCom::InsertarD(const TComplejo &com, const TListaPos &p){
	bool insertado=false;
	if(!p.EsVacia()){	
		TListaNodo *nodo;
		nodo=new TListaNodo;	
		if(nodo!=NULL){			
			if(p.pos==ultimo){
				ultimo=nodo;
				nodo->e=com;						
				nodo->anterior=p.pos;
				p.pos->siguiente=nodo;
			}
			else{
				nodo->e=com;
				nodo->anterior=p.pos;
				nodo->siguiente=p.pos->siguiente;
				p.pos->siguiente->anterior=nodo;
				p.pos->siguiente=nodo;
			}
			insertado=true;
		}
	}
	return insertado;
}



