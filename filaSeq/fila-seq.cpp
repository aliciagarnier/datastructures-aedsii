#include <stdio.h> 
#include <iostream>

using namespace std; 

typedef struct no_ { 
  int dado; 
} no; 

int fim = -1;
int inicio = -1; 
int qtd = 0; 
int tam = 10; 
// elas precisam ser variáveis globais
no vet[10];

int inserir(no novo) { // No caso da pilha, o nosso limite é o inicio, ou seja o ultimo elemento alocado. Não posso inserir no mesmo local que ele. 
int insere = -1; // função que retorna se a inserção foi possível. 
int aux = qtd % tam; // resto da divisão. Qtd sempre representa o próximo indice, ou seja, onde ocorre a próxima inserção. 
  if (aux != inicio) { // Nosso limite é o inicio 
    fim = aux; 
    vet[fim] = novo; 
    qtd++; 
  } else { 
    cout << "Fila cheia.\n"; 
  }
  if (inicio == -1) { // inicio == -1 estado inicial dele. 
  inicio = fim; 
  }
   
   return fim;
}

int remove () { 
int retorno;
  if (fim != -1) {  // Possível remover, a fila não está vazia! 
     retorno = vet[inicio].dado; 
       if (inicio == fim) { 
        inicio, fim = -1; 
        qtd = 0; 
       } else { 
        inicio = inicio + 1;
        qtd--;
       }
  } else { 
    cout << "Fila está vazia" << endl; 
  } 
  return retorno; 
}

void imprimir() { 
int i; 

    for (i = 0; i < qtd; i++) { 
    printf("%d", vet[i].dado); 
    if (i != qtd-1) { 
    cout << "->"; 
    }
  }

  cout << endl; 
  cout << "inicio: " << vet[inicio].dado << " indice: " << inicio << endl; 
  cout << "fim: " << vet[fim].dado << " indice: " << fim << endl; 
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
				inserir(novoelemento);

				break;
            //remover
			case 1:
				remove();

				break;
            //escrever
			case 2:
				imprimir();
				
				break;

      case 3:
      ans = 3;  
			default:
				
				break;
		}
	} while (ans != 3);

	return (0);
}


