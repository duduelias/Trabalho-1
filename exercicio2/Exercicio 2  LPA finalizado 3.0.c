#include<stdio.h>
#include<stdlib.h>

int comparaCrescente( const void * a, const void * b){
    if (*(int*)a == *(int*)b)
        return 0;//iguais
    else
        if(*(int*)a < *(int*)b)
            return -1;//vem antes
        else
            return 1;//vem depois
    }//Esta fun��o ser� utilizada na fun��o qsort para ordenar os elementos do vetor de forma crescente

//Este programa receber� elementos inteiros para um vetor, os ordenar� e imprimir� na tela quais destes elementos aparecem uma unica vez
int main (){
    int i,n;
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&n);
    int *vet = (int*)calloc(n,sizeof(int));//aloca��o dinamica de memoria para o vetor
    if(n<=0){
    	printf("Voce digitou um tamanho invalido para o vetor");
	}//checando se o vetor possui tamanho minimo suficiente para a execu��o do programa
	else{
    printf("Entre com os elementos do vetor\n");
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }//recebendo os elementos do vetor
    qsort(vet, n, sizeof(int), comparaCrescente);//ordenando os elementos de forma crescente
    printf("\nOs valores que aparecem uma unica vez sao:\n");
    if(n == 1){
    	printf("%d\n",vet[0]);
	}//se o vetor possuir apenas um elemento, este elemento ser� o unico elemento �nico
	else{
    if(vet[0] != vet[1]){
    	printf("%d\n",vet[0]);
	}//como o primeiro elemento ser� o menor do vetor ele ser� �nico se for diferente do pr�ximo elemento do vetor
	for(i=1; i<n-1; i++){
		if(vet[i] != vet[i-1] && vet[i] != vet[i+1]){
			printf("%d\n",vet[i]);
		}
	}//cada elemento, com exce��o do primeiro e ultimo, ser� �nico se for diferente do seu antecessor e seu sucessor
	if(vet[n-2] != vet[n-1]){
		printf("%d\n",vet[n-1]);
	}//o ultimo elemento ser� �nico se for diferente de seu antecessor
}
}
	free(vet);
    return 0;
    system("pause");
}
