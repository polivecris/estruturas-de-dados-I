// Arquivo com funções que serão utilizadas para trabalhar com listas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//  ESTRUTURAS
struct transacao_st{
    char *login_A;
    char *login_B;
    float peso;
};
typedef struct transacao_st transacao;

struct nodo_fila_st {
    transacao dado;
    struct nodo_fila_st *ant;
    struct nodo_fila_st *prox;
};
typedef struct nodo_fila_st nodo_fila_t;

struct fila_st {
     nodo_fila_t *inicio;
     nodo_fila_t *fim;
     int tamanho;
};
typedef struct fila_st fila_t;


// FUNCOES
void inicializa_fila(fila_t *f){
    // Inicializar
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void dequeue(fila_t *f){
    // Remover do inicio
    nodo_fila_t *removido;

    if(f->tamanho==0)
        return;

    removido=f->inicio;

    if(f->tamanho==1){
        f->inicio=NULL;
        f->fim=NULL;
    }
    else{
        f->inicio=f->inicio->prox;
        f->inicio->ant=NULL;
    }

    f->tamanho=f->tamanho-1;
    free(removido);

}

void enqueue(fila_t *f, transacao dado){
    // Inserir no final:
    nodo_fila_t *novo;
    novo=malloc(sizeof(nodo_fila_t));

    novo->dado=dado;
    if(f->tamanho==0){
        novo->ant=NULL;
        novo->prox=NULL;
        f->inicio=novo;
        f->fim=novo;
    }
    else{
        novo->prox=NULL;
        novo->ant=f->fim;
        f->fim->prox=novo;
        f->fim=novo;
    }
    f->tamanho=f->tamanho+1;
    if(f->tamanho>10)
    	dequeue(f);
}

transacao front(fila_t *f){
    // Consultar o elemento da frente
    return (f->inicio->dado);
}

void imprime_fila(fila_t *f){
  // Imprimir lista das 10 ultimas transacoes
  transacao aux;
  int i=0;

  do{
    aux=front(f); // Armazena o primeiro da fila
    printf("%d. %s pagou R$ %.2f para %s.\n",i+1,aux.login_A,aux.peso,aux.login_B);
    dequeue(f); // Remove o primeiro da fila
    enqueue(f,aux); // Insere novamente no final
    i++;
  }while(i<f->tamanho); // Repete o processo 10 vezes
}
