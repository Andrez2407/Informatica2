#include <stdio.h>
#include <stdlib.h>
#define max 10
#define n 10

typedef struct {
    int items[max];
    int top;
} Stack;

void IniciarStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == max - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int obtenerTamanoActual(Stack *s) {
    return s->top + 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Error: Stack is full\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack esta vacio\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void mostrarLista(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack vacio\n");
        return;
    }
    printf("->: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d  ", s->items[i]);
    }
    printf("\n");
}

int main() {
    system("clear");
    printf("\nIngrese los valores para un stack de 10 elementos:\n\n");
    Stack stack;
    IniciarStack(&stack);

    for (int i = 0; i < n; i++)
    {
        printf("Escribe el valor para la posicion %d: ", i);
        int valor;
        scanf("%d", &valor);
        push(&stack, valor);
    }

    system("clear");
    printf("\nSumatoria y eliminación de elementos del stack:\n");


    while (obtenerTamanoActual(&stack) > 1)
    {
        int x1 = pop(&stack);
        int x2 = pop(&stack);
        int suma = x1 + x2;
        push(&stack, suma);

        mostrarLista(&stack);

    }

    

    return 0;
}


//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II