#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Registro
{
    char nombre[50];
    int edad;
};

#define NOMBRE_ARCHIVO "datos_almacenados.txt"

void mostrar_menu();
void crear_archivo();
void agregar_registro();
void visualizar_registros();

int main()
{
    int opcion;

    do
    {
        mostrar_menu();
        printf("Ingrese su opción: ");

        if (scanf("%d", &opcion) != 1)
        {

            while (getchar() != '\n')
                ;
            opcion = 0;
        }

        switch (opcion)
        {
        case 1:
            crear_archivo();
            break;
        case 2:
            agregar_registro();
            break;
        case 3:
            visualizar_registros();
            break;
        case 4:
            printf("\nSaliendo del programa.\n");
            break;
        default:
            printf("\nOpción no válida.\n");
            break;
        }
        printf("\n----------------------------------------\n");
    } while (opcion != 4);

    return 0;
}

void mostrar_menu()
{
    printf("\n--- MENÚ DE GESTIÓN DE ARCHIVOS ---\n");
    printf("1. Crear/Inicializar Archivo\n");
    printf("2. Agregar Nuevo Registro\n");
    printf("3. Visualizar Registros Almacenados\n");
    printf("4. Salir\n");
}

void crear_archivo()
{
    FILE *archivo;

    archivo = fopen(NOMBRE_ARCHIVO, "w");

    if (archivo == NULL)
    {
        printf("ERROR: No se pudo crear el archivo %s.\n", NOMBRE_ARCHIVO);
    }
    else
    {
        printf("Archivo '%s' inicializado correctamente.\n", NOMBRE_ARCHIVO);
        fclose(archivo);
    }
}

void agregar_registro()
{
    FILE *archivo;
    struct Registro nuevo_registro;

    archivo = fopen(NOMBRE_ARCHIVO, "a");

    if (archivo == NULL)
    {
        printf("ERROR: No se pudo abrir el archivo %s\n", NOMBRE_ARCHIVO);
        return;
    }

    printf("\nAGREGAR NUEVO REGISTRO\n");

    printf("Ingrese Nombre: ");

    while (getchar() != '\n')
        ;
    fgets(nuevo_registro.nombre, sizeof(nuevo_registro.nombre), stdin);

    nuevo_registro.nombre[strcspn(nuevo_registro.nombre, "\n")] = 0;

    printf("Ingrese Edad: ");
    while (scanf("%d", &nuevo_registro.edad) != 1)
    {
        printf("Entrada inválida. Ingrese un número para la edad: ");
        while (getchar() != '\n')
            ;
    }

    fprintf(archivo, "%s,%d\n", nuevo_registro.nombre, nuevo_registro.edad);

    fclose(archivo);
    printf("Registro de '%s' (Edad: %d) agregado\n", nuevo_registro.nombre, nuevo_registro.edad);
}

void visualizar_registros()
{
    FILE *archivo;
    struct Registro registro_leido;
    int cuenta_registros = 0;

    archivo = fopen(NOMBRE_ARCHIVO, "r");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo %s.\n", NOMBRE_ARCHIVO);
        return;
    }

    printf("\n--- REGISTROS ALMACENADOS ---\n");
    printf("| %-20s | %-5s |\n", "NOMBRE", "EDAD");

    while (fscanf(archivo, "%49[^,],%d\n", registro_leido.nombre, &registro_leido.edad) == 2)
    {

        printf("| %-20s | %-5d |\n", registro_leido.nombre, registro_leido.edad);
        cuenta_registros++;
    }

    fclose(archivo);

    if (cuenta_registros == 0)
    {
        printf("\n(No hay registros almacenados en el archivo.)\n");
    }
    else
    {
        printf("\nTotal de registros visualizados: %d.\n", cuenta_registros);
    }
}

//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II