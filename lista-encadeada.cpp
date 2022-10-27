#include <iostream> 
#include <fstream> 
#include <stdlib.h>


// endereço de uma variável comum -> ponteiro ( * ) 
// endereço de uma variável ponteiro -> ponteiro de ponteiro ( ** )


using namespace std; 

typedef struct encadeada_ { 
    //critério de busca
    int chave; 
    // carga útil do nó, num cenário real poderia ser um nome, endereço. dados relevantes. 
    int valor; 
    struct encadeada_ * prox; 

} encadeada; 

encadeada* ptlista; // ponteiro de início da lista. variável global. 

encadeada* inicia_lista () { 
    encadeada* tmp = new encadeada; 
    tmp->chave= 0;
    tmp->valor= 0; 
    tmp-> prox = NULL; // nó "cabeça"

    return tmp; 
}


void busca_encadeada(int chave, encadeada** ant, encadeada** pont) { // ponteiro de ponteiro 
    *ant = ptlista;
    *pont = NULL; 

     encadeada* ptr = ptlista->prox; // quando inicio a lista ptlista->prox = NULL; 
    while(ptr != NULL) { 
        if (ptr->chave < chave){ 
            *ant = ptr; // to atualizando o conteúdo de uma variável ponteiro, portanto * pra atualizar o endereço
            ptr = ptr->prox; 
        } else { 
           if (ptr->chave == chave) { 
                *pont = ptr; 
            }  
            ptr = NULL; // justamente pra sair da repetição 
        }    
    }
}

int insere_encadeada(int chave, int valor) {  // chave e o valor como parâmetros 
    int retorno = -1; 
    encadeada* ant;
    encadeada* pont;

    busca_encadeada(chave, &ant, &pont); 

    if (pont == NULL) {  //posso inserir, não pertence a lista.
    encadeada* ponteiro = new encadeada; 
    ponteiro->chave = chave;
    ponteiro->valor = valor; 
    ponteiro->prox = ant->prox; // tmp vai apontar para onde ant estava apontando. 
    ant->prox = ponteiro; // anterior recebe o ponteiro de tmp;
    retorno = 0;  // foi possível inserir. 
    }

  return retorno; 
} 


void imprime_lista() { 
    encadeada * ponteiro = ptlista->prox; 
    while (ponteiro != NULL) { 
        cout << "chave: " << ponteiro->chave << endl;
        cout << "valor: " << ponteiro->valor << endl; 

        ponteiro = ponteiro->prox; 

    }
}

//desaloca o espaço previamente alocado para a lista encadeada 
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

ptlista = inicia_lista(); 
encadeada* ant;
encadeada* pont; 

busca_encadeada(10, &ant, &pont);

cout << "valor retornado da função de insere" << endl; 

cout << "  " << insere_encadeada(1,5) << endl; // chave e valor como argumentos
cout << "  " << insere_encadeada(8,7) << endl; 
cout << "  " << insere_encadeada(10, 6) << endl; 


imprime_lista(); 


encerra_lista(); 




}