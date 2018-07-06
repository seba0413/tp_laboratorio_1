#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Movie.h"

int controller_alta(char titulo[], char genero[], int duracion, char descripcion[],  float puntaje, char* linkImagen);
void controller_modificar(char titulo[], char genero[], int duracion, char descripcion[],  float puntaje, char* linkImagen, int id, int index);

#endif // CONTROLLER_H_INCLUDED
