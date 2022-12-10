#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP* HEAP_create(int n, COMP* compara){
    HEAP* heap = malloc(sizeof(HEAP));
    heap->comparador = compara;
    heap->N = n;
    heap->P = 0;
    heap->elems = malloc(n * sizeof(void *));
    for(int i = 0;i<n;i++){
        heap->elems[i] = NULL;
    }
    return heap;
}

void HEAP_add(HEAP* vetor, void* newelem){
    if(vetor->P < vetor->N){
        if(vetor->P == 0){
            vetor->elems[0] = newelem;
            vetor->P++;
        }
        else{
            vetor->elems[vetor->P] = newelem;
            vetor->P++;
            for(int i=vetor->P-1;i>0;i = i/2){
                if(vetor->comparador(vetor->elems[i], vetor->elems[i/2]) == 1){
                    void* aux = vetor->elems[i];
                    vetor->elems[i] = vetor->elems[i/2];
                    vetor->elems[i/2] = aux;
                }
            }
        }
    }
}

void descer(HEAP* veto, int pos){
    int P = pos;
    int N = veto->P;
    void** vet = veto->elems;
    COMP* comp= veto->comparador;

    if(2*P < N){
        int son = 2*P;
        if(2*P+1<N){
            if(comp(vet[2*P], vet[2*P+1]) == 1)
                son = 2*P;
            else son = 2*P+1;
        }
        if(comp(vet[son], vet[P]) == 1){
            void* aux = vet[son];
            vet[son] = vet[P];
            vet[P] = aux;
            descer(veto, son);
        }
    }
}

void* HEAP_remove(HEAP* vetor){
    void* aux = vetor->elems[0];
    vetor->elems[0] = vetor->elems[vetor->P-1];
    vetor->elems[vetor->P-1] = aux;
    vetor->P--;
    descer(vetor, 0);
    void* ret = vetor->elems[vetor->P];
    return ret;
}
