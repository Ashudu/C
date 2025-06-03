#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 10

int topo1 = 0;
int topo2 = 0; 

int pilha1[tamanho];
int pilha2[tamanho];

int Size_Pilha() {
	return topo1;
}

void Push(int pilha_s, int valor) {
	if(pilha_s == 1) {
		if(topo1 < tamanho) {
			pilha1[topo1] = valor;
			topo1++;
			printf("Inserido!");
		} else {
			printf("Pilha cheia\n");
		}
	} else if(pilha_s == 2) {
		if(topo2 < tamanho) {
			pilha2[topo2] = valor;
			topo2++;
			printf("Inserido!");
		} else {
			printf("Pilha cheia\n");
		}
	} else {
		printf("Essa pilha nao existe!");
	}

}

int Pop(int pilha_s) {
	if(pilha_s == 1) {
		if(topo1==0) {
			printf("Pilha vazia!");
		} else {
			topo1--;
			return topo1;
		}
	} else {
		if(topo2==0) {
			printf("Pilha vazia!");
		} else {
			topo2--;
			return topo2;
		}
	}
}

void Comp() {
	if(topo1 == topo2) {
		printf("As pilhas possue o mesmo tamanho");
	} else if(topo1 < topo2) {
		printf("A pilha 1 e menor que a pilha 2");
	} else {
		printf("A pilha 1 e maior que a pillha 2");
	}
}

void Valores(int pilha_s) {
	int i;
	int maior = 0;
	int menor = 999;
	int med = 0;
	int impar = 0;
	int par = 0;
	if(pilha_s == 1) {
		for(i = 0; i < topo1; i++) {
			if(maior < pilha1[i]) {
				maior = pilha1[i];
				if(menor > pilha1[i]) {
					menor = pilha1[i];
				}
				med = pilha1[i] + med;
				if(pilha1[i] % 2 == 0) {
					par++;
				} else {
					impar++;
				}
			}
		}
		med= med / topo1;
		printf("%d, %d, %d, %d, %d", maior, menor, med, impar, par);
	} else if(pilha_s == 2) {
		for(i = 0; i < topo2; i++) {
			if(maior < pilha2[i]) {
				maior = pilha2[i];
				if(menor > pilha2[i]) {
					menor = pilha2[i];
				}
				med = pilha2[i] + med;
				if(pilha2[i] % 2 == 0) {
					par++;
				} else {
					impar++;
				}
			}
		}
		med= med / topo2;
		printf("%d, %d, %d", maior, menor, med);

	}
}

void Copy() {
	int i;
	for(i = 0; i < tamanho; i++) {
		pilha2[i] = pilha1[i];
	}
	topo2 = topo1;
}




int main() {
	int aux, aux2, menu;



	do {
		printf("\n1 - Adicionar elemento as pilhas\n");
		printf("2 - Excluir elemento as pilhas\n");
		printf("3 - Comparar pilhas\n");
		printf("4 - Consultar valores\n");
		printf("5 - Copiar listas\n");

		scanf("%d", &menu);
		system("cls");
		if (menu == 1) {
			printf("1- Pilha1\n2 - Pilha 2\nSelecione qual pilha deseja adicionar: ");
			scanf("%d", &aux);
			printf("Digite o valor a ser adicionado: ");
			scanf("%d", &aux2);
			Push(aux, aux2);
		} else if (menu == 2) {
			printf("1- Pilha1\n2 - Pilha 2\nSelecione qual pilha deseja deletar: ");
			scanf("%d", &aux);
			Pop(aux);
		} else if (menu == 3) {
			printf("Op��o escolhida: Comparar pilhas\n");
			Comp();
		} else if (menu == 4) { // Ambas as op��es t�m o mesmo nome
			printf("1- Pilha1\n2 - Pilha 2\nSelecione qual pilha deseja consultar: ");
			scanf("%d", &aux);
			Valores(aux);
		} else if (menu == 5) { // Ambas as op��es t�m o mesmo nome
			Copy();
		} else {
			printf("Op��o inv�lida! Tente novamente.\n");
		}

	} while(menu != 6);
}
