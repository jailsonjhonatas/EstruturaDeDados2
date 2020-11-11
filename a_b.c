#include <stdio.h>

typedef struct No No;

struct No{
	int chave;
	char Letra;
	
	No *filhoE;
	No *filhoD;
};

No criarNo(int chave, char l){
	No n;
	
	n.chave = chave;
	n.Letra = l;
	n.filhoE = NULL;
	n.filhoD = NULL;
	
	return n;
}

void conectaNo(No *pai, No *filhoE, No *filhoD){
	if (filhoD != NULL){
		if (filhoD->chave > pai->chave){
			printf("pode direito !!! \n");
			pai->filhoD = filhoD;
		} else {
			printf("nao pode direito !!! \n");
		}
	}
	
	if(filhoE != NULL){
		if(filhoE->chave < pai->chave){
			printf("pode esquerdo !!! \n");
			pai->filhoE = filhoE;
		} else {
			printf("nao pode esquerdo !!! \n");
		}
	}
	

}

void nivel_arvore(No *raiz, *filho1, *filho2, *filho3, *filho4, *filho5, *filho6){
	if(raiz >= 0){
		printf("Nível 0");
	}
	if(filho1 < raiz && filho2 > raiz){
		printf("Nível 1");

	}
	if(filho3 < filho1 && filho4 > filho1){
		printf("Nível 2");

	}
	if(filho5 < filho2 && filho6 > filho2){
		printf("Nível 2");

	}
	else{
		printf("Error no nível da árvore")
	}
}

// Na vídeo aula a informação que imprimo do nó é sua chave, como exercício gostaria que fosse impresso o nível do nó também, por exemplo:
// Chave: 15 Nivel: 0
// Chave: 10 Nivel: 1
// Chave: 30 Nivel: 

void imprime_arvore(No *r){
	printf("Chave: %i \n", r->chave);
	if (r->filhoD != NULL){
		printf("Filho direito do no com chave -- %i\n", r->chave);
		nivel_arvore()
		imprime_arvore(r->filhoD);
	}
	
	if (r->filhoE != NULL){
		printf("Filho esquerdo do no com chave -- %i\n", r->chave);
		nivel_arvore()
		imprime_arvore(r->filhoE);

	}
	
}

int main(){
	No raiz,filho1, filho2, filho3, filho4, filho5;
	
	raiz = criarNo(15, 'A');
	filho1 = criarNo(10, 'B');
	filho2 = criarNo(30, 'C');
	filho3 = criarNo(3, 'D');
	filho4 = criarNo(50, 'E');
	filho5 = criarNo(12, 'F');
	
	conectaNo(&raiz, &filho1, &filho2);
	conectaNo(&filho1, &filho3,NULL);
	conectaNo(&filho2, NULL, &filho4);
	
	imprime_arvore(&raiz);
	
	conectaNo(&filho1, NULL,&filho5);
	imprime_arvore(&raiz);
	//printf("Chave raiz: %i \n", raiz.chave);
	//printf("Chave filho esquerdo: %i \n", (raiz.filhoE)->chave);
	//printf("Chave filho esquerdo do filho esquerdo: %i \n", ((raiz.filhoE)->filhoE)->chave);
	
	return 0;
}
