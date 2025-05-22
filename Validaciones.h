#include <stdio.h>
#include <string.h>

void calcularTotales(struct Producto productos[], int n) {
    int totalTiempo = 0, totalRecursos = 0;
    for (int i = 0; i < n; i++) {
        totalTiempo += productos[i].cantidad * productos[i].tiempo;
        totalRecursos += productos[i].cantidad * productos[i].recursos;
    }
    printf("Total de tiempo requerido: %d minutos\n", totalTiempo);
    printf("Total de recursos necesarios: %d\n", totalRecursos);
}

void verificarProduccion(struct Producto productos[], int n) {
    int tiempoDisponible, recursosDisponibles;
    printf("Ingrese el tiempo disponible (minutos): ");
    scanf("%d", &tiempoDisponible);
    printf("Ingrese los recursos disponibles: ");
    scanf("%d", &recursosDisponibles);

    int totalTiempo = 0, totalRecursos = 0;
    for (int i = 0; i < n; i++) {
        totalTiempo += productos[i].cantidad * productos[i].tiempo;
        totalRecursos += productos[i].cantidad * productos[i].recursos;
    }

    printf("Tiempo total requerido: %d\n", totalTiempo);
    printf("Recursos totales requeridos: %d\n", totalRecursos);
    printf("Tiempo disponible: %d\n", tiempoDisponible);
    printf("Recursos disponibles: %d\n", recursosDisponibles);

    if (totalTiempo <= tiempoDisponible && totalRecursos <= recursosDisponibles) {
        printf("Produccion posible.\n");
    } else {
        printf("Produccion NO posible.\n");
    }
}
