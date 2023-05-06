// Cristiane de Paula Oliveira - 261424
// Estrutura de Dados I - Laboratorio 3
// Carteira
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct subcateg_st {
  char *nome_subcateg;
};

struct categoria_st {
  char *nome;
  int num_subcateg;
  struct subcateg_st *subcateg;
};

struct registro_st {
  int dia, mes, ano;
  float valor;
  char *desc;
  char *nome_categ;
  char *nome_subcateg;
};

int main(){
  int i,j,tam,num_categ, cat,subcat;
  char aux[500];
  struct categoria_st *categoria;
  struct registro_st *registro;

  // Le e adiciona categorias
  printf("Quantas categorias? ");
  scanf("%d",&num_categ);
  categoria=malloc(num_categ*sizeof(struct categoria_st));

  // Para cada categoria, le o nome e subcategorias
  for(i=0;i<num_categ; i++){
    printf("Qual o nome da categoria %d? ",i+1);
    do{
      fgets(aux,500,stdin);
    }while(strcmp(aux,"\n")==0);

    // Aloca memória para o nome da categoria 
    categoria[i].nome=malloc((strlen(aux)+1)*sizeof(char));
    strcpy(categoria[i].nome,aux);
    categoria[i].nome[strlen(categoria[i].nome)-1] = '\0';

    // Le e adiciona subcategorias
    printf("Quantas subcategorias? ");
    scanf("%d",&(categoria[i].num_subcateg));
    categoria[i].subcateg = malloc(categoria[i].num_subcateg*sizeof(struct subcateg_st));

    // Le o nome de cada subcategoria de uma categoria
    for(j=0;j<(categoria[i].num_subcateg);j++){
      printf("Qual o nome da subcategoria %d de %s? ",j+1,categoria[i].nome);
      do{
	fgets(aux,500,stdin);
      }while(strcmp(aux,"\n")==0);

      // Aloca memória para o nome da subcategoria
      (categoria[i].subcateg[j]).nome_subcateg=malloc((strlen(aux)+1)*sizeof(char));
      strcpy((categoria[i].subcateg[j]).nome_subcateg,aux);
      categoria[i].subcateg[j].nome_subcateg[strlen(categoria[i].subcateg[j].nome_subcateg)-1] = '\0';
    }

  }

  // Agora vamos trabalhar com registros
  printf("\nPronto, agora diga quantos gastos voce quer registrar: ");
  scanf("%d",&tam);
  
  // Aloca memória para o registro de gastos
  registro=malloc(tam*sizeof(struct registro_st));

  for(i=0;i<tam;i++){
    // Categorias
    printf("\nEscolha uma categoria para registrar um gasto: ");
    printf("\nAs categorias sao:");
    for(j=0;j<num_categ;j++){
      printf("\n%d. %s",j+1,categoria[j].nome);
    }
    printf("\nQual categoria voce quer? ");
    scanf("%d",&cat);
    cat=cat-1;
    
    // Aloca memória para nome da categoria no registro
    registro[i].nome_categ=malloc(sizeof(categoria[cat].nome));
    strcpy(registro[i].nome_categ,categoria[cat].nome);

    // Subcategorias
    printf("\nAs subcategorias de %s sao: ",registro[i].nome_categ);
    for(j=0;j<categoria[cat].num_subcateg;j++){
      printf("\n%d. %s",j+1,categoria[cat].subcateg[j].nome_subcateg);
    }
    printf("\nQual subcategoria voce quer? ");
    scanf("%d",&subcat);
    subcat=subcat-1;
    // Aloca memória para nome da subcategoria no registro
    registro[i].nome_subcateg=malloc(sizeof(categoria[cat].subcateg[subcat].nome_subcateg));
    strcpy(registro[i].nome_subcateg,categoria[cat].subcateg[subcat].nome_subcateg);

    // Registra a data do gasto, o valor e a descricao
    printf("\nVoce selecionou %s>%s\n",registro[i].nome_categ,registro[i].nome_subcateg);
    printf("Digite o dia do gasto: ");
    scanf("%d",&registro[i].dia);
    printf("Digite o mes do gasto: ");
    scanf("%d",&registro[i].mes);
    printf("Digite o ano do gasto: ");
    scanf("%d",&registro[i].ano);
    printf("Qual o preco? ");
    scanf("%f",&registro[i].valor);
    printf("Descricao: ");
    do{
      fgets(aux,500,stdin);
    }while(strcmp(aux,"\n")==0);
    registro[i].desc=malloc((strlen(aux)+1)*sizeof(char));
    strcpy(registro[i].desc,aux);
  }
  
  // Liberar TODA memória alocada
  for(i=0;i<tam;i++){
    free(registro[i].nome_categ);
    free(registro[i].nome_subcateg);
    free(registro[i].desc);
  }  
  free(registro);

  for(i=0;i<num_categ;i++){
    for(j=0;j<(categoria[i].num_subcateg);j++){
      free(categoria[i].subcateg[j].nome_subcateg);
    }
    free(categoria[i].subcateg);
    free(categoria[i].nome);
  }
  free(categoria);
  return 0;
}
