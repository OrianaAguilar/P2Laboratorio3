#include "../include/personasABB.h"
#include "../include/colaPersonasABB.h"
#include "../include/pilaPersona.h"
#include<math.h>

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_personasAbb {
    TPersona persona;
    TPersonasABB izq, der;
};

TPersonasABB crearTPersonasABB() {
    return NULL;
}

bool esVacioTPersonasABB(TPersonasABB personasABB) {
    return personasABB == NULL;
}

void insertarTPersonasABB(TPersonasABB &personasABB, TPersona p) {
    if (personasABB == NULL){
        personasABB = new rep_personasAbb;
        personasABB->persona = p;
        personasABB->izq = NULL;
        personasABB->der = NULL;
    } else{
        if(idTPersona(personasABB->persona) < idTPersona(p)){
            insertarTPersonasABB(personasABB->der, p);

        }else if(idTPersona(personasABB->persona) > idTPersona(p)){
            insertarTPersonasABB(personasABB->izq, p);
        }
    }
}

void liberarNodoABB(TPersonasABB &nodo){
    if (nodo != NULL){
        liberarTPersona(nodo->persona);
        delete nodo;
        nodo = NULL;
    }
}

void liberarTPersonasABB(TPersonasABB &personasABB){
    if (personasABB != NULL){ //Recorrido PostOrder
        liberarTPersonasABB(personasABB->izq);
        liberarTPersonasABB(personasABB->der);
        liberarNodoABB(personasABB);
        personasABB = NULL;
    }
}

void imprimirTPersonasABB(TPersonasABB personasABB) {
   if (personasABB != NULL){ //Recorrido InOrder
        imprimirTPersonasABB(personasABB->izq);
        imprimirTPersona(personasABB->persona);
        imprimirTPersonasABB(personasABB->der);
   }
}

nat cantidadTPersonasABB(TPersonasABB personasABB) {
    nat cant = 0;
    if (personasABB != NULL){
        cant = 1 + cantidadTPersonasABB(personasABB->izq) + cantidadTPersonasABB(personasABB->der);
    }
    return cant;
}

TPersona maxIdPersona(TPersonasABB personasABB) {
     if (personasABB->der == NULL){
        return personasABB->persona;
    }else{
       return maxIdPersona(personasABB->der);
    } 
}

void removerTPersonasABB(TPersonasABB &personasABB, nat id){   
    if(personasABB == NULL){
        return;
    }
 
    //Buscamos si el valor esta en el subarbol izquiero o derecho
    if(idTPersona(personasABB->persona) > id){
        removerTPersonasABB(personasABB->izq, id);

    }else if(idTPersona(personasABB->persona) < id){
        removerTPersonasABB(personasABB->der, id);

    }else{  // Encontramos el nodo a eliminar
        //Caso1: No tiene hijos
        if(personasABB->izq == NULL && personasABB->der == NULL){
            liberarNodoABB(personasABB);
            
        }
        //Caso2: Nodo con un hijo
        else if(personasABB->izq == NULL && personasABB->der != NULL){
            TPersonasABB aux = personasABB;
            personasABB = personasABB->der;
            liberarNodoABB(aux); 


        }else if(personasABB->der == NULL && personasABB->izq != NULL){
            TPersonasABB aux = personasABB;
            personasABB = personasABB->izq;
            liberarNodoABB(aux); 

        }

        //Caso3: Nodo con dos hijos
        else{
            TPersona aux = personasABB->persona;
            TPersona maxIzq = maxIdPersona(personasABB->izq);

            TPersona maxAux = copiarTPersona(maxIzq);
            
            liberarTPersona(aux);
            
            personasABB->persona = maxAux;
            removerTPersonasABB(personasABB->izq, idTPersona(maxIzq));

        }
    }
}

bool estaTPersonasABB(TPersonasABB personasABB, nat id){
    if(personasABB == NULL){
        return false;

    }else if (id < idTPersona(personasABB->persona)){
        return estaTPersonasABB(personasABB->izq, id);

    }else if (id > idTPersona(personasABB->persona)){
        return estaTPersonasABB(personasABB->der, id);

    }else{
         return true;
    }
}
 
