#include <iostream> 

using namespace std; 



typedef struct no_ { 
    int valor;
    struct no_ *prox; 
} no;

no *ptlista = NULL; 


void busca_enc(int valor, no** ant, no** pont, no** pmr) { 

*ant = ptlista; 
*pont = NULL;
*pmr = NULL;  

no* ptr = ptlista; 
while (ptr != NULL) { 
    if (ptr->valor < valor) { 
    *pmr = ptr;
    *ant = ptr; 
    ptr = ptr->prox; 
    } else { 
     if (ptr->valor == valor) {
     *pont = ptr; 
     }
     ptr = NULL; 
    }
  }
}

void insere_enc(int valor) { 
no *ant; 
no *pont;
no *pmr = NULL;  

busca_enc(valor, &ant, &pont, &pmr); 
if (pont == NULL) { 
no *novo = new no; 
novo->valor = valor; 
   if (ptlista == NULL) { // primeira inserção
   ptlista = novo;
   novo->prox = NULL;
   } else if (ant == ptlista && pmr == NULL) { 
    novo->prox = ptlista; 
    ptlista = novo;  
  } else if (ant == ptlista && pmr != NULL) { 
    novo->prox = ptlista->prox; 
    ptlista->prox = novo; 
    } else { 
    novo->prox = ant->prox; 
    ant->prox = novo; 
  }
} else { 
    cout << "Elemento já existente" << endl; 
  }
}

no* remove_enc (int valor) { 
no *ant; 
no *pont; 
no *pmr = NULL; 

busca_enc(valor, &ant, &pont, &pmr); 
if (pont != NULL) {  // posso remover!!!
  if (ant == ptlista) { 
   ptlista = ptlista->prox;
  } else { 
    ant->prox = pont->prox; 
  }
  return pont; 
} else { 
    cout << "Elemento não encontrado, não foi possível remover" << endl; 
    return pont; 
 }
}


void escrever() {
	printf("[");
	no * atual = ptlista;

	while (atual != NULL) {
		printf("%d", atual->valor);
		if (atual->prox != NULL)
			printf(" -> ");

		atual = atual->prox;
	}
	printf("]\n\n");
}

int main () { 

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
                insere_enc(valor);
				break;
            //remover
			case 1:
                scanf("%d", &valor);
				remove_enc(valor);
				break;
            //escrever
			case 2:
				escrever();
				
				break;

            case 3:
               ans = 3;  
			   default:
				
			break;
		}

	} while (ans != 3);

	return (0);
}



