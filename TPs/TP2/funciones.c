#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

int persona_ordenar(Persona* array,int limite, int orden);

int persona_init(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado=0;
        }
    }
    return retorno;
}
/** \brief Imprime los valores cargados
 *
 * \param Persona array
 * \param int limite
 * \return 0 Ok, -1 Error
 *
 */

int persona_mostrarDebug(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if (array[i].estado)
            {
                printf("[DEBUG] - %s - %d - %d\n",array[i].nombre, array[i].dni, array[i].edad);
            }

        }
    }
    return retorno;
}
/** \brief Muestra por consola los datos requeridos
 *
 * \param Persona array
 * \param int limite
 * \return int 0 ok, -1 Error
 *
 */

int persona_mostrar(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado)
                printf("\n%s - %d - %d\n",array[i].nombre, array[i].dni, array[i].edad);
        }
    }
    return retorno;
}

/** \brief Da de alta elementos Persona harcodeados
 *
 * \param Persona array
 * \param int limite
 * \param char nombre
 * \return 0 ok, -1 Error
 *
 */

int persona_altaForzada(Persona* array,int limite, char* nombre, int dni, int edad)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibrePersona(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].dni = dni;
            array[i].edad = edad;
            array[i].estado = 1;
        }
    }
    return retorno;
}

int persona_alta(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    char auxNombre[50];
    int auxDni;
    int auxEdad;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibrePersona(array,limite);
        if(i >= 0)
        {
            retorno = -2;
            if(!getValidString("\nNombre?\n","\nEso no es un nombre\n","\nEl maximo de caracteres es 50\n",auxNombre,50,2))
            {
                if(!getValidInt("\nDni\n","\nDni invalido\n",&auxDni,1,99999999,2))
                   {
                       if(!getValidInt("\nEdad?\n","\nEdad invalida\n",&auxEdad,1,200,2))
                       {
                            retorno = 0;
                            strcpy(array[i].nombre,auxNombre);
                            array[i].dni = auxDni;
                            array[i].edad = auxEdad;
                            array[i].estado = 1;
                       }

                   }

            }
        }
    }
    return retorno;
}

int persona_baja(Persona* array,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado && array[i].dni==dni)
            {
                array[i].estado = 0;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica los datos de un elemento Persona
 *
 * \param Persona array
 * \param int limite
 * \param int id
 * \return 0 ok, -1 Error
 *
 */

int persona_modificacion(Persona* array,int limite, int dni)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].dni==dni)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,buffer);
                    //------------------------------
                    //------------------------------
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Ordena un array de elementos Persona
 *
 * \param Persona array
 * \param int limite
 * \param int orden
 * \return 0 ok, -1 Error
 *
 */


int persona_listarOrdenadoPorNombre(Persona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Persona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(array[i].estado && array[i+1].estado)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
        persona_mostrar(array, limite);
    }
    return retorno;
}

int persona_graficarEdades(Persona* array, int limite)
{
    int retorno=-1;
    int i;
    int j;
    int contador[3];
    contador[0] = 0;
    contador[1] = 0;
    contador[2] = 0;

    for(i = 0;i < limite;i++)
    {
        if(array[i].edad < 18 && array[i].estado)
            contador[0]++;
        else if(array[i].edad > 18 && array[i].edad <= 35 && array[i].estado)
            contador[1]++;
        else if(array[i].edad > 35 && array[i].estado)
            contador[2]++;
    }

    if(limite>0 && array != NULL)
    {
        retorno=0;

        for (i = 20;i > 0;i--)
        {
            for(j = 0;j < 3;j++)
            {
                if(i <= contador[j])
                    printf("  *   ");
                else
                    printf("      ");
            }
            printf("\n");
        }
        printf(" <18  19-35  >35");
    }
    return retorno;
}

/** \brief Pide un id y busca el elemento Persona que coincide con ese id
 *
 * \param Persona array
 * \param int limite
 * \param int id
 * \return 0 ok, -1 Error
 *
 */

int persona_buscarPorDni(Persona* array,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].dni==dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un lugar libre en un array Persona
 *
 * \param Persona array
 * \param int limite
 * \return 0 ok, -1 Error
 *
 */

int buscarLugarLibrePersona(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].estado==0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Guarda el valor del ultimo id y obtiene el proximo id libre
 *
 * \param void
 * \return int proximoId
 *
 */

int proximoIdPersona()
{
    static int proximoId = 0;
    proximoId++;
    return proximoId;
}
