#include "../include/aplicaciones.h"
#include "../include/personasLDE.h"
#include "../include/persona.h" 

TPilaPersona menoresQueElResto(TPersonasLDE lista) {
    /* TPilaPersona pila = crearTPilaPersona();
    TPersona menorActual = copiarTPersona(obtenerFinalDeTPersonasLDE(lista));
    apilarEnTPilaPersona(pila, menorActual);
    eliminarFinalTPersonasLDE(lista);
    
    while (cantidadTPersonasLDE(lista)>0){
        TPersona persona = copiarTPersona(obtenerFinalDeTPersonasLDE(lista));
        eliminarFinalTPersonasLDE(lista);

        if(edadTPersona(persona) < edadTPersona(menorActual)){
            apilarEnTPilaPersona(pila,persona);
            liberarTPersona(menorActual);
            menorActual = persona;
        }
    } */
    TPilaPersona pila = crearTPilaPersona();
    
    while(cantidadTPersonasLDE(lista)>0){
        TPersona persona = copiarTPersona(obtenerInicioDeTPersonasLDE(lista));
        while(cantidadEnTPilaPersona(pila)>0 && edadTPersona(cimaDeTPilaPersona(pila))>=edadTPersona(persona)){
            desapilarDeTPilaPersona(pila);
        }
        apilarEnTPilaPersona(pila,persona);
        eliminarInicioTPersonasLDE(lista);
        liberarTPersona(persona);
        
    }
    return pila;
}

bool sumaPares(nat k, TConjuntoIds c){
    nat i = 1;
    bool res = false;
    while(i <= k/2 && i <= cantMaxTConjuntoIds(c) && !res){
        if(perteneceTConjuntoIds(i,c) && perteneceTConjuntoIds(k-(i),c) && (i != k-i)){
            res = true;
        }
        i++;
    }
    return res;
}