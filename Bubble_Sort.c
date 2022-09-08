#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 100000

main(){
	FILE *txt;
	txt=fopen("Arquivo.txt", "r");
	int v[TAMANHO], n=TAMANHO;
	int j= 0, aux;
	int i=0;
	printf("\nCarregando o Arquivo no Vetor");
	while(i<n){
		fscanf(txt, "%i", &v[i]);
		i++;
	}
	fclose(txt);
	
	// Algoritmo Bubble Sort
	while (j < n){
		for(i = 0; i < n-1; i++){
			if(v[i] > v[i + 1]){
				aux=v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
		j++;
		printf("%d\n", j);
	}	
	// Fim

	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado_bubble_sort.txt", "w");
	//Laço de impressão do Vetor
	for(i=0; i<n; i++){
		fprintf(txt, "%i\n", v[i]);
	}
	fclose(txt);
}
