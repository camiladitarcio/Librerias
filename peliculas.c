
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "peliculas.h"
#include "actores.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array Peliculas Array of Peliculas
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int Peliculas_Inicializar(Peliculas array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Inicializa 5 arrays con datos cargados para testear funcionalidad del programa
* \param array Peliculas Array of Peliculas
* \param size int Array length
* \return int Return 0
*
*/

//inicializar con valores cargados

void inicializarPeliculasConDatos(Peliculas array[], int size)
{
    int id[10];
    char titulo[10][50] = {"El viaje de Chihiro","","Blade Runner","Susan Did It","La isla siniestra","Tu cara de mapa"};
    char genero[10][50] = {"Infantil","Comedia","Terror","Romantica","Comedia"};
    int dia[10] = {24,13,2,8,11};
    int mes[10] = {3,8,11,6,2};
    int ano[10] = {1985,1994,2002,2010,1964};
    int actorPelicula[5] = {15,12,24,3,42};
    int i;
    for (i=0; i<5; i++)
    {
        array[i].idPeliculas = id[i];
        strcpy(array[i].titulo,titulo[i]);
        strcpy(array[i].genero,genero[i]);
        array[i].dia=dia[i];
        array[i].mes=mes[i];
        array[i].ano=ano[i];
        array[i].isEmpty = 0; // OCUPADO.
    }
}


//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Peliculas_buscarEmpty(Peliculas array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Peliculas_buscarID(Peliculas array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPeliculas==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int Peliculas_buscarInt(Peliculas array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].sector==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un array
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Peliculas_buscarString(Peliculas array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].titulo,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int Peliculas_buscarPorPais(Peliculas array[], int size, char* valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].titulo,valorBuscado)==0)
            {
                printf("\n ID: %d --\t Titulo: %s\t Genero: %s\t Estreno: %d/%d/%d \t Actor: %s",
                   array[i].idPeliculas,array[i].titulo,array[i].genero,
                   array[i].dia,array[i].mes,array[i].ano,array[i].actorPelicula);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Peliculas_alta(Peliculas array[], int size, int* contadorID, Actores *pActores, int cant)
{
    int i;
    int idActor;
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Peliculas_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPeliculas=*contadorID;
            array[posicion].isEmpty=0;
            utn_getTexto("\nIngrese titulo:","\n-- ERROR --",1,100,1,array[posicion].titulo);
            utn_getTexto("\nIngrese genero:","\n-- ERROR --",1,50,1,array[posicion].genero);
            utn_getSignedInt("\nIngrese dia de estreno:","\n-- ERROR --",1,3,1,31,2,&array[posicion].dia);
            utn_getSignedInt("\nIngrese mes de estreno:","\n-- ERROR --",1,3,1,12,2,&array[posicion].mes);
            utn_getUnsignedInt("\nIngrese ano de estreno:","\n-- ERROR --",1,5,1900,2019,2,&array[posicion].ano);
            utn_getSignedInt("\nIngrese ID de actor:","\n-- ERROR --",1,3,1,50,2,&idActor);
            for(i=0;i<cant;i++)
            {
                if(idActor==pActores[i].idActores)
                {
                    if(pActores[i].isEmpty==0)
                    {
                        strcpy(array[posicion].actorPelicula,pActores[i].nombre);
                    }
                }
            }

            printf("\n ID: %d --\t Titulo: %s\t Genero: %s\t Estreno: %d/%d/%d \t Actor: %s",
                   array[posicion].idPeliculas,array[posicion].titulo,array[posicion].genero,
                   array[posicion].dia,array[posicion].mes,array[posicion].ano,array[posicion].actorPelicula);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Peliculas_baja(Peliculas array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a dar de baja: ","\n-- ERROR --",1,sizeof(int),1,sizeArray,1,&id);
        if(Peliculas_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Peliculas_bajaValorRepetidoInt(Peliculas array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPeliculas==valorBuscado)
            {
                array[i].isEmpty=1;
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int Peliculas_modificar(Peliculas array[], int sizeArray, Actores *pActores, int cant)
{
    int retorno=-1;
    int posicion;
    int i;
    int idActor;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getSignedInt("\nID a modificar: ","\n-- ERROR --",1,5,1000,2000,1,&id);
        if(Peliculas_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n ID: %d \t Titulo: %s\t Genero: %s\t Estreno: %d/%d/%d \t Actor: %s",
                   array[posicion].idPeliculas,array[posicion].titulo,array[posicion].genero,
                   array[posicion].dia,array[posicion].mes,array[posicion].ano,array[posicion].actorPelicula);
                utn_getChar("\nModificar: A(titulo) -- B(genero) -- C(fecha) -- D (actor) -- S(salir)","\n-- ERROR --",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("\nIngrese nuevo titulo:","\n-- ERROR --",1,100,1,array[posicion].titulo);
                        break;
                    case 'B': ;
                        utn_getTexto("\nIngrese nuevo genero:","\n-- ERROR --",1,50,1,array[posicion].genero);
                        break;
                    case 'C':
                        utn_getSignedInt("\nIngrese nuevo dia de estreno:","\n-- ERROR --",1,3,1,31,2,&array[posicion].dia);
                        utn_getSignedInt("\nIngrese nuevo mes de estreno:","\n-- ERROR --",1,3,1,12,2,&array[posicion].mes);
                        utn_getUnsignedInt("\nIngrese nuevo ano de estreno:","\n-- ERROR --",1,5,1900,2019,2,&array[posicion].ano);
                        break;
                    case 'D':
                        utn_getSignedInt("\nIngrese nuevo ID para reemplazar viejo ID:","\n-- ERROR --",1,3,1,50,2,&idActor);
                        for(i=0;i<cant;i++)
                        {
                            if(idActor==pActores[i].idActores)
                            {
                                if(pActores[i].isEmpty==0)
                                {
                                    strcpy(array[posicion].actorPelicula,pActores[i].nombre);
                                    break;
                                }
                                else{
                                    printf("No se encuentra ID de actor.\n");
                                    break;
                                }
                            }
                        }
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int Peliculas_ordenarPorString(Peliculas array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferIntDia;
    int bufferIntMes;
    int bufferIntAno;
    char bufferLongString[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            bufferId=array[i].idPeliculas;
            bufferIsEmpty=array[i].isEmpty;
            strcpy(bufferString,array[i].titulo);
            strcpy(bufferLongString,array[i].genero);
            bufferIntDia=array[i].dia;
            bufferIntMes=array[i].mes;
            bufferIntAno=array[i].ano;

            j = i - 1;
            while((j >= 0)&&(bufferIntAno>array[j].ano))
                {
                array[j + 1].idPeliculas=array[j].idPeliculas;
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].titulo,array[j].titulo);
                strcpy(array[j + 1].genero,array[j].genero);
                array[j + 1].dia=array[j].dia;
                array[j + 1].mes=array[j].mes;
                array[j + 1].ano=array[j].ano;
                j--;
            }
                array[j + 1].idPeliculas=bufferId;
                array[j + 1].isEmpty=bufferIsEmpty;
                strcpy(array[j + 1].titulo,bufferString);
                strcpy(array[j + 1].genero,bufferLongString);
                array[j + 1].dia=bufferIntDia;
                array[j + 1].mes=bufferIntMes;
                array[j + 1].ano=bufferIntAno;
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Peliculas Array de Peliculas
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Peliculas_listar(Peliculas array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            printf("\n ID: %d --\t Titulo: %s\t Genero: %s\t Estreno: %d/%d/%d \t Actor: %s",
                   array[i].idPeliculas,array[i].titulo,array[i].genero,
                   array[i].dia,array[i].mes,array[i].ano,array[i].actorPelicula);
        }
        retorno=0;
    }
    return retorno;
}
/*
int Peliculas_Salarios(Peliculas array[],int size)
{
    float promedio;
    int bufferSalario;
    int contador = 0;
    int acum;
    int overSalario = 0;
    int i;


    for(i=0;i<size;i++)
    {
        if(array[i].isEmpty==0)
        {
        bufferSalario = array[i].salario;
        acum = acum + bufferSalario;
        contador++;
    }
    }
    promedio = acum / contador;

    for(i=0;i<contador;i++)
    {
        bufferSalario = array[i].salario;
        if(bufferSalario>promedio)
        {
            overSalario++;
        }
    }
    if(overSalario > 0)
    {
        printf("\nCantidad de Peliculass que superan el promedio salario: %d",overSalario);
    }
    else
        {
           printf("\nNo se han encontrado Peliculas que superen el promedio salario");
        }

    printf("\n\n TOTAL SALARIOS: %d \t PROMEDIO: %2.f",acum,promedio);
    return 0;
}
*/

