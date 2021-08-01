#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
//Bibliotecas com fun��es basicas do C al�m da locale.h que permite a escrita com acentua��o.
void mergeSort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio, int fim);
//Declara��o das fun��es, al�m da melhoria de performance, ajuda na hora de usar as fun��es.
int tam;
int cancelarPaP=0;
//Variaveis universais criadas para manter consistencia durante toda a execu��o do codigo, por exemplo tam vai ser o tamanho do vetor para qualquer vetor criado durante a execu��o do codigo, e cancelarPaP vai manter a decis�o do usuario de ver ou n�o os passos da recursividade.
int main()
{
    setlocale(LC_ALL, "Portuguese");
	//Colocando a linguagem exibida como portugu�s.
//Declarando ponteiro "*v"
    int *v;
//fun��o para gerar n�meros aleat�rios
    srand(time(NULL));

    printf("\nMERGESORT: ");
    printf("\n--------------------------------------");
    // "Printf" e "Scanf" para o usu�rio escolher o tamanho do vetor
    printf("\nDigite um tamanho para o vetor que vai ter valores gerados aleatoriamente:\n");
    scanf("%d", &tam);

    printf("\nDeseja mostrar o passo a passo da recursividade?\nOs detalhes est�o no relat�rio\nDigite 0 para sim e qualquer outro numero para n�o:\n");
    int sel;
    scanf("%d", &sel);
    if(!sel){}
    else{
        cancelarPaP=1;
    }
	//Parte do codigo criada para demonstrar ou n�o os passos para ajudar na compreens�o do codigo, se o usuario digitar qualquer numero alem de 0 ela ser� desativada para n�o poluir o codigo.
	//Tal fun��o funciona melhor para acompanhar os passos da recursividade, para ver um resultado semelhante ao relatorio use um vetor com 4 posi��es.
	//As informa��es dos simbolos est�o no relatorio do Grupo 3.

// Aloca��o de mem�ria para o vetor "v" do tipo inteiro do tamanho "tam"
    v = (int*) malloc(tam * sizeof(int));
// Testando se a aloca��o de mem�ria foi feita corretamente
    if(v == NULL){
        printf("ERRO NO MALLOC");
        exit(1);
    }
// Atribuindo valores para o vetor "v" utilizando a fun��o "rand" que gera n�meros aleat�rios
    for(int c = 0; c < tam; c++){
           v[c] = (rand() % 100);
    }
// Printf para mostrar o vetor desordenado na tela
    printf("\n--------------------------------------");
    for(int c = 0; c < tam; c++){
            printf("\nPosi��o %d do vetor desordenado: %d\n", c, v[c]);
    }

    printf("\n--------------------------------------");
    if(!cancelarPaP){
            printf("\nPasso a passo das a��es recursivas:\n");
    }
    //Chamando e passando valores para a fun��o mergesort
    mergeSort(v,0, tam - 1);

    printf("\n--------------------------------------");
//printf para mostrar vetor ordenado na tela
    for(int c = 0; c < tam; c++){
            printf("\nPosi��o %d do vetor ordenado: %d\n", c, v[c]);
    }
    printf("\n--------------------------------------");

    system("pause");
//liberando mem�ria do vetor "v"
    free(v);

    return 0;
}

void merge(int *V, int inicio, int meio, int fim){
//Declara��o de vari�veis que ser�o usadas durante a execu��o da fun��o
    int *temp, p1, p2, tamanho, i, j, k;
//aloca��o de mem�ria din�mica de tamanho "tam" do tipo inteiro
    temp = (int*) malloc(tam * sizeof(int));
// verificando se a aloca��o foi feita corretamente
    if(temp == NULL){
        printf("ERRO NO MALLOC");
        exit(1);
    }

    int fim1 = 0, fim2 = 0;
// declarando o tamanho do vetor na vari�vel "tamanho"
    tamanho = fim - inicio + 1;
//marcando o inicio e o meio do vetor por meio das vari�veis "p1" e "p2"
    p1 = inicio;
    p2 = meio + 1;

    if(temp != NULL){
// "for" para varrer o vetor "V"
        for(i = 0; i<tamanho; i++){
//"if" para validar se o "fim1" ou "fim2" continuam com o valor "0"
            if(!fim1 && !fim2){
// verificando se a posi��o "p1" do 1� subvetor � menor que a posi��o "p2" que d� in�cio ao 2� subvetor
                if(V[p1] < V[p2])
// se a posi��o "p1" for a menor, ent�o ela � passada para o  vetor tempor�rio "temp", e h� uma incrementa��o da vari�vel "p1"
                    temp[i] = V[p1++];
                    else
// se a posi��o "p2" for a menor, ent�o ela � passada para o  vetor tempor�rio, e h� uma incrementa��o da vari�vel "p2"
                        temp[i] = V[p2++];
// "if" para atribuir o valor "1" para "fim1" ou "fim2" caso "p1" ultrapasse o valor do que marca a metade do vetor ou "p2" ultrapasse o valor que marca o final do vetor
                    if(p1>meio) fim1=1;
                    if(p2>fim) fim2=1;
                }

//com "fim1" ou "fim2" atingindo o valor "1", o valor que sobrou no 1� ou no 2� subvetor � passado para o vetor tempor�rio "temp"
                else{
                    if(!fim1)
                        temp[i] = V[p1++];
                    else
                        temp[i] = V[p2++];

            }
        }
//Valores s�o passados de forma ordenada do vetor tempor�rio "temp" para o vetor "V"
        for(j = 0, k =  inicio; j<tamanho; j++, k++){
            V[k] =  temp[j];
        }
    }
//liberando mem�ria do vetor "temp"
    free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
	//Declara o meio do subvetor, que vai ser usado para parametro de compara��o.
    if(inicio < fim){
		//Condi��o de parada da chamada recursiva do MergeSort.
        if(!cancelarPaP){
                printf("\nInicio<Fim true");
        }
		//Condi��o de demonstrar os passos da recursividade.
        meio = floor((inicio+fim)/2);
		//Conseguindo o valor de meio a partir do floor dos valores inicio e fim, ou seja, do menor resultado de um possivel numero quebrado, por exemplo 4,5 ficaria 4.
        if(!cancelarPaP){
                printf("\n-MS-");
        }
		//Condi��o de demonstrar os passos da recursividade.
        mergeSort(V,inicio,meio);
		//Chamando o mergeSort para criar o subvetor do lado esquerdo, para fins de compara��o no merge().
        if(!cancelarPaP){
                printf("\n+MS+");
        }
		//Condi��o de demonstrar os passos da recursividade.
        mergeSort(V,meio+1,fim);
		//Chamando o mergeSort para criar o subvetor do lado direito, para fins de compara��o no merge().
        if(!cancelarPaP){
                printf("\n?Merge?");
        }
		//Condi��o de demonstrar os passos da recursividade.
        merge(V, inicio, meio, fim);
		//Chamando a fun��o merge() com as posi��es completas do subvetor, sendo elas inicio, meio e fim, tal fun��o vai unificar subvetores afim de criar um vetor principal ordenado.


    }

}

