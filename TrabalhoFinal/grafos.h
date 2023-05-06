// Arquivo com estruturas e funções que serão utilizadas para trabalhar com o grafo
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct pessoa_st{
  char *nome;
  char *login;
};
typedef struct pessoa_st pessoa_t;

struct elem_viz_st{
  struct elem_pessoa_st *pessoa;
  float peso;
  struct elem_viz_st *prox;
};
typedef struct elem_viz_st elem_viz;

struct lista_arestas_st{
  elem_viz *ini;
};
typedef struct lista_arestas_st lista_arestas;

struct elem_pessoa_st{
  struct pessoa_st pessoa;
  struct elem_pessoa_st *prox;
  struct lista_arestas_st vizinhos;
};
typedef struct elem_pessoa_st elem_pessoa;

struct lista_vertices_st{
  elem_pessoa *ini;
};
typedef struct lista_vertices_st lista_vertices;

void inicializa_grafo(lista_vertices *l){
  l->ini = NULL;
}

void inicializa_aresta(lista_arestas *l){
  l->ini = NULL;
}

int insere_vertice(lista_vertices *l, pessoa_t usuario){
  elem_pessoa *novo = NULL; // Ponteiro para novo elemento
  elem_pessoa *ant = NULL; // Aux. para a posição anterior
  elem_pessoa *aux = l->ini; // Aux. para percorrer a lista

  novo = malloc(sizeof(elem_pessoa)); // Aloca um novo nodo

  if (novo == NULL) {
    printf("Erro!\n");
    return 0; // Falta de memoria!
  }

  novo->pessoa = usuario;

  // Procura o final da lista
  while(aux != NULL) {
    ant = aux;
    aux = aux->prox;
  }
  // Encadeia o elemento
  if (ant == NULL) { //Insere no inicio (lista vazia)
    novo->prox = l->ini;
    l->ini = novo;
  } else { // Insere no final da lista
    novo->prox = ant->prox;
    ant->prox = novo;
  }

  inicializa_aresta(&(novo->vizinhos)); // Inicializa lista de vizinhos
  printf("Inserido com sucesso!\n");
  return 1; // Sucesso!
}

int remove_vertice(lista_vertices *l, char *login){
  // Funcao para remover um vertice do grafo
  elem_pessoa *ant = NULL; // Aux. para a posição anterior
  elem_pessoa *aux = l->ini; // Aux. para percorrer a lista

  // Procura o elemento na lista
  while(aux != NULL && strcmp((aux->pessoa.login),login) != 0) {
    ant = aux;
    aux = aux->prox;
  }
  if(aux == NULL){ //Se não achou
    printf("Usuario nao encontrado!\n");
    return 0;
  }
  if(ant == NULL) { // Vai remover o primeiro elemento
    l->ini = aux->prox;
  }
  else {          // Vai remover do meio ou do final
    ant->prox = aux->prox;
  }

  // Falta remover da lista de vizinhos de outros vértices

  free(aux); // Libera a memória alocada
  printf("Removido com sucesso!\n");
  return 1;
}

elem_pessoa *busca_login(lista_vertices *l,char *login){
  elem_pessoa *aux = l->ini; // Aux. para percorrer a lista

  while (aux != NULL && strcmp(aux->pessoa.login,login)!=0){
    aux = aux->prox;
  }
  if (aux != NULL){
    return aux;
  }
  else
    return NULL;
}

int insere_aresta(lista_arestas *l, elem_pessoa *pessoa, float peso){
  // Funcao para inserir aresta
  elem_viz *novo = NULL; // Ponteiro para novo elemento
  elem_viz *ant = NULL; // Aux. para a posição anterior
  elem_viz *aux = l->ini; // Aux. para percorrer a lista

  novo = malloc(sizeof(elem_viz)); // Aloca um novo nodo

  if (novo == NULL) {
    printf(">>>Erro!\n");
    return 0; // Falta de memoria!
  }

  novo->pessoa = pessoa;
  // Procura o final da lista
  while(aux != NULL) {
    ant = aux;
    aux = aux->prox;
  }
  // Encadeia o elemento
  if (ant == NULL) { //Insere no inicio (lista vazia)
    novo->prox = l->ini;
    l->ini = novo;
  } else { // Insere no final da lista
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  printf("Inserido com sucesso!\n");
  return 1; // Sucesso!
}

int vincular_vertices(lista_vertices *l, char *login_origem, char *login_destino, float peso){
  // Essa função tem como objetivo encontrar dois vertices no grafo a partir do login e criar um vinculo entre eles
  elem_pessoa *origem;
  elem_pessoa *destino;

  origem=malloc(sizeof(elem_pessoa)); // Aloca memória para elemento
  destino=malloc(sizeof(elem_pessoa));

  origem=busca_login(l,login_origem); // Busca login na lista de vertices
  destino=busca_login(l,login_destino);

  insere_aresta(&(origem->vizinhos),destino,peso);   // Insere aresta entre os vertices
  insere_aresta(&(destino->vizinhos),origem,(-peso));
}

pessoa_t *consulta_vizinhos(lista_vertices *l, char *login){
  // Essa funcao tem como objetivo localizar um usuario por login e consultar seus vizinhos,
  // ou seja, suas dívidas e emprestimos
}
