#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED


int altura(No* t) {
  if (t == NULL)
    return 0;
  int hesq = altura(t->esq);
  int hdir = altura(t->dir);
  return hesq > hdir ? hesq + 1 : hdir + 1;
}

No* criarAvl(Dado v, No* esq, No* dir) {
  No* n = (No*) malloc (sizeof(No));
  n->elemento = v;
  n->bal = altura(dir) - altura(esq);
  n->esq = esq;
  n->dir = dir;
  return n;
}

int verifica_AVL(No* t) {
  if (t == NULL)
    return 1;
  return abs(altura(t->dir) - altura(t->esq)) <= 1;
}

void inserirAvl(No* r) {
  if (r != NULL) {
    inserirAvl(r->esq);
    inserirAvl(r->dir);
  }
}

void inserirAvl_verifica(No* t) {
  if (!verifica_AVL(t))
    printf("Não é AVL!\n");
  inserirAvl(t);
  printf("\n");
}

void LL(No** r) {
  No* b = *r;
  No* a = b->esq;
  b->esq = a->dir;
  a->dir = b;
  a->bal = 0;
  b->bal = 0;
  *r = a;
}

void RR(No** r) {
  No* a = *r;
  No* b = a->dir;
  a->dir = b->esq;
  b->esq = a;
  a->bal = 0;
  b->bal = 0;
  *r = b;
}

void LR(No** r) {
  No *c = *r;
  No *a = c->esq;
  No *b = a->dir;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  switch(b->bal) {
  case -1:
    a->bal = 0;
    c->bal = 1;
    break;
  case 0:
    a->bal = 0;
    c->bal = 0;
    break;
  case +1:
    a->bal = -1;
    c->bal = 0;
    break;
  }
  b->bal = 0;
  *r = b;
}

void RL(No** r) {
  No *a = *r;
  No *c = a->dir;
  No *b = c->esq;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  switch(b->bal) {
  case -1:
    a->bal = 0;
    c->bal = 1;
    break;
  case 0:
    a->bal = 0;
    c->bal = 0;
    break;
  case +1:
    a->bal = -1;
    c->bal = 0;
    break;
  }
  b->bal = 0;
  *r = b;
}

int aux_insereAVL(No** t, Dado v, int *cresceu) {
  if (*t == NULL) {
    *t = criarAvl(v, NULL, NULL);
    *cresceu = 1;
    return 1;
  }

  if (v.cod_municipio == (*t)->elemento.cod_municipio)
    return 0;

  if (v.cod_municipio < (*t)->elemento.cod_municipio) {
    if (aux_insereAVL(&(*t)->esq, v, cresceu)) {
      if (*cresceu) {
	switch ((*t)->bal) {
	case -1:
	  if ((*t)->esq->bal == -1)
	    LL(t);
	  else
	    LR(t);
	  *cresceu = 0;
	  break;
	case 0:
	  (*t)->bal = -1;
	  *cresceu = 1;
	  break;
	case +1:
	  (*t)->bal = 0;
	  *cresceu = 0;
	  break;
	}
      }
      return 1;
    }
    else
      return 0;
  }

  if (aux_insereAVL(&(*t)->dir, v, cresceu)) {
      if (*cresceu) {
	switch ((*t)->bal) {
	case -1:
	  (*t)->bal = 0;
	  *cresceu = 0;
	  break;
	case 0:
	  (*t)->bal = +1;
	  *cresceu = 1;
	  break;
	case +1:
	  if ((*t)->dir->bal == +1)
	    RR(t);
	  else
	    RL(t);
	  *cresceu = 0;
	  break;
	}
      }
      return 1;
    }
    else
      return 0;


}
int insereAVL(No **t, Dado v) {
  int cresceu;
  return aux_insereAVL(t, v, &cresceu);
}

#endif // AVL_H_INCLUDED
