#include <iostream> 

using namespace std; 



typedef struct no_ { 
    int chave; 
    int valor;
    struct no_ *prox;
    struct no_ *ant; 
} encadeada; 



encadeada *ptlista; 

encadeada* inicialista () { 

    encadeada* cb = new encadeada; 
    cb->chave = 0; 
    cb->valor = 0; 
    cb->prox = NULL; 
    cb->ant = NULL; 

    return cb; 
}


void busca_encadeada(int valor, encadeada** pont, encadeada** busca) { 

encadeada *ptr = ptlista; // primeiro elemento da lista. ptlista->prox = nó cabeça->prox; 
*pont = ptr; 

while (ptr->prox != NULL) { 
    if (ptr->prox->valor < valor) { 
      ptr = ptr->prox; 
      *pont = ptr; 
    } else { 
       if(ptr->prox->valor == valor) { 
        *busca = ptr->prox; 
        *pont = ptr->prox; 
        }
        break; 
     }
   }
 }


int insere(int valor, int chave) { 
int r = 0; 
encadeada* busca = NULL; 
encadeada* pont;

busca_encadeada(valor, &pont, &busca); 
    if (busca == NULL) { 
    encadeada *novo = new encadeada; 
    novo->valor = valor; 
    novo->chave = chave; 
     if(pont == ptlista){ 
         novo->prox = pont->prox;
         pont->prox = novo; 
         novo->ant = pont;  
     } else if (pont->prox == NULL) { 
      novo->prox = pont->prox; 
      novo->ant = pont; 
      pont->prox = novo; 
     } else { 
     novo->prox = pont->prox; 
     novo->ant = pont;
     pont->prox->ant = novo; 
     pont->prox = novo; 
     }
      return r = 1; 
    } 
    return r;
 }
encadeada *remove(int valor) { 

encadeada* pont;
encadeada* busca = NULL;
busca_encadeada(valor, &pont, &busca);
if (busca != NULL) { 
    pont->ant->prox = pont->prox; 
  } else { 
    cout << endl;
    cout << "Elemento não encontrado, não foi possível remover" << endl; 
  }
  return busca; 
}

void imprime_lista() { 
    encadeada * ponteiro = ptlista->prox; 
    while (ponteiro != NULL) { 
        cout << "" << ponteiro->valor; 
        if(ponteiro->prox != NULL)
        cout << "->"; 
        ponteiro = ponteiro->prox; 
    }
}

void encerra_lista() { 
    encadeada* ant = ptlista->prox; 
    encadeada* pont = ant->prox; 
    while (pont != NULL) { 
        free(ant); 
        ant = pont; // agora ant aponta para onde pont aponta. 
        pont = pont->prox;  // e pont para o prox 

    }

    free(ant); 
    free(ptlista); 
    
}



int main () { 
ptlista = inicialista(); 
insere(5,1);
insere(4,2);
insere(7,3);
insere(1,4);
insere(2,5);
insere(11,6); 
insere(9,7); 
imprime_lista(); 
remove(4);
cout << endl; 
imprime_lista(); 
remove(11);
cout << endl; 
imprime_lista(); 
remove(13); 
cout << endl; 
imprime_lista(); 
remove(1); 
cout << endl; 
imprime_lista();




encerra_lista(); 


}