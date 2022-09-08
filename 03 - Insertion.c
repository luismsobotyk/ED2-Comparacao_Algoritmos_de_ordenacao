#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANHO 100000

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
	
	// Algoritmo Insertion
	for(j=1; j<n; j++){
		chave = v[j];
		i = j-1;
		while(i >= 0 && v[i] > chave) {
			v[i+1] = v[i];
			i--;
		}
		v[i+1] = chave;
		printf("%d\n", j);
	}	
	// Fim

	printf("\nImprimindo Vetor Ordenado");
	txt= fopen("Arquivo_ordenado_insertion.txt", "w");
	//Laço de impressão do Vetor
	for(i=0; i<n; i++){
		fprintf(txt, "%i\n", v[i]);
	}
	fclose(txt);
}
