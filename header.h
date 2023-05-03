#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Funcs.h"
#include <time.h>

int menu(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas);
void libertar_sistema(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas );
void printalinhas(Sistema *sistema);
void adicionar_paragem(Sistema *sistema,Linha *linha, char *nome_paragem, char *codigo_paragem, Paragem *paragens);
void adicionar_linha(Sistema *sistema, char *nome_linha);
void printaparagens(Sistema *sistema);
void printaparagensU(Paragem *paragens);
void adicionaparagemutilizador(Paragem *paragens);
void removerparagens(Paragem *paragens);
void adicionalinhadoc(Sistema *sistema, Paragem *paragens);
NoLinha* inicializar_lista(Sistema *sistema);
void encontrar_percurso(NoLinha *lista_linhas, char *partida, char *chegada);