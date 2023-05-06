// Cristiane de Paula Oliveira - 261424
// Estrutura de Dados
// Laboratório 7 - Lista de alunos

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct dados_st {
    int chave;
    char nome[100];
} dados_t;

typedef struct nodo_st {
    dados_t dados;
    struct nodo_st* esq;
    struct nodo_st* dir;
} nodo_t;

nodo_t* inserir(dados_t novo, nodo_t* raiz)
{
   if (raiz == NULL) {
      nodo_t* aux = (nodo_t*) malloc(sizeof(nodo_t));
      aux->esq = NULL;
      aux->dir = NULL;
      aux->dados = novo;
      raiz = aux;
   } else {
      if (novo.chave >= raiz->dados.chave)
         raiz->dir=inserir(novo, raiz->dir);
      else
         raiz->esq=inserir(novo, raiz->esq);
   }
   return raiz;
}

nodo_t* pesquisar(int x, nodo_t* raiz)
{
   if (raiz == NULL) {
      printf("Aluno nao encontrado!\n");
      return NULL;
   }

   if (x == raiz->dados.chave){
        printf("Aluno: %sCartao: %d\n",raiz->dados.nome,raiz->dados.chave);
        return raiz;
   }

   if (x > raiz->dados.chave)
      return pesquisar(x, raiz->dir);
   else
      return pesquisar(x, raiz->esq);
}

nodo_t *remover(int chave, nodo_t* raiz){
   nodo_t *aux, *aux_pai;
   if (raiz == NULL) {
        printf("Aluno nao encontrado!\n");
        return NULL;
   } else // esta' no nodo certo?
   if (chave == raiz->dados.chave) {
        printf("Aluno: %sCartao: %d\n",raiz->dados.nome,raiz->dados.chave);
      if (raiz->esq == NULL &&
          raiz->dir == NULL) {
           free(raiz);

            return NULL;
      } else if (raiz->esq == NULL) {
            aux=raiz->dir;
            free(raiz);
            return aux;
      } else if(raiz->dir == NULL) {
            aux = raiz->esq;
            free(raiz);
            return aux;
      } else {
          aux = raiz->dir;
        aux_pai = raiz; //pai do aux

            while(aux->esq != NULL) {
               aux_pai = aux;
               aux = aux->esq;
            }

            aux->esq = raiz->esq;
            aux_pai->esq = aux->dir;

            if(aux != raiz->dir)
              aux->dir = raiz->dir;
            free(raiz);
            return aux;
      }
   } else {
   if (chave > raiz->dados.chave) {
      raiz->dir=remover(chave, raiz->dir);
   } else {
      raiz->esq=remover(chave, raiz->esq);
   }

   return raiz;
    }
}

nodo_t* destruir(nodo_t *raiz){
    if (raiz != NULL){
        destruir(raiz->esq); // libera sae
        destruir(raiz->dir); // libera sad
        free(raiz);         // libera raiz
    }
    return NULL;
}

int main(){
    dados_t aluno;
    nodo_t arvore_alunos;

    printf("LISTA DE ALUNOS\n");

    printf("*Insercao\n");
    do{
        printf("Cartao: ");
        scanf("%d",&aluno.chave);

        if(aluno.chave!=0){
            printf("Nome: ");
            do{
                fgets(aluno.nome,100,stdin);
            }while(strcmp(aluno.nome,"\n")==0);
            inserir(aluno,&arvore_alunos);
        }
    }while(aluno.chave!=0);

    printf("*Consulta\n");
    do{
        printf("Qual aluno consultar? ");
        scanf("%d",&aluno.chave);
        if(aluno.chave!=0){
            pesquisar(aluno.chave, &arvore_alunos);
        }
    }while(aluno.chave!=0);

    printf("*Remocao\n");
    do{
        printf("Qual aluno remover? ");
        scanf("%d",&aluno.chave);
        if(aluno.chave!=0){
            remover(aluno.chave, &arvore_alunos);
        }
    }while(aluno.chave!=0);

    return 0;
}
