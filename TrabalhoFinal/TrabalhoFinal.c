//Cristiane de Paula Oliveira - 261424
// Estrutura de Dados
// Trabalho Final

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Bibliotecas criadas para esse trabalho
//#include"arvores.h" :(
#include"grafos.h"
#include"fila.h"

// FUNCOES
void imprime_opcoes(void){
  printf("\nO que voce deseja fazer?\n");
  printf("[1] Inserir ou remover pessoas.\n");
  printf("[2] Inserir ou remover dividas entre pessoas.\n");
  printf("[3] Encontrar uma pessoa por nome.\n");
  printf("[4] Listar todas as dividas ou emprestimos de determinada pessoa.\n");
  printf("[5] Listar as 10 ultimas transacoes.\n");
  printf("[6] Salvar estado atual em arquivo.\n");
  printf("[0] Sair.\nResposta: ");
}

char *leitura(){
  // Essa funcao nao esta funcionando
  char aux[500];
  char *strng;
  do{
    fgets(aux,500,stdin);
  }while(strcmp(aux,"\n")==0);
  strng=malloc((strlen(aux)+1)*sizeof(char));
  strcpy(strng,aux);
  strng[strlen(strng)-1] = '\0';

  return strng;
}

int verifica_login(char *login){
  int i,j, count=0;
  char alfanum[]="abcdefghijklmnopqrstuvwxyz1234567890_";
  for(i=0;i<strlen(login);i++){
    for(j=0;j<strlen(alfanum);j++){
      if(login[i]==alfanum[j])
	count=1;
    }
  }
  if(count==0){
    printf(">>>Insira somente letras minusculas, numeros ou \"_\".\n");
    return 0;
  }
  else if(count==1)
    return 1;
}

int verifica_nome(char *nome){
  // Funcao que verifica se o nome possui caracteres de 'A' a 'Z', 'a' a 'z' e espeços ' '.
  int i,j, count=0;
  char alfanum[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
  for(i=0;i<strlen(nome);i++){      // Percorre cada caractere do nome
    for(j=0;j<strlen(alfanum);j++){ // Percorre cada caractere da lisra de permitidos
      if(nome[i]==alfanum[j])
 	count=1;   // O caractere pertence
    }
  }
  if(count==0){ // Se o caractere não faz parte da lista de caracteres permitidos
    printf(">>>Insira somente letras (maiusculas ou minusculas) e espacos.\n");
    return 0;
  }
  else if(count==1)
    return 1;
}


// FUNCAO MAIN
int main(){
  lista_vertices grafo;
  pessoa_t pessoa;
  elem_pessoa *result_busca;
  transacao trans;
  fila_t dez_ult;

  char aux[500];
  int teste_login;
  int op=1, resp;

  inicializa_grafo(&grafo);
  inicializa_fila(&dez_ult);

  printf("Bem-vindo!");
  do{
    imprime_opcoes();
    scanf("%d",&op);

    switch(op){
    case 1: //REGISTRO OU DESREGISTRO
      // Inserir ou remover pessoas
      printf("\t[1]Inserir\n\t[2]Remover\n" );
      printf("Resposta: ");
      scanf("%d",&resp);
      if(resp==1){
	do{
	  printf("Login: ");
	  pessoa.login=leitura();
	  teste_login=verifica_login(pessoa.login);
	  result_busca=busca_login(&grafo,pessoa.login);
	  if(result_busca != NULL)
	    printf(">>>Login ja existente! Tente outro\n");
    }while(teste_login==0 || result_busca != NULL);

    printf("Nome: ");
    pessoa.nome=leitura();
    insere_vertice(&grafo, pessoa);
      }
      else if(resp==2){
        printf("Login: ");
        pessoa.login=leitura();
        remove_vertice(&grafo,pessoa.login);
      }
      else
        printf(">>>Escolha uma opcao valida!\n" );
        break;
    case 2:
      // Inserir ou remover dividir
      printf("\t[1]Inserir\n\t[2]Remover\n");
      printf("Resposta: ");
      scanf("%d",&resp);
      if(resp==1){
        printf("Quem deve: ");
        trans.login_A=leitura();
        printf("Para quem deve: ");
        trans.login_B=leitura();
        printf("Quanto deve: ");
        scanf("%f",&trans.peso);
        enqueue(&dez_ult,trans);
        vincular_vertices(&grafo,trans.login_A,trans.login_B,trans.peso);
      }
      else if(resp==2){
	printf("Infelizmente ainda nao implementado, desculpa :( \n");
      }
      else
	printf(">>>Escolha uma opcao valida!\n");
      break;
    case 3: // PESQUISA POR NOME
      printf("Infelizmente ainda nao implementado, desculpa :( \n" );
      break;
    case 4: // BALANCO ATUAL
      printf("Infelizmente ainda nao implementado, desculpa :( \n" );
      break;
    case 5:   // LISTAS DAS 10 ULTIMAS TRANSAÇÕES
      printf("Ultimas transacoes:\n");
      imprime_fila(&dez_ult);
      break;
    case 6:  // SALVA E CARREGA DE ARQUIVOS
      printf("Infelizmente ainda nao implementado, desculpa :(\n");
      break;
    case 0:
      printf("Obrigado(a) por utilizar nosso sistema!\n");
      break;
    default:
      printf(">>>Escolha uma opcao valida!\n" );
    }
  }while(op!=0);

  // FUNCOES ADICIONAIS
  // 1. Nomes similares: Imprime todas as folhas que partem daquela raiz
  // 2. Lista ordenada: Armazena os login em ordem alfabetica
  // 3. Detalhamento nas dívidas: Só colocar uma string a mais nos dados dos nodos
  // 4. Busca de login: Em árvores binárias

  return 0;
}

