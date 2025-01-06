#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(0));
	printf("Bem vindo ao jodo de adivinhação!");
	
	int jogador = 0;
	int maquina = (rand() % 5) + 1;
	
	printf("\nAdivinhe o número que estou pensando entre 0 e 5: ");
	scanf("%d", &jogador);

	if(jogador != maquina){
	    printf("\nVocê errou! o número que pensei foi %d", maquina);
	}else
	    printf("\nVocê acertou eu estava pensando exatamente nesse número!!");
	

	return 0;
}
