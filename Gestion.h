#include <stdio.h>
#include <string.h>

struct Producto {
    char codigo[10];
    char nombre[30];
    int cantidad;
    int tiempo;
    int recursos;
};

void ingresarProductos(struct Producto productos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nProducto #%d\n", i + 1);
        printf("Codigo: ");
        scanf(" %9s", productos[i].codigo);
        printf("Nombre: ");
        scanf(" %29s", productos[i].nombre);
        printf("Cantidad a producir: ");
        scanf("%d", &productos[i].cantidad);
        printf("Tiempo requerido por unidad (minutos): ");
        scanf("%d", &productos[i].tiempo);
        printf("Recursos necesarios por unidad: ");
        scanf("%d", &productos[i].recursos);
    }
}

void editarProducto(struct Producto productos[], int n) {
    char buscado[10];
    printf("Ingrese el codigo del producto a editar: ");
    scanf(" %9s", buscado);

    for (int i = 0; i < n; i++) {
        if (strcmp(productos[i].codigo, buscado) == 0) {
            printf("Nuevo nombre: ");
            scanf(" %29s", productos[i].nombre);
            printf("Nueva cantidad: ");
            scanf("%d", &productos[i].cantidad);
            printf("Nuevo tiempo por unidad: ");
            scanf("%d", &productos[i].tiempo);
            printf("Nuevos recursos por unidad: ");
            scanf("%d", &productos[i].recursos);
            printf("Producto actualizado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(struct Producto productos[], int n) {
    char buscado[10];
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf(" %9s", buscado);

    for (int i = 0; i < n; i++) {
        if (strcmp(productos[i].codigo, buscado) == 0) {
            productos[i].codigo[0] = '\0';
            productos[i].nombre[0] = '\0';
            productos[i].cantidad = 0;
            productos[i].tiempo = 0;
            productos[i].recursos = 0;
            printf("Producto eliminado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void mostrarProductos(struct Producto productos[], int n) {
    printf("\nProductos registrados:\n");
    for (int i = 0; i < n; i++) {
        if (productos[i].codigo[0] != '\0') {
            printf("Codigo: %s\n", productos[i].codigo);
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Cantidad: %d\n", productos[i].cantidad);
            printf("Tiempo por unidad: %d\n", productos[i].tiempo);
            printf("Recursos por unidad: %d\n\n", productos[i].recursos);
        }
    }
}
