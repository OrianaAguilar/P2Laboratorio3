#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

struct rep_NodoCola{
  TPersonasABB arbol;
  rep_NodoCola* sig;
};
typedef struct rep_NodoCola *TNodoCola;

struct rep_colaPersonasABB {
  nat cant = 0;
  rep_NodoCola* inicio;
  rep_NodoCola* final;
};

TColaPersonasABB crearTColaPersonasABB() {
  TColaPersonasABB cola = new rep_colaPersonasABB;
  cola->inicio = NULL;
  cola->final = NULL;
  return cola;
}

void liberarNodoCola(TNodoCola &nodo) {
  if(nodo != NULL){
   // liberarTPersonasABB(nodo->arbol);
    liberarNodoCola(nodo->sig);
    delete nodo;
    nodo = NULL;
  }
}

void liberarTColaPersonasABB(TColaPersonasABB &c) {
  if(c->inicio != NULL){
    liberarNodoCola(c->inicio);
  }
  delete c;
  c = NULL;
}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c) { 
  return c->cant;
 }

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c) {
  TNodoCola nodo = new rep_NodoCola;
  nodo->arbol = t;
  nodo->sig = NULL;

  if(c->inicio == NULL){
    c->inicio = nodo;   
  }
  else{
    //nodo->sig = c->inicio;
    //c->inicio = nodo;
    c->final->sig = nodo;
  } 
  c->final = nodo;
  c->cant++;
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c) { 
  if (c == NULL || c->inicio == NULL ||c->inicio->arbol == NULL) {
    return NULL;
  }
  
  return c->inicio->arbol;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c) {
  TNodoCola nodo = c->inicio;
  c->inicio = c->inicio->sig;
  c->cant--;
  //liberarNodoCola(nodo);
  delete nodo;
  nodo = NULL;
}
