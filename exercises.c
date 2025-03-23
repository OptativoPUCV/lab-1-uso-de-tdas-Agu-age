#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(int i = 1; i <= 10 ; i++){
      int *num = (int*) malloc(sizeof(int));
      if(num == NULL) exit(1);
      *num = i;
      pushBack(L, num);
   }
   
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   for(void *elemento = first(L); elemento != NULL; elemento = next(L))
   {
      suma += *(int*)elemento;
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   for(void *actual = first(L); actual != NULL; actual = next(L))
   {
      if(*(int*)actual == elem){
         popCurrent(L);
      }
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack *aux = create_stack();
   while(top(P1) != NULL){
      void *dato = pop(P1);
      push(aux, dato);
   }

   while(top(aux) != NULL){
      void *dato = pop(aux);
      push(P1, dato);
      push(P2, dato);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) 
{
   Stack *aux = create_stack();

   while(*cadena)
   {
      if(*cadena == '(' || *cadena == '[' || *cadena == '{')
      {
         char *elemento = (char*) malloc(sizeof(char));
         if(elemento == NULL) exit(1);
         *elemento = *cadena;
         push(aux, elemento);
      }

      else if(*cadena == ')' || *cadena == ']' || *cadena == '}')
      {
         if(top(aux) == NULL)
         {
            return 0;
         }
         char *ult = (char*) pop(aux);
         char elem = *ult;
         free(ult);

         if ((*cadena == ')' && elem != '(') || 
         (*cadena == ']' && elem != '[') || 
         (*cadena == '}' && elem != '{')) return 0;
      }
      cadena++;
   }
   if(top(aux) == NULL) exit(1);
   return 0;
}

