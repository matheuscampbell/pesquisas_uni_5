#ifndef  LISTA_H
#define  LISTA_H

typedef struct Celula{
  Dado dado;
  struct Celula *prox;
}Celula;

Celula *new_celula(Dado dado){
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->dado = dado;
  tmp->prox = NULL;

  return tmp;
}

//========================================
typedef struct Lista{
  Celula *inicio;
  Celula *fim;
  int tam;
}Lista;
//========================================
void new_lista(Lista *l){

  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->prox = NULL;

  l->inicio = l->fim = tmp;
  l->tam = 0;
}
//========================================
void add(Lista *l, Dado dado){

  Celula *tmp = new_celula(dado);
  l->fim->prox = tmp;
  l->fim = tmp;
  l->tam++;
}
//========================================



void pesquisa_lista(Lista *l, int item){

    Celula *tmp = l->inicio->prox;
    while(tmp != NULL){
      if(tmp->dado.cod_municipio == item)
        printDado(tmp->dado);
        comparacoes++;
      tmp = tmp->prox;
    }

    Dado a;
    a.cod_municipio = -1;
    strcpy(a.municipio, "nao achou");

    return a;
}

void print_lista(Lista *l){

    Celula *tmp = l->inicio->prox;

    while(tmp != NULL){
        printDado(tmp->dado);
      tmp = tmp->prox;
    }
}


//========================================
#endif
