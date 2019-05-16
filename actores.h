#ifndef ACTORES_H_INCLUDED
#define ACTORES_H_INCLUDED
#define TEXT_SIZE 50

typedef struct
{
    int idActores;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char pais[TEXT_SIZE];

}Actores;


#endif // Actores_H_INCLUDED
void inicializarActoresConDatos(Actores array[], int size);
int Actores_Salarios(Actores array[],int size);
int Actores_Inicializar(Actores array[], int size);                                    //cambiar Actores
int Actores_buscarEmpty(Actores array[], int size, int* posicion);                    //cambiar Actores
int Actores_buscarID(Actores array[], int size, int valorBuscado, int* posicion);                    //cambiar Actores
int Actores_buscarInt(Actores array[], int size, int valorBuscado, int* posicion);                    //cambiar Actores
int Actores_buscarString(Actores array[], int size, char* valorBuscado, int* indice);                    //cambiar Actores
int Actores_alta(Actores array[], int size, int* contadorID);                          //cambiar Actores
int Actores_baja(Actores array[], int sizeArray);                                      //cambiar Actores
int Actores_bajaValorRepetidoInt(Actores array[], int sizeArray, int valorBuscado);
int Actores_modificar(Actores array[], int sizeArray);                                //cambiar Actores
int Actores_ordenarPorString(Actores array[],int size);                              //cambiar Actores
int Actores_listar(Actores array[], int size);                      //cambiar Actores

