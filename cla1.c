#include <stdio.h>

struct Hora {
    int horas;
    int minutos;
    int segundos;
};

void asignarHora(struct Hora *h, int hh, int mm, int ss) {
    h->horas = hh;
    h->minutos = mm;
    h->segundos = ss;
}

void mostrarHora(struct Hora h) {
    printf("%02d:%02d:%02d\n", h.horas, h.minutos, h.segundos);
}

struct Hora constructorDefecto() {
    struct Hora h;
    h.horas = 0;
    h.minutos = 0;
    h.segundos = 0;
    return h;
}

struct Hora constructorParametros(int hh, int mm, int ss) {
    struct Hora h;
    h.horas = hh;
    h.minutos = mm;
    h.segundos = ss;
    return h;
}

int main() {
    struct Hora h1 = constructorDefecto();
    struct Hora h2 = constructorParametros(12, 45, 30);

    mostrarHora(h1);
    mostrarHora(h2);

    asignarHora(&h1, 8, 5, 9);
    mostrarHora(h1);

    return 0;
}


//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II
