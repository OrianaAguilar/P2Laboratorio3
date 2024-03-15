#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona {
 TPersonasLDE pila;
};

TPilaPersona crearTPilaPersona() {
  TPilaPersona pila = new rep_pilaPersona;
  pila->pila = crearTPersonasLDE();
  return pila;
}

bool esVaciaTPilaPersona(TPilaPersona p) {
  return cantidadTPersonasLDE(p->pila) == 0;
}

void liberarTPilaPersona(TPilaPersona &p) {
/*   while (!esVaciaTPilaPersona(p)) {
    eliminarFinalTPersonasLDE(p->pila);
  } */
  if(p->pila != NULL){
    liberarTPersonasLDE(p->pila);
  }
  delete p;
  p = NULL; 
  
}

nat cantidadEnTPilaPersona(TPilaPersona p) { 
  return cantidadTPersonasLDE(p->pila);
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona) {
  TPersona npersona = copiarTPersona(persona);
  insertarFinalDeTPersonasLDE(p->pila, npersona);
}

TPersona cimaDeTPilaPersona(TPilaPersona p) { 
  return obtenerFinalDeTPersonasLDE(p->pila);
}

void desapilarDeTPilaPersona(TPilaPersona &p) {
 eliminarFinalTPersonasLDE(p->pila);
}
