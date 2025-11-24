#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Constantes
#define MAX_LONGITUD 100

// Prototipos de funciones
void cargar_palabra(char *palabra);
void a_minusculas(char *palabra);
void contar_frecuencia_letras(const char *palabra);
void verificar_letras_diferentes(const char *palabra);
void verificar_letras_dobles_exactamente_dos(const char *palabra);
void verificar_dos_letras_dobles(const char *palabra);
void verificar_cinco_vocales(const char *palabra);
void verificar_palindromo(const char *palabra);

int main() {
    char palabra[MAX_LONGITUD];

    printf("--- Programa de Analisis de Palabras ---\n");
    cargar_palabra(palabra);

    char palabra_min[MAX_LONGITUD];
    strcpy(palabra_min, palabra);
    a_minusculas(palabra_min);
    
    printf("\nAnalizando la palabra: \"%s\"\n", palabra);
    printf("--------------------------------------\n");

    printf("1. Frecuencia de cada letra:\n");
    contar_frecuencia_letras(palabra_min);
    printf("\n");

    printf("2. Todas las letras son diferentes:\n");
    verificar_letras_diferentes(palabra_min);
    printf("\n");

    printf("3. Todas las letras se repiten dos veces:\n");
    verificar_letras_dobles_exactamente_dos(palabra_min);
    printf("\n");

    printf("4. Tiene dos letras dobles (Ej. 'cc' o 'rr'):\n");
    verificar_dos_letras_dobles(palabra_min);
    printf("\n");

    printf("5. Posee las 5 vocales:\n");
    verificar_cinco_vocales(palabra_min);
    printf("\n");

    printf("6. Es un palíndromo:\n");
    verificar_palindromo(palabra_min);
    printf("\n");

    return 0;
}

/**
 * Pide al usuario que ingrese una palabra.
 * @param palabra Puntero al array de caracteres donde se guardará la palabra.
 */
void cargar_palabra(char *palabra) {
    printf("Por favor, ingresa una palabra (max %d caracteres): ", MAX_LONGITUD - 1);
    // Usar scanf y limitar la lectura para evitar desbordamiento de buffer
    if (scanf("%99s", palabra) != 1) {
        // En caso de error de lectura, asigna una cadena vacía
        palabra[0] = '\0'; 
    }
}

/**
 * Convierte una cadena a minúsculas.
 * @param palabra Puntero a la cadena a modificar.
 */
void a_minusculas(char *palabra) {
    for (int i = 0; palabra[i]; i++) {
        palabra[i] = tolower((unsigned char)palabra[i]);
    }
}

// 1. Contar cuantas veces se repite cada letra
void contar_frecuencia_letras(const char *palabra) {
    int contador[26] = {0}; // Inicializa un array de 26 elementos a 0 para 'a' a 'z'
    int longitud = strlen(palabra);
    int encontradas = 0;

    for (int i = 0; i < longitud; i++) {
        char c = palabra[i];
        if (c >= 'a' && c <= 'z') {
            // El índice es el valor ASCII de la letra menos el valor ASCII de 'a'
            contador[c - 'a']++;
        }
    }
    
    // Imprimir el resultado
    for (int i = 0; i < 26; i++) {
        if (contador[i] > 0) {
            printf("  - La letra '%c' se repite %d vez(es).\n", (char)('a' + i), contador[i]);
            encontradas = 1;
        }
    }
    
    if (!encontradas) {
        printf("  - La palabra no contiene letras del alfabeto.\n");
    }
}

// 2. Dar un mensaje si todas las letras son diferentes
void verificar_letras_diferentes(const char *palabra) {
    int contador[26] = {0};
    int longitud = strlen(palabra);
    bool todas_diferentes = true;

    for (int i = 0; i < longitud; i++) {
        char c = palabra[i];
        if (c >= 'a' && c <= 'z') {
            int indice = c - 'a';
            contador[indice]++;
            if (contador[indice] > 1) {
                todas_diferentes = false;
                break; // Una repetición basta para fallar la condición
            }
        }
    }

    if (longitud == 0) {
        printf("  - La palabra está vacía.\n");
    } else if (todas_diferentes) {
        printf("  -> **MENSAJE: Todas las letras son diferentes.**\n");
    } else {
        printf("  - Hay letras repetidas en la palabra.\n");
    }
}