TPersona obtenerDeTPersonasABB(TPersonasABB personasABB, nat id){ 
    if (personasABB == NULL){
        return NULL;

    }else if (id < idTPersona(personasABB->persona)){
        return obtenerDeTPersonasABB(personasABB->izq, id);

    }else if (id > idTPersona(personasABB->persona)){
        return obtenerDeTPersonasABB(personasABB->der, id);

    }else{
        return personasABB->persona;
    }
}

nat alturaTPersonasABB(TPersonasABB personasABB) {
    if (personasABB == NULL){
        return 0;
    }
    nat altI = 0, altD = 0;
    if(personasABB->izq != NULL){
        altI = alturaTPersonasABB(personasABB->izq);
    }
    if(personasABB->der != NULL){
        altD = alturaTPersonasABB(personasABB->der);
    }

    if(altD > altI){
        return altD + 1;
    } else{
        return altI + 1;
    }
}

bool esPerfectoTPersonasABB(TPersonasABB personasABB) {
    nat alt = alturaTPersonasABB(personasABB);
    nat nodos = cantidadTPersonasABB(personasABB);
    return (nodos == pow(2,alt)-1);
}

 void removerMaxABB (TPersonasABB &personasABB){ 
    if(personasABB->der==NULL){
        TPersonasABB aborrar = personasABB;
         personasABB = personasABB->izq;
        liberarNodoABB(aborrar);
    }
    else
        removerMaxABB(personasABB->der);
} 


 TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad) {
    TPersonasABB res, fi, fd;
    TPersona iraiz; 
    if(personasABB == NULL){
        return NULL;
    }
    else{
        fi = mayoresTPersonasABB(personasABB->izq, edad);
        fd = mayoresTPersonasABB(personasABB->der, edad);
        iraiz = personasABB->persona;

        if(edadTPersona(personasABB->persona) > edad){ 
            res = new rep_personasAbb;
            res->persona = copiarTPersona(iraiz);
            res->izq = fi;
            res->der = fd;
        }
        else{
            if(fi == NULL){
                res = fd;
            } 
            else if (fd == NULL){
                res = fi;
            }
            else{
                TPersona imayor = maxIdPersona(fi);
                removerMaxABB(fi);
                res = new rep_personasAbb;
                res->persona = copiarTPersona(imayor);
                res->izq = fi;
                res->der = fd;
            }
        }
    }
    return res; 

}

