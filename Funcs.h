#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MLEN 128
#define MAX_NOME_LINHA 50
#define MAX_NOME_PARAGEM 50
#define MAX_CODIGO_PARAGEM 5
#define MAX_PARAGENS 100
#define MAX_LINHAS 100
#define MAX_PARAGENS_LINHA 100
extern int flag2;
typedef struct{
    char **nomep;
    char **codigop;
    int num_paragensp;
}Paragem;
typedef struct{
    char *nomep;
    char **codigop;
    int num_paragensp;
}Paragem2;

typedef struct 
{
    char *nome; 
    char **paragens;//Array de ponteiros para strings com os varios nomes
    char **codigo;//Array de ponteiros para strings com os varios codigos
    int num_paragens;   
}Linha;

typedef struct{
    Paragem *paragens;//Array de ponteiros que aponta para varias estruturas
    Linha *linhas;//Array de ponteiros que aponta para varias estruturas
    int num_linhas;
    int Snumparagens;
}Sistema;

typedef struct NoParagem {
    Paragem *paragem;
    struct NoParagem *prox;
} NoParagem;

typedef struct NoLinha {
    Linha *linha;
    struct NoLinha *prox;
} NoLinha;

typedef struct NoPercurso {
    Linha *linha;
    struct NoPercurso *prox;
} NoPercurso;


