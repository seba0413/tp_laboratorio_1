#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int a = 0;
    int b = 0;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    long factorial;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (%d)\n", a);
        printf("2- Ingresar 2do operando (%d)\n", b);
        printf("3- Calcular la suma (%d+%d)\n",a,b);
        printf("4- Calcular la resta (%d-%d)\n",a,b);
        printf("5- Calcular la division (%d/%d)\n",a,b);
        printf("6- Calcular la multiplicacion (%d*%d)\n",a,b);
        printf("7- Calcular el factorial (%d!)\n",a);
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                cargarA(&a);
                break;
            case 2:
                cargarB(&b);
                break;
            case 3:
                calcularSuma(&suma, a, b);
                printf("La suma es: %d\n", suma);
                break;
            case 4:
                calcularResta(&resta, a, b);
                printf("La resta es: %d\n", resta);
                break;
            case 5:
                if (calcularDivision(&division, a, b) == 0)
                    printf("La division es: %.2f\n", division);
                else
                    printf("El divisor no puede ser cero\n");
                break;
            case 6:
                calcularMultiplicacion(&multiplicacion, a, b);
                printf("La multiplicacion es: %d\n", multiplicacion);
                break;
            case 7:
                if (calcularFactorial(&factorial,a) == 0)
                    printf("El factorial es: %ld\n", factorial);
                else
                    printf("El factorial no puede ser menor o igual a cero\n");
                break;
            case 8:
                calcularSuma(&suma, a, b);
                printf("La suma es: %d\n", suma);
                calcularResta(&resta, a, b);
                printf("La resta es: %d\n", resta);
                if (calcularDivision(&division, a, b) == 0)
                    printf("La division es: %.2f\n", division);
                else
                    printf("El divisor no puede ser cero\n");
                calcularMultiplicacion(&multiplicacion, a, b);
                printf("La multiplicacion es: %d\n", multiplicacion);
                if (calcularFactorial(&factorial,a) == 0)
                    printf("El factorial es: %ld\n", factorial);
                else
                    printf("El factorial no puede ser menor o igual a cero\n");
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;

}
