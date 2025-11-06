#include <stdio.h>
#include <stdlib.h>

// Estructura para el nodo de la cola
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} Nodo;

// Estructura para la cola
typedef struct {
    Nodo* frente;
    Nodo* final;
} Cola;

// Función para crear una cola vacía
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    if (cola != NULL) {
        cola->frente = NULL;
        cola->final = NULL;
    }
    return cola;
}

// Función para verificar si la cola está vacía
int estaVacia(Cola* cola) {
    return (cola->frente == NULL);
}

// Función para agregar un elemento (encolar)
void encolar(Cola* cola, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        
        if (estaVacia(cola)) {
            cola->frente = nuevo;
        } else {
            cola->final->siguiente = nuevo;
        }
        cola->final = nuevo;
    }
}

// Función para eliminar un elemento (desencolar)
int desencolar(Cola* cola) {
    if (estaVacia(cola)) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    
    Nodo* temp = cola->frente;
    int valor = temp->dato;
    cola->frente = cola->frente->siguiente;
    
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    
    free(temp);
    return valor;
}

// Función para obtener el elemento del frente sin eliminarlo
int verFrente(Cola* cola) {
    if (estaVacia(cola)) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    return cola->frente->dato;
}

// Función para liberar la memoria de la cola
void destruirCola(Cola* cola) {
    while (!estaVacia(cola)) {
        desencolar(cola);
    }
    free(cola);
}