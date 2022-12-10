#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


int comparacao(void* x, void* y){
    if(*(int*)x == *(int*)y){
        return 0;
    }else if(*(int*)x > *(int*)y){
        return -1;
    }else{
        return 1;
    }
}

int main(){
    COMP* comp = comparacao;
    int t;
    printf("Tamanho vetor: ");
    scanf("%d", &t);
    HEAP* veto = HEAP_create(t, comp);
    int in[90] = {};
    int i = 0;
    while(in[i] >= 0){
        printf("NUM: ");
        scanf("%d", &in[i]);
        if(in[i] >= 0){
            HEAP_add(veto, &in[i]);
            i++;
        }
    }
    
    
    //veto->elems[200] = "oi";
    printf("%d removido\n", *(int*)HEAP_remove(veto));
    for(int i = 0;i<veto->P;i++){
        printf("%d ", *(int*)veto->elems[i]);
    }
    //printf(veto->elems[200]);
    return 0;
}
