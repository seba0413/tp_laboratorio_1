#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED
#define LEN_DESCRIPCION 1000
#define LEN_LINK 1000
#include "Movie.h"


EMovie* model_getMovies(void);
int model_getMoviesLen(void);

void model_cargarMovie(EMovie movie, int index);
int model_generarProximoId();
int model_buscarPosicionLibre();
int model_buscarIndicePorId(int id);

#endif // MODEL_H_INCLUDED
