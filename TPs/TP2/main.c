#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define LIMITE_PERSONAS 20


int main()
{
    Persona personas[20];
    persona_init(personas, LIMITE_PERSONAS);

    persona_altaForzada(personas, LIMITE_PERSONAS, "Diego",33333333,28);
    persona_altaForzada(personas, LIMITE_PERSONAS, "Sebastian",32911995,31);
    persona_altaForzada(personas, LIMITE_PERSONAS, "Derwin",31111111,30);
    persona_altaForzada(personas, LIMITE_PERSONAS, "Luz",40000000,17);
    persona_altaForzada(personas, LIMITE_PERSONAS, "Agustina",41111111,40);

    char seguir='s';
    int opcion=0;
    int auxDni;

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(personas, LIMITE_PERSONAS);
                break;
            case 2:
                getValidInt("\nDni?\n", "\nDni invalido\n", &auxDni, 1000000, 99999999,2);
                persona_baja(personas, LIMITE_PERSONAS, auxDni);
                break;
            case 3:
                persona_listarOrdenadoPorNombre(personas, LIMITE_PERSONAS, 1);
                break;
            case 4:
                persona_graficarEdades(personas, LIMITE_PERSONAS);
                break;
            case 5:
                seguir = 'n';
                break;
            case 6:
                persona_mostrarDebug(personas, LIMITE_PERSONAS);
        }
    }

    return 0;
}