/*Paragem** paragens;*/
void adicionar_linha(Sistema *sistema, char *nome_linha){
    printf("HEY\n");
     if (sistema->num_linhas == 0 || sistema->linhas == NULL) { // se não houver nenhuma linha ainda
     printf("Hey2\n");
        sistema->linhas = malloc(sizeof(Linha));
        printf("Done\n");
        sistema->num_linhas = 0;
    } else { // se já houver linhas
        printf("Hey3\n");
        sistema->linhas = realloc(sistema->linhas, (sistema->num_linhas + 1) * sizeof(Linha));
        printf("Done2\n");
        
    }
    if (sistema->linhas==NULL){
        printf("Erro a alocar memoria para a linha\n");
        return;
    }
    printf("Hey4\n");
    printf("numlihas->[%d]\n",sistema->num_linhas);
    Linha *linha = &sistema->linhas[sistema->num_linhas];
    linha->nome = malloc(strlen(nome_linha) + 1);
    printf(" malloc nome done\n");
    if (linha->nome == NULL){
        printf("Erro a alocar memoria para o nome da linha\n");
        return;
    }
    strcpy(linha->nome, nome_linha);
    printf("\n->%s\n",linha->nome);
    linha->num_paragens = 0;
    sistema->num_linhas++;//Exemplo 1linha->p0, numlinhas++ 2linha->p1 numlinhas++ etc 
    printf("Teste do num_paragens %d\n",linha->num_paragens);
    int posicaolinha= sistema->num_linhas - 1;
    printf("Linha [%s] adicionada com sucesso na posicao [%d]!\n", linha->nome,posicaolinha);
    
   
}
void adicionar_linhaUinput(Sistema *sistema){
    char nomedalinha[40],  paragem[40],  cod[7];
    int quantidade,flagloop=1;
    char *testelinha;
    while(flagloop == 1){
        int flags=0;
    printf("Introduza o nome da linha (Nome: 'Linha Central'):%s\n");
    scanf("%s",nomedalinha);
    testelinha=strstr(nomedalinha,"Linha");
    if (testelinha == NULL){
        printf("O nome da linha tem de ser iniciado por 'Linha'\n");//testes de seguranca em falta TODO:
         printf("Introduza o nome da linha (Nome: 'Linha Central'):%s\n");
        scanf("%s",nomedalinha);
    }
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
        }
    }
    if(flags==0){
    printf("Introduza a quantidade de paragens que a linha vai ter:%d\n");
    scanf("%d",&quantidade);
    for(int u = 0; u<quantidade; u++){
        printf("Introduza o nome da paragem:\n");
        scanf("%s",paragem);
        for(int j=0;j<sistema->paragens->num_paragensp;j++){
        if(strcmp(paragem,sistema->paragens->nomep[j])==0){
            printf("A paragem %s ja existe no sistema, vou busca-la\n");
            //nao acabei lul
        }
        }
    }
    }
    }
}
void adicionar_paragem(Sistema *sistema,Linha *linha, char *nome_paragem, char *codigo_paragem, Paragem *paragens) {
      int indicadorlinha=sistema->num_linhas;
     --indicadorlinha;
     //Falta comparar com as paragens já existentes não quero nomes iguais nem cods TODO:
    if (indicadorlinha < 0 ) {
        printf("Indice de linha invalido!\n");
        return;
    } else {
        printf("Indice de linha valido\n");
        printf("Indicador linha->%d\n", indicadorlinha);
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
    printf("Paragens era Null\n");
        paragens->nomep = malloc(sizeof(char *));
        paragens->codigop=malloc(sizeof(char *));
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
        printf("Erro a alocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
        exit(1);
        }
        
    }
    else {
        printf("Paragens nao era Null\n");
        paragens->nomep = realloc(paragens->nomep, (paragens->num_paragensp + 1) * sizeof(char *));
        paragens->codigop = realloc(paragens->codigop,(paragens->num_paragensp + 1)* sizeof(char *));
        printf("Estranho\n");
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
            printf("Erro a realocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
            exit(1);
        }
    }
    

    printf("siga\n");
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
void adicionaparagemutilizador(Paragem *paragens){
    char Nnome[40];
    char cod[6];
    printf("Introduza o nome da paragem\n");
    scanf("%s",Nnome);
    //Falta comparar com as paragens já existentes não quero nomes iguais TODO:
  if (paragens->nomep == NULL || paragens->num_paragensp == 0) {
    printf("Paragens era Null\n");
        paragens->nomep = malloc(sizeof(char *));
        paragens->codigop=malloc(sizeof(char *));
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
        printf("Erro a alocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
        exit(1);
        }
        
    }
    else {
        printf("Paragens nao era Null\n");
        paragens->nomep = realloc(paragens->nomep, (paragens->num_paragensp + 1) * sizeof(char *));
        paragens->codigop = realloc(paragens->codigop,(paragens->num_paragensp + 1)* sizeof(char *));
        printf("Estranho\n");
        if (paragens->nomep == NULL || paragens->codigop == NULL) {
            // erro ao alocar memória
            printf("Erro a realocar memoria do tamanho do ponteiro no adicionaparagemutilizador\n");
            exit(1);
        }
    }
    

    printf("siga\n");
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
void adicionalinhadoc(Sistema *sistema,Paragem *paragens){
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
                printf ("\nLinha [%s] ainda nao mandei para a func\n",linha123);
                adicionar_linha(sistema, linha123);//apenas para ficheiros
                printf("ja mandei\n");
                printf("HELP\n");
            } else { // paragem       
                printf("Paragem time\n");         
                char nome_paragem[MAX_NOME_PARAGEM], codigo[MAX_CODIGO_PARAGEM];
                sscanf(linha123, "%[^#] #%s", nome_paragem, codigo);
                printf("Codigo:%s\n",codigo);
                int indicador=sistema->num_linhas;
                --indicador;
                Linha *linha = (&sistema->linhas[indicador]);
                printf("Vou enviar a paragem\n");
                adicionar_paragem(sistema,linha, nome_paragem, codigo,paragens);//falta guardar o codigo
                
                printf("Paragens da Linha-> [-%s-]\n",linha->nome);
                printf("Numero de paragens da linha ->%d\n",linha->num_paragens);
                


                //adicionar_paragem_linha(&sistema, sistema.linhas[sistema.num_linhas - 1].nome, nome_paragem);
            }
        }
    }
    fclose(arquivo);

}
void printalinhas(Sistema *sistema){
    
    for (int i=0; i < sistema->num_linhas;i++){
        printf("Linha-> [-%s-]\n",sistema->linhas[i].nome);

    }
}

