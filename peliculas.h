#ifndef Peliculas_H_INCLUDED
#define Peliculas_H_INCLUDED
#define TEXT_SIZE 50
#include "actores.h"

typedef struct
{
    int idPeliculas;
    int isEmpty;
    //-----------------
    char titulo[TEXT_SIZE];
    char genero[TEXT_SIZE];
    int dia;
    int mes;
    int ano;
    char actorPelicula[TEXT_SIZE];

}Peliculas;


#endif // Peliculas_H_INCLUDED
int Peliculas_buscarPorPais(Peliculas array[], int size, char* valorBuscado);
void inicializarPeliculasConDatos(Peliculas array[], int size);
int Peliculas_Salarios(Peliculas array[],int size);
int Peliculas_Inicializar(Peliculas array[], int size);                                    //cambiar Peliculas
int Peliculas_buscarEmpty(Peliculas array[], int size, int* posicion);                    //cambiar Peliculas
int Peliculas_buscarID(Peliculas array[], int size, int valorBuscado, int* posicion);                    //cambiar Peliculas
int Peliculas_buscarInt(Peliculas array[], int size, int valorBuscado, int* posicion);                    //cambiar Peliculas
int Peliculas_buscarString(Peliculas array[], int size, char* valorBuscado, int* indice);                    //cambiar Peliculas
int Peliculas_alta(Peliculas array[], int sizePeliculas, int* contadorID, Actores *pActores, int cant);                          //cambiar Peliculas
int Peliculas_baja(Peliculas array[], int sizeArray);                                      //cambiar Peliculas
int Peliculas_bajaValorRepetidoInt(Peliculas array[], int sizeArray, int valorBuscado);
int Peliculas_modificar(Peliculas array[], int sizeArray,Actores *pActores, int cant);                                //cambiar Peliculas
int Peliculas_ordenarPorString(Peliculas array[],int size);                              //cambiar Peliculas
int Peliculas_listar(Peliculas array[], int size);                      //cambiar Peliculas


