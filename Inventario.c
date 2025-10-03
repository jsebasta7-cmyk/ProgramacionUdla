#include <stdio.h>
#include <string.h>

int main() {
    // Declaracion de Variables 
    int id_del_producto = 0;                  
    int stock_del_producto = 0;               
    int articulos_vendidos = 0, cantidad = 0; 
    char nombre[50];                          
    float precio_al_Publico = 0.0, precio_al_Vendedor = 0.0, ganancias_totales = 0.0;
                                              // Precios y ganancias acumuladas
    int productoRegistrado = 0;               // Bandera para saber si hay producto registrado
    int opcion = 0;                           

    // Condicion para que el usuario pueda salir del programa
    while (opcion != 6) {
        // Menu principal
        printf("Vista general de la opciones del programa:\n");
        printf("Ingrese el numero de la opcion que desea realizar(del 1 al 6):\n");
        printf("1 para registrar Nuevo Producto\n");
        printf("2 para vender producto\n");
        printf("3 para reabastecer producto\n");
        printf("4 para consultar inventario\n");
        printf("5 para ver las ganancias\n");
        printf("6 si desea Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        // Uso dedl switch para los datos que se requiran del producto
        switch (opcion) {
            case 1:
                // Registro de un nuevo producto
                printf("Ingrese ID del producto: ");
                scanf("%d", &id_del_producto);
                getchar(); // Limpia el buffer para evitar problemas con el nombre

                printf("Ingrese nombre del producto: ");
                scanf("%s", nombre);

                printf("Ingrese cantidad en inventario: ");
                scanf("%d", &stock_del_producto);

                printf("Ingrese precio al publico: ");
                scanf("%f", &precio_al_Publico);

                printf("Ingrese precio al vendedor: ");
                scanf("%f", &precio_al_Vendedor);

                // Inicializamos valores asociados al nuevo producto
                articulos_vendidos = 0;
                ganancias_totales = 0.0;
                productoRegistrado = 1; // Marca que hay un producto registrado

                printf("Producto registrado correctamente\n");
                break;
            case 2:
                // Validacion de que exista un producto antes de vender
                if (!productoRegistrado) {
                    printf("Error, primero debe registrar un producto\n");
                    break;
                }

                // Proceso de venta
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);

                if (cantidad <= stock_del_producto) {
                    // Se descuenta del stock y se calcula la ganancia
                    stock_del_producto -= cantidad;
                    articulos_vendidos += cantidad;
                    ganancias_totales += cantidad * (precio_al_Publico - precio_al_Vendedor);
                    printf("La Venta se ha realizado con exito\n");
                } else {
                    // Si no hay stock suficiente
                    printf("Stock insuficiente Disponible: %d unidades\n", stock_del_producto);
                }
                break;

            case 3:
                // Valida que exista un producto antes de reabastecer
                if (!productoRegistrado) {
                    printf("Error primero debe registrar un producto\n");
                    break;
                }

                // Reabastecer inventario
                printf("Ingrese cantidad a reabastecer: ");
                scanf("%d", &cantidad);
                stock_del_producto += cantidad;
                printf("Stock actualizado. Nuevo stock: %d unidades.\n", stock_del_producto);
                break;

            case 4:
                // Consultar informacion del producto
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto\n");
                    break;
                }

                printf("--- INFORMACION DEL PRODUCTO ---\n"); //Pone toda la informacion del producto que se ha ingresado
                printf("ID: %d\n", id_del_producto);
                printf("Nombre: %s\n", nombre);
                printf("Stock actual: %d\n", stock_del_producto);
                printf("Precio al publico: $%.2f\n", precio_al_Publico);
                printf("Precio al vendedor: $%.2f\n", precio_al_Vendedor);
                printf("Total unidades vendidas: %d\n", articulos_vendidos);
                break;

            case 5:
                // Muestra las  ganancias generadas
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto\n");
                    break;
                }

                printf("Ganancias obtenidas: $%.2f\n", ganancias_totales);
                break;

            case 6:
                // Salida del programa
                printf("Saliendo del programa...\n");
                break;

            default:
                // Validacion para que no se ingresen valores incorrectos
                printf("Error la opcion es invalida Intente nuevamente\n");
        }
    }

    return 0;
}
