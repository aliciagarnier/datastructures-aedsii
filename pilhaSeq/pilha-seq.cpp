#include <stdio.h> 
#include <iostream>

using namespace std; 

typedef struct no_ { 
  int dado; 
} no; 

int topo = -1; 
int qtd = 0; 
int tam = 10; 
// elas precisam ser variáveis globais
no vet[10];

int inserirpilha (no novo) { 
int insere = -1; // função que retorna se a inserção foi possível. 
    if (qtd != tam) { 
     vet[qtd] = novo; 
     qtd++; 
     topo++; 
     insere = topo; // retorno o indice o qual está o topo da pilha. 
   } else { 
    printf("A pilha está cheia.\n"); 
   }
   return insere;
}

void remove () { 
    if (qtd != 0) { // ou topo !+ -1, não sei qual encaixa melhor ainda. 
    topo--; 
    qtd--;
    } else { 
    printf("Pilha está vazia.\n"); 
  }
  
}

void imprimirpilha() { 
int i;
    for (i = 0; i < qtd; i++) { 
    printf("%d", vet[i].dado); 
    if (i != qtd-1) { 
    cout << "->"; 
    }
  } 
}

int main () { 

no novoelemento; 
int valor;
int ans; 

	do {
        //Opcoes:
		//0 -> inserir
		//1 -> remover
		//2 -> escrever
		//3 -> sair
		scanf("%d", &ans);

		switch (ans) {
            //inserir
			case 0:
				scanf("%d", &valor);
        novoelemento.dado = valor;
				inserirpilha(novoelemento);

				break;
            //remover
			case 1:
				remove();

				break;
            //escrever
			case 2:
				imprimirpilha();
				
				break;

      case 3:
      ans = 3;  
			default:
				
				break;
		}
	} while (ans != 3);

	return (0);
}


