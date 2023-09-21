// ColaCircular.h
// Implementa los métodos requerdidos para construir TDA Colas
// basadas en el empleo de un arreglo circular
//pARA Colas cirucares se hereda de la clase cola, y algunos de sus metodos se sobreescriben o overwriten

//NORA: EL GAP es un povote que no se pone valor si no que señala las vueltas del vector,. separalas pos final y el inicio 

#ifndef _COLACIRCULAR_H 
#define _COLACIRCULAR_H

#include "TDA_cola.h"

class ColaCircular: public Cola{		//definir la clase que hereda de la clase cola

public:									//metodos publicos
	ColaCircular();						//constructor
	int siguiente(int v);				//metodo que permite calcular la posicion siguiente correspondiente a su parametro
	void borrarCola();					//metodo que vuelve a inicializar el TDA
	bool colaVacia();					//metodo que determina si el TDA esta vacio o no
	bool colaLlena();					//metodo que determina si el TDA esta lleno o no
	Tipo quitar();						//metodo que extrae y elimina un elemento del TDA
	void insertar(Tipo v);				//metodo que inserta un elemento en el TDA
	
};

ColaCircular::ColaCircular(){					//constructor
	setFrente(0);								//inicilizar la pos apuntada por frente
	setFinal(EXT-1);							//inicilizar la pos apuntada por final
}

int ColaCircular::siguiente(int v){				//metodo que permite calcular la posicion siguiente correspondiente a su parametro
	return ((v+1) % EXT);						//calculo del valor respuesta, para poder volver al comeinzo 
}

void ColaCircular::borrarCola(){	 			//metodo que vuelve a inicializar el TDA
	setFrente(0);								//inicilizar la pos apuntada por frente
	setFinal(EXT-1);							//inicilizar la pos apuntada por final
}

bool ColaCircular::colaVacia(){					//metodo que determina si el TDA esta vacio o no
	return (siguiente(getFinal()) == getFrente());
}

bool ColaCircular::colaLlena(){					//metodo que determina si el TDA esta lleno o no
	return (siguiente(siguiente(getFinal())) == getFrente());	//determina que el apuntador final esta a dos posiciones antes del apuntador frente
}

Tipo ColaCircular::quitar(){					//metodo que extrae y elimina un elemento del TDA
	Tipo aux;									//var para contener el valor a devolver
	
	if (!colaVacia()){
		aux = getVec(getFrente());				//almacena el valor en var respuesta
		setFrente(siguiente(getFrente()));		//modifica frente para que apunte al siguiente elemento del TDA
	}
	return aux;									//devuelve respuesta
}

void ColaCircular::insertar(Tipo v){			//metodo que inserta un elemento en el TDA
	if (!colaLlena()){
		setFinal(siguiente(getFinal()));		//modifica frente para que apunte al siguiente elemento del TDA
		setVec(v,getFinal());					//almacena el valor en posicion apuntada por final
	}
}

#endif