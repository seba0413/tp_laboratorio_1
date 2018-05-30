#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}Persona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int buscarLugarLibrePersona(Persona* array,int limite);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int persona_buscarPorDni(Persona* array,int limite, int dni);

/** \brief Inicializar un array de personas
 *
 * \param array de personas
 * \param int limite del array
 * \return 0 ok, -1 error
 *
 */

int persona_init(Persona* array, int limite);

/** \brief Da de alta una nueva persona
 *
 * \param array de personas
 * \param int limite del array
 * \return 0 ok, -1 error
 *
 */

int persona_alta(Persona* array,int limite);

/** \brief Elimina una persona
 *
 * \param Array de personas
 * \param int limite del array
 * \param int dni

 * \return 0 ok, -1 error
 *
 */

int persona_baja(Persona* array,int limite, int dni);


/** \brief Imprime los datos de las personas ordenadas por nombre
 *
 * \param Array de personas
 * \param int limite del array
 * \param int orden
 * \return 0ok, -1 error
 *
 */

int persona_listarOrdenadoPorNombre(Persona* array,int limite, int orden);

/** \brief Imprime un grafico que indica la cantidad de personas de diferentes edades
 *
 * \param Array de personas
 * \param int limite del array
 * \return 0 ok, -1 error
 *
 */

int persona_graficarEdades(Persona* array, int limite);

/** \brief Imprime un listado de las personas dadas de alta
 *
 * \param Array de personas
 * \param int limite del array
 * \return 0 ok, -1 error
 *
 */

int persona_mostrarDebug(Persona* array,int limite);

/** \brief Da de alta una persona pasando los datos por parametro
 *
 * \param Array de personas
 * \param int limite del array
 * \param char nombre de la persona
 * \param int dni
 * \param int edad
 * \return 0 ok, -1 error
 *
 */

int persona_altaForzada(Persona* array,int limite, char* nombre, int dni, int edad);

#endif // FUNCIONES_H_INCLUDED
