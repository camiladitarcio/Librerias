
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "actores.h"
#include "peliculas.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array Actores Array of Actores
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
/*
int Actores_Inicializar(Actores array[], int size)
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
*/

/** \brief Inicializa 5 arrays con datos cargados para testear funcionalidad del programa
* \param array Actores Array of Actores
* \param size int Array length
* \return int Return 0
*
*/
//inicializar con valores cargados
void inicializarActoresConDatos(Actores array[], int size)
{
    char name[50][50] = {"Abbott","Acevedo", "Acosta","Adams ","Adkins","Aguilar","Aguirre","Albert","Alexander","Alford","Allen ",
                        "Allison","Alston","Alvarado","Alvarez","Anderson","Andrews","Anthony","Armstrong","Arnold","Ashley","Atkins","Atkinson",
                        "Austin","Avery ","Avila ","Ayala ","Ayers ","Bailey","Baird ","Baker ","Baldwin","Ball  ","Ballard","Banks ","Barber","Barker",
                        "Barlow","Barnes","Barnett","Barr  ","Barrera","Barrett","Barron","Barry ","Bartlett","Barton","Bass ","Bates","Battle"};
    char lastName[50][50] = {"Mexico", "Dinamarca", "Austria", "Mexico", "Estados Unidos", "Canada", "Australia", "Estados Unidos",
                            "Taiwan","Vietnam", "Chile", "China", "Japon", "Islandia", "Colombia",
                            "Estados Unidos", "Francia", "Estados Unidos", "Francia", "Argentina", "Grecia",
                            "Croacia", "Cuba", "Francia", "Estados Unidos", "Brasil", "Colombia", "España", "Mexico",
                            "Argentina", "Ecuador", "Egipto", "Francia", "Alemania", "Italia", "Estonia", "Argentina",
                            "Portugal", "Rusia", "Uruguay", "España", "Francia", "Estados Unidos", "España",
                            "Mexico", "Mexico", "Gabon", "España", "Georgia", "Germany"};
    int i;
    for (i=0; i<size; i++)
    {
        array[i].idActores = i;
        strcpy(array[i].nombre,name[i]);
        strcpy(array[i].pais,lastName[i]);
        array[i].isEmpty = 0; // OCUPADO.
    }
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Actores_buscarEmpty(Actores array[], int size, int* posicion)
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
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Actores_buscarID(Actores array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idActores==valorBuscado)
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
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int Actores_buscarInt(Actores array[], int size, int valorBuscado, int* posicion)
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
}*/

//String
/** \brief Busca un string en un array
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Actores_buscarString(Actores array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
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
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Actores_alta(Actores array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Actores_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idActores=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre:","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getTexto("\nIngrese pais:","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].pais);
            printf("\n ID: %d\n nombre: %s\n pais: %s",
                   array[posicion].idActores,array[posicion].nombre,array[posicion].pais);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Actores_baja(Actores array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a dar de baja: ","\n-- ERROR --",1,sizeof(int),1,sizeArray,1,&id);
        if(Actores_buscarID(array,sizeArray,id,&posicion)==-1)
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
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Actores_bajaValorRepetidoInt(Actores array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idActores==valorBuscado)
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
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int Actores_modificar(Actores array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\n-- ERROR --",1,sizeof(int),1,sizeArray,1,&id);
        if(Actores_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                 printf("\n Posicion: %d\n ID: %d\n nombre: %s\n pais: %s",
                   posicion, array[posicion].idActores,array[posicion].nombre,array[posicion].pais);
                utn_getChar("\nModificar: A(Nombre) -- B(pais) -- S(salir)","\n-- ERROR --",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre: ","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'B': ;
                        utn_getTexto("\nIngrese nuevo pais: ","\n-- ERROR --",1,TEXT_SIZE,1,array[posicion].pais);
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
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int Actores_ordenarPorString(Actores array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    char bufferLongString[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombre);
            bufferId=array[i].idActores;
            bufferIsEmpty=array[i].isEmpty;
            strcpy(bufferLongString,array[i].pais);

            j = i - 1;
            while ((j >= 0) && (strcmp(bufferLongString,array[j].pais)<0))
                {
                array[j + 1].idActores=array[j].idActores;
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].nombre,array[j].nombre);
                strcpy(array[j + 1].pais,array[j].pais);
                j--;
            }
                array[j + 1].idActores=bufferId;
                array[j + 1].isEmpty=bufferIsEmpty;
                strcpy(array[j + 1].nombre,bufferString);
                strcpy(array[j + 1].pais,bufferLongString);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Actores Array de Actores
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Actores_listar(Actores array[], int size)
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
        printf("\nID: %d \t nombre: %s \t pais: %s",
                array[i].idActores,array[i].nombre,array[i].pais);
        }
        retorno=0;
    }
    return retorno;
}

/*int Actores_addPelicula(Actores *arrayActores, int QTY_ACTORES, Peliculas* arrayPeliculas, int QTY_PELICULAS)
{
    int ret = 1;
    int idActor;
    int i;
    Actores_listar(arrayActores,QTY_ACTORES);
    utn_getSignedInt("\nIngrese ID actor:","\n-- ERROR --",1,2,1,50,2,&idActor);

    for(i=0;i<QTY_ACTORES;i++)
    {
        if(idActor==arrayActores[i].idActores)
        {
            if(arrayActores[i].isEmpty==0)
            {
               arrayPeliculas[i].actorPelicula = idActor;
               ret = 0;
               break;
            }
            else
            {
                ret = 1;
            }
        }
    }
    return ret;
}*/

/*
int Actores_Salarios(Actores array[],int size)
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
        printf("\nCantidad de Actoress que superan el promedio salario: %d",overSalario);
    }
    else
        {
           printf("\nNo se han encontrado Actoress que superen el promedio salario");
        }

    printf("\n\n TOTAL SALARIOS: %d \t PROMEDIO: %2.f",acum,promedio);
    return 0;
}
*/


