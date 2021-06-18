#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
// tamanho da tabela
#define MAX 104729
typedef struct TabelaHash{
  Lista *tabela[MAX];
}TabelaHash;

void new_hash_f(TabelaHash *th){
  for(int i=0; i<MAX; i++)
    new_lista(&th->tabela[i]);
}


int hash_f(int chave){
  return chave%MAX;
}

void print_tabela_hash(TabelaHash *th){

  for(int i=0; i<MAX; i++){
    printf("%d\t", i);
    print_lista(&th->tabela[i]);
  }
}

void add_hash_f(TabelaHash *th, Dado dado){
  int pos = hash_f(dado.cod_municipio);
  //print_tabela_hash(&th->tabela[pos]);
  add(&th->tabela[pos], dado);
}


Dado pesquisa_hash_f(TabelaHash *th, int item){
  int pos = hash_f(item);
  pesquisa_lista(&th->tabela[pos], item);
}

#endif // HASH_H_INCLUDED
