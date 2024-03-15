#include "../include/conjuntoIds.h"

struct rep_conjuntoIds{
	int cant;
	nat cantMax;
	bool *ids; // Arreglo de elementos utilizando un arreglo booleano para representar la presencia o ausencia
    
};


TConjuntoIds crearTConjuntoIds(nat cantMax){
	TConjuntoIds c = new rep_conjuntoIds;
	c->cantMax = cantMax+1;
	c->cant = 0;
	c->ids = new bool[c->cantMax+1];
	for(nat i=0; i <= c->cantMax; i++){
		c->ids[i] = false;
	}
	return c;   
};


bool esVacioTConjuntoIds(TConjuntoIds c){
	return c->cant == 0;
}; 


void insertarTConjuntoIds(nat id, TConjuntoIds &c){ 
    if(id <= c->cantMax && !c->ids[id]){
		c->ids[id] = true;
		c->cant++;
	}
}; 

void borrarTConjuntoIds(nat id, TConjuntoIds &c){ 
    if(c->ids[id]){
		c->ids[id] = false;
		c->cant--;
	}
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c){
	if(id > c->cantMax || id==0){
		return false;
	}
	return c->ids[id];
};

nat cardinalTConjuntoIds(TConjuntoIds c){
	return c->cant;
};

nat cantMaxTConjuntoIds(TConjuntoIds c){
	return c->cantMax-1;
};

void imprimirTConjuntoIds(TConjuntoIds c){
    for (nat i=1; i < c->cantMax; i++){ //LE AGREGUE UN = EN (i < c->cantMax) Y SIGUE FUNCIONANDO SOSPECHOSAMENTE BIEN
		if(c->ids[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
};

void liberarTConjuntoIds(TConjuntoIds &c){
    delete [] c->ids;
	delete c;
	c = NULL;
};




TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds c = crearTConjuntoIds(c1->cantMax);
	for(nat i=1; i <= c1->cantMax; i++){
		c->ids[i] = c1->ids[i] || c2->ids[i];
	}
	return c;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds c = crearTConjuntoIds(c1->cantMax);
	for(nat i=1; i <= c1->cantMax; i++){
		c->ids[i] = c1->ids[i] && c2->ids[i];
	}
	return c;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds c = crearTConjuntoIds(c1->cantMax);
	for(nat i=1; i <= c1->cantMax; i++){
		if(c1->ids[i] && !c2->ids[i]){
			c->ids[i] = true;
		}
	}
	return c;
};

