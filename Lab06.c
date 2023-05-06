// Cristiane de Paula Oliveira
// Estrutura de Dados - Laboratorio 6
// Palíndromos
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct nodo_st {
    char dado;
    struct nodo_st *prox;
    struct nodo_st *ant;
};
typedef struct nodo_st nodo_t;

struct deque_enc_st {
    nodo_t *inicio;
    nodo_t *fim;
    int tamanho;
};
typedef struct deque_enc_st deque_t;

// Inicializar
void inicializa(deque_t *d) {
    d->inicio = NULL;
    d->fim = NULL;
    d->tamanho = 0;
}


// Inserir
void push_front(deque_t *d, char dado){
    nodo_t *novo;
    novo=malloc(sizeof(nodo_t));

    novo->dado=dado;
    if(d->tamanho==0){
        novo->ant=NULL;
        novo->prox=NULL;
        d->inicio=novo;
        d->fim=novo;
    }
    else{
        novo->ant=NULL;
        novo->prox=d->inicio;
        d->inicio->ant=novo;
        d->inicio=novo;
    }
    d->tamanho=d->tamanho+1;
}
void push_back(deque_t *d, char dado){
    nodo_t *novo;
    novo=malloc(sizeof(nodo_t));

    novo->dado=dado;
    if(d->tamanho==0){
        novo->ant=NULL;
        novo->prox=NULL;
        d->inicio=novo;
        d->fim=novo;
    }
    else{
        novo->prox=NULL;
        novo->ant=d->fim;
        d->fim->prox=novo;
        d->fim=novo;
    }
    d->tamanho=d->tamanho+1;
}

// Remover
void pop_front(deque_t *d){
        nodo_t *removido;

    if(d->tamanho==0)
        return;

    removido=d->inicio;

    if(d->tamanho==1){
        d->inicio=NULL;
        d->fim=NULL;
    }
    else{
        d->inicio=d->inicio->prox;
        d->inicio->ant=NULL;
    }

    d->tamanho=d->tamanho-1;
    free(removido);

}
void pop_back(deque_t *d){
    nodo_t *removido;

    if(d->tamanho==0)
        return;

    removido=d->fim;

    if(d->tamanho==1){
        d->inicio=NULL;
        d->fim=NULL;
    }
    else{
        d->fim=d->fim->ant;
        d->fim->prox=NULL;
    }

    d->tamanho=d->tamanho-1;
    free(removido);
}

// Consultar
char front(deque_t *d){
    return (d->inicio->dado);

}
char back(deque_t *d){
    return (d->fim->dado);
}

int main(){
    char palavra[500],prim,ult;
    char letras[]="abcdefghijklmnopqrstuvwxyz"; // Todas as letras do alfabeto
    deque_t palindromo;
    int i,j,n;


    do{
        printf("Digite a palavra ou frase (sem acentos): ");    // Recebe a palavra
        fgets(palavra,500,stdin);
    }while(strcmp(palavra,"\n")==0);

    n=strlen(palavra)-1;                      // A capacidade da lista palindromo e no maximo o tamanho da palavra
    inicializa(&palindromo);

    for(i=0;i<n;i++){                       // Testa se os elementos a ser inseridos na lista palindromo sao só letras, neste caso minusculas
        for(j=0;j<27;j++){
            if(tolower(palavra[i])==letras[j]){
                push_back(&palindromo,tolower(palavra[i]));
            }
        }
    }

    while(palindromo.tamanho > 1){          // Testa se a ultima letra e a primeira letra do palindromo sao iguais e as remove se forem
        prim=front(&palindromo);
        ult=back(&palindromo);
        if(prim!=ult){
            printf("\nNao e palindromo!\n");
            break;
        }
        pop_front(&palindromo);
        pop_back(&palindromo);
    }

    if(palindromo.tamanho<=1){              // Se restar somente um elemento ou nenhum na lista palindromo, a palavra digitada e um palindromo
        printf("\nE palindromo\n");
    }

    return 0;
}
