//Cristiane de Paula Oliveira
// Estrutura de Dados - U
// Laboratório 10

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo_st{
  char nome[100];
};
typedef struct nodo_st nodo_t;

//struct vizinhos_st{
//    nodo_t dados;
//    struct vizinhos_st *prox;
//};
//typedef struct vizinhos_st vizinhos_t;

//struct elem_st{
//    nodo_t dado;
//    struct elem_st *prox;
//    vizinhos_t *viz;
//};
//typedef struct elem_st elem_t;

//struct lista_st{
//    elem_t *ini;
//};
//typedef struct lista_st lista_t;

struct dijkstra_st{
    nodo_t id;
    int dist;
    nodo_t *ant;
    char vis;
};
typedef dijkstra_st dijkstra_t;

// FUNÇÂO QUE CALCULA CAMINHO MÍNIMO PELO ALGORISMO DE DIJKSTRA
void dijkstra(nodo_t *nodos, int *arestas, int origem, int destino, n){
  int i, j;
  int INFINITO=2147483647;
  dijkstra_t caminho[n];
  
  for(i=0;i<n;i++){
    caminho[n].id=nodos[i];
    if(i==0){
      caminho[i].dist=0;
    }
    else
      caminho.dist=INFINITO;
    caminho[i].ant;
  }

  // Visita nó de origem;
  // Enquanto há nós não visitados:
  // Verifica todos os vizinhos deste nodo e atualiza distância a origem;
  // Adiciona nodo atual como antecessor;
  // Seleciona nodo de menor custo;
  // Visita o nodo de menor custo;
}

int main(){
  int i, j, N=3;
  char aux[100];
  int distancia;

  // Grafo: Matriz de adjacências
  int arestas[N][N];
  nodo_t nodos[N];

  //Leitura dos nomes
  for(i=0;i<N;i++){
    printf("Nome da cidade: ");
    do{
      fgets(nodos[i].nome,100,stdin);
    }while(strcmp(nodos[i].nome,"\n")==0);
    //Seria legal uma função para remover o \n do fim dos nomes
  }

  //Leitura das distâncias
  for(i=0;i<3;i++){
    for(j=1;j<3;j++){
      if(i<j){
	printf("Distancia de %s a %s: ", nodos[i].nome, nodos[j].nome);
	scanf("%d",&arestas[i][j]);
      }
    }
  }


  // Implementação do algoritmos de Dijkstra

  return 0;
}

