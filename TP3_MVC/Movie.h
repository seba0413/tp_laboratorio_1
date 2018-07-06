#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    float puntaje;
    char linkImagen[50];
    int flagOcupado;
    int idPelicula;
}EMovie;


EMovie* Movie_new();
void Movie_delete();
EMovie* Movie_newConParametros(char* titulo,char* genero,int duracion,char* descripcion,float puntaje,char* linkImagen,int flagOcupado,int idPelicula);

int Movie_setTitulo(EMovie* this,char* titulo);
int Movie_getTitulo(EMovie* this,char* titulo);

int Movie_setGenero(EMovie* this,char* genero);
int Movie_getGenero(EMovie* this,char* genero);

int Movie_setDuracion(EMovie* this,int duracion);
int Movie_getDuracion(EMovie* this,int* duracion);

int Movie_setDescripcion(EMovie* this,char* descripcion);
int Movie_getDescripcion(EMovie* this,char* descripcion);

int Movie_setPuntaje(EMovie* this,float puntaje);
int Movie_getPuntaje(EMovie* this,float* puntaje);

int Movie_setLinkImagen(EMovie* this,char* linkImagen);
int Movie_getLinkImagen(EMovie* this,char* linkImagen);

int Movie_setFlagOcupado(EMovie* this,int flagOcupado);
int Movie_getFlagOcupado(EMovie* this,int* flagOcupado);

int Movie_setIdPelicula(EMovie* this,int idPelicula);
int Movie_getIdPelicula(EMovie* this,int* idPelicula);

int movie_buscarPosicionLibre(EMovie* movie, int len);

#endif // MOVIE_H_INCLUDED
