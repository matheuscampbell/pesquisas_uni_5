#ifndef ARVOREBINARIA_INCLUDED
#define ARVOREBINARIA_INCLUDED
//==================================================

//==================================================

typedef struct No {
    Dado elemento;
    int bal;
	struct No *esq, *dir;
} No;

No* novoNo(Dado elemento) {
   No* novo = (No*) malloc(sizeof(No));
   novo->elemento = elemento;
   novo->esq = NULL;
   novo->dir = NULL;
   return novo;
}

typedef struct ArvBin {
    No * raiz;
} ArvBin;

void create_arvbin(ArvBin *arv) {
   arv->raiz = NULL;
}


bool pesquisarRec(int x, No* i) {
   bool resp;
   if (i == NULL) {
      resp = false;

   } else if (x == i->elemento.cod_municipio) {
      resp = true;
      comparacoes++;
      printDado(i->elemento);

   } else if (x < i->elemento.cod_municipio) {
      resp = pesquisarRec(x, i->esq);

   } else {
      resp = pesquisarRec(x, i->dir);
   }
   return resp;
}

bool pesquisar(ArvBin *arv, int x) {
   return pesquisarRec(x, arv->raiz);
}




void caminharCentralRec(No* i) {
   if (i != NULL) {
      caminharCentralRec(i->esq);
      printDado(i->elemento);
      caminharCentralRec(i->dir);
   }
}

void caminharCentral(ArvBin *arv) {
   printf("[ ");
   caminharCentralRec(arv->raiz);
   printf("]\n");
}



void caminharPreRec(No* i) {
   if (i != NULL) {
      printf("%d ", i->elemento);
      caminharPreRec(i->esq);
      caminharPreRec(i->dir);
   }
}

void caminharPre(ArvBin *arv) {
   printf("[ ");
   caminharPreRec(arv->raiz);
   printf("]\n");
}



void caminharPosRec(No* i) {
   if (i != NULL) {
      caminharPosRec(i->esq);
      caminharPosRec(i->dir);
      printf("%d ", i->elemento);
   }
}

void caminharPos(ArvBin *arv) {
   printf("[ ");
   caminharPosRec(arv->raiz);
   printf("]\n");
}


void inserirRec(Dado x, No** i) {
    //printf("%d - %d \n",x.cod_municipio, &(*i)->elemento.cod_municipio);
   if (*i == NULL) {
      *i = novoNo(x);
   } else if (x.cod_municipio < (*i)->elemento.cod_municipio) {
      inserirRec(x, &((*i)->esq));

   } else if (x.cod_municipio > (*i)->elemento.cod_municipio) {
      inserirRec(x, &((*i)->dir));

   } else {
     // printf( "\nErro ao inserir!\n");
   }
}

void inserirBin(ArvBin *arv, Dado x) {
   inserirRec(x, &arv->raiz);
}



void antecessor(No** i, No** j) {
   if ((*j)->dir != NULL) {
      antecessor(i, &((*j)->dir));

   } else {
      No* del = *j;
      (*i)->elemento = (*j)->elemento;
      (*j) = (*j)->esq;
      free(del);
   }
}





//==================================================
#endif //
