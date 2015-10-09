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

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
int roundup_division(int a, int b);

/***************************************************/
/* Funcion: aleat_num Fecha: 2015-10-02            */
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
  return inf + rand()%(sup - inf + 1);
}

/***************************************************/
/* Funcion: genera_perm Fecha: 2015-10-02          */
/* Autores: Ángel Manuel Martín                    */
/*          Darío Adrián Hernández Barroso         */
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
  int r;
  int* perm = (int*)malloc(n*sizeof(perm[0]));
 
  if(!perm)
    return 0;

  for(i = 0; i < n; ++i)
    perm[i] = i + 1;

  for(i = 0; i < n; ++i) {
    r = aleat_num(i, n - 1);
    swap(&perm[r], &perm[i]);
  }

  return perm;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha: 2015-10-02 */
/* Autores: Ángel Manuel Martín                    */
/*          Darío Adrián Hernández Barroso         */
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
  int i;
  int** perms = (int**)malloc(sizeof(perms[0])*n_perms);

  if(!perms)
    return NULL;

  for(i = 0; i < n_perms; ++i) {
    perms[i] = NULL;
    perms[i] = genera_perm(tamanio);

    if(perms[i] == NULL) {
      int j;

      for(j = i - 1; j >= 0; --j)
        free(perms[j]);

      free(perms);

      return NULL;
    }
  }

  return perms;
}

/***************************************************/
/* Funcion: BubbleSort    Fecha: 2015-10-02        */
/* Autores: Ángel Manuel Martín                    */
/*          Darío Adrián Hernández Barroso         */
/* Ordena una tabla usando el algoritmo BubbleSort */
/* La ordenación es de menor a mayor.              */
/*                                                 */
/* Entrada:                                        */
/* int* tabla: Puntero a la tabla que se debe ord. */
/* int ip: Indice del primer elemento del rango a  */
/*         ordenar.                                */
/* int iu: Indice del final del rango a ordenar.   */
/*         El final esta incluido en el rango.     */
/* Salida:                                         */
/* int: Numero de operaciones basicas realizadas.  */
/***************************************************/
int BubbleSort(int* tabla, int ip, int iu)
{
  int ob = 0;
  int i = iu;
  int j;
  int swapped = 1;

  while(swapped) {
    swapped = 0;

    for(j = ip; j < i; ++j) {
      ++ob;
      if(tabla[j] > tabla[j+1]) {
        swap(&tabla[j], &tabla[j+1]);
        swapped = 1;
      }
    }

    --i;
  }

  return ob;
}

/***************************************************/
/* Funcion: BubbleSort    Fecha: 2015-10-02        */
/* Autores: Ángel Manuel Martín                    */
/*          Darío Adrián Hernández Barroso         */
/* Ordena una tabla usando el algoritmo BubbleSort */
/* La ordenación es de mayor a menor               */
/*                                                 */
/* Entrada:                                        */
/* int* tabla: Puntero a la tabla que se debe ord. */
/* int ip: Indice del primer elemento del rango a  */
/*         ordenar.                                */
/* int iu: Indice del final del rango a ordenar.   */
/*         El final esta incluido en el rango.     */
/* Salida:                                         */
/* int: Numero de operaciones basicas realizadas.  */
/***************************************************/
int BubbleSortInv(int* tabla, int ip, int iu)
{
  int ob = 0;
  int i = iu;
  int j;
  int swapped = 1;

  while(swapped) {
    swapped = 0;

    for(j = ip; j < i; ++j) {
      ++ob;
      if(tabla[j] < tabla[j+1]) {
        swap(&tabla[j], &tabla[j+1]);
        swapped = 1;
      }
    }

    --i;
  }

  return ob;
}


