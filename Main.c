#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
int flag2 = 1;





int main() {
    int flaglinha = -1;
    int opcao;
    int opcao2;
   
     Sistema* sistema = (Sistema*) malloc(sizeof(Sistema));
     Paragem* paragens= (Paragem*) malloc(sizeof(Paragem));
     if (sistema == NULL){
        printf("Erro a alocar a memoria da estr Sistema\n");
        return -1;
     }
      if (sistema == NULL){
        printf("Erro a alocar a memoria da estr Paragem\n");
        return -1;
     }
     paragens->num_paragensp =0;
     sistema->num_linhas = 0;
     sistema->Snumparagens = 0;
     printf("Pretende ler um ficheiro: 1-->txt \n 2-->binario\n");
     scanf("%d",&opcao2);
    adicionalinhadoc(sistema,paragens);
 
    NoLinha* lista_linhas =inicializar_lista(sistema);
    while (flag2==1){
    printf("Bem vindo!\n");
    menu(sistema, paragens, lista_linhas);
   

}

   return 2;
}
