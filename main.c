#include <stdio.h>
#include <stdlib.h>
#include "actores.h"
#include "peliculas.h"
#include "utn.h"
#define QTY_PELICULAS 1000
#define QTY_ACTORES 50

int main()
{

int opcion;
    int contadorIdPeliculas=1000;
    Peliculas arrayPeliculas[QTY_PELICULAS];
    Actores arrayActores[QTY_ACTORES];
    //int contadorIdPeliculas=5;
    //inicializarPeliculasConDatos(arrayPeliculas,QTY_PELICULAS); //INICIALIZA PeliculasS CON DATOS YA CARGADOS

    Peliculas_Inicializar(arrayPeliculas,QTY_PELICULAS);
    inicializarActoresConDatos(arrayActores,QTY_ACTORES);
    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Informar\n \n7) Salir\n",
                      "\n-- ERROR --",1,sizeof(int),1,7,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                Actores_listar(arrayActores,QTY_ACTORES);
                Peliculas_alta(arrayPeliculas,QTY_PELICULAS,&contadorIdPeliculas, arrayActores, 50);
                break;

            case 2: //Modificar
                Peliculas_modificar(arrayPeliculas,QTY_PELICULAS, arrayActores, 50);
                break;

            case 3: //Baja
                Peliculas_baja(arrayPeliculas,QTY_PELICULAS);
                break;

            case 4://Listar
                Peliculas_listar(arrayPeliculas,QTY_PELICULAS);
                break;

            case 5://Ordenar
                Peliculas_ordenarPorString(arrayPeliculas,QTY_PELICULAS);
                Actores_ordenarPorString(arrayActores, QTY_ACTORES);
                break;

            case 6:
                Peliculas_listar(arrayPeliculas,QTY_PELICULAS);
                Actores_listar(arrayActores,QTY_ACTORES);
                Peliculas_buscarPorPais(arrayPeliculas,QTY_PELICULAS,"Estados Unidos");
                break;

            case 7://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=7);
    return 0;
}

