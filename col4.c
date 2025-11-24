#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Estructura de la pila
typedef struct {
    Nodo* tope;
    int tamano;
} Pila;

// Crear una pila vacía
Pila* crearPila() {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->tope = NULL;
    pila->tamano = 0;
    return pila;
}

// Verificar si la pila está vacía
int estaVacia(Pila* pila) {
    return pila->tope == NULL;
}

// Apilar un elemento (push)
void apilar(Pila* pila, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = pila->tope;
    pila->tope = nuevoNodo;
    pila->tamano++;
}

// Desapilar un elemento (pop)
int desapilar(Pila* pila) {
    if (estaVacia(pila)) {
        printf("Error: La pila está vacía\n");
        return -1;
    }
    
    Nodo* temp = pila->tope;
    int dato = temp->dato;
    pila->tope = temp->siguiente;
    free(temp);
    pila->tamano--;
    return dato;
}

// Ver el elemento en el tope sin desapilarlo
int verTope(Pila* pila) {
    if (estaVacia(pila)) {
        printf("Error: La pila está vacía\n");
        return -1;
    }
    return pila->tope->dato;
}

// Obtener el tamaño de la pila
int obtenerTamano(Pila* pila) {
    return pila->tamano;
}

// Liberar la memoria de la pila
void destruirPila(Pila* pila) {
    while (!estaVacia(pila)) {
        desapilar(pila);
    }
    free(pila);
}


//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II