void printaparagens(Sistema *sistema){
    for (int i=0; i < sistema->num_linhas;i++){
        Linha *linha = &sistema->linhas[i];
        printf("Paragens da Linha-> [-%s-]\n",linha->nome);
        printf("Numero de paragens da linha ->%d\n",linha->num_paragens);
        for (int x = 0; x < linha->num_paragens;x++){
            printf("Paragem: %s %s\n",linha->paragens[x], linha->codigo[x]);
        
        }
    }
    
}
void printaparagensU(Paragem *paragens){
    printf("Paragens do utilizador:\n");
    for (int u=0; u < paragens->num_paragensp; u++){
        if(paragens->codigop[u][0] == 'U'){
        printf("->%s %s\n",paragens->nomep[u], paragens->codigop[u]);
        }
    }
}

void removerparagens(Paragem *paragens){
    char escolhido[10];
    int numero;
    if (paragens->num_paragensp == 0 ){
        printf("Impossivel remover paragens no momento\n");
    }
    else {
        printaparagensU(paragens);
        printf("Introduza o codigo da paragem a ser removida\n");
        scanf("%s", escolhido);
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
            break;
            }
        }
    }
}
//FIXME:

/*
Paragem *encontrar_paragem(Sistema *sistema, char *nome_paragem) {
    for (int i = 0; i < sistema->Snumparagens; i++) {
        if (strcmp(sistema->paragens[i].nomep, nome_paragem) == 0) {
            return &(sistema->paragens[i]);
        }
    }
    return NULL;
}
//O stress aqui é que quando adiciono as paragens as linhas devo tambem guardar os nomes das paragens 
//para ter onde dps ir comparalas dai querer compara com a struct paragem e o nomep
int linha_tem_paragem(Linha *linha, char *nome_paragem) {
    for (int i = 0; i < linha->num_paragens; i++) {
        if (strcmp(linha->paragens[i], nome_paragem) == 0) {
            return 1;
        }
    }
    return 0;
}

NoLinha* obter_linhas_com_paragem(Sistema *sistema, char *nome_paragem) {
    NoLinha *resultado = NULL;
    for (int i = 0; i < sistema->num_linhas; i++) {
        Linha *linha = &sistema->linhas[i];
        if (linha_tem_paragem(linha, nome_paragem)) {
            NoLinha *no = malloc(sizeof(NoLinha));
            no->linha = &sistema->linhas[i];
            no->prox = resultado;
            resultado = no;
        }
    }
    return resultado;
}

NoParagem* obter_paragens_da_linha(Sistema *sistema, char *nome_linha) {
    for (int i = 0; i < sistema->num_linhas; i++) {
        Linha *linha = &sistema->linhas[i];
        if (strcmp(linha->nome, nome_linha) == 0) {
            NoParagem *resultado = NULL;
            for (int j = 0; j < linha->num_paragens; j++) {
                Paragem *paragem = encontrar_paragem(sistema, linha->paragens[j]);
                NoParagem *no = malloc(sizeof(NoParagem));
                no->paragem = paragem;
                no->prox = resultado;
                resultado = no;
            }
            return resultado;
        }
    }
    return NULL;
}


NoPercurso* calcular_percursos(Sistema *sistema, char* nome_partida, char* nome_chegada) {

    // Inicializar a lista ligada de percursos
    NoPercurso *lista_percursos = NULL;

    // Encontrar a paragem de partida
    Paragem *partida = encontrar_paragem(sistema, nome_partida);//Não quero usar a estrutura paragem
    if (partida == NULL) {
        printf("Paragem de partida nao encontrada!\n");
        return NULL;
    }

    // Encontrar a paragem de chegada
    Paragem *chegada = encontrar_paragem(sistema, nome_chegada);//Não quero usar a estrutura paragem
    if (chegada == NULL) {
        printf("Paragem de chegada nao encontrada!\n");
        return NULL;
    }

    // Para cada linha que contém a paragem de partida, verificamos se também contém
    // a paragem de chegada. Se sim, adicionamos o percurso na lista ligada de percursos.
    for (int i = 0; i < sistema->num_linhas; i++) {
        Linha linha_partida = sistema->linhas[i];
        if (linha_tem_paragem(linha_partida, nome_partida)) {
            for (int j = 0; j < sistema->num_linhas; j++) {
                Linha linha_chegada = sistema->linhas[j];
                if (linha_tem_paragem(linha_chegada, nome_chegada)) {

                    // Se as paragens de partida e chegada estão na mesma linha, adicionamos
                    // um percurso com apenas uma linha
                    if (linha_partida.nome == linha_chegada.nome) {
                        Percurso *percurso = criar_percurso(&linha_partida, partida, chegada);
                        adicionar_percurso_lista(&lista_percursos, percurso);
                    }

                    // Se as paragens de partida e chegada estão em linhas diferentes, procuramos
                    // uma paragem de transbordo e adicionamos um percurso com duas linhas
                    else {
                        Paragem *transbordo = encontrar_paragem_transbordo(&linha_partida, &linha_chegada);
                        if (transbordo != NULL) {
                            Percurso *percurso1 = criar_percurso(&linha_partida, partida, transbordo);
                            Percurso *percurso2 = criar_percurso(&linha_chegada, transbordo, chegada);
                            adicionar_percurso_lista(&lista_percursos, percurso1);
                            adicionar_percurso_lista(&lista_percursos, percurso2);
                        }
                    }
                }
            }
        }
    }

    // Retornar a lista de percursos encontrados
    return lista_percursos;
}
*/
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
void encontrar_percurso(NoLinha *lista_linhas, char *partida, char *chegada) {
    
    NoLinha *no = lista_linhas;
    int encontrou_percurso = 0;

    while (no != NULL) {
        Linha *linha = no->linha;

        // Procurar a paragem de partida na linha atual
        int encontrou_partida = 0;
        int i;
        printf("Linha em estudo: [%s]\n",linha->nome);
        for (i = 0; i < linha->num_paragens; i++) {
            printf("Vou comparar : %s com : %s\n",linha->paragens[i], partida);
            if (strcmp(linha->paragens[i], partida) == 0) {
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
        printf("Linha em estudo: [%s]\n",linha->nome);
        for (; i < linha->num_paragens; i++) {
             printf("Vou comparar : %s com : %s\n",linha->paragens[i], chegada);
            if (strcmp(linha->paragens[i], chegada) == 0) {
                printf("Encontrei\n");
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
        printf("Linha %s: ", linha->nome);
        for (int j = i; j >= 0; j--) {
            printf("%s", linha->paragens[j]);
            if (j > 0) {
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

   void libertar_sistema(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas) {
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






int menu(Sistema *sistema, Paragem *paragens, NoLinha *lista_linhas){
    int opcao;
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
         removerparagens(paragens);
         break;
      case 3:
         printf("Opcao 3 selecionada\n");
         printaparagens(sistema);
         printaparagensU(paragens);
         break;
      case 4:
         printf("Opcao 4 selecionada\n");
         adicionalinhadoc(sistema, paragens);
         break;
      case 5:
         printf("Opcao 5 selecionada\n");
         break;
      case 6:
         printf("Opcao 6 selecionada\n");
         printalinhas(sistema);
         break;
      case 7:
         printf("Opcao 7 selecionada\n");
         char paragem_incio[246],paragem_fim[246];
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
         paragem_incio[strcspn(paragem_incio, "\n")] = '\0'; // remove o caractere de nova linha

         printf("Paragem Destino: \n");
         fflush(stdout);
         fgets(paragem_fim, sizeof(paragem_fim), stdin);
         paragem_fim[strcspn(paragem_fim, "\n")] = '\0'; // remove o caractere de nova linha


         
         encontrar_percurso(lista_linhas,paragem_incio,paragem_fim);
         break;
      case 8:
            printf("Opcao 8 selecionada\n");
            libertar_sistema(sistema, paragens, lista_linhas);
            printf("Adeus!\n");
            flag2=0;
            break;
      default:
         printf("Opçao inválida\n");
         break;
   }

}



