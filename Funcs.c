//@Rodrigo Dinis Lourenço 2021155662

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "header.h"
#define MLEN 128
#define MAX_NOME_LINHA 50
#define MAX_NOME_PARAGEM 50
#define MAX_CODIGO_PARAGEM 5
#define MAX_PARAGENS 100
#define MAX_LINHAS 100
#define MAX_PARAGENS_LINHA 100
extern int flag2;





void adicionar_linha(Sistema *sistema, char *nome_linha){ //adiciona linha há estrutura Sistema
   
     if (sistema->num_linhas == 0 || sistema->linhas == NULL) { // se não houver nenhuma linha ainda
     
        sistema->linhas = malloc(sizeof(Linha));
        
        sistema->num_linhas = 0;
    } else { // se já houver linhas
        
        sistema->linhas = realloc(sistema->linhas, (sistema->num_linhas + 1) * sizeof(Linha));
        
        
    }
    if (sistema->linhas==NULL){
        printf("Erro a alocar memoria para a linha\n");
        return;
    }
   
    
    Linha *linha = &sistema->linhas[sistema->num_linhas];
    linha->nome = malloc(strlen(nome_linha) + 1);
    
    if (linha->nome == NULL){
        printf("Erro a alocar memoria para o nome da linha\n");
        return;
    }
    strcpy(linha->nome, nome_linha);
   
    linha->num_paragens = 0;
    sistema->num_linhas++;//Exemplo 1linha->p0, numlinhas++ 2linha->p1 numlinhas++ etc 
    
    int posicaolinha= sistema->num_linhas - 1;
    
    
   
}

