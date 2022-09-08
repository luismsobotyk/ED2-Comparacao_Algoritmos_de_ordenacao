#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 100000
void mergeSort(int vec[], int vecSize);
void merge(int vec[], int vecSize);
main(){
	FILE *txt;
	txt=fopen("Arquivo.txt", "r");
	int v[TAMANHO], n=TAMANHO;
	int j= 0, aux, chave;
	int i=0;
	printf("\nCarregando o Arquivo no Vetor");
	while(i<n){
		fscanf(txt, "%i", &v[i]);
		i++;
	}
	fclose(txt);
	
	// Algoritmo Bubble Sort
	mergeSort(v,n);
	// Fim

	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado_merge_sort.txt", "w");
	//Laço de impressão do Vetor
	for(i=0; i<n; i++){
		fprintf(txt, "%i\n", v[i]);
	}
	fclose(txt);
}

void mergeSort(int vec[], int vecSize){
	int mid;
	if (vecSize > 1){
		mid = vecSize / 2;
		mergeSort(vec, mid);
		mergeSort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
	}
}
void merge(int vec[], int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;
	tmp = (int*) malloc(vecSize * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}
	mid = vecSize / 2;
	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < vecSize) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		}else {
			tmp[k] = vec[j];
			++j;
		}
		++k;
	}
	if (i == mid) {
		while (j < vecSize) {
			tmp[k] = vec[j];
			++j;
			++k;
		}
	}else {
		while (i < mid) {
			tmp[k] = vec[i];
			++i;
			++k;
		}
	}
	for (i = 0; i < vecSize; ++i) {
		vec[i] = tmp[i];
		//printf("%d\n", i+1);
	}
	free(tmp);
}