void aTPersonasLDEaux (TPersonasABB personasABB, TPersonasLDE &personasLDE){
   if(personasABB != NULL){
    aTPersonasLDEaux(personasABB->der, personasLDE);
    TPersona persona = copiarTPersona(personasABB->persona);
    insertarTPersonasLDE(personasLDE, persona, 1);
    aTPersonasLDEaux(personasABB->izq, personasLDE);
   }

}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB) {
    TPersonasLDE personasLDE = crearTPersonasLDE();
    aTPersonasLDEaux(personasABB, personasLDE);

    return personasLDE;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

nat amplitudTPersonasABB(TPersonasABB personasABB) {
    if (personasABB == NULL){
        return 0;
    }
    //int nivel = 1; 
    nat amplitud = 1;
    TColaPersonasABB cola = crearTColaPersonasABB();
    encolarEnTColaPersonasABB(personasABB, cola);
    encolarEnTColaPersonasABB(NULL, cola);

    while(cantidadEnTColaPersonasABB(cola)>0){
        personasABB = frenteDeTColaPersonasABB(cola);
        desencolarDeTColaPersonasABB(cola);

        if(personasABB == NULL && cantidadEnTColaPersonasABB(cola)>0){
            //nivel++;
            if(cantidadEnTColaPersonasABB(cola) > amplitud){
                amplitud = cantidadEnTColaPersonasABB(cola);
            }
            encolarEnTColaPersonasABB(NULL,cola); 
        } 
        else{        
           if(personasABB != NULL){ // LINEA IMPORTANTE FIJATE PORQUE
                if(personasABB->izq != NULL){
                    encolarEnTColaPersonasABB(personasABB->izq, cola);
                }   
                if(personasABB->der != NULL){
                    encolarEnTColaPersonasABB(personasABB->der, cola);
                }
           }
        }

    }
    liberarTColaPersonasABB(cola);
    return amplitud;
}

TPilaPersona serializarTPersonasABB(TPersonasABB personasABB){
    if(personasABB == NULL){
        return NULL;
    }
    TColaPersonasABB cola = crearTColaPersonasABB();
    encolarEnTColaPersonasABB(personasABB, cola);
    TPilaPersona pilaPersonas = crearTPilaPersona();
    TPilaPersona aux = crearTPilaPersona();

    while (cantidadEnTColaPersonasABB(cola) > 0){
        personasABB = frenteDeTColaPersonasABB(cola);
        desencolarDeTColaPersonasABB(cola);
        apilarEnTPilaPersona(aux, personasABB->persona);

        if(personasABB->izq != NULL){
            encolarEnTColaPersonasABB(personasABB->izq, cola);
        }   
        if(personasABB->der != NULL){
            encolarEnTColaPersonasABB(personasABB->der, cola);
        }
     }
    liberarTColaPersonasABB(cola);
    while(cantidadEnTPilaPersona(aux)>0){
        apilarEnTPilaPersona(pilaPersonas, cimaDeTPilaPersona(aux));
        desapilarDeTPilaPersona(aux);
    }
    liberarTPilaPersona(aux);
    return pilaPersonas;
}

TPersonasABB crearTNodoPersonasABB(TPersona persona) {
    TPersonasABB nodo = new rep_personasAbb;
    nodo->persona = persona;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

TPersonasABB deserializarTPersonasABB(TPilaPersona &pilaPersonas) {
   /*  if(pilaPersonas == NULL){
        return NULL;
    }
    TPersonasABB personasABB = crearTPersonasABB();
    
    while (cantidadEnTPilaPersona(pilaPersonas) > 0){
        TPersona persona = copiarTPersona(cimaDeTPilaPersona(pilaPersonas));
        desapilarDeTPilaPersona(pilaPersonas);
        insertarTPersonasABB(personasABB, persona);
    }

    liberarTPilaPersona(pilaPersonas);
    return personasABB;  */

    /*if(pilaPersonas == NULL){
        return NULL;
    }
    TPersonasABB personasABB = crearTPersonasABB();
    
    nat tamStack = cantidadEnTPilaPersona(pilaPersonas);
    for(nat i = 0; i < tamStack; i++){
        TPersona persona = copiarTPersona(cimaDeTPilaPersona(pilaPersonas));
        desapilarDeTPilaPersona(pilaPersonas);
        insertarTPersonasABB(personasABB, persona);
    }
    liberarTPilaPersona(pilaPersonas);
    return personasABB;*/

    if(pilaPersonas == NULL){
        return NULL;
    }
    TColaPersonasABB cola = crearTColaPersonasABB();
    TPersonasABB personasABB = crearTNodoPersonasABB(copiarTPersona(cimaDeTPilaPersona(pilaPersonas)));

    

    desapilarDeTPilaPersona(pilaPersonas);
    encolarEnTColaPersonasABB(personasABB, cola);

    while((cantidadEnTPilaPersona(pilaPersonas) > 0) && (cantidadEnTColaPersonasABB(cola)>0)){
        TPersonasABB nodoActual = frenteDeTColaPersonasABB(cola);
        desencolarDeTColaPersonasABB(cola);
        
        TPersona pizq = NULL;
        TPersona pder = NULL;

        if(cantidadEnTPilaPersona(pilaPersonas)>0){
           pizq = copiarTPersona(cimaDeTPilaPersona(pilaPersonas));
           desapilarDeTPilaPersona(pilaPersonas);
        }
        if(cantidadEnTPilaPersona(pilaPersonas)>0){
           pder = copiarTPersona(cimaDeTPilaPersona(pilaPersonas));
           desapilarDeTPilaPersona(pilaPersonas);
        }

        if (pizq != NULL) {
            TPersonasABB nodoIzq = crearTNodoPersonasABB(pizq);

            nodoActual->izq = nodoIzq;
            encolarEnTColaPersonasABB(nodoIzq, cola);
        }
        if (pder != NULL) {
            TPersonasABB nodoDer = crearTNodoPersonasABB(pder);

            nodoActual->der = nodoDer;
            encolarEnTColaPersonasABB(nodoDer, cola);
        }
    }
    liberarTColaPersonasABB(cola);
    liberarTPilaPersona(pilaPersonas);
    return personasABB;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