void adicionar_paragem(Sistema *sistema,Linha *linha, char *nome_paragem, char *codigo_paragem, Paragem *paragens) {//Adiciona Paragem há Linha no Sistema
      int indicadorlinha=sistema->num_linhas;
     --indicadorlinha;
    if (indicadorlinha < 0 ) {
        printf("Indice de linha invalido!\n");
        return;
    } 
       
    
    if (linha == NULL) {
        printf("Linha nao pode ser nula.\n");
        return;
    }
       // se ainda não tiver nenhuma paragem, aloca memória para o ponteiro de paragens
    if (linha->num_paragens == 0) {
        linha->paragens = malloc(sizeof(char *));
        if (linha->paragens == NULL) {
            // erro ao alocar memória
            printf("Erro ao alocar memoria\n");
            exit(1);
        }
        linha->codigo = malloc(sizeof(char *));
        if (linha->codigo == NULL) {
            // erro ao alocar memória
            printf("Erro ao alocar memoria\n");
            exit(1);
        }
    }
    // aloca mais um ponteiro para string no array de paragens
    linha->paragens = realloc(linha->paragens, (linha->num_paragens + 1) * sizeof(char *));
    if (linha->paragens == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    linha->codigo = realloc(linha->codigo, (linha->num_paragens + 1) * sizeof(char *));
    if (linha->codigo == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    // aloca memória para a nova string com o nome da paragem
    linha->paragens[linha->num_paragens] = malloc((strlen(nome_paragem) + 1) * sizeof(char));
    if (linha->paragens[linha->num_paragens] == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    // aloca memória para a nova string com o cod da paragem
    linha->codigo[linha->num_paragens] = malloc((strlen(codigo_paragem) + 1) * sizeof(char));
    if (linha->paragens[linha->num_paragens] == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    // copia o nome da paragem para a nova string
    strcpy(linha->paragens[linha->num_paragens], nome_paragem);
     // copia o cod da paragem para a nova string
    strcpy(linha->codigo[linha->num_paragens], codigo_paragem);
    // atualiza o número de paragens da linha
    linha->num_paragens++;
    sistema->Snumparagens++;
  //------------------------Vou guardar também na struct Paragens para depois poder usar na lista ligada----------------//

    if (paragens->nomep == NULL || paragens->num_paragensp == 0) {
   
        paragens->nomep = malloc(sizeof(char *));
        paragens->codigop=malloc(sizeof(char *));
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
        printf("Erro a alocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
        exit(1);
        }
        
    }
    else {
        
        paragens->nomep = realloc(paragens->nomep, (paragens->num_paragensp + 1) * sizeof(char *));
        paragens->codigop = realloc(paragens->codigop,(paragens->num_paragensp + 1)* sizeof(char *));
        
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
            printf("Erro a realocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
            exit(1);
        }
    }
    

   
// aloca memória para a nova string com o nome da paragem
paragens->nomep[paragens->num_paragensp] = malloc((strlen(nome_paragem) + 1) * sizeof(char));
if (paragens->nomep[paragens->num_paragensp] == NULL) {
    // erro ao alocar memória
    printf("Erro a alocar memoria para a nova string no adicionaparagemutilizador\n");
    exit(1);
}

// copia o nome da paragem para a nova string
strcpy(paragens->nomep[paragens->num_paragensp], nome_paragem);

 paragens->codigop[paragens->num_paragensp]= malloc((strlen(codigo_paragem)+ 1) * sizeof(char));
 if (paragens->codigop[paragens->num_paragensp] == NULL) {
    // erro ao alocar memória
    printf("Erro a alocar memoria para a nova string codigo no adicionaparagemutilizador\n");
    exit(1);
}
strcpy(paragens->codigop[paragens->num_paragensp], codigo_paragem);
// atualiza o número de paragens da estrutura
paragens->num_paragensp++;



    
}

void adicionaparagemutilizador(Paragem *paragens){//Adiciona Paragem ao Sistema mas com Cod U
    char Nnome[40], teste[40], teste1[40];
    char cod[6];
    while (getchar() != '\n');
    printf("Introduza o nome da paragem\n");
    fflush(stdout);
    fgets(Nnome, sizeof(Nnome), stdin);
     Nnome[strcspn(Nnome, "\n")] = '\0';
    strcpy(teste1,Nnome);
    Upper(teste1);
    for(int i = 0; i< paragens->num_paragensp; i++){
      strcpy(teste,paragens->nomep[i]);
      Upper(teste);
      if(strcmp(teste,teste1)==0){
        printf("Nome da Paragem ja esta tomado por uma paragem do Sistema\n");
        return;
      }
    }
    
  if (paragens->nomep == NULL || paragens->num_paragensp == 0) {

        paragens->nomep = malloc(sizeof(char *));
        paragens->codigop=malloc(sizeof(char *));
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
        printf("Erro a alocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
        exit(1);
        }
        
    }
    else {
       
        paragens->nomep = realloc(paragens->nomep, (paragens->num_paragensp + 1) * sizeof(char *));
        paragens->codigop = realloc(paragens->codigop,(paragens->num_paragensp + 1)* sizeof(char *));
       
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
            printf("Erro a realocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
            exit(1);
        }
    }
    

    
// aloca memória para a nova string com o nome da paragem
paragens->nomep[paragens->num_paragensp] = malloc((strlen(Nnome) + 1) * sizeof(char));
if (paragens->nomep[paragens->num_paragensp] == NULL) {
    // erro ao alocar memória
    printf("Erro a alocar memoria para a nova string no adicionaparagemutilizador\n");
    exit(1);
}

// copia o nome da paragem para a nova string
strcpy(paragens->nomep[paragens->num_paragensp], Nnome);
srand(time(NULL));
int numcod = rand() % 10000;
 sprintf(cod, "U%04d", numcod);
 paragens->codigop[paragens->num_paragensp]= malloc((strlen(cod)+ 1) * sizeof(char));
 if (paragens->codigop[paragens->num_paragensp] == NULL) {
    // erro ao alocar memória
    printf("Erro a alocar memoria para a nova string codigo no adicionaparagemutilizador\n");
    exit(1);
}
strcpy(paragens->codigop[paragens->num_paragensp], cod);
// atualiza o número de paragens da estrutura
paragens->num_paragensp++;



}

void adicionalinhadoc(Sistema *sistema,Paragem *paragens){//Le as linhas do ficheiro txt e adiciona a linha e as paragens ao Sistema
    char ficheiro[20],  linha123[264];
    char *extensao;
    int flag1 = 0;    
    FILE *arquivo;
       printf("Insere o nome do ficheiro para ler ('ficheiro.txt'):\n");
    scanf("%s",ficheiro);
    
    
    while (flag1 == 0){
        extensao = strstr(ficheiro, ".txt");
    if (extensao == NULL){
        printf("Tem de inserir a extensao do arquivo ('.txt')\n");
        printf("Insere o nome do ficheiro para ler ('ficheiro.txt'):\n");
        scanf("%s",ficheiro);
    }
    else {
        flag1 = 1;
        
    }
    }
    arquivo = fopen(ficheiro,"r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        free(sistema);
        
    }
    while (fgets(linha123, 400, arquivo)) {
        linha123[strcspn(linha123, "\r\n")] = 0; // remove o \n ou \r\n do final da linha
        if (linha123[0] != '\0') { // verifica se a linha não está vazia
            if (strncmp(linha123,"Linha",5)== 0) { // se a linha começa com Linha
                
                adicionar_linha(sistema, linha123);
                
            } else { // paragem       
                       
                char nome_paragem[MAX_NOME_PARAGEM], codigo[MAX_CODIGO_PARAGEM];
                 sscanf(linha123, " %[^#] #%s ", nome_paragem, codigo);
                  int tamanho= strlen(nome_paragem);
                  nome_paragem[tamanho-1]='\0';
                
                int indicador=sistema->num_linhas;
                --indicador;
                Linha *linha = (&sistema->linhas[indicador]);
                
                adicionar_paragem(sistema,linha, nome_paragem, codigo,paragens);
                
                
                


                
            }
        }
    }
    fclose(arquivo);

}



void adicionalinhadoc2(Sistema *sistema,Paragem *paragens, NoLinha *lista_linhas){//Le do ficheiro as linhas e as paragens adicionando-as ao Sistema e
                                                                                  // há lista ligada
    char ficheiro[20],  linha123[264];
    char *extensao;
    int flag1 = 0;
    int contador = 0;   
    FILE *arquivo;
       printf("Insere o nome do ficheiro para ler ('ficheiro.txt'):\n");
    scanf("%s",ficheiro);
    
    
    while (flag1 == 0){
        extensao = strstr(ficheiro, ".txt");
    if (extensao == NULL){
        printf("Tem de inserir a extensao do arquivo ('.txt')\n");
        printf("Insere o nome do ficheiro para ler ('ficheiro.txt'):\n");
        scanf("%s",ficheiro);
    }
    else {
        flag1 = 1;
        
    }
    }
    arquivo = fopen(ficheiro,"r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        free(sistema);
        
    }
    while (fgets(linha123, 400, arquivo)) {
        int teste = 0; 
        linha123[strcspn(linha123, "\r\n")] = 0; // remove o \n ou \r\n do final da linha
        if (linha123[0] != '\0') { // verifica se a linha não está vazia
            if (strncmp(linha123,"Linha",5)== 0) { // se a linha começa com Linha
                
                adicionar_linha(sistema, linha123);//apenas para ficheiros
                
                contador++;
                if (contador != 0){
                  Linha *linha = (&sistema->linhas[sistema->num_linhas - 2]);
                  NoLinha *noatual = lista_linhas;
                  while(noatual->prox!=NULL){
                  noatual = noatual->prox;
                  }
                  NoLinha *novoNo = malloc(sizeof(NoLinha));
                  novoNo->linha = linha;
                  noatual->prox=novoNo;
                  novoNo->prox=NULL;
                }
            } else { // paragem       
                    
                char nome_paragem[MAX_NOME_PARAGEM], codigo[MAX_CODIGO_PARAGEM];
                 sscanf(linha123, " %[^#] #%s ", nome_paragem, codigo);
                  int tamanho= strlen(nome_paragem);
                  nome_paragem[tamanho-1]='\0';
                
                int indicador=sistema->num_linhas;
                --indicador;
                
              for(int y = 0; y < paragens->num_paragensp; y++){
              if(strcmp(nome_paragem,paragens->nomep[y])==0){
                teste=1;
              
              break;
              }
              }
      
               
                 

                if (teste == 0){
                  printf("A paragem %s nao sera adicionada por nao pertencer ao sistema\n",nome_paragem);
                  
                }
                if (teste == 1){
                Linha *linha = (&sistema->linhas[indicador]);
                
                adicionar_paragem(sistema,linha, nome_paragem, codigo,paragens);//falta guardar o codigo
                
                
                }


                
            }
        }
    }
    fclose(arquivo);
    if(contador != 0){
    Linha *linha = (&sistema->linhas[sistema->num_linhas - 1]);
                  NoLinha *noatual = lista_linhas;
                  while(noatual->prox!=NULL){
                  noatual = noatual->prox;
                  }
                  NoLinha *novoNo = malloc(sizeof(NoLinha));
                  novoNo->linha = linha;
                  noatual->prox=novoNo;
                  novoNo->prox=NULL;
    }
}



void printalinhas(NoLinha *lista_linhas){//Printa as linhas
    int numero = 0;
    if(lista_linhas == NULL) {
        printf("A lista de linhas esta vazia.\n");
        return;
    }

    NoLinha *no = lista_linhas;
    while(no != NULL){
        Linha *linha = no->linha;
        printf("%d -> [-%s-]\n",numero,linha->nome);
        no =  no->prox;
        numero++;
    }   
}



void printaparagens(NoLinha *lista_linhas){//Printa as paragens das linhas

  if(lista_linhas == NULL) {
        printf("A lista de linhas esta vazia.\n");
        return;
    }

    NoLinha *no = lista_linhas;
    while(no != NULL){
        Linha *linha = no->linha;
        printf("Linha -> [-%s-]\n",linha->nome);
        for(int i = 0; i< linha->num_paragens;i++){
            printf(":%s: %s\n",linha->paragens[i],linha->codigo[i]);
        }
        printf("\n");
        no =  no->prox;
    }    
}
void printaparagens2(NoLinha *lista_linhas){//Printa as paragens de uma linha enviada
NoLinha *no = lista_linhas;
    
        Linha *linha = no->linha;
        printf("Linha -> [-%s-]\n",linha->nome);
        for(int i = 0; i< linha->num_paragens;i++){
            printf(":%s: %s\n",linha->paragens[i],linha->codigo[i]);
        }
           

}
void printaparagens3(NoLinha *lista_linhas){//Printa as posicoes possiveis de adicionar paragens na linha
    NoLinha *no = lista_linhas;
    Linha *linha = no->linha;
    int y = 1, j = 0;
    for (int i = 0; i < linha->num_paragens;i++){
        if(i == 0){
        printf(" [%d]:%s:[%d]",j,linha->paragens[i],y);
        }
        else{
        printf(":%s:[%d]",linha->paragens[i],y);
        }
        y++;//-> 2
        }
    printf("\n");
}
void printaparagensU(Paragem *paragens){ //Printa as paragens introduzidas pelo Utilizador
    printf("Paragens do utilizador:\n");
    for (int u=0; u < paragens->num_paragensp; u++){
        if(paragens->codigop[u][0] == 'U'){
        printf("%d->%s %s\n",u,paragens->nomep[u], paragens->codigop[u]);
        }
    }
    
}
void printaparagens4(Paragem *paragens){ //Printa as paragens do sistema com um numerador atras 
for (int u=0; u < paragens->num_paragensp; u++){
       
        printf("%d->%s %s\n",u,paragens->nomep[u], paragens->codigop[u]);
 }
    }

void printaparagensUR(Paragem *paragens, NoLinha *lista_linhas){ //Printa paragens do Utilizador que nao estejam presentes em nenhuma Linha
    char parg1 [30], parg2[30];
    int adicionada = 0, contador = 0;
    
    for (int u=0; u < paragens->num_paragensp; u++){
        adicionada = 0;
        if((paragens->codigop[u][0] == 'U')){
            strcpy(parg1,paragens->nomep[u]);
            NoLinha *no2= lista_linhas;
            Linha *linha2 = no2->linha;
            while(no2 != NULL){
         for(int x = 0; x<linha2->num_paragens; x++){
          strcpy(parg2,linha2->paragens[x]);
          if(strcmp(parg1,parg2)==0){
            adicionada = 1;
          }
         }
         no2=no2->prox;
          if (no2 != NULL) {
                  linha2 = no2->linha;
                }
            }
         if(adicionada == 0){
            printf("%d->%s %s\n",u,paragens->nomep[u], paragens->codigop[u]);
            contador++;
         }
        
        }
       
    }
    
    if(contador == 0){
        printf("Nenhuma paragem disponivel a ser eliminada pois todas pertencem a uma linha\n");
    }
}
char* getparagem(Paragem *paragens, int parag){ //Recebe o numerador que indica a Paragem do Utilzador e retorna o nome da mesma
    int encontrou = 0;
    char* escolhida = malloc(sizeof(char*)); 
   
    for (int u=0; u < paragens->num_paragensp; u++){
        if(paragens->codigop[u][0] == 'U'){
        if(parag == u){
            encontrou = 1;
             escolhida = realloc(escolhida,sizeof(char) * sizeof(paragens->nomep[u]));
         strcpy(escolhida,paragens->nomep[u]);
        }
        }
    }
    if (encontrou != 1){
        printf("\nErro-Nao foi possivel encontrar a paragem\n");
        exit(1);
    }
    
    return escolhida;
}
char* getparagem2(Paragem *paragens, int parag){ //Recebe o numerador que indica a Paragem e retorna o nome da mesma
    int encontrou = 0;
    char* escolhida = malloc(sizeof(char*)); 
    
    for (int u=0; u < paragens->num_paragensp; u++){
        
        if(parag == u){
            encontrou = 1;
             escolhida = realloc(escolhida,sizeof(char) * sizeof(paragens->nomep[u]));
         strcpy(escolhida,paragens->nomep[u]);
        }
        
    }
    if (encontrou != 1){
        printf("\nErro-Nao foi possivel encontrar a paragem\n");
        exit(1);
    }
    
    return escolhida;
}
char* getcodigo(Paragem *paragens, char parag[]){ //Recebe a Paragem Do Utilizador e retorna o Cod da mesma
    int encontrou = 0;
    char* escolhida = malloc(sizeof(char*)); 
    
    for (int u=0; u < paragens->num_paragensp; u++){
        if(paragens->codigop[u][0] == 'U'){
        if(strcmp(parag,paragens->nomep[u])==0){
            encontrou = 1;
            escolhida = realloc(escolhida,sizeof(char) * sizeof(paragens->codigop[u]));
         strcpy(escolhida,paragens->codigop[u]);
        }
        }
    }
    if (encontrou != 1){
        printf("Erro -  Cod da paragem escolhida nao encontrado\n");
        exit(1);
    }
    return escolhida;
    
}

char* getcodigo2(Paragem *paragens, char parag[]){ //Recebe uma paragem e retorna o Cod da mesma
    int encontrou = 0;
    char* escolhida = malloc(sizeof(char*)); 
    
    for (int u=0; u < paragens->num_paragensp; u++){
        
        if(strcmp(parag,paragens->nomep[u])==0){
            encontrou = 1;
            escolhida = realloc(escolhida,sizeof(char) * sizeof(paragens->codigop[u]));
         strcpy(escolhida,paragens->codigop[u]);
        }
        
    }
    if (encontrou != 1){
        printf("Erro -  Cod da paragem escolhida nao encontrado\n");
        exit(1);
    }
    return escolhida;
    
}


void removerparagens(Paragem *paragens, NoLinha *lista_linhas){//Escolhe a Paragem a remover 
    char escolhido[10];
    int numero, encontrou = 0;
    if (paragens->num_paragensp == 0 ){
        printf("Impossivel remover paragens no momento porque nao existem paragens a remover\n");
    }
    else {
        
        printaparagensUR(paragens,lista_linhas);
        printf("Introduza o codigo da paragem a ser removida\n");
        scanf("%s", escolhido);
        Upper(escolhido);
        if (paragens->num_paragensp == 1){
            if (strcmp(escolhido, paragens->codigop[0])==0){
            strcpy(paragens->nomep[0],"x");
            strcpy(paragens->codigop[0],"x");
            free(paragens->nomep[0]);
            free(paragens->codigop[0]);
            paragens->nomep = realloc(paragens->nomep, (paragens->num_paragensp - 1) * sizeof(char *));
            paragens->codigop = realloc(paragens->codigop, (paragens->num_paragensp - 1) * sizeof(char *));
            paragens->num_paragensp--;
            encontrou = 1;
            }
            else{
                printf("Codigo introduzido nao corresponde a nenhuma paragem\n");
                removerparagens(paragens,lista_linhas);
            }
        }
        else{
        for (int k = 0;k < paragens->num_paragensp;k++){
            if (strcmp(escolhido, paragens->codigop[k])==0){
                free(paragens->nomep[k]);
                free(paragens->codigop[k]);
                if (k < paragens->num_paragensp - 1){
                    for (int i = k; i < paragens->num_paragensp - 1; i++) {
                        paragens->nomep[i] = paragens->nomep[i+1];
                        paragens->codigop[i] = paragens->codigop[i+1];
                }
                }
                  paragens->nomep = realloc(paragens->nomep, (paragens->num_paragensp - 1) * sizeof(char *));
                paragens->codigop = realloc(paragens->codigop, (paragens->num_paragensp - 1) * sizeof(char *));
        
                if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
            printf("Erro a realocar memoria do tamanho do ponteiro no removerparagens\n");
            exit(1);
            }
        
            // diminui o número de paragens da estrutura
            paragens->num_paragensp--;
             encontrou = 1;
            }
        }
            if (encontrou == 0){
            printf("Codigo introduzido nao corresponde a nenhuma paragem\n");
            removerparagens(paragens,lista_linhas);
            }
            
        }
    }
}

void Upper(char *str) { //Passa uma string para Maiusculas 
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}

//Lista ligada para as estruturas linha cada no representa uma estrutura 
NoLinha* inicializar_lista(Sistema *sistema){
    NoLinha *iniciolista = NULL; // inicializa o início da lista como nulo

for (int i = sistema->num_linhas - 1; i >= 0; i--) {
    Linha *linha = &sistema->linhas[i]; // obtém as linhas
    NoLinha *novo_no = malloc(sizeof(NoLinha)); // aloca memória para o novo nó
    novo_no->linha = linha; // atribui a linha ao novo nó

    // insere o novo nó no início da lista
    novo_no->prox = iniciolista;
    iniciolista = novo_no;
    
}
return iniciolista;
}


void encontrar_percurso(NoLinha *lista_linhas, char *partida, char *chegada) {//Encontrar Percurso 1 linha sentido Ida
    
    NoLinha *no = lista_linhas;
    int encontrou_percurso = 0;
    char templinha[40], tempparagem[40];
    while (no != NULL) {
        Linha *linha = no->linha;

        // Procurar a paragem de partida na linha atual
        int encontrou_partida = 0;
        int i, d;
        //printf("Linha em estudo: [%s]\n",linha->nome);
        for (i = 0; i < linha->num_paragens; i++) {
            strcpy(templinha,linha->paragens[i]);
            Upper(templinha);
            strcpy(tempparagem,partida);
            Upper(tempparagem);
         
            //printf("Vou comparar : %s com : %s\n",templinha,tempparagem);
            if (strcmp(templinha,tempparagem) == 0) {
                encontrou_partida = 1;
                break;
            }
        }

        // Se não encontrou a paragem de partida, passar à próxima linha
        if (!encontrou_partida) {
            no = no->prox;
            continue;
        }

        // Procurar a paragem de chegada na linha atual, a partir da paragem de partida
        int encontrou_chegada = 0;
        //printf("Linha em estudo: [%s]\n",linha->nome);
        for ( d=i; d < linha->num_paragens; d++) {
            strcpy(templinha,linha->paragens[d]);
            Upper(templinha);
            strcpy(tempparagem,chegada);
            Upper(tempparagem); 
          
           // printf("Vou comparar : %s com : %s\n",templinha,tempparagem);
            if (strcmp(templinha, tempparagem) == 0) {
                encontrou_chegada = 1;
                break;
            }
        }

        // Se não encontrou a paragem de chegada, passar à próxima linha
        if (!encontrou_chegada) {
            no = no->prox;
            continue;
        }

        // Encontrou o percurso
        encontrou_percurso = 1;
        printf(" %s : ", linha->nome);
        printf("Sentido normal\n");
        for (int j = i; j <=d; j++) {
            printf("%s", linha->paragens[j]);
            if (j < d) {
                printf(" -> ");
            }
        }
        printf("\n");

        // Passar à próxima linha para verificar se há outros percursos possíveis
        no = no->prox;
    }

    // Se não encontrou percurso, mostrar mensagem
    if (!encontrou_percurso) {
        printf("Nao foi encontrado percurso entre %s e %s.\n", partida, chegada);
    }
}


void encontrar_percurso_inverso(NoLinha *lista_linhas, char *partida, char *chegada) {//Encontrar Percurso 1 linha sentido volta
    
    NoLinha *no = lista_linhas;
    int encontrou_percurso = 0;
    char templinha[40], tempparagem[40];
    while (no != NULL) {
        Linha *linha = no->linha;

        // Procurar a paragem de partida na linha atual
        int encontrou_partida = 0;
        int i, d;
        //printf("Linha em estudo: [%s]\n",linha->nome);
        for (i = 0; i < linha->num_paragens; i++) {
            strcpy(templinha,linha->paragens[i]);
            Upper(templinha);
            strcpy(tempparagem,partida);
            Upper(tempparagem);
         
            //printf("Vou comparar : %s com : %s\n",templinha,tempparagem);
            if (strcmp(templinha,tempparagem) == 0) {
                encontrou_partida = 1;
                break;
            }
        }

        // Se não encontrou a paragem de partida, passar à próxima linha
        if (!encontrou_partida) {
            no = no->prox;
            continue;
        }

        // Procurar a paragem de chegada na linha atual, a partir da paragem de partida
        int encontrou_chegada = 0;
        //printf("Linha em estudo: [%s]\n",linha->nome);
        for ( d=i; d >= 0; d--) {
            strcpy(templinha,linha->paragens[d]);
            Upper(templinha);
            strcpy(tempparagem,chegada);
            Upper(tempparagem); 
          
           // printf("Vou comparar : %s com : %s\n",templinha,tempparagem);
            if (strcmp(templinha, tempparagem) == 0) {
                encontrou_chegada = 1;
                break;
            }
        }

        // Se não encontrou a paragem de chegada, passar à próxima linha
        if (!encontrou_chegada) {
            no = no->prox;
            continue;
        }

        // Encontrou o percurso
        encontrou_percurso = 1;
        printf(" %s : ", linha->nome);
        printf("Sentido inverso\n");       
        for (int j = i; j >=d; j--) {
            printf("%s", linha->paragens[j]);
            if (j > d) {
                printf(" -> ");
            }
        }
        printf("\n");
        printf("\n");

        // Passar à próxima linha para verificar se há outros percursos possíveis
        no = no->prox;
    }

    // Se não encontrou percurso, mostrar mensagem
    if (!encontrou_percurso) {
        printf("Nao foi encontrado percurso entre %s e %s.\n", partida, chegada);
    }
}




void encontrar_percurso_transbordo(NoLinha * lista_linhas, char * partida, char * chegada) {//Encontrar Percurso 2 linhas sentido Ida
    int encontrou_percurso = 0;
    int indicePlinha1, indicePlinha2, poschegada;
    char templinha[40], tempparagem[40];
  // Procurar a paragem de partida
  strcpy(tempparagem,partida);
    Upper(tempparagem);
    int encontrou_parLinha1 = 1;
  NoLinha * no1 = lista_linhas;
  while (no1 != NULL) {
    Linha * linha1 = no1 -> linha;
    for (int i = 0; i < linha1 -> num_paragens; i++) {
        strcpy(templinha,linha1->paragens[i]);
        Upper(templinha);
        strcpy(tempparagem,partida);
        Upper(tempparagem);
      if (strcmp(templinha, tempparagem) == 0) {
        // Encontrou a paragem de partida na linha 1
        
        // Procurar a paragem de chegada na mesma linha
        encontrou_parLinha1 = 0;
       
        //!var se for = 0 ta bacano e entra no if 
        
        if (!encontrou_parLinha1) {
            
          NoLinha * no2 = lista_linhas;
          while (no2 != NULL) {
            Linha * linha2 = no2 -> linha;
            
            // Se a linha for diferente da linha 1
            if (linha2 != linha1) {
              // Procurar a paragem de chegada na linha 2
              int encontrou_chegada = 0;
              for (int k = 0; k < linha2 -> num_paragens; k++) {
                    strcpy(templinha,linha2->paragens[k]);
                    Upper(templinha);
                    strcpy(tempparagem,chegada);
                    Upper(tempparagem);
        
                if (strcmp(templinha,tempparagem) == 0) {
                  encontrou_chegada = 1;
                  poschegada = k;
                  break;
                }
              }

              // Se não encontrou a paragem de chegada, passar à próxima linha
              if (!encontrou_chegada) {
                no2 = no2 -> prox;
                
                continue;
              }

              // Procurar paragem comum entre as duas linhas
              int encontrou_transbordo = 0;
              for (int j = i + 1; j < linha1 -> num_paragens; j++) {
                for (int k = poschegada - 1; k >= 0; k--) {
                  if ((strcmp(linha1 -> paragens[j], linha2 -> paragens[k]) == 0)&& linha2->paragens[k] != linha2->paragens[poschegada]) {
                    encontrou_transbordo = 1;
                    indicePlinha1=j;
                    indicePlinha2=k;
                    
                    break;
                  }
                }
                if (encontrou_transbordo) {
                  break;
                }
              }

              // Se não encontrou paragem de transbordo, passar à próxima linha
              if (!encontrou_transbordo) {
                no2 = no2 -> prox;
                
                continue;
              }

              // Encontrou percurso com transbordo
              
              encontrou_percurso = 1;
              printf(" %s: Sentido Normal\n ", linha1 -> nome);
              for (int j = i; j <= indicePlinha1; j++) {
                printf("%s", linha1 -> paragens[j]);
                if (j < indicePlinha1) {
                  printf(" -> ");
                }
              }
              printf("\n");

              
              printf("%s: ", linha2 -> nome);
              for (int j = indicePlinha2; j <=poschegada; j++) {
                printf("%s", linha2 -> paragens[j]);
                if (j < poschegada) {
                  printf(" -> ");
                }
              }
              printf("\n");
              printf("\n");
    
              // Passar à próxima linha para verificar se há outros percursos possíveis
              no2 = no2 -> prox;
              
            }
            else{
              
              // Passar à próxima linha para verificar se há outros percursos possíveis
              no2 = no2 -> prox;
              
            }
            
          }
        }
      }
        
            
    }
   
    
    no1 = no1->prox;//Procura outra linha1
               
            
  }
   // fim do while para percorrer lista de linhas
            if (!encontrou_percurso) {
              printf("Não foi possível encontrar um percurso entre as paragens especificadas.\n");
            }
}



void encontrar_percurso_transbordo_inverso(NoLinha * lista_linhas, char * partida, char * chegada) {//Encontrar Percurso 2 linhas sentido volta
    int encontrou_percurso = 0;
    int indicePlinha1, indicePlinha2, poschegada;
    char templinha[40], tempparagem[40];
  // Procurar a paragem de partida
  strcpy(tempparagem,partida);
    Upper(tempparagem);
    int encontrou_parLinha1 = 1;
  NoLinha * no1 = lista_linhas;
  while (no1 != NULL) {
    Linha * linha1 = no1 -> linha;
    for (int i = 0; i < linha1 -> num_paragens; i++) {
        strcpy(templinha,linha1->paragens[i]);
        Upper(templinha);
        strcpy(tempparagem,partida);
        Upper(tempparagem);
      if (strcmp(templinha, tempparagem) == 0) {
        // Encontrou a paragem de partida na linha 1
        
        // Procurar a paragem de chegada na mesma linha
        encontrou_parLinha1 = 0;
       
        //!var se for = 0 ta bacano e entra no if 
        
        if (!encontrou_parLinha1) {
          NoLinha * no2 = lista_linhas;
          while (no2 != NULL) {
            Linha * linha2 = no2 -> linha;
            
            // Se a linha for diferente da linha 1
            if (linha2 != linha1) {
              // Procurar a paragem de chegada na linha 2
              int encontrou_chegada = 0;
              for (int k = 0; k < linha2 -> num_paragens; k++) {
                    strcpy(templinha,linha2->paragens[k]);
                    Upper(templinha);
                    strcpy(tempparagem,chegada);
                    Upper(tempparagem);
        
                if (strcmp(templinha,tempparagem) == 0) {
                  encontrou_chegada = 1;
                  poschegada = k;
                  
                  break;
                }
              }

              // Se não encontrou a paragem de chegada, passar à próxima linha
              if (!encontrou_chegada) {
                no2 = no2 -> prox;
                
                continue;
              }

              // Procurar paragem comum entre as duas linhas
              int encontrou_transbordo = 0;
              for (int j = i - 1; j >= 0; j--) {
                for (int k = poschegada + 1; k < linha2 -> num_paragens; k++) {
                  if ((strcmp(linha1 -> paragens[j], linha2 -> paragens[k]) == 0)&& linha2->paragens[k]!= linha2->paragens[poschegada]) {
                    encontrou_transbordo = 1;
                    indicePlinha1=j;
                    indicePlinha2=k;
                    
                    break;
                  }
                }
                if (encontrou_transbordo) {
                  break;
                }
              }

              // Se não encontrou paragem de transbordo, passar à próxima linha
              if (!encontrou_transbordo) {
                no2 = no2 -> prox;
                
                continue;
              }

              // Encontrou percurso com transbordo
              
              encontrou_percurso = 1;
              printf(" %s: Sentido Inverso\n ", linha1 -> nome);
              for (int j = i; j >= indicePlinha1; j--) {
                printf("%s", linha1 -> paragens[j]);
                if (j > indicePlinha1) {
                  printf(" -> ");
                }
              }
              printf("\n");

              
              printf("%s: ", linha2 -> nome);
              for (int j = indicePlinha2; j >= poschegada; j--) {
                printf("%s", linha2 -> paragens[j]);
                if (j > poschegada) {
                  printf(" -> ");
                }
              }
              printf("\n");
              
              // Passar à próxima linha para verificar se há outros percursos possíveis
              no2 = no2 -> prox;
              
            }
            else{
                
              // Passar à próxima linha para verificar se há outros percursos possíveis
              no2 = no2 -> prox;
              
            }
            
          }
        }
      }
        
            
    }
   
    
    no1 = no1->prox;//Procura outra linha1
    
            
            
  }
   // fim do while para percorrer lista de linhas
            if (!encontrou_percurso) {
              printf("Não foi possível encontrar um percurso entre as paragens especificadas.\n");
            }
}


void atualizarlinha(Sistema * sistema, NoLinha * lista_linhas, Paragem * paragens) {//Atualizar Linha Adicionar Paragem / Remover Paragem
  NoLinha * no = lista_linhas;
  int escolha, escolha2, aprovado = 0, flag = 1;
  char cod[20], in [20], temppar[20], tempcod[20];
  int parag, posicao;
  char tempparagem1[20], tempcod1[20], tempparagem2[20], tempcod2[20];
  printf("Escolha a linha que pretende atualizar:\n");
  printalinhas(lista_linhas);
  scanf("%d", & escolha);
  for (int i = 0; i < sistema -> num_linhas; i++) {
    if (i == escolha) {
      aprovado = 1;

    }
  }
  if (aprovado == 0) {
    printf("Erro na escolha da linha\n");
    printf("Escolha novamente\n");
    atualizarlinha(sistema, lista_linhas, paragens);
  }
  if (aprovado == 1) {
    for (int x = 0; x < escolha; x++) {
      no = no -> prox;
    }
    Linha * linha = no -> linha;
    printf("Linha escolhida -%s-\n", linha -> nome);
    printaparagens2(no);
    printf("Pretende \n 1-Adicionar Paragem \n 2-Remover Paragem\n");
    scanf("%d", & escolha2);
    while (escolha2 != 1 && escolha2 != 2) {
      while (getchar() != '\n');
      fflush(stdout);
      printf("Pretende \n 1-Adicionar Paragem \n 2-Remover Paragem\n");
      scanf("%d", & escolha2);

    }
    if (escolha2 == 1) {
      printaparagensU(paragens);
      printf("Introduza o numero da paragem a adicionar e a posicao escolhida\n");
      while (flag == 1) {
        printaparagens3(no);
        printf("[Exemplo:20 3\n Escolheu a paragem 20 que ira ser colocada na posicao 3\n");
        printf("Quanto terminar introduza :Sair:]\n");
        printf("Introduza\n");
        int flagseguranca = 0;
        while (getchar() != '\n');
        fflush(stdout);
        fgets(in, sizeof(in), stdin);
        // remove o caractere de nova linha
        in [strcspn(in, "\n")] = '\0';
        Upper(in);
        if (strcmp(in,"SAIR") == 0) {
          flag = 0;
          break;
        }
        if (flag == 1) {
          sscanf(in, "%d %d", & parag, & posicao);
          //obtemparagem
          char * getp = getparagem(paragens, parag);

          char * getc = getcodigo(paragens, getp);
          printf("\n%s %s\n", getp, getc);
          for(int q = 0; q<linha->num_paragens; q++){

          if(strcmp(linha->paragens[q],getp)==0){
            flagseguranca = 1;
            break;
          }
        }
        if(flagseguranca == 1){
          printf("A paragem que pretende adicionar ja se encontra presente na linha\n");
          flag = 0;
          continue;
        }
          if (posicao == 0) {
            
            linha -> paragens = realloc(linha -> paragens, (linha -> num_paragens + 1) * sizeof(char * ));
            linha -> codigo = realloc(linha -> codigo, (linha -> num_paragens + 1) * sizeof(char * ));
            linha->paragens[linha->num_paragens] = malloc((strlen(getp) + 1) * sizeof(char));
            linha->codigo[linha->num_paragens] = malloc((strlen(getc) + 1) * sizeof(char));

            for (int i = linha -> num_paragens - 1; i > 0; i--) {

              strcpy(linha -> paragens[i],linha -> paragens[i - 1]);
                strcpy(linha -> codigo[i],linha -> codigo[i - 1]);

            }
            strcpy(linha -> paragens[0], getp);
            strcpy(linha -> codigo[0], getc);
            linha -> num_paragens++;
            continue;
          } else if (posicao == linha -> num_paragens) {
            
            linha -> paragens = realloc(linha -> paragens, (linha -> num_paragens + 1) * sizeof(char * ));
            linha -> codigo = realloc(linha -> codigo, (linha -> num_paragens + 1) * sizeof(char * ));
            linha->paragens[linha->num_paragens] = malloc((strlen(getp) + 1) * sizeof(char));
            linha->codigo[linha->num_paragens] = malloc((strlen(getc) + 1) * sizeof(char));
            strcpy(linha -> paragens[linha -> num_paragens], getp);
            strcpy(linha -> codigo[linha -> num_paragens], getc);
            linha -> num_paragens++;
            continue;
          } else {
           
            
              
                
                 linha -> paragens = realloc(linha -> paragens, (linha -> num_paragens + 1) * sizeof(char * ));
                  linha -> codigo = realloc(linha -> codigo, (linha -> num_paragens + 1) * sizeof(char * ));
                  linha->paragens[linha->num_paragens] = malloc((strlen(getp) + 1) * sizeof(char));
                  linha->codigo[linha->num_paragens] = malloc((strlen(getc) + 1) * sizeof(char));

                for (int x = linha -> num_paragens; x >= posicao; x--) {
                    

                 strcpy(linha -> paragens[x],linha -> paragens[x - 1]);
                  strcpy(linha -> codigo[x],linha -> codigo[x - 1]);
                }
               
                strcpy(linha -> paragens[posicao], getp);
                strcpy(linha -> codigo[posicao], getc);
                linha -> num_paragens++;
                continue;
              
            
          }

        }

      }

    }
  
   else {
    while (flag == 1) {
      printaparagens2(no);
      printf("Introduza o cod da paragem a remover\n");
      printf("Quanto terminar introduza :Sair:\n");
      scanf("%s", cod);
      Upper(cod);
      if (strcmp(cod, "SAIR") == 0) {
        flag = 0;
        break;
      }
      if (flag == 1) {
        for (int x = 0; x < linha -> num_paragens; x++) {
          if (strcmp(cod, linha -> codigo[x]) == 0) {
            if (linha -> num_paragens == 1) {
              strcpy(linha -> paragens[x], "X");
              strcpy(linha -> codigo[x], "X");
              free(linha -> paragens[x]);
              free(linha -> codigo[x]);
              linha -> num_paragens--;

            } else {
              free(linha -> paragens[x]);
              free(linha -> codigo[x]);
              for (int i = x; i < linha -> num_paragens - 1; i++) {
                
                linha -> paragens[i] = linha -> paragens[i + 1];
                linha -> codigo[i] = linha -> codigo[i + 1];
              }

              linha -> paragens = realloc(linha -> paragens, (linha -> num_paragens - 1) * sizeof(char * ));
              linha -> codigo = realloc(linha -> codigo, (linha -> num_paragens - 1) * sizeof(char * ));

              if (linha -> paragens == NULL || linha -> codigo == NULL) {
                // erro ao alocar memória
                printf("Erro a realocar memoria do tamanho do ponteiro no removerparagens\n");
                exit(1);
              }
              linha -> num_paragens--;
            }
          }

        }

      }
    }
  }

}
    
}

void printalinhas2(NoLinha *lista_linhas, Paragem *paragens){//Printa as Linhas que passem numa Paragem Enviada
    int numero = 0, escolha, numeroP;
    if(lista_linhas == NULL) {
        printf("A lista de linhas esta vazia.\n");
        return;
    }
    printf("Pretende visualizar linhas que passem em alguma paragem especifica?\n");
    while(escolha != 1 && escolha != 2){
    printf("1-->Sim\n2-->Nao\n");
    scanf("%d",&escolha);
    }
    if(escolha == 2){
      return;
    }
    else if(escolha == 1){
      printaparagens4(paragens);
      printf("Introduza o numero da paragem que pretende selecionar\n");
      scanf("%d",&numeroP);
      char * escolha = getparagem2(paragens,numeroP);
      NoLinha *no = lista_linhas;
    while(no != NULL){
        Linha *linha = no->linha;
        for(int y = 0; y < linha->num_paragens; y++){
          if(strcmp(escolha,linha->paragens[y])==0){
        printf("%d -> [-%s-]\n",numero,linha->nome);
        break;
          }
      
    } 
      no =  no->prox;
        numero++; 

    }
      
    }
    

}

void adicionar_linhaUinput(Sistema *sistema , Paragem *paragens, NoLinha *lista_linhas){//O utilizador Adiciona uma linha 
    char nomedalinha[40],  paragem[40],  cod[7], templinha1[30],templinha2[30];
    int quantidade,flagloop=1;
    char *testelinha;
    int flag = 1;
    while(flagloop == 1){
        int flags=0;
    printf("Introduza o nome da linha (Nome: 'Linha Central')\n");
    while (getchar() != '\n');
        fflush(stdout);
    fgets(nomedalinha, sizeof(nomedalinha), stdin);
        // remove o caractere de nova linha
        nomedalinha [strcspn(nomedalinha, "\n")] = '\0';
    testelinha=strstr(nomedalinha,"Linha");
    if (testelinha == NULL){
        printf("O nome da linha tem de ser iniciado por 'Linha'\n");
         printf("Introduza o nome da linha (Nome: 'Linha Central')\n");
         while (getchar() != '\n');
        fflush(stdout);
        fgets(nomedalinha, sizeof(nomedalinha), stdin);
        // remove o caractere de nova linha
        nomedalinha [strcspn(nomedalinha, "\n")] = '\0';
    }
    printf("->:%s:\n",nomedalinha);
    int indlinha= sistema->num_linhas;
    --indlinha;
     if (indlinha < 0 ) {
        printf("Indice de linha invalido!\n");
        return;
    } 
    
   
    for(int y = 0; y<sistema->num_linhas;y++){
        Linha *linha = (&sistema->linhas[y]);
         if ( linha == NULL) {
        printf("Linha nao pode ser nula.\n");
        return;
    }
        if( strcmp(nomedalinha,linha->nome)==0){
            printf("Erro->O nome da linha ja existe!\n");
            flags=1;
            break;
        }
    
    }
    sistema->linhas = realloc(sistema->linhas, (sistema->num_linhas + 1) * sizeof(Linha));
    Linha *linha = &sistema->linhas[sistema->num_linhas];
    linha->nome = malloc(strlen(nomedalinha) + 1);
    
    if (linha->nome == NULL){
        printf("Erro a alocar memoria para o nome da linha\n");
        return;
    }
    strcpy(linha->nome, nomedalinha);
    linha->num_paragens = 0;
    sistema->num_linhas++;
    while(flag == 1){
       flag = 1;
      char in [30];
      printaparagens4(paragens);
      printf("Introduza o numero da paragem a adicionar\n");
      
        int parag;
       
        printf("Quanto terminar introduza :Sair:]\n");
        printf("Introduza\n");
        int flagseguranca = 0;
        while (getchar() != '\n');
        fflush(stdout);
        fgets(in, sizeof(in), stdin);
        // remove o caractere de nova linha
        in [strcspn(in, "\n")] = '\0';
        Upper(in);
        if (strcmp(in,"SAIR") == 0) {
          flag = 0;
          flagloop = 0;
          break;
        }
        if (flag == 1) {
          sscanf(in, "%d %d", &parag);
          //obtemparagem
          char * getp = getparagem2(paragens, parag);

          char * getc = getcodigo2(paragens, getp);
          printf("\n%s %s\n", getp, getc);
          for(int q = 0; q<linha->num_paragens; q++){

          if(strcmp(linha->paragens[q],getp)==0){
            flagseguranca = 1;
            break;
          }
        }
        if(flagseguranca == 1){
          printf("A paragem que pretende adicionar ja se encontra presente na linha\n");
          continue;
        }
      
     if (linha->num_paragens == 0) {
        linha->paragens = malloc(sizeof(char *));
        if (linha->paragens == NULL) {
            // erro ao alocar memória
            printf("Erro ao alocar memoria\n");
            exit(1);
        }
        linha->codigo = malloc(sizeof(char *));
        if (linha->codigo == NULL) {
            // erro ao alocar memória
            printf("Erro ao alocar memoria\n");
            exit(1);
        }
    }
    // aloca mais um ponteiro para string no array de paragens
    linha->paragens = realloc(linha->paragens, (linha->num_paragens + 1) * sizeof(char *));
    if (linha->paragens == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    linha->codigo = realloc(linha->codigo, (linha->num_paragens + 1) * sizeof(char *));
    if (linha->codigo == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    // aloca memória para a nova string com o nome da paragem
    linha->paragens[linha->num_paragens] = malloc((strlen(getp) + 1) * sizeof(char));
    if (linha->paragens[linha->num_paragens] == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    // aloca memória para a nova string com o cod da paragem
    linha->codigo[linha->num_paragens] = malloc((strlen(getc) + 1) * sizeof(char));
    if (linha->paragens[linha->num_paragens] == NULL) {
        // erro ao alocar memória
        exit(1);
    }
    // copia o nome da paragem para a nova string
    strcpy(linha->paragens[linha->num_paragens], getp);
     // copia o cod da paragem para a nova string
    strcpy(linha->codigo[linha->num_paragens], getc);
    // atualiza o número de paragens da linha
    linha->num_paragens++;
    sistema->Snumparagens++;
    }
    


}
NoLinha *noatual = lista_linhas;
while(noatual->prox!=NULL){
noatual = noatual->prox;
}
NoLinha *novoNo = malloc(sizeof(NoLinha));
novoNo->linha = linha;
noatual->prox=novoNo;
novoNo->prox=NULL;

}
    }

    void guardarDadosEmArquivo(Sistema *sistema, Paragem *paragens) {
      char ficheiro[20];
      char *extensao;
      int flag1 = 0;    
    FILE *arquivo;
       printf("Insere o nome do ficheiro para ler ('ficheiro.bin'):\n");
    scanf("%s",ficheiro);
    
    
    while (flag1 == 0){
        extensao = strstr(ficheiro, ".bin");
    if (extensao == NULL){
        printf("Tem de inserir a extensao do arquivo ('.bin')\n");
        printf("Insere o nome do ficheiro para ler ('ficheiro.bin'):\n");
        scanf("%s",ficheiro);
    }
    else {
        flag1 = 1;
        
    }
    }
   arquivo = fopen(ficheiro, "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  // Escrever os dados das linhas
  fwrite(sistema,sizeof(Sistema),1,arquivo);

  // Escrever os dados da struct paragens
  fwrite(paragens, sizeof(Paragem), 1, arquivo);

  fclose(arquivo);
}
void restaurarDadosDoArquivo(Sistema **sistema, Paragem **paragens) {
   char ficheiro[20];
      char *extensao;
      int flag1 = 0;
       int sistema_tamanho, paragens_tamanho;    
    FILE *arquivo;
       printf("Insere o nome do ficheiro para ler ('ficheiro.bin'):\n");
    scanf("%s",ficheiro);
    
    
    while (flag1 == 0){
        extensao = strstr(ficheiro, ".bin");
    if (extensao == NULL){
        printf("Tem de inserir a extensao do arquivo ('.bin')\n");
        printf("Insere o nome do ficheiro para ler ('ficheiro.bin'):\n");
        scanf("%s",ficheiro);
    }
    else {
        flag1 = 1;
        
    }
    }

  arquivo = fopen(ficheiro, "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para leitura.\n");
    return;
  }
  fread(&sistema_tamanho, sizeof(int), 1, arquivo);
  fread(&paragens_tamanho, sizeof(int), 1, arquivo);
   *sistema = realloc(*sistema,sistema_tamanho * sizeof(Sistema));
   *paragens = realloc(*paragens,paragens_tamanho * sizeof(Paragem) );

  // Ler os dados das linhas
  fread(*sistema,sizeof(Sistema), sistema_tamanho , arquivo);

  // Ler os dados da struct paragens
  fread(*paragens, sizeof(Paragem), paragens_tamanho, arquivo);

  fclose(arquivo);
}


   void libertar_sistema(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas) {//Free da memoria
     NoLinha *atual = lista_linhas;
    while (atual != NULL) {
        NoLinha *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    
    for (int i = 0; i < sistema->num_linhas; i++) {
        Linha *linha = (&sistema->linhas[i]);
       
        free(linha->nome);
        
         printf("---------------------------\n");
        for(int l = 0; l < linha->num_paragens;l++){
        free(linha->paragens[l]);
        free(linha->codigo[l]);
        }
        
        
    }
    free(sistema->linhas);
    for(int x = 0; x < paragens->num_paragensp; x++){
        free(paragens->nomep[x]);
        free(paragens->codigop[x]);
    }
    free(sistema->paragens);

    free(sistema);
    
   }






int menu(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas){//Menu
    int opcao, opcao2 = 3;
    printf("---Menu---\n");
    printf("1-->Registar Paragem\n");
    printf("2-->Elimar Paragem\n");
    printf("3-->Visualizar Paragens\n");
    printf("4-->Adcionar Linhas\n");
    printf("5-->Atualizar Linha\n");
    printf("6-->Visualizar Linhas\n");
    printf("7-->Percurso teste\n");
    printf("8-->Sair do Programa\n");
    scanf("%d",&opcao);
       switch(opcao) {
      case 1:
         printf("Opcao 1 selecionada\n");
         adicionaparagemutilizador(paragens);
         break;
      case 2:
         printf("Opcao 2 selecionada\n");
         removerparagens(paragens,lista_linhas);
         break;
      case 3:
         printf("Opcao 3 selecionada\n");
         printaparagens(lista_linhas);
         printaparagensU(paragens); 
                  break;
      case 4:
         printf("Opcao 4 selecionada\n");
         while(opcao2 != 1 && opcao2 != 2){
         printf("1--introduzir informacao\n 2--Ficheiro Txt\n[Introduza o numero]\n");
         scanf("%d",&opcao2);
         
         }
         if(opcao2==1){
         adicionar_linhaUinput(sistema,paragens,lista_linhas);
         }
         else{
         adicionalinhadoc2(sistema, paragens,lista_linhas);
         //adicionarNO(lista_linhas,sistema);
         }
         break;
      case 5:
         printf("Opcao 5 selecionada\n");
         atualizarlinha(sistema,lista_linhas,paragens);
         break;
      case 6:
         printf("Opcao 6 selecionada\n");
         printalinhas(lista_linhas);
         printalinhas2(lista_linhas,paragens);
         break;
      case 7:
         printf("Opcao 7 selecionada\n");
         char paragem_incio[50],paragem_fim[50];
         printf("As paragens disponiveis sao:\n");
         printf("--------------\n");
          //printaparagens(sistema);
          printf("--------------\n");
         //printaparagensU(paragens);
         printf("--------------\n");
         printf("Introduza as paragens que deseja incluir no seu percurso:\n");
         while (getchar() != '\n');
         printf("Paragem de Partida: \n");
         fflush(stdout);
         fgets(paragem_incio, sizeof(paragem_incio), stdin);
          // remove o caractere de nova linha
         paragem_incio[strcspn(paragem_incio, "\n")] = '\0'; 
         printf("Paragem Destino: \n");
         fflush(stdout);
         fgets(paragem_fim, sizeof(paragem_fim), stdin);
         paragem_fim[strcspn(paragem_fim, "\n")] = '\0'; // remove o caractere de nova linha

         printf("\n");
         printf("-----------------------\n");
         printf("Percurso linha unica [Sentido Ida]\n");
         encontrar_percurso(lista_linhas,paragem_incio,paragem_fim);
         printf("-----------------------\n");
         printf("Percurso linha unica [Sentido Volta]\n");
         encontrar_percurso_inverso(lista_linhas,paragem_incio,paragem_fim);
         printf("-----------------------\n");
         printf("Percurso duas linhas [Sentido Ida]\n");
         encontrar_percurso_transbordo(lista_linhas,paragem_incio,paragem_fim);
         printf("-----------------------\n");
         printf("Percurso duas linhas [Sentido Volta]\n");
         encontrar_percurso_transbordo_inverso(lista_linhas,paragem_incio,paragem_fim);
         break;
      case 8:
            printf("Opcao 8 selecionada\n");
            guardarDadosEmArquivo(sistema,paragens);
            libertar_sistema(sistema, paragens, lista_linhas);
            printf("Adeus!\n");
            flag2=0;
            break;
      default:
         printf("Opçao inválida\n");
         break;
   }

}



