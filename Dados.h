#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

int comparacoes =0;

typedef struct  Data{
int dia;

int mes;

int ano;
}Data;

typedef struct Dado
{

char regiao[40];

char estado[40];

char municipio[40];

short int cod_uf;

int cod_municipio;

int cod_regiao_saude;

char nome_regiao_saude[100];

Data data;

short int semana_epi;

int populacao;

int casos_acumulado;

int casos_novos;

int obitos_acumulado;

int obitos_novos;

int recuperados_novos;

int em_acompanhamento_novos;

bool fora_de_capital;

}Dado;









Dado* carrega_na_memoria(){
FILE *arquivo;
Dado *dado;
////////////////////////////////////////////////////////////////
dado = (Dado*)malloc(linhas*sizeof(Dado));
//^^Aloca dinamicamenta de acordo com o numero de linhas do arquivo^^
arquivo = fopen ("Covid.csv", "r");
////////////////////////////////
if (arquivo == NULL) {
    printf ("Houve um erro ao abrir o arquivo.\n");
    exit(0);
}
//^^Testa a abertura do arquivo^^
    ///////////////////////////////
    fscanf(arquivo, "%*[^\n]\n");
    //^^Pula o cabeçario^^
    printf("Iniciando Leitura dos Dados...\n");
    for(int k = 0; k<linhas; k++){
    /////////////////////////////
        fscanf(arquivo,"%[^;];%[^;];%[^;];%d;%d;%d;%[^;];%d-%d-%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;\n",&dado[k].regiao,
                                                                                                &dado[k].estado,
                                                                                                &dado[k].municipio,
                                                                                                &dado[k].cod_uf,
                                                                                                &dado[k].cod_municipio,
                                                                                                &dado[k].cod_regiao_saude,
                                                                                                &dado[k].nome_regiao_saude,
                                                                                                &dado[k].data.ano,
                                                                                                &dado[k].data.mes,
                                                                                                &dado[k].data.dia,
                                                                                                &dado[k].semana_epi,
                                                                                                &dado[k].populacao,
                                                                                                &dado[k].casos_acumulado,
                                                                                                &dado[k].casos_novos,
                                                                                                &dado[k].obitos_acumulado,
                                                                                                &dado[k].obitos_novos,
                                                                                                &dado[k].recuperados_novos,
                                                                                                &dado[k].em_acompanhamento_novos,
                                                                                                &dado[k].fora_de_capital);
    //Le do arquivo e coloca na struct Dado
       /* printf("\n_______\n%s;\n%s;\n%s;\n%d;\n%d;\n%d;\n%s;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;",
                                                                dado[k].regiao,
                                                                dado[k].estado,
                                                                dado[k].municipio,
                                                                dado[k].cod_uf,
                                                                dado[k].cod_municipio,
                                                                dado[k].cod_regiao_saude,
                                                                dado[k].nome_regiao_saude,
                                                                dado[k].data.ano,
                                                                dado[k].data.mes,
                                                                dado[k].data.dia,
                                                                dado[k].semana_epi,
                                                                dado[k].populacao,
                                                                dado[k].casos_acumulado,
                                                                dado[k].casos_novos,
                                                                dado[k].obitos_acumulado,
                                                                dado[k].obitos_novos,
                                                                dado[k].recuperados_novos,
                                                                dado[k].em_acompanhamento_novos,
                                                                dado[k].fora_de_capital);*/
        }
    int fclose (FILE *arquivo);

    return dado;

}

void printDado(Dado dado){
    printf("\n_______\n%s;\n%s;\n%s;\n%d;\n%d;\n%d;\n%s;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;\n%d;",
                                                                dado.regiao,
                                                                dado.estado,
                                                                dado.municipio,
                                                                dado.cod_uf,
                                                                dado.cod_municipio,
                                                                dado.cod_regiao_saude,
                                                                dado.nome_regiao_saude,
                                                                dado.data.ano,
                                                                dado.data.mes,
                                                                dado.data.dia,
                                                                dado.semana_epi,
                                                                dado.populacao,
                                                                dado.casos_acumulado,
                                                                dado.casos_novos,
                                                                dado.obitos_acumulado,
                                                                dado.obitos_novos,
                                                                dado.recuperados_novos,
                                                                dado.em_acompanhamento_novos,
                                                                dado.fora_de_capital);
}

#endif // DADOS_H_INCLUDED
