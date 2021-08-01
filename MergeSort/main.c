#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
//Bibliotecas com funções basicas do C além da locale.h que permite a escrita com acentuação.
void mergeSort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio, int fim);
//Declaração das funções, além da melhoria de performance, ajuda na hora de usar as funções.
int tam;
int cancelarPaP=0;
//Variaveis universais criadas para manter consistencia durante toda a execução do codigo, por exemplo tam vai ser o tamanho do vetor para qualquer vetor criado durante a execução do codigo, e cancelarPaP vai manter a decisão do usuario de ver ou não os passos da recursividade.
int main()
{
    setlocale(LC_ALL, "Portuguese");
	//Colocando a linguagem exibida como português.
//Declarando ponteiro "*v"
    int *v;
//função para gerar números aleatórios
    srand(time(NULL));

    printf("\nMERGESORT: ");
    printf("\n--------------------------------------");
    // "Printf" e "Scanf" para o usuário escolher o tamanho do vetor
    printf("\nDigite um tamanho para o vetor que vai ter valores gerados aleatoriamente:\n");
    scanf("%d", &tam);

    printf("\nDeseja mostrar o passo a passo da recursividade?\nOs detalhes estão no relatório\nDigite 0 para sim e qualquer outro numero para não:\n");
    int sel;
    scanf("%d", &sel);
    if(!sel){}
    else{
        cancelarPaP=1;
    }
	//Parte do codigo criada para demonstrar ou não os passos para ajudar na compreensão do codigo, se o usuario digitar qualquer numero alem de 0 ela será desativada para não poluir o codigo.
	//Tal função funciona melhor para acompanhar os passos da recursividade, para ver um resultado semelhante ao relatorio use um vetor com 4 posições.
	//As informações dos simbolos estão no relatorio do Grupo 3.

// Alocação de memória para o vetor "v" do tipo inteiro do tamanho "tam"
    v = (int*) malloc(tam * sizeof(int));
// Testando se a alocação de memória foi feita corretamente
    if(v == NULL){
        printf("ERRO NO MALLOC");
        exit(1);
    }
// Atribuindo valores para o vetor "v" utilizando a função "rand" que gera números aleatórios
    for(int c = 0; c < tam; c++){
           v[c] = (rand() % 100);
    }
// Printf para mostrar o vetor desordenado na tela
    printf("\n--------------------------------------");
    for(int c = 0; c < tam; c++){
            printf("\nPosição %d do vetor desordenado: %d\n", c, v[c]);
    }

    printf("\n--------------------------------------");
    if(!cancelarPaP){
            printf("\nPasso a passo das ações recursivas:\n");
    }
    //Chamando e passando valores para a função mergesort
    mergeSort(v,0, tam - 1);

    printf("\n--------------------------------------");
//printf para mostrar vetor ordenado na tela
    for(int c = 0; c < tam; c++){
            printf("\nPosição %d do vetor ordenado: %d\n", c, v[c]);
    }
    printf("\n--------------------------------------");

    system("pause");
//liberando memória do vetor "v"
    free(v);

    return 0;
}

void merge(int *V, int inicio, int meio, int fim){
//Declaração de variáveis que serão usadas durante a execução da função
    int *temp, p1, p2, tamanho, i, j, k;
//alocação de memória dinâmica de tamanho "tam" do tipo inteiro
    temp = (int*) malloc(tam * sizeof(int));
// verificando se a alocação foi feita corretamente
    if(temp == NULL){
        printf("ERRO NO MALLOC");
        exit(1);
    }

    int fim1 = 0, fim2 = 0;
// declarando o tamanho do vetor na variável "tamanho"
    tamanho = fim - inicio + 1;
//marcando o inicio e o meio do vetor por meio das variáveis "p1" e "p2"
    p1 = inicio;
    p2 = meio + 1;

    if(temp != NULL){
// "for" para varrer o vetor "V"
        for(i = 0; i<tamanho; i++){
//"if" para validar se o "fim1" ou "fim2" continuam com o valor "0"
            if(!fim1 && !fim2){
// verificando se a posição "p1" do 1º subvetor é menor que a posição "p2" que dá início ao 2º subvetor
                if(V[p1] < V[p2])
// se a posição "p1" for a menor, então ela é passada para o  vetor temporário "temp", e há uma incrementação da variável "p1"
                    temp[i] = V[p1++];
                    else
// se a posição "p2" for a menor, então ela é passada para o  vetor temporário, e há uma incrementação da variável "p2"
                        temp[i] = V[p2++];
// "if" para atribuir o valor "1" para "fim1" ou "fim2" caso "p1" ultrapasse o valor do que marca a metade do vetor ou "p2" ultrapasse o valor que marca o final do vetor
                    if(p1>meio) fim1=1;
                    if(p2>fim) fim2=1;
                }

//com "fim1" ou "fim2" atingindo o valor "1", o valor que sobrou no 1º ou no 2º subvetor é passado para o vetor temporário "temp"
                else{
                    if(!fim1)
                        temp[i] = V[p1++];
                    else
                        temp[i] = V[p2++];

            }
        }
//Valores são passados de forma ordenada do vetor temporário "temp" para o vetor "V"
        for(j = 0, k =  inicio; j<tamanho; j++, k++){
            V[k] =  temp[j];
        }
    }
//liberando memória do vetor "temp"
    free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
	//Declara o meio do subvetor, que vai ser usado para parametro de comparação.
    if(inicio < fim){
		//Condição de parada da chamada recursiva do MergeSort.
        if(!cancelarPaP){
                printf("\nInicio<Fim true");
        }
		//Condição de demonstrar os passos da recursividade.
        meio = floor((inicio+fim)/2);
		//Conseguindo o valor de meio a partir do floor dos valores inicio e fim, ou seja, do menor resultado de um possivel numero quebrado, por exemplo 4,5 ficaria 4.
        if(!cancelarPaP){
                printf("\n-MS-");
        }
		//Condição de demonstrar os passos da recursividade.
        mergeSort(V,inicio,meio);
		//Chamando o mergeSort para criar o subvetor do lado esquerdo, para fins de comparação no merge().
        if(!cancelarPaP){
                printf("\n+MS+");
        }
		//Condição de demonstrar os passos da recursividade.
        mergeSort(V,meio+1,fim);
		//Chamando o mergeSort para criar o subvetor do lado direito, para fins de comparação no merge().
        if(!cancelarPaP){
                printf("\n?Merge?");
        }
		//Condição de demonstrar os passos da recursividade.
        merge(V, inicio, meio, fim);
		//Chamando a função merge() com as posições completas do subvetor, sendo elas inicio, meio e fim, tal função vai unificar subvetores afim de criar um vetor principal ordenado.


    }

}

