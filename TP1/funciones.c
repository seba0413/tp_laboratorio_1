#include <stdio.h>
#include <stdlib.h>

/**

*\brief Se le socilita al usuario que cargue un numero
*\param int* numero Puntero al numero a
*\return void

*/

void cargarA(int* numero)
{
    int primerNumero;
    printf("Ingrese el numero A: ");
    scanf("%d", &primerNumero);
    *numero = primerNumero;

}

/**

*\brief Se le socilita al usuario que cargue un numero
*\param int* numero Puntero al numero b
*\return void

*/

void cargarB(int* numero)
{
    int segundoNumero;
    printf("Ingrese el numero B: ");
    scanf("%d", &segundoNumero);
    *numero = segundoNumero;
}

/**

*\brief Calcula la suma de dos numeros
*\param int* resultado Puntero al resultado de la suma
*\param int numero1 Uno de los numeros a sumar
*\param int numero2 El otro numero a sumar
*\return void

*/

void calcularSuma(int* resultado, int numero1, int numero2)
{
    *resultado = numero1 + numero2;
}

/**

*\brief Calcula la resta de dos numeros
*\param int* resultado Puntero al resultado de la resta
*\param int numero1 Uno de los numeros a restar
*\param int numero2 El otro numero a restar
*\return void

*/

void calcularResta(int* resultado, int numero1, int numero2)
{
    *resultado = numero1 - numero2;
}

/**

*\brief Calcula la division de dos numeros
*\param float* resultado Puntero al resultado de la division
*\param int numero1 Uno de los numeros a dividir
*\param int numero2 El otro numero a dividir
*\return int [-1] Error [0] Ok

*/

int calcularDivision(float* resultado, int numero1, int numero2)
{
    int retorno;
    if(numero2 ==0)
    {
        retorno = -1;
    }
    else
    {
        *resultado = (float) numero1 / numero2;
        retorno= 0;
    }
    return retorno;
}

/**

*\brief Calcula la multiplicacion de dos numeros
*\param int* resultado Puntero al resultado de la multiplicacion
*\param int numero1 Uno de los numeros a multiplicar
*\param int numero2 El otro numero a multiplicar
*\return void

*/

void calcularMultiplicacion(int* resultado, int numero1, int numero2)
{
    *resultado = numero1 * numero2;
}

/**

*\brief Calcula el factorial de un numero
*\param long* resultado Puntero al resultado del factorial
*\param int numero El numero al que se le calcula el factorial
*\return int [-1] Error [0] Ok

*/

int calcularFactorial(long* resultado, int numero)
{
    int retorno;
    long auxiliarFactorial = (long) numero;
    long i;
    if (numero >= 0)
    {
        for(i = numero - 1; i > 1; i--)
        {
            auxiliarFactorial = auxiliarFactorial * i;
        }
        *resultado = auxiliarFactorial;
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}
