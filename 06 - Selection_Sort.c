#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 100000

main(){
	int* v = malloc(TAMANHO*sizeof(int));
	if(v == NULL){
		printf("Memória insuficiente para alocação.");
		exit(1);
	}
	FILE *txt;
	txt=fopen("Arquivo100k.txt", "r");
	int i=0;
	printf("\nCarregando o Arquivo no Vetor");
	int porcentagem=0;
	while(i<TAMANHO){
		fscanf(txt, "%i", &v[i]);
		i++;
		float percent= TAMANHO/100;
		if(i-porcentagem>=percent){
			porcentagem= porcentagem+percent;
			system("cls");
			printf("Carregando o Arquivo no Vetor\nStatus: %f %%", porcentagem/percent);
		}
	}
	
	fclose(txt);
	printf("\nIniciando Ordenacao");
	
	// Algoritmo Selection Sort
	int j, min;
	for (i = 0; i < (TAMANHO-1); i++) {
		min = i;
		for (j = (i+1); j < TAMANHO; j++) {
			if(v[j] < v[min]) {
				min = j;
			}
		}
		if (i != min) {
			int swap = v[i];
			v[i] = v[min];
			v[min] = swap;
		}
	}
		
	// Fim
	
	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado_selection_sort_100k.txt", "w");
	
	//Laço de impressão do Vetor
	for(i=0; i<TAMANHO; i++){
		fprintf(txt, "%i\n", v[i]);
	}
	fclose(txt);
	free(v);
}
