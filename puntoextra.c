#include <stdio.h>
#include <cs50.h>

int es_par(int num) {
    return num % 2 == 0;
}


int es_impar(int num) {
    return num % 2 != 0;
}


void imprimir_pares(int inicio, int fin) {
    int suma = 0;
    printf("Números pares: ");
    for (int i = inicio; i <= fin; i++) {
        if (es_par(i)) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma de los números pares: %d\n", suma);
}

void imprimir_impares(int inicio, int fin) {
    int suma = 0;
    printf("Números impares: ");
    for (int i = inicio; i <= fin; i++) {
        if (es_impar(i)) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma de los números impares: %d\n", suma);
}


void imprimir_pares_impares(int inicio, int fin) {
    int suma_pares = 0, suma_impares = 0;

    printf("Números pares: ");
    for (int i = inicio; i <= fin; i++) {
        if (es_par(i)) {
            printf("%d ", i);
            suma_pares += i;
        }
    }

    printf("\nNúmeros impares: ");
    for (int i = inicio; i <= fin; i++) {
        if (es_impar(i)) {
            printf("%d ", i);
            suma_impares += i;
        }
    }

    printf("\nSuma de los números pares: %d\n", suma_pares);
    printf("Suma de los números impares: %d\n", suma_impares);
}


void manejar_opciones(int inicio, int fin) {
    int opcion;

    printf("\nElija una opción:\n");
    printf("1. Mostrar números pares y calcular su suma\n");
    printf("2. Mostrar números impares y calcular su suma\n");
    printf("3. Mostrar tanto los números pares como los impares y sus respectivas sumas\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            imprimir_pares(inicio, fin);
            break;
        case 2:
            imprimir_impares(inicio, fin);
            break;
        case 3:
            imprimir_pares_impares(inicio, fin);
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }
}

int main() {
    int inicio, fin;
    char continuar;

    do {
       
        do {
            printf("Ingrese el valor inicial: ");
            scanf("%d", &inicio);
            printf("Ingrese el valor final: ");
            scanf("%d", &fin);

            if (inicio > fin) {
                printf("El valor inicial debe ser menor o igual al valor final. Intente de nuevo.\n");
            }
        } while (inicio > fin);


        manejar_opciones(inicio, fin);


        printf("\n¿Desea realizar otra operación? (s/n): ");
        scanf(" %c", &continuar);  // Espacio antes de %c para capturar cualquier salto de línea previo
    } while (continuar == 's' || continuar == 'S');

    printf("¡Gracias por usar el programa!\n");
    return 0;
}
