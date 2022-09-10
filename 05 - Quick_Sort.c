#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 10000000
// quick sort
void swap(int* a, int* b);
int partition(int vec[], int left, int right);
void quickSort(int vec[], int left, int right);

main(){
	int* v = malloc(TAMANHO*sizeof(int));
	if(v == NULL){
		printf("Memória insuficiente para alocação.");
		exit(1);
	}
	FILE *txt;
	txt=fopen("Arquivo500k.txt", "r");
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
	
	// Algoritmo Quick Sort
	quickSort(v,0,TAMANHO-1);	
	// Fim
	
	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado_quick_sort_500k.txt", "w");
	
	//Laço de impressão do Vetor
	for(i=0; i<TAMANHO; i++){
		fprintf(txt, "%i\n", v[i]);
	}
	fclose(txt);
	free(v);
}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int* vec, int left, int right) {
	int i, j;
	i = left;
		for (j = left + 1; j <= right; ++j) {
			if (vec[j] < vec[left]) {
				++i;
				swap(&vec[i], &vec[j]);
			}
		}
		swap(&vec[left], &vec[i]);
		return i;
}
void quickSort(int* vec, int left, int right) {
	int r;
	if (right > left) {
		r = partition(vec, left, right);
		quickSort(vec, left, r - 1);
		quickSort(vec, r + 1, right);
	}
}

