#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 512 
#define MAX_CAST_LISTED 20
#define MAX_PARTS 60
#define MAX_LISTA 2000

typedef struct SHOW{

    char showId[7]; 
    char type[MAX];
    char title[MAX];
    char director[MAX];
    char cast[MAX_CAST_LISTED][MAX];
    int castCount;
    char country[MAX];
    char dateAdded[MAX];
    int realeseYear;
    char rating[MAX];
    char duration[MAX];
    char listedIn[MAX_CAST_LISTED][MAX];
    int listedInCount;

} Show;

// Definição do nó da pilha
typedef struct CelulaPilha {
    Show* show;
    struct CelulaPilha* prox;
} CelulaPilha;

// Definição da pilha dinâmica
typedef struct {
    CelulaPilha* topo;
    int tamanho;
} Pilha;

/** 
 * Aloca uma matriz de strings
 * @param rows Número de linhas
 * @return Ponteiro para a matriz alocada ou NULL em caso de falha
 */
char** alocar(int rows){
    if(rows <= 0 || rows > MAX_CAST_LISTED){
        return NULL;
    }
    char** matrix = (char**)malloc(rows * sizeof(char*));
    if(matrix == NULL){
        return NULL;
    }
    for(int i = 0; i < rows; i++){
        matrix[i] = (char*)malloc(MAX * sizeof(char));
        if(matrix[i] == NULL){
            for(int j = 0; j < i; j++){
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
        matrix[i][0] = '\0';
    }
    return matrix;
}
/**
 * Alocar espa�o para Array de Shows
 * @param n Tamanho do array
 * @return Array alocado
 */
Show* ArrayShow(int n){
    Show* s = (Show*)malloc(n * sizeof(Show));
    if(!s) return NULL;
    return s;
}

const char* getShowId(Show* show){

    return show->showId;
}

void setShowId(Show* show, const char* id){

    strcpy(show->showId, id);
}

const char* getType(Show* show){

    return show->type;
}

void setType(Show* show, const char* type){

    strcpy(show->type, type);
}

const char* getTitle(Show* show){

    return show->title;
}

void setTitle(Show* show, const char* title){

    strcpy(show->title, title);
}

const char* getDirector(Show* show){

    return show->director;
}

void setDirector(Show* show, const char* director){

    strcpy(show->director, director);
}

char** getCastMember(const Show* show){

    if(show == NULL || show->castCount <= 0 || show->castCount > MAX_CAST_LISTED){

        return NULL;
    }
    char** castArray = alocar(show->castCount);
    if(castArray == NULL){
        return NULL;
    }

    for(int i = 0; i < show->castCount; i++){
        strcpy(castArray[i], show->cast[i]);
    }
    return (char**)castArray;
}

void setCastMembers(Show* show, char** cast, int count){
    for(int i = 0; i < count; i++){
        strcpy(show->cast[i], cast[i]);
    }
    show->castCount = count;
}

const char* getCountry(Show* show){

    return show->country;
}

void setCountry(Show* show, const char* country){
    strcpy(show->country, country);
}

const char* getDateAdded(Show* show){

    return show->dateAdded;
}

void setDateAdded(Show* show, const char* date){

    strcpy(show->dateAdded, date);
}


int getReleaseYear(Show* show){

    return show->realeseYear;
}

void setReleaseYear(Show* show, int year){

    show->realeseYear = year;
}

const char* getRating(Show* show){

    return show->rating;
}

void setRating(Show* show, const char* rating){

    strcpy(show->rating, rating);
}

const char* getDuration(Show* show){

    return show->duration;
}

void setDuration(Show* show, const char* duration){
    strcpy(show->duration, duration);
}

char** getListedIn(const Show* show){
    // Verifica show
    if(show == NULL || show->listedInCount <= 0 || show->listedInCount > MAX_CAST_LISTED){
        return NULL;
    }
    // Aloca a matriz de strings
    char** listedInArray = alocar(show->listedInCount);
    if(listedInArray == NULL){

        return NULL;
    }
    // Copia cada categoria para a matriz alocada
    for(int i = 0; i < show->listedInCount; i++){
        strcpy(listedInArray[i], show->listedIn[i]);
    }
    return (char**)listedInArray;
}

void setListedIn(Show* show, char** listed, int count){
    if(count > MAX_CAST_LISTED) count = MAX_CAST_LISTED;
    for(int i = 0; i < count; i++){
        strcpy(show->listedIn[i], listed[i]);
    }
    show->listedInCount = count;
}
/**
 * Função para clonar.
 *
 * @param original Ponteiro para a struct Show original.
 * @return Um novo Show com os mesmos dados do original.
 */
Show clone(const Show* original) {
    Show novo;
    strcpy(novo.showId, original->showId);
    strcpy(novo.type, original->type);
    strcpy(novo.title, original->title);
    strcpy(novo.director, original->director);
    strcpy(novo.country, original->country);
    strcpy(novo.dateAdded, original->dateAdded);
    strcpy(novo.rating, original->rating);
    strcpy(novo.duration, original->duration);
    novo.realeseYear = original->realeseYear;
    novo.castCount = original->castCount;
    for(int i = 0; i < original->castCount; i++){
        strcpy(novo.cast[i], original->cast[i]);
    }
    novo.listedInCount = original->listedInCount;
    for(int i = 0; i < original->listedInCount; i++){
        strcpy(novo.listedIn[i], original->listedIn[i]);
    }
    return novo;
}
/**
 * Imprime os dados de um show.
 *
 * @param show Ponteiro para a struct Show.
 */
void printar(Show show){
    printf("=> ");
    printf("%s ## ", show.showId);
    printf("%s ## ", show.title);
    printf("%s ## ", show.type);
    printf("%s ## ", show.director);
    printf("[");
    for(int i = 0; i < show.castCount; i++){
        printf("%s", show.cast[i]);
        if(i < show.castCount - 1){
           printf(", ");
        }
    }
    printf("] ## ");
    printf("%s ## ", show.country);
    printf("%s ## ", show.dateAdded);
    printf("%d ## ", show.realeseYear);
    printf("%s ## ", show.rating);
    printf("%s ## ", show.duration);
    printf("[");
    for(int i = 0; i < show.listedInCount; i++){
        printf("%s", show.listedIn[i]);
        if(i < show.listedInCount - 1){
           printf(", ");
        }
    }
    printf("] ##\n");
}
/**
 * Converte uma String em Array de Strings separadas por -
 *
 * @param str String de entrada.
 * @return Array de strings resultantes.
 */
char** StrToArrayStringToken(char* str){

    if(!str) return NULL;
    // Contar quantidade de '|'
    int cont = 0;
    int k = 0;
    while(str[k] != '\0'){
        if(str[k] == '|') cont++;
        k++;
    }
    int totalCampos = cont + 1;
    char** result = (char**)malloc(totalCampos * sizeof(char*));

    for (int i = 0; i < totalCampos; i++){

        result[i] = (char*)malloc(MAX * sizeof(char));
    }
    // Definir dados
    int campo = 0;
    int i = 0, j = 0;
    char tmp[MAX];
    int len = strlen(str);
    // Percorrer String
    while (i <= len){
        // Se for - ou \0 encerra o campo
        if(str[i] == '|' || str[i] == '\0'){
            tmp[j] = '\0';
            // Se campo for vazio = NaN
            if(j == 0){
                strcpy(result[campo++], "NaN");
            } else{
                // Copia o campo para o resultado
                strcpy(result[campo++], tmp);
            }
            // Reinicia temp
            j = 0;
        }else{
            tmp[j++] = str[i];
        }
        i++;
    }
    return result;
}

/**
 * Conta quantas virgulas uma String possui
 *
 * @param str String a ser contada
 * @return Quantia de v�rgulas
 */
int ContVir(char* str){
    // Definir dados
    int i = 0, cont = 0;
    while(str[i] != '\0'){
        if(str[i] == ','){
            cont++;
        }
        i++;
    }
    return cont;
}

/**
 * Converte uma String em Array de Strings separadas por virgulas
 * @param str String de entrada
 * @return Array de strings alocado dinamicamente ou NULL em caso de erro
 */
char** StrToArrayStringVir(char* str){
    if(!str){
        char** result = (char**)malloc(sizeof(char*));
        result[0] = (char*)malloc(MAX * sizeof(char));
        strcpy(result[0], "NaN");
        return result;
    }
    // Contar quantidade de virgulas
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++){

        if(str[i] == ',') cont++;
    }
    int totalCampos = cont + 1;
    char** result = (char**)malloc(totalCampos * sizeof(char*));
    for(int i = 0; i < totalCampos; i++){

        result[i] = (char*)malloc(MAX * sizeof(char));
        strcpy(result[i], "");
    }
    // Definir dados
    int campo = 0;
    int i = 0, j = 0;
    char tmp[MAX];
    int len = strlen(str);
    int primeiroChar = 1;
    int ultimoNaoEspaco = -1;
    while (i <= len){
        if(str[i] == ',' || str[i] == '\0'){
            tmp[j] = '\0';
            tmp[ultimoNaoEspaco + 1] = '\0';
            if(j == 0 || strlen(tmp) == 0){
                strcpy(result[campo++], "NaN");
            } else {
                strcpy(result[campo++], tmp);
            }
            j = 0;
            primeiroChar = 1;
            ultimoNaoEspaco = -1;
        }else{
            if(!(primeiroChar && str[i] == ' ')){
                if(str[i] != ' ') ultimoNaoEspaco = j;
                tmp[j++] = str[i];
                primeiroChar = 0;
            }
        }
        i++;
    }
    return result;
}


/**
 * Função para transformar string em inteiro
 * @param str String a ser transformada
 */
int toInt(char* str){
    // Definir dados
    int len = strlen(str);
    int data = 0;
    for(int i = 0; i < len; i++){
        char c = str[i];
        data = (10 * data) + (c - '0');
    }
    return data;
}

/**
 * Função para realizar a leitura de um show
 * @param in String de entrada
 */
Show Ler(const char* in){
    // Definir dados
    Show show;
    int len = strlen(in);
    bool flag = true;
    int j = 0;
    char* simplify = (char*)malloc(2 * MAX * sizeof(char));
    if(!simplify)return show;
    for(int i = 0; i < len; i++){

        char c = in[i];

        if(c == '"'){
            flag = !flag;
        } else if (c == ',' && flag){
            simplify[j++] = '|';
        } else {
            simplify[j++] = c;
        }
    }
    simplify[j] = '\0';
    char** ArrayStrings = StrToArrayStringToken(simplify);
    setShowId(&show, ArrayStrings[0]);
    setType(&show, ArrayStrings[1]);
    setTitle(&show, ArrayStrings[2]);
    setDirector(&show, ArrayStrings[3]);
    char** CastMembers = StrToArrayStringVir(ArrayStrings[4]);
    setCastMembers(&show, CastMembers, ContVir(ArrayStrings[4]) + 1);
    setCountry(&show, ArrayStrings[5]);
    setDateAdded(&show, ArrayStrings[6]);
    setReleaseYear(&show, toInt(ArrayStrings[7]));
    setRating(&show, ArrayStrings[8]);
    setDuration(&show, ArrayStrings[9]);
    char** ListedIn = StrToArrayStringVir(ArrayStrings[10]);
    setListedIn(&show, ListedIn, ContVir(ArrayStrings[10]) + 1);
    return show;
}

/**
 * Função para realizar leitura do arquivo CSV
 * @return Vetor de structs Show alocado dinamicamente.
 */
Show** LerCsv() {
    Show** resultado = calloc(1369, sizeof(Show*));
    FILE* csv = fopen("/tmp/disneyplus.csv", "rt");
    if (!csv) {
        printf("Erro ao abrir o arquivo");
        return NULL;
    }
    char* lixo = malloc(2048 * sizeof(char));
    fgets(lixo, 2047, csv);
    free(lixo);
    for(int i = 0; i < 1369; i++){
        char* buffer = malloc(2048 * sizeof(char));
        if(fgets(buffer, 2047, csv) == NULL){
            free(buffer);
        } else {
            buffer[strcspn(buffer, "\n")] = '\0';
            resultado[i] = malloc(sizeof(Show));
            *(resultado[i]) = Ler(buffer);
            free(buffer);
        }
    }
    fclose(csv);
    return resultado;
}
/**
 * Função que realiza a troca de duas strings
 * @param a String
 * @param b String
 */
void swap(char a[MAX], char b[MAX]){
    char temp[MAX];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
/**
 * Função de ordenação - Quicksort
 *
 * @param esq   �ndice inicial
 * @param dir   �ndice final
 * @param array Array de Strings a ser ordenado
 */
void quickSort(int esq, int dir, char arr[][MAX]){
    int i = esq, j = dir;
    char pivo[MAX];
    strcpy(pivo, arr[(esq + dir) / 2]);
    while (i <= j){
        while (strcmp(arr[i], pivo) < 0) i++;
        while (strcmp(arr[j], pivo) > 0) j--;
        if(i <= j){

            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if(esq < j) quickSort(esq, j, arr);
    if(i < dir) quickSort(i, dir, arr);
}

// Inicializa a pilha
void criarPilha(Pilha* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

// Empilha (push)
void empilhar(Pilha* p, Show* show) {
    CelulaPilha* nova = (CelulaPilha*)malloc(sizeof(CelulaPilha));
    nova->show = show;
    nova->prox = p->topo;
    p->topo = nova;
    p->tamanho++;
}

// Desempilha (pop)
Show* desempilhar(Pilha* p) {
    if (p->topo == NULL) return NULL;
    CelulaPilha* tmp = p->topo;
    Show* resp = tmp->show;
    p->topo = tmp->prox;
    free(tmp);
    p->tamanho--;
    return resp;
}

// Mostra todos os elementos da pilha (do topo para a base)
void mostrarPilha(Pilha* p) {
    Show* stack[2000];
    int idx = 0;
    for (CelulaPilha* c = p->topo; c != NULL; c = c->prox)
        stack[idx++] = c->show;
    for (int i = 0; i < idx; i++) {
        printf("[%d] ", 45 - i); // Começa em 45 e vai até 0
        printar(*stack[i]);
    }
}

// Libera toda a pilha
void liberarPilha(Pilha* p) {
    while (p->topo != NULL) {
        CelulaPilha* tmp = p->topo;
        p->topo = tmp->prox;
        free(tmp->show);
        free(tmp);
    }
}

int main() {
    Show** shows = LerCsv();
    if(shows == NULL){
        printf("Falha ao carregar os dados.\n");
        return 1;
    }

    Pilha pilha;
    criarPilha(&pilha);

    // Entrada de dados iniciais (primeira parte)
    char input[1001];
    scanf(" %1000[^\n]", input);
    while(strcmp(input, "FIM") != 0){
        for(int i = 0; i < 1369; i++){
            if(shows[i] != NULL && strcmp(getShowId(shows[i]), input) == 0){
                Show* novo = malloc(sizeof(Show));
                *novo = clone(shows[i]);
                empilhar(&pilha, novo);
                break;
            }
        }
        scanf(" %1000[^\n]", input);
    }

    // Segunda parte: comandos
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char comando[10], arquivo[1000];
        scanf(" %s", comando);

        if(strcmp(comando, "I") == 0){
            scanf(" %s", arquivo);
            for(int j = 0; j < 1369; j++){
                if(shows[j] != NULL && strcmp(getShowId(shows[j]), arquivo) == 0){
                    Show* novo = malloc(sizeof(Show));
                    *novo = clone(shows[j]);
                    empilhar(&pilha, novo);
                    break;
                }
            }
        } else if(strcmp(comando, "R") == 0){
            Show* removido = desempilhar(&pilha);
            if(removido != NULL){
                printf("(R) %s\n", removido->title);
                free(removido);
            }
        }
    }

    // Mostrar elementos restantes na pilha
    mostrarPilha(&pilha);

    // Liberar memória
    liberarPilha(&pilha);
    for(int i = 0; i < 1369; i++){
        if(shows[i] != NULL){
            free(shows[i]);
        }
    }
    free(shows);
    return 0;
}