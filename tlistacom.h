#ifndef _TLISTACOM_H
#define _TLISTACOM_H
#include "tcomplejo.h"

class TListaPos;
class TListaCom;

class TListaNodo{
	friend ostream& operator<<(ostream &, const TListaCom &);
	friend class TListaPos;
	friend class TListaCom;
	private:
		TComplejo e;
		TListaNodo *anterior;
		TListaNodo *siguiente;
	public:
		TListaNodo();
		~TListaNodo();
		TListaNodo(const TListaNodo &);
		TListaNodo& operator=(const TListaNodo &);
};

class TListaPos{
	friend class TListaCom;
	friend class TListaNodo;
	private:
		TListaNodo *pos;
	public:
		TListaPos();
		~TListaPos();
		TListaPos(const TListaPos &);
		TListaPos& operator=(const TListaPos &);
		bool operator==(const TListaPos &) const;
		bool operator!=(const TListaPos &) const;
		bool EsVacia() const;
		TListaPos Anterior() const;
		TListaPos Siguiente() const;
};

class TListaCom{
	friend ostream& operator<<(ostream &, const TListaCom &);
	friend class TListaNodo;
	friend class TListaPos;
	private:
		TListaNodo *primero;
		TListaNodo *ultimo;
	public:
		TListaCom();
		TListaCom(const TListaCom &);
		~TListaCom();
		bool EsVacia() const;
		TListaPos Primera() const;
		TListaPos Ultima() const;
		int Longitud() const;
		bool operator==(const TListaCom &) const;
		bool operator!=(const TListaCom &) const;
		TListaCom& operator=(const TListaCom &);
		bool InsCabeza(const TComplejo &);
		TComplejo Obtener(const TListaPos &) const;
		bool Buscar(const TComplejo &) const;
		TListaCom operator+(const TListaCom &) const;
		TListaCom operator-(const TListaCom &) const;
		bool Borrar(const TComplejo &);
		bool BorrarTodos(const TComplejo &);
		bool Borrar(const TListaPos &);
		bool InsertarI(const TComplejo &, const TListaPos &);
		bool InsertarD(const TComplejo &, const TListaPos &);
};

#endif
