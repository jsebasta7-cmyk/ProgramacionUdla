#include <stdio.h>
#include <string.h>

int main() {
    int id = 0, stock = 0, vendidos = 0, cantidad = 0;
    char nombre[50];
    float precioPublico = 0.0, precioVendedor = 0.0, ganancias = 0.0;
    int productoRegistrado = 0;
    int opcion = 0;

    while (opcion != 6) {
        printf("--- MENU PRINCIPAL ---\n");
        printf("1. Registrar Nuevo Producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Consultar inventario\n");
        printf("5. Ver ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese ID del producto: ");
                scanf("%d", &id);
                getchar();

                printf("Ingrese nombre del producto: ");
                scanf("%s", nombre);


                printf("Ingrese cantidad en inventario: ");
                scanf("%d", &stock);

                printf("Ingrese precio al público: ");
                scanf("%f", &precioPublico);

                printf("Ingrese precio al vendedor: ");
                scanf("%f", &precioVendedor);

                vendidos = 0;
                ganancias = 0.0;
                productoRegistrado = 1;

                printf("Producto registrado correctamente\n");
                break;

            case 2:
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto\n");
                    break;
                }

                printf("Ingrese cantidad a vender: ");
                scanf("%d", &cantidad);

                if (cantidad <= stock) {
                    stock -= cantidad;
                    vendidos += cantidad;
                    ganancias += cantidad * (precioPublico - precioVendedor);
                    printf("Venta realizada con exito\n");
                } else {
                    printf("Stock insuficiente Disponible: %d unidades\n", stock);
                }
                break;

            case 3:
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto\n");
                    break;
                }

                printf("Ingrese cantidad a reabastecer: ");
                scanf("%d", &cantidad);
                stock += cantidad;
                printf("Stock actualizado. Nuevo stock: %d unidades.\n", stock);
                break;

            case 4:
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto\n");
                    break;
                }

                printf("--- INFORMACION DEL PRODUCTO ---\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock actual: %d\n", stock);
                printf("Precio al publico: $%.2f\n", precioPublico);
                printf("Precio al vendedor: $%.2f\n", precioVendedor);
                printf("Unidades vendidas: %d\n", vendidos);
                break;

            case 5:
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto\n");
                    break;
                }

                printf("Ganancias obtenidas: $%.2f\n", ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion inválida Intente nuevamente\n");
        }
    }

    return 0;
}
