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

// Aquí se guarda la información de cada producto
struct Producto {
    char codigo[10];
    char nombre[30];
    int cantidad;
    int tiempo;
    int recursos;
};

// Permite ingresar varios productos
void ingresarProductos(struct Producto productos[], int n) {
    for (int i = 0; i < n; i++) {
        // Se piden los datos del producto
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

// Permite cambiar los datos de un producto ya guardado
void editarProducto(struct Producto productos[], int n) {
    char buscado[10];
    printf("Ingrese el codigo del producto a editar: ");
    scanf(" %9s", buscado);

    for (int i = 0; i < n; i++) {
        if (strcmp(productos[i].codigo, buscado) == 0) {
            // Se actualizan los datos del producto encontrado
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

// "Borra" un producto quitando sus datos
void eliminarProducto(struct Producto productos[], int n) {
    char buscado[10];
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf(" %9s", buscado);

    for (int i = 0; i < n; i++) {
        if (strcmp(productos[i].codigo, buscado) == 0) {
            // Se vacían todos los datos del producto
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

// Muestra todos los productos guardados (que no han sido eliminados)
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

// Suma el tiempo total y los recursos que se necesitan para producir todo
void calcularTotales(struct Producto productos[], int n) {
    int totalTiempo = 0, totalRecursos = 0;
    for (int i = 0; i < n; i++) {
        totalTiempo += productos[i].cantidad * productos[i].tiempo;
        totalRecursos += productos[i].cantidad * productos[i].recursos;
    }
    printf("Total de tiempo requerido: %d minutos\n", totalTiempo);
    printf("Total de recursos necesarios: %d\n", totalRecursos);
}

// Revisa si es posible producir todo con el tiempo y recursos disponibles
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

    // Se compara lo que se necesita con lo que hay disponible
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

int main() {
    struct Producto productos[5] = {0}; // Aquí se guardarán hasta 5 productos
    int opcion;

    // Menú principal del programa
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
            case 1: ingresarProductos(productos, 5);     // Agrega productos
                break;
            case 2: editarProducto(productos, 5);        // Edita un producto
                break;
            case 3: eliminarProducto(productos, 5);      // Elimina un producto
                break;
            case 4: mostrarProductos(productos, 5);      // Muestra los productos
                break;
            case 5: calcularTotales(productos, 5);       // Calcula totales
                break;
            case 6: verificarProduccion(productos, 5);   // Revisa si se puede producir
                break;
            case 0: printf("Saliendo...\n");             // Sale del programa
                break;
            default: printf("Opcion invalida.\n");       // Opción incorrecta
        }
    } while (opcion != 0); // Repite hasta que se elija salir

    return 0;
}
