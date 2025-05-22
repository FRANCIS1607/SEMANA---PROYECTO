/*
Caso: Optimización de Producción en una Fábrica de Componentes Electrónicos

Descripción del Problema:
Una fábrica de componentes electrónicos necesita optimizar su producción para cumplir con
la demanda de cinco productos distintos. Cada producto tiene un tiempo de fabricación
específico y requiere una cantidad fija de recursos. El equipo de ingeniería ha identificado
que la línea de producción tiene limitaciones de tiempo y recursos que deben ser tomadas en cuenta

*/
#include <stdio.h>
#include <string.h>
#include "Gestion.h"
#include "Validaciones.h"

int main() {
    struct Producto productos[5] = {0};
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ingresar productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar el producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Calcular totales\n");
        printf("6. Verificar la produccion\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: ingresarProductos(productos, 5); 
                break;
            case 2: editarProducto(productos, 5); 
                break;
            case 3: eliminarProducto(productos, 5); 
                break;
            case 4: mostrarProductos(productos, 5); 
                break;
            case 5: calcularTotales(productos, 5); 
                break;
            case 6: verificarProduccion(productos, 5); 
                break;
            case 0: printf("Saliendo...\n"); 
                break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}