// Cristiane de Paula Oliveira - 261424
// Estrutura de Dados I - Laboratorio 4
// Contando Estrelas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct estrelas_st{
    int id;
    char cor;
    float dist;
};
typedef struct estrelas_st estrelas_t;

struct lista_cntg_st {
    int ini;
    int fim;
    int cap;
    struct estrelas_st *dados;
};
typedef struct lista_cntg_st lista_cntg_t;

// Inicializar lista
void inicializa(struct lista_cntg_st *l, int cap) {
    l->ini = -1;
    l->fim = -1;
    l->cap = cap;
    l->dados = malloc(cap * sizeof(struct estrelas_st));
}

// Destruir lista
void destroi(lista_cntg_t *l) {
    l->ini = -1;
    l->fim = -1;
    l->cap = 0;
    free(l->dados);
    l->dados = NULL;
}

// Exibir tamanho da lista
int tamanho(lista_cntg_t l){
    if (l.ini == -1 || l.fim == -1) //Lista vazia, tamanho 0
        return 0;

    return (l.fim - l.ini) + 1;
}

// Inserir na lista
int insere(lista_cntg_t *l, struct estrelas_st novo, int pos) {
    int i;
    if (l->cap == tamanho(*l)) return 0; //lista cheia
    if (pos > tamanho(*l) || pos < 0) return 0; //posição inválida

    if (l->ini == -1){ //Lista previamente vazia, inicializar início e fim
        l->ini = 0;
        l->fim = 0;
    } else if (l->fim < l->cap - 1) { //Tem espaço no final
        for (i=l->fim; i >= l->ini + pos; i--)
            l->dados[i+1] = l->dados[i];
        l->fim++;
    } else { //Tem espaço no começo
        for (i=l->ini; i < l->ini + pos; i++)
            l->dados[i-1] = l->dados[i];
        l->ini--;
    }
    l->dados[l->ini + pos] = novo;
    return 1;
}

// Remover da lista
int remover(lista_cntg_t *l, int pos) {
    int i;
    if (pos >= tamanho(*l) || pos < 0) return 0; //posição inválida
    if (tamanho(*l) == 1){ //Lista só tinha 1 elemento, agora ficou vazia
        l->ini = -1;
        l->fim = -1;
        return 1;
    }
    for (i=l->ini + pos; i< l->fim; i++) //Puxa elementos do fim
        l->dados[i] = l->dados[i+1];
    l->fim--;

    return 1;
}

// Consultar na lista
struct estrelas_st *consultar(lista_cntg_t *l, int pos) {
    if (pos >= tamanho(*l) || pos < 0) return NULL; //Posição inválida
    return &l->dados[l->ini + pos];
}

// Alterar elemento na lista
int alterar(lista_cntg_t *l, struct estrelas_st novo, int pos) {
    struct estrelas_st *aux = consultar(l, pos);
    if (aux == NULL) return 0; //Posição inválida

    *aux = novo;
    return 1;
}

// Determinar posicao de insercao na lista
int posicao(lista_cntg_t*l, struct estrelas_st estrela){
    int pos;
    pos=0;
        while(l->dados[pos].dist<estrela.dist && pos<= l->fim){
            pos++;
        }
    return pos;
}

int main(){
    lista_cntg_t estrelas_lista;
    int cap, pos, count;
    int i,j,n_elem;
    int existe;
    float soma;
    struct estrelas_st estrela;
    struct estrelas_st *info;


    //printf("Numero MAXIMO de estrelas: ");
    //scanf("%d",&cap);
    //estrelas_lista.dados=malloc(cap*sizeof(struct estrelas_st));

    printf("Quantas estrelas? ");
    scanf("%d", &n_elem);
    inicializa(&estrelas_lista, n_elem);

    for(i=0;i<n_elem;i++){
        printf("Qual a cor da estrela %d? ",i+1);
        do{
            scanf("%c",&estrela.cor);
        }while(estrela.cor=='\n');
        printf("Qual a distancia da estrela %d? ",i+1);
        scanf("%f",&estrela.dist);
        printf("Qual a identificacao da estrela %d? ",i+1);
        scanf("%d",&estrela.id);

        if(tamanho(estrelas_lista)==0)
        {
            if(insere(&estrelas_lista,estrela,0)){
                printf("Estrela adicionada com sucesso\n");
            }
            else
                printf("Erro!\n");
        }
        else
        {
            existe=0;
            for(j=estrelas_lista.ini;j<=estrelas_lista.fim;j++){
                if(estrela.id==estrelas_lista.dados[j].id){
                    existe++;
                }
            }
            if(existe==0){
                if(insere(&estrelas_lista,estrela,posicao(&estrelas_lista,estrela))){
                    printf("Estrela adicionada com sucesso\n");
                    }
                    else
                        printf("Erro\n");
            }
            else
                printf("Estrela repetida\n");
        }
    }

    // Numero de estrelas unicas
    printf("\nNumero de estrelas unicas: %d",tamanho(estrelas_lista));
    // Media
    soma=0;
    for(i=estrelas_lista.ini;i<=estrelas_lista.fim;i++)
        soma=soma+estrelas_lista.dados[i].dist;
    printf("\nMedia das distancias: %f", soma/tamanho(estrelas_lista));
    // Mediana
    if(tamanho(estrelas_lista)%2!=0){
        pos=tamanho(estrelas_lista)/2;

        info=consultar(&estrelas_lista,pos);
        if(info != NULL)
            printf("\nMediana das distancias: %f\n",info->dist);
        else
            printf("Erro!\n");
    }
    else{
        pos=tamanho(estrelas_lista)/2;
        info=consultar(&estrelas_lista,pos-1);
        printf("\nMediana das distancias: %f, ",info->dist);
        info=consultar(&estrelas_lista,pos);
        printf("%f",info->dist);
    }
    // Quartis
    pos=tamanho(estrelas_lista)/4;
    info=consultar(&estrelas_lista,pos);
    printf("\nQuartis: %f e ",info->dist);
    pos=(3*tamanho(estrelas_lista))/4;
    info=consultar(&estrelas_lista,pos);
    printf("%f",info->dist);

    // Estrelas mais proximas
    info=consultar(&estrelas_lista,0);
    printf("\n5 estrelas mais proximas: %d, ",info->id);
    info=consultar(&estrelas_lista,1);
    printf("%d, ",info->id);
    info=consultar(&estrelas_lista,2);
    printf("%d, ",info->id);
    info=consultar(&estrelas_lista,3);
    printf("%d, ",info->id);
    info=consultar(&estrelas_lista,4);
    printf("%d ",info->id);

    // Estrelas mais distantes
    info=consultar(&estrelas_lista,tamanho(estrelas_lista)-1);
    printf("\n5 estrelas mais distantes: %d, ", info->id);
    info=consultar(&estrelas_lista,tamanho(estrelas_lista)-2);
    printf("%d, ",info->id);
    info=consultar(&estrelas_lista,tamanho(estrelas_lista)-3);
    printf("%d, ",info->id);
    info=consultar(&estrelas_lista,tamanho(estrelas_lista)-4);
    printf("%d, ",info->id);
    info=consultar(&estrelas_lista,tamanho(estrelas_lista)-5);
    printf("%d ",info->id);

    // Estrelas mais quentes
    printf("\n3 estrelas mais quentes: ");

    // Destroi estrutura
    destroi(&estrelas_lista);
    return 0;
}
