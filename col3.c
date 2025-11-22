#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para el nodo de la cola
typedef struct Nodo {
    char nombre[50];
    int edad;
    struct Nodo* siguiente;
} Nodo;

// Estructura para la cola
typedef struct {
    Nodo* frente;
    Nodo* final;
} Cola;

// Función para crear una cola vacía
void inicializarCola(Cola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

// Función para verificar si la cola está vacía
int estaVacia(Cola* cola) {
    return (cola->frente == NULL);
}

// Función para agregar un elemento (encolar)
void encolar(Cola* cola, char nombre[], int edad) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->edad = edad;
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->siguiente = NULL;
    
    if (estaVacia(cola)) {
        cola->frente = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
    }
    cola->final = nuevoNodo;
}

// Función para eliminar un elemento (desencolar)
int desencolar(Cola* cola) {
    if (estaVacia(cola)) {
        printf("Error: La cola está vacía\n");
        return -1;
    }
    
    Nodo* temp = cola->frente;
    cola->frente = cola->frente->siguiente;

    printf("[%s, %d]\n\n", temp->nombre, temp->edad);
    
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    
    free(temp);
    return 0;
}

int tamanoCola(Cola* cola) {
    int tamaño = 0;
    Nodo* actual = cola->frente;
    while (actual != NULL) {
        tamaño++;
        actual = actual->siguiente;
    }
    return tamaño;
}

void mostrarCola(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía\n");
        return;
    }
    
    Nodo* actual = cola->frente;
    printf("Cola: ");
    while (actual != NULL) {
        printf("[%s, %d] -> ", actual->nombre, actual->edad);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int verFrente(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía\n");
        return -1;
    }

    return cola->frente->edad;
}

int main(){

    Cola cola1;
    Cola cola2;
    inicializarCola(&cola1);
    inicializarCola(&cola2);

    encolar(&cola1, "Alice", 30);
    encolar(&cola1, "Bob", 25);
    encolar(&cola1, "Fiona", 30);
    encolar(&cola1, "Victor", 25);
    encolar(&cola2, "Charlie", 35); 
    encolar(&cola2, "Diana", 28);
    encolar(&cola2, "Eve", 22);
    encolar(&cola2, "Frank", 40);

    mostrarCola(&cola1);
    mostrarCola(&cola2);

    printf("\n\n");

    int esperando = (tamanoCola(&cola1) + tamanoCola(&cola2));
    while (esperando > 0) {

        int edadFila1 = estaVacia(&cola1) ? -1 : verFrente(&cola1);
        int edadFila2 = estaVacia(&cola2) ? -1 : verFrente(&cola2);

        if(edadFila1 >= edadFila2){
            printf("Atendiendo de la cola 1: ");
            desencolar(&cola1);
        } else {
            printf("Atendiendo de la cola 2: ");
            desencolar(&cola2);
        }

        esperando--;

    }

    return 0;
}