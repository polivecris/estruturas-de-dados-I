// Arquivo com estruturas e funções que serão utilizadas para trabalhar com a árvore
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ESTRUTURAS
struct elem_nodo_st;
struct nodo_arvore_st;
struct lista_nodo_st;
struct lista_nomes_st;

struct nodo_arvore_st{
    char chave;
    struct lista_nodo_st *filhos;
    struct lista_nomes_st *nomes;
};

struct elem_nodo_st{
    struct nodo_arvore_st *nodo;
    struct elem_nodo_st *prox;
};

// FUNCOES

