#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct
{
    int documento;
    char nombre[30];
} registro;

typedef struct nodo
{
    registro dato;
    struct nodo *sig;
} nodo;

void agregar_registro(FILE *f);
void modificar_por_documento(FILE *f);
nodo *cargar_10(FILE *f);
void mostrar_lista(nodo *lista);

int main()
{
    FILE *f;
    int opcion;

    f = fopen("personas.dat", "r+b");
    if (!f)
        f = fopen("personas.dat", "w+b");

    do
    {
        printf("\nMENU\n");
        printf("1. Agregar registro\n");
        printf("2. Buscar por documento y modificar nombre\n");
        printf("3. Cargar primeros 10 registros a lista\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregar_registro(f);
            break;
        case 2:
            modificar_por_documento(f);
            break;
        case 3:
        {
            nodo *lista = cargar_10(f);
            mostrar_lista(lista);
            break;
        }
        }

    } while (opcion != 4);

    fclose(f);
    return 0;
}

void agregar_registro(FILE *f)
{
    registro r;

    printf("\nIngrese numero de documento: ");
    scanf("%d", &r.documento);

    printf("Ingrese nombre: ");
    scanf("%s", r.nombre);

    fseek(f, 0, SEEK_END);
    fwrite(&r, sizeof(registro), 1, f);

    printf("Registro agregado.\n");
}

void modificar_por_documento(FILE *f)
{
    int doc, encontrado = 0;
    registro r;

    printf("\nDocumento a buscar: ");
    scanf("%d", &doc);

    rewind(f);

    while (fread(&r, sizeof(registro), 1, f))
    {
        if (r.documento == doc)
        {
            encontrado = 1;

            printf("Documento encontrado. Nombre actual: %s\n", r.nombre);
            printf("Nuevo nombre: ");
            scanf("%s", r.nombre);

            fseek(f, -sizeof(registro), SEEK_CUR);
            fwrite(&r, sizeof(registro), 1, f);

            printf("Nombre modificado.\n");
            break;
        }
    }

    if (!encontrado)
        printf("No se encontro el documento.\n");
}

nodo *cargar_10(FILE *f)
{
    rewind(f);
    nodo *lista = NULL, *nuevo, *ultimo = NULL;
    registro r;
    int contador = 0;

    while (contador < 10 && fread(&r, sizeof(registro), 1, f))
    {
        nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->dato = r;
        nuevo->sig = NULL;

        if (!lista)
            lista = nuevo;
        else
            ultimo->sig = nuevo;

        ultimo = nuevo;
        contador++;
    }

    return lista;
}

void mostrar_lista(nodo *lista)
{
    printf("\n--- LISTA (primeros 10) ---\n");
    while (lista)
    {
        printf("Doc: %d  Nombre: %s\n",
               lista->dato.documento,
               lista->dato.nombre);
        lista = lista->sig;
    }
}


//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II
