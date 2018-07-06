#ifndef MOVIEDAO_H_INCLUDED
#define MOVIEDAO_H_INCLUDED
#include "Movie.h"

int movieDAO_guardarPeliculas(EMovie* movie,int lenPeliculas);
int movieDAO_importarPeliculas(EMovie* movie,int lenPeliculas);

#endif // MOVIEDAO_H_INCLUDED
