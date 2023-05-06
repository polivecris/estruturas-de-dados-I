// Cristiane de Paula Oliveira - 261426
// Estrutura de Dados I - Lab 2

struct eventos_atm_st {
  float temp;
  float press;
  int choveu;
  int mm_prec;
  char nome[201];
};

#include<stdio.h>
#include<string.h>
// Ler os valores e armazenar em uma estrutura
void ler_estrutura(struct eventos_atm_st *estrutura){
  printf("Qual a temperatura? ");
  scanf("%f", &estrutura->temp);
  printf("Qual a pressao? ");
  scanf("%f", &estrutura->press);
  printf("Choveu? ");
  scanf("%d", &estrutura->choveu);
  printf("Quantos mm de precipitacao? ");
  scanf("%d", &estrutura->mm_prec);
  printf("Qual o nome da pessoa? ");
  fflush(stdin);
  fgets(estrutura->nome,201,stdin);
}

// Editar uma estrutura
void editar_estrutura(struct eventos_atm_st *estrutura){
  printf("Qual a temperatura? ");
  scanf("%f", &estrutura->temp);
  printf("Qual a pressao? ");
  scanf("%f", &estrutura->press);
  printf("Choveu? ");
  scanf("%d", &estrutura->choveu);
  printf("Quantos mm de precipitacao? ");
  scanf("%d", &estrutura->mm_prec);
  printf("Qual o nome da pessoa? ");
  fflush(stdin);
  fgets(estrutura->nome,201,stdin);
}

// Exibir os dados de uma estrutura
void exibir_estrutura(struct eventos_atm_st estrutura, int n){
  printf("No dia %d\n", n);
  printf("A temperatura foi de %.2f C\n", estrutura.temp);
  printf("A pressao foi de %.2f atm\n", estrutura.press);
  if(estrutura.choveu==0){
    printf("Não choveu\n");
  }
  else{
    printf("Choveu %d mm\n", estrutura.mm_prec);
  }
}

// Retornar a quantidade de mm de precipitação
int pegar_mm_prec(struct eventos_atm_st estrutura){

}


int main(){
  int i, n;
  int opcao;

  struct eventos_atm_st eventos_atm[2];

  // Ler os 7 dias da semana
  //>>>>>>>>>ATENCAO POR ENQUANTO SÓ ESTÁ LENDO 2<<<<<<<
  for(i=0;i<2;i++){
    printf("DIA %d\n", i+1);
    ler_estrutura(&(eventos_atm[i]));
  };

  opcao=0;
  do{
    printf("\nESCOLHA UMA OPCAO\n1. Editar dia\n2. Exibir dia\n3. Exibir mm\n4. Sair\n");
    scanf("%d",&opcao);

    // 1. Editar um dos dias (uma das sete estruturas);
    if(opcao==1){
      printf("\nQUAL DIA QUER EDITAR? ");
      scanf("%d",&n);
      editar_estrutura(&(eventos_atm[(n-1)]));
    }

    // 2. Exibir um dos dias (uma das sete estruturas);
    else if(opcao==2){
      printf("\nQUAL DIA QUER EXIBIR? ");
      scanf("%d",&n);
      exibir_estrutura(eventos_atm[n],(n-1));
    }

    // 3. Exibir a quantidade de mm de precipitação em um dos dias (uma das sete estruturas).
    else if(opcao==3){
      printf("\nQUAL DIA QUER EXIBIR PRECIPITACAO? ");
      scanf("%d",&n);
    }
  }while(opcao!=4);
  printf("Volte Logo\n");

}
