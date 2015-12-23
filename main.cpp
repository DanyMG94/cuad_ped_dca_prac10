#include <iostream>

using namespace std;

#include "tvectorcom.h"
#include "tcomplejo.h"
#include "tlistacom.h"

int main(void)
{
	cout << "<------------------Pruebas para la TCOMPLEJO------------------------->" << endl;
	TComplejo vacio2;
	cout << "Complejo vacío2 (1,0): " << vacio2 << endl;
	
	TComplejo vacio;
	cout << "Complejo vacío (0,0): " << vacio << endl;
	
	TComplejo parteReal(4);
	cout << "Complejo a partir de parte real: " << parteReal << endl;
	
	TComplejo parteReal2(8);
	cout << "Complejo a partir de parte real: " << parteReal2 << endl;
	
	TComplejo copia(parteReal);
	cout << "Complejo a partir de constructor copia: " << copia << endl;
	
	TComplejo definido(4,8.9);
	cout << "Complejo a partir de real e imaginaria: " << definido << endl;
	
	TComplejo definido2(5,8.2);
	cout << "Complejo a partir de real e imaginaria: " << definido2 << endl;
	
	TComplejo asignar;
	asignar=parteReal;
	cout << "Complejo a partir de asignación: " << asignar << endl;
	
	TComplejo suma;
	TComplejo def(1,0.1);
	suma=definido+def;
	cout << "Complejo suma con otro complejo: " << suma << endl;
	
	TComplejo restac;
	restac=definido-def;
	cout << "Complejo resta con otro complejo: " << restac << endl;
	
	TComplejo multi;
	multi=definido*def;
	cout << "Complejo multiplicación con otro complejo: " << multi << endl;
	
	TComplejo sumae;
	sumae=def+3;
	cout << "Complejo suma con un número: " << sumae << endl;
	
	TComplejo restae;
	restae=def-1;
	cout << "Complejo resta con un número: " << restae << endl;
	
	TComplejo multie;
	multie=def*7;
	cout << "Complejo multiplicación con un número: " << multie << endl;
	
	TComplejo sumap;
	sumap=6+def;
	cout << "Suma de número con complejo: " << sumap << endl;
	
	TComplejo restap;
	restap=3-definido;
	cout << "Resta de número con complejo: " << restap << endl;
	
	TComplejo multip;
	multip=5*definido;
	cout << "Multiplicación de número con complejo: " << multip << endl;
	
	TComplejo ptr, ptd;
	TComplejo compp(3,3.5), compa(3,3.5);
	if(ptr==ptd)
		cout << "Los complejos " << ptr << " y " << ptd << " son iguales" << endl;
	else
		cout << "Los complejos " << ptr << " y " << ptd << " son distintos" << endl;
	
	if(compp==compa)
		cout << "Los complejos " << compp << " y " << compa << " son iguales" << endl;
	else
		cout << "Los complejos " << compp << " y " << compa << " son distintos" << endl;
		
	if(compp!=ptr)
		cout << "Los complejos " << compp << " y " << ptr << " son distintos" << endl;
	else
		cout << "Los complejos " << compp << " y " << ptr << " son iguales" << endl;
		
	double modulo;
	modulo=compp.Mod();
	cout << "El módulo de " << compp << " es: " << modulo << endl;
	
	double argumento;
	argumento=compp.Arg();
	cout << "El argumento de " << compp << " es: " << argumento << endl;
	
	cout << "<------------------Pruebas para la TVECTORCOM------------------------>" << endl;
    TComplejo c1(1,0.5);
	TComplejo c2(3,0.5);
	TComplejo c3(5,0.5);
	TComplejo c4, c5;
	TComplejo c6(9,0.5);
	TVectorCom v1(6);
	v1[1]=c1;
	v1[2]=c2;
	v1[3]=c3;
	v1[4]=c4;
	v1[5]=c5;
	v1[6]=c6;
	
	TVectorCom vector2(v1);
	
	cout << "Mostramos el vector entero: ";
	cout << v1;
	cout << " y su tamaño es: " << v1.Tamano() << endl;
	
	cout << "Mostramos un vector creado a partir del constructor copia: ";
	cout << vector2 << endl;
	
	cout << "Complejos cuya parte real es igual o mayor que 3: ";
	v1.MostrarComplejos(3);
	cout << endl;
	
	cout << "Posiciones ocupadas (distintas de complejo 0,0): ";
	cout << v1.Ocupadas() << endl;
	
	cout << "Comprobamos si existe el complejo (9,0.5): ";
	cout << v1.ExisteCom(c6) << endl;
	
	cout << "Comprobamos si existe el complejo (8,8): ";
	cout << v1.ExisteCom(TComplejo(8,8)) << endl;
	
	TVectorCom v2(3);
	v2[1]=TComplejo(1,1);
	v2[2]=TComplejo(2,2);
	v2[3]=TComplejo(3,3);
	
	TVectorCom v3(3);
	v3[1]=TComplejo(1,1);
	v3[2]=TComplejo(2,2);
	v3[3]=TComplejo(3,3);
	
	TVectorCom v4(3);
	v4[1]=TComplejo(9,9);
	v4[2]=TComplejo(2,2);
	v4[3]=TComplejo(3,3);
	
	if(v2==v3)
		cout << "Son iguales los vectores: " << v2 << " y " << v3 << endl;
	else
		cout << "Son distintos los vectores: " << v2 << " y " << v3 << endl;
		
	if(v2!=v4)
		cout << "Son distintos los vectores: " << v2 << " y " << v4 << endl;
	else
		cout << "Son iguales los vectores: " << v2 << " y " << v4 << endl;
		
	TVectorCom v5(3);
	v5=v4;
	cout << "Asignación del vector 4 " << v4 << " al 5: " << v5 << endl;
	cout << "Mostramos la posición 3 del vector 4, donde estará su complejo: " << v4[3] << endl;
	
	
	cout << "Vamos a redimensionar el vector 5 a tamaño 5 (dos posiciones más): " << endl;
	v5.Redimensionar(5);
	cout << "Mostrando el vector redimensionado: " << v5 << endl;
	
	cout << "Vamos a redimensionar el vector 5 a tamaño 2 (tres posiciones menos): " << endl;
	v5.Redimensionar(2);
	cout << "Mostrando el vector redimensionado: " << v5 << endl;
	
	cout << "<---------------------Pruebas para la TLISTACOM-------------------------->" << endl;
	TListaCom lista, lista4, concatenacion, concat;
	lista.InsCabeza(c1);
	lista.InsCabeza(c2);
	lista.InsCabeza(c4);
	lista.InsCabeza(c6);
	TListaCom lista5;
	lista5.InsCabeza(c4);
	lista5.InsCabeza(c6);
	lista5.InsCabeza(c1);
	TListaCom lista1(lista), lista2=lista;
	cout << "Lista 1 insertando elementos en cabeza: " << lista << endl;
	cout << "Longitud de la lista 1: " << lista.Longitud() << endl;
	cout << "¿Está el complejo (1,0.5) en la lista 1?: " << lista.Buscar(c1) << endl;
	TComplejo obtenidou, obtenidop;
	obtenidou=lista5.Obtener(lista5.Ultima());
	obtenidop=lista5.Obtener(lista5.Primera());
	cout << "Complejo obtenido en la ultima posición de la lista " << lista5 << " : " << obtenidou << endl;
	cout << "Complejo obtenido en la primera posición de la lista " << lista5 << " : " << obtenidop << endl;
	cout << "Lista 2 usando el constructor copia: " << lista1 << endl;
	cout << "Lista 3 usando la asignación: " << lista2 << endl;
	cout << "Lista 4 esta vacia: " << lista4.EsVacia() << endl;
	cout << "Longitud de la lista 4: " << lista4.Longitud() << endl;
	concatenacion=lista1+lista2;
	cout << "Lista concatenada: " << concatenacion << endl;
	concat=lista+lista5;
	cout << "Lista concatenada de las listas " << lista << " y " << lista5 << " : " << concat << endl;
	TListaCom listavacia=lista4+lista4, listar=lista1+lista4;
	cout << "Concatenar listas vacías: " << listavacia << endl;
	cout << "Concatenar listas: " << listar << endl;
	TListaCom listaq;
	listaq.InsCabeza(c1);
	cout << "Lista antes de borrar: " << listaq << endl;
	listaq.Borrar(c1);
	cout << "Lista después de borrar: " << listaq << endl;
	listaq.InsCabeza(c1);
	listaq.InsCabeza(c2);
	cout << "Lista antes de borrar: " << listaq << endl;
	listaq.Borrar(c1);
	cout << "Lista después de borrar: " << listaq << endl;
	listaq.InsCabeza(c1);
	cout << "Lista antes de borrar: " << listaq << endl;
	listaq.Borrar(c1);
	cout << "Lista después de borrar: " << listaq << endl;
	cout << "--------------------------------" << endl;
	listaq.InsCabeza(c1);
	listaq.InsCabeza(c3);
	listaq.InsCabeza(c4);
	listaq.InsCabeza(c6);
	cout << "Lista antes de borrar: " << listaq << endl;
	listaq.Borrar(c3);
	cout << "Lista después de borrar: " << listaq << endl;
	cout << "-------------------------------------" << endl;
	TListaPos primera=listaq.Primera();
	for(int i=1;i<=listaq.Longitud();i++){
		listaq.Borrar(primera);
	}
	cout << "Lista después de borrar: " << listaq << endl;
	cout << "-------------------------------------------" << endl;
	TListaCom play;
	play.InsCabeza(TComplejo(1,1));
	play.InsCabeza(TComplejo(1,2));
	play.InsCabeza(TComplejo(1,1));
	play.InsCabeza(TComplejo(1,3));
	play.InsCabeza(TComplejo(1,1));
	cout << "Lista antes de borrar: " << play << endl;
	play.BorrarTodos(TComplejo(1,1));
	cout << "Lista después de borrar: " << play << endl;
	TListaCom uno;
	uno.InsCabeza(TComplejo(1,1));
	uno.InsCabeza(TComplejo(1,2));
	uno.InsCabeza(TComplejo(1,1));
	uno.InsCabeza(TComplejo(1,5));
	cout << "--------------------------------------------" << endl;
	cout << "Lista antes de restar: " << uno << endl;
	TListaCom resta=uno-play;
	cout << "Lista después de restar: " << resta << endl;
	cout << "--------------------------------------------" << endl;
	TListaCom vacia;
	TListaCom res=vacia-uno;
	cout << "Lista después de restar: " << res << endl;
	cout << "---------------------------------------------------------" << endl;
	TListaCom prueba;
	prueba.InsCabeza(c1);
	prueba.InsCabeza(c2);
	cout << "Lista antes de prueba " << prueba << endl;
	prueba.InsertarD(c3,prueba.Ultima());
	prueba.InsertarD(c3,prueba.Primera());
	cout << "Lista después de prueba " << prueba << endl;
	cout << "-------------------------------------------------" << endl;
	prueba.InsertarI(c4,prueba.Primera());
	prueba.InsertarI(c4,prueba.Ultima());
	cout << "Lista después de prueba " << prueba << endl;
	cout << "-----------------------------------------------------" << endl;
	
	TComplejo p(1,1), q(2,2), r(3,3);
	TListaCom a;
	TListaPos pos;
	
	a.InsCabeza(p);
	a.InsertarD(q,a.Ultima());
	a.InsertarD(r,a.Ultima());
	cout << "Lista: " << a << endl;
	pos=a.Ultima();
	a.Borrar(pos);
	cout << "Lista: " << a << endl;
	pos=a.Ultima();
	a.Borrar(pos);
	cout << "Lista: " << a << endl;
	pos=a.Ultima();
	a.Borrar(pos);
	cout << "Lista: " << a << endl;
	
	TListaCom listaa;
	listaa.InsCabeza(TComplejo(1,1));
	listaa.InsCabeza(TComplejo(1,1));
	listaa.InsCabeza(TComplejo(1,1));
	
	TListaCom listab(listaa);
	TListaCom listac;
	listac.InsCabeza(TComplejo(2,2));
	if(listaa==listab)
		cout << "Las listas " << listaa << " y " << listab << " son iguales" << endl;
	else
		cout << "Las listas " << listaa << " y " << listab << " son distintas" << endl;
	
	if(listaa!=listac)
		cout << "Las listas " << listaa << " y " << listac << " son distintas" << endl;
	else
		cout << "Las listas " << listaa << " y " << listac << " son iguales" << endl;
		
  return 0;
}
