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
    }//Esta função será utilizada na função qsort para ordenar os elementos do vetor de forma crescente

//Este programa receberá elementos inteiros para um vetor, os ordenará e imprimirá na tela quais destes elementos aparecem uma unica vez
int main (){
    int i,n;
    printf("Digite o tamanho do vetor\n");
    scanf("%d",&n);
    int *vet = (int*)calloc(n,sizeof(int));//alocação dinamica de memoria para o vetor
    if(n<=0){
    	printf("Voce digitou um tamanho invalido para o vetor");
	}//checando se o vetor possui tamanho minimo suficiente para a execução do programa
	else{
    printf("Entre com os elementos do vetor\n");
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }//recebendo os elementos do vetor
    qsort(vet, n, sizeof(int), comparaCrescente);//ordenando os elementos de forma crescente
    printf("\nOs valores que aparecem uma unica vez sao:\n");
    if(n == 1){
    	printf("%d\n",vet[0]);
	}//se o vetor possuir apenas um elemento, este elemento será o unico elemento único
	else{
    if(vet[0] != vet[1]){
    	printf("%d\n",vet[0]);
	}//como o primeiro elemento será o menor do vetor ele será único se for diferente do próximo elemento do vetor
	for(i=1; i<n-1; i++){
		if(vet[i] != vet[i-1] && vet[i] != vet[i+1]){
			printf("%d\n",vet[i]);
		}
	}//cada elemento, com exceção do primeiro e ultimo, será único se for diferente do seu antecessor e seu sucessor
	if(vet[n-2] != vet[n-1]){
		printf("%d\n",vet[n-1]);
	}//o ultimo elemento será único se for diferente de seu antecessor
}
}
	free(vet);
    return 0;
    system("pause");
}
