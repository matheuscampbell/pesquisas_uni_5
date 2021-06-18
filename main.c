#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
#define linhas 2501324
#include "Dados.h"
#include "arvore_binaria.h"
#include "avl.h"
#include "lista.h"
#include "hash.h"



double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info) );
    return (double)info.PeakWorkingSetSize/ (1024*1024);
}


     clock_t start_time, end_time;
     double cpu_time_used, memory_used;
     size_t peakSize;


Dado* PesquisaSequencial(Dado *dados, int codigo){
    for(int i =0; i< linhas; i++){
        if(dados[i].cod_municipio == codigo){
                comparacoes++;
            printDado(dados[i]);
        }
    }
    return;
}

int pesquisa_binaria(Dado *vetor, int item)
{
    int inicio = 0;
    int fim = linhas - 1;
    int count = 0;
    while (inicio <= fim) {

        int i = (inicio + fim) / 2;
        if (vetor[i].cod_municipio == item) {
                comparacoes++;
            printDado(vetor[i]);
        }
        if (vetor[i].cod_municipio < item) {
            inicio = i + 1;
        } else {
            fim = i;
        }
    }
    return -1;
}

void arvoreBinNaria(Dado *dados, int elemento){
    printf("Criando Arvore\n");
    ArvBin arvore;
    create_arvbin(&arvore);
    for(int i =0; i< linhas; i++){
        inserirBin(&arvore, dados[i]);
    }
    printf("inserido com sucesso!");
    pesquisar(&arvore,elemento);
}

void arvore_AVL(Dado *dados, int elemento){
    printf("Criando Arvore\n");
    ArvBin arvore;
    create_arvbin(&arvore);
    No* t = criarAvl(dados[0],NULL, NULL);
    for(int i =1; i< linhas-1; i++){
        insereAVL(&t,dados[i]);
    }
    printf("inserido com sucesso!");
    verifica_AVL(t);
    printf("/n Pesquisando/n");
    pesquisar(&t,elemento);
}

void tabelaHash(Dado *dados, int item){
    printf("Iniciando tabelahash!\n");
    TabelaHash tabela;
    new_hash_f(&tabela);
    printf("Carregado!\n");
    printf("Iniciando carregamento!\n");
    for(int i =1; i< linhas-1; i++){
        add_hash_f(&tabela,dados[i]);
    }
    printf("Completo!\n");
    printf("Iniciando Pesquisa!\n");
    pesquisa_hash_f(&tabela,item);
    printf("Completa!\n");
}

void endtime(){
end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    memory_used = get_memory_used_MB();
    printf("Tempo: %0.2f segundos - Memoria: %0.2f MB - Comparacoes: %d\n",cpu_time_used, memory_used,comparacoes);
}

int main(void) {
     Dado *dados;
     int op = -1;
     dados = carrega_na_memoria();
     printf("Carregado!\n");
     do{
        printf("1- Pesquisa Sequencial\n2- Pesquisa Binaria\n3- Arvore Binaria de Pesquisa\n4- Arvore AVL\n5- Tabela Hash\n0- Sair\n\nDigite uma opcao:");
        scanf("%d",&op);
        if(op == 1){
            printf("Digite o Codigo do municipio:");
            scanf("%d",&op);
           start_time = clock();
           PesquisaSequencial(dados,op);
           endtime();
           op = -1;
        }else if(op == 2){
            printf("Digite o Codigo do municipio:");
            scanf("%d",&op);
           start_time = clock();
           pesquisa_binaria(dados,op);
           endtime();
           op = -1;
        }else if(op == 3){
            printf("Digite o Codigo do municipio:");
            scanf("%d",&op);
           start_time = clock();
           arvore_AVL(dados,op);
           endtime();
           op = -1;
        }else if(op == 4){
            printf("Digite o Codigo do municipio:");
            scanf("%d",&op);
           start_time = clock();
           pesquisa_binaria(dados,op);
           endtime();
           op = -1;
        }else if(op == 5){
            printf("Digite o Codigo do municipio:");
            scanf("%d",&op);
           start_time = clock();
           tabelaHash(dados,op);
           endtime();
           op = -1;
        }else{
            printf("\n\nOpcao Invalida!\n\n");
        }
     }while(op != 0);
    free(dados);
    printf("\n finalizado \n");
    return 0;
}
