#include "tp0.h"

#define MAXIMO_VECTOR_VACIO (-1)

#define COMPARAR_VECTOR1_MAYOR 1
#define COMPARAR_VECTOR2_MAYOR (-1)
#define COMPARAR_IGUALES 0

/* *****************************************************************
 *                     FUNCIONES A COMPLETAR                       *
 *         (ver en tp0.h la documentación de cada función)         *
 * *****************************************************************/

void swap(int *x, int *y){

    int aux = *x;
    *x = *y;
    *y = aux;

}

int maximo(int vector[], int n){

    if(n < 1){
        return MAXIMO_VECTOR_VACIO;
    }

    int pos = 0;
    int max = vector[0];

    for(int i = 0; i < n; i++){  
        if(vector[i] > max){
            max = vector[i];
            pos = i;
        }
    }

    return pos;

}

int comparar(int vector1[], int n1, int vector2[], int n2){

    int i = 0;

    for(i = 0; i < n1 && i < n2; i++){
        if(vector1[i] > vector2[i]){
            return COMPARAR_VECTOR1_MAYOR;
        }
        else if(vector1[i] < vector2[i]){
            return COMPARAR_VECTOR2_MAYOR;
        }
    }

    if(n1 > i){
        return COMPARAR_VECTOR1_MAYOR;
    }
    else if(n2 > i){
        return COMPARAR_VECTOR2_MAYOR;
    }

    return COMPARAR_IGUALES;

}

void seleccion(int vector[], int n){

    for(int i = (n-1); i > 0; i--){
        int pos_max = maximo(vector, i+1);
        if(pos_max != i){
            swap(&vector[pos_max], &vector[i]);
        }
    }

}