// 3. Dar un mensaje si todas las letras se repiten dos veces
void verificar_letras_dobles_exactamente_dos(const char *palabra) {
    int contador[26] = {0};
    int longitud = strlen(palabra);
    bool cumple_condicion = true;
    int letras_unicas = 0;

    for (int i = 0; i < longitud; i++) {
        char c = palabra[i];
        if (c >= 'a' && c <= 'z') {
            contador[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (contador[i] > 0) {
            letras_unicas++;
            if (contador[i] != 2) {
                cumple_condicion = false;
                break; // Si alguna letra se repite un número diferente de 2, falla
            }
        }
    }

    // La longitud total debe ser par, y cada letra única debe contarse 2 veces.
    // Además, debe haber al menos una letra.
    if (letras_unicas == 0) {
        printf("  - La palabra no contiene letras del alfabeto.\n");
    } else if (cumple_condicion) {
        printf("  -> **MENSAJE: Todas las letras que aparecen se repiten exactamente dos veces.**\n");
    } else {
        printf("  - La condición no se cumple. (Ejemplo: 'aabbcc' SÍ cumple, 'abc' NO, 'aaabbb' NO).\n");
    }
}

// 4. Dar un mensaje si tiene dos letras dobles (Ej. cc o rr)
void verificar_dos_letras_dobles(const char *palabra) {
    int longitud = strlen(palabra);
    int contador_dobles = 0;
    
    if (longitud < 2) {
        printf("  - La palabra es demasiado corta para tener letras dobles.\n");
        return;
    }
    
    // El bucle va hasta longitud - 1 para que i+1 sea un índice válido
    for (int i = 0; i < longitud - 1; i++) {
        // Verificar si los caracteres adyacentes son iguales y son letras
        if (palabra[i] >= 'a' && palabra[i] <= 'z' && palabra[i] == palabra[i+1]) {
            // Se encontró una letra doble. Saltar al siguiente carácter después de la doble.
            // Esto asegura que 'aaaa' se cuente como UNA sola secuencia doble ('aa'), no tres.
            contador_dobles++;
            // Avanzar el índice i para saltar la segunda letra del par y no recontar
            i++; 
        }
    }

    if (contador_dobles == 2) {
        printf("  -> **MENSAJE: La palabra tiene exactamente dos secuencias de letras dobles (ej. 'lluvia', 'carroza').**\n");
    } else {
        printf("  - La palabra tiene %d secuencias de letras dobles.\n", contador_dobles);
    }
}

// 5. Dar un mensaje si la palabra posee las 5 vocales
void verificar_cinco_vocales(const char *palabra) {
    // Array booleano para rastrear si cada vocal ha sido encontrada (a, e, i, o, u)
    bool vocales_encontradas[5] = {false}; 
    const char *vocales = "aeiou";
    int longitud = strlen(palabra);
    int vocales_unicas = 0;

    for (int i = 0; i < longitud; i++) {
        char c = palabra[i];
        
        // Buscar la vocal en la cadena "aeiou"
        for (int j = 0; j < 5; j++) {
            if (c == vocales[j]) {
                if (!vocales_encontradas[j]) {
                    vocales_encontradas[j] = true;
                    vocales_unicas++;
                }
                break; // Si se encuentra, pasa a la siguiente letra de la palabra
            }
        }
    }

    if (vocales_unicas == 5) {
        printf("  -> **MENSAJE: La palabra posee las 5 vocales (a, e, i, o, u).**\n");
    } else {
        printf("  - La palabra NO posee las 5 vocales. Se encontraron %d de 5.\n", vocales_unicas);
    }
}

// 6. Indicar si la palabra es un palíndromo
void verificar_palindromo(const char *palabra) {
    int longitud = strlen(palabra);
    // Un palíndromo se lee igual de izquierda a derecha y de derecha a izquierda
    // Solo necesitamos verificar hasta la mitad de la palabra
    bool es_palindromo = true;

    for (int i = 0; i < longitud / 2; i++) {
        // Compara el caracter i con el caracter en la posición (longitud - 1 - i)
        if (palabra[i] != palabra[longitud - 1 - i]) {
            es_palindromo = false;
            break;
        }
    }

    if (longitud == 0) {
        printf("  - La palabra está vacía (técnicamente no es un palíndromo significativo).\n");
    } else if (es_palindromo) {
        printf("  -> **RESULTADO: La palabra es un PALÍNDROMO.** (Ej. 'ala', 'reconocer')\n");
    } else {
        printf("  -> **RESULTADO: La palabra NO es un palíndromo.**\n");
    }
}

//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II