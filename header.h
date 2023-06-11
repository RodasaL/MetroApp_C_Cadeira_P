//@Rodrigo Dinis Lourenço 2021155662

#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


extern int flag2;



typedef struct{
    char **nomep;
    char **codigop;
    int num_paragensp;
}Paragem;


typedef struct 
{
    char *nome; 
    char **paragens;//Array de ponteiros para strings com os varios nomes
    char **codigo;//Array de ponteiros para strings com os varios codigos
    int num_paragens;   
}Linha;

typedef struct{
    Paragem *paragens;// ponteiro que aponta para uma estrutura
    Linha *linhas;// ponteiro que aponta para uma estrutura
    int num_linhas;
    int Snumparagens;
}Sistema;


typedef struct NoLinha {
    Linha *linha;
    struct NoLinha *prox;
} NoLinha;






int menu(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas);
void printaparagensUR(Paragem *paragens, NoLinha *lista_linhas);
void printalinhas(NoLinha *lista_linhas);
void adicionar_paragem(Sistema *sistema,Linha *linha, char *nome_paragem, char *codigo_paragem, Paragem *paragens);
void adicionar_linha(Sistema *sistema, char *nome_linha);
void printalinhas(NoLinha *lista_linhas);
void printaparagens(NoLinha *lista_linhas);
void printaparagensU(Paragem *paragens);
void printaparagens2(NoLinha *lista_linhas);
void printaparagens3(NoLinha *lista_linhas);
void printaparagens4(Paragem *paragens);
void adicionaparagemutilizador(Paragem *paragens);
void removerparagens(Paragem *paragens,NoLinha *lista_linhas);
void adicionalinhadoc2(Sistema *sistema,Paragem *paragens, NoLinha *lista_linhas);
void adicionalinhadoc(Sistema *sistema, Paragem *paragens);
char* getparagem(Paragem *paragens, int parag);
NoLinha* inicializar_lista(Sistema *sistema);
char* getparagem2(Paragem *paragens, int parag);
char* getcodigo(Paragem *paragens, char parag[]);
char* getcodigo2(Paragem *paragens, char parag[]);
void encontrar_percurso(NoLinha *lista_linhas, char *partida, char *chegada);
void encontrar_percurso_inverso(NoLinha *lista_linhas, char *partida, char *chegada);
void Upper(char *str);
void encontrar_percurso_transbordo(NoLinha * lista_linhas, char * partida, char * chegada);
void encontrar_percurso_transbordo_inverso(NoLinha * lista_linhas, char * partida, char * chegada);
void atualizarlinha(Sistema * sistema, NoLinha * lista_linhas, Paragem * paragens);
void encontrar_percurso_transbordo(NoLinha * lista_linhas, char * partida, char * chegada);
void printalinhas2(NoLinha *lista_linhas, Paragem *paragens);
void adicionar_linhaUinput(Sistema *sistema , Paragem *paragens, NoLinha *lista_linhas);
void guardarDadosEmArquivo(Sistema *sistema, Paragem *paragens);
void restaurarDadosDoArquivo(Sistema **sistema, Paragem **paragens);
void libertar_sistema(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas );

#endif