/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenar.c
 * Autor: 
 * Version: 1.0
 * Fecha: 22-09-2011
 *
 */


#include "ordenar.h"

/***************************************************/
/* Funcion: aleat_num Fecha:                       */
/* Autores: Ángel Manuel Martín                    */
/*          Darío Adrián Hernández Barroso         */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
  int s = (sup - inf) + 1;
  
  return rand()%s + inf;
}

/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int n)
{
  int i;
  int tmp;
  int r;
  int* perm = (int*)malloc(n*sizeof(int));
 
  if(!perm)
    return 0;

  for(i = 0; i < n; ++i)
    perm[i] = i + 1;

  for(i = 0; i < n; ++i) {
    r = aleat_num(0, n - 1);
    tmp = perm[r];
    perm[r] = perm[i];
    perm[i] = tmp;
  }

  return perm;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int tamanio: Numero de elementos de cada        */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int tamanio)
{
/* vuestro codigo */
}

/***************************************************/
/* Funcion: SelectSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int BubbleSort(int* tabla, int ip, int iu)
{
  /* vuestro codigo */
}

/***************************************************/
/* Funcion: SelectSortInv    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int BubbleSortInv(int* tabla, int ip, int iu)
{
  /* vuestro codigo */
}


/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int tamanio, 
                              PTIEMPO ptiempo)
{
/* vuestro codigo */
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*                                                 */
/* Vuestra documentacion                           */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
  /* vuestro codigo */
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int N)
{
  /* vuestro codigo */
}