/******************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha: 2015-10-02 */
/*                                                    */
/* Autores: Ángel Manuel Martín                       */
/*          Darío Adrián Hernández Barroso            */
/* Mide diversos parametros de un algoritmo de ord.   */
/* para un tamanio de entrada dado.                   */
/*                                                    */
/* Entrada:                                           */
/* pfunc_ordena metodo: algoritmo de ordenacion       */
/* int n_perms: numero de permutaciones a promediar   */
/* int tamanio: tamanio de las permutaciones a ordenar*/
/* PTIEMPO ptiempo: Puntero a estructura donde        */
/*                  guardar tiempos y medidas.        */
/* Salida:                                            */
/* short: OK si todo fue bien, ERR en caso contrario  */
/******************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int tamanio, 
                              PTIEMPO ptiempo)
{
  double tiempo_tot;
  double tiempo;
  double medio_ob;
  int min_ob = INT_MAX;
  int max_ob = -1;
  int tot_ob = 0;
  int i;
  int** perms = genera_permutaciones(n_perms, tamanio);
  clock_t inicio, final;
     
  inicio = clock();

  if(perms == NULL)
    return ERR;

  for(i = 0; i < n_perms; ++i) {
    int ob;

    ob = metodo(perms[i], 0, tamanio-1);

    if(ob == ERR) {
      int j;

      for(j = 0; j < n_perms; ++j)
        free(perms[j]);

      free(perms);

      return ERR;
    }

    tot_ob += ob;

    if(ob > max_ob)
      max_ob = ob;

    if(ob < min_ob)
      min_ob = ob;
  }

  final = clock();
  tiempo_tot = (double)(final - inicio)/CLOCKS_PER_SEC;

  tiempo = tiempo_tot/n_perms;

  medio_ob = (double)tot_ob/n_perms;

  ptiempo->n_perms = n_perms;
  ptiempo->tamanio = tamanio;
  ptiempo->tiempo = tiempo;
  ptiempo->medio_ob = medio_ob;
  ptiempo->min_ob = min_ob;
  ptiempo->max_ob = max_ob;

  for(i = 0; i < n_perms; ++i)
    free(perms[i]);

  free(perms);

  return OK;
}

/********************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha: 2015-10-02 */
/*                                                      */
/* Autores: Ángel Manuel Martín                         */
/*          Darío Adrián Hernández Barroso              */
/*                                                      */
/* Mide y guarda los tiempos de un algoritmo dado.      */
/*                                                      */
/* Entrada:                                             */
/* pfunc_ordena metodo: algoritmo de ordenacion         */
/* char* fichero: nombre del fichero donde guardar      */
/* int num_min: tamanio minimo de las permutaciones     */
/* int num_max: tamanio maximo                          */
/* int incr: incremento del tamanio                     */
/* int n_perms: numero de permutaciones a promediar     */
/*              para cada tamanio                       */
/* PTIEMPO ptiempo: Puntero a estructura donde          */
/*                  guardar tiempos y medidas.          */
/* Salida:                                              */
/* short: OK si todo fue bien, ERR en caso contrario    */
/********************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
  int i;
  int s;
  int N = roundup_division(num_max - num_min + 1, incr);
  TIEMPO *t = (TIEMPO*)malloc(sizeof(t[0])*N);

  for (i = 0, s = num_min; s <= num_max; ++i, s += incr) {
    if (tiempo_medio_ordenacion(metodo, n_perms, s, &t[i]) == ERR)
      return ERR;
  }

  if(guarda_tabla_tiempos(fichero, t, N) == ERR) {
    free(t);
    return ERR;
  }

  free(t);
  return OK;
}

/********************************************************/
/* Funcion: guarda_tabla_tiempos Fecha: 2015-10-02      */
/*                                                      */
/* Autores: Ángel Manuel Martín                         */
/*          Darío Adrián Hernández Barroso              */
/*                                                      */
/* Entrada:                                             */
/* pfunc_ordena metodo: algoritmo de ordenacion         */
/* char* fichero: nombre del fichero donde guardar      */
/* PTIEMPO tiempo: array de TIEMPO                      */
/* int N: longitud del array tiempo                     */
/*                                                      */
/* PTIEMPO ptiempo: Puntero a estructura donde          */
/*                  guardar tiempos y medidas.          */
/* Salida:                                              */
/* short: OK si todo fue bien, ERR en caso contrario    */
/********************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int N)
{
  int i;
  FILE* f;

  f = fopen(fichero, "w");

  if (f == NULL)
    return ERR;

  for(i = 0; i < N; ++i)
    fprintf(f,
    "%d\t%10.10f\t%10.2f\t%d\t%d\n",
    tiempo[i].tamanio,
    tiempo[i].tiempo,
    tiempo[i].medio_ob,
    tiempo[i].min_ob,
    tiempo[i].max_ob);

  fclose(f);

  return OK;
}

/**********************************************/
/* Funcion: swap Fecha: 2015-10-02            */
/*                                            */
/* Autores: Ángel Manuel Martín               */
/*          Darío Adrián Hernández Barroso    */
/*                                            */
/* Intercambia dos enteros en memoria         */
/*                                            */
/* Entrada:                                   */
/* int *a: Puntero a A                        */
/* int *b: Puntero a B                        */
/**********************************************/
void swap(int *a, int *b) {
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

/**********************************************/
/* Funcion: swap Fecha: 2015-10-02            */
/*                                            */
/* Autores: Ángel Manuel Martín               */
/*          Darío Adrián Hernández Barroso    */
/*                                            */
/* Implementa techo(A/B)                      */
/*                                            */
/* Entrada:                                   */
/* int a: A                                   */
/* int b: B                                   */
/* Salida:                                    */
/* int: techo(A/B)                            */
/**********************************************/
int roundup_division(int a, int b) {
  return (a + b - 1) / b;
}


