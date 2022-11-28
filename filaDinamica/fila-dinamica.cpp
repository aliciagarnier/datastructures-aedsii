#include <iostream> 

using namespace std; 


typedef struct no_{ 
    int valor;
    struct no_ *proximo; 
} no; 

no* inicio = NULL; 
no* fim = NULL; 
//ambos os ponteiros se inicializam com null. 


void inserefila(int valor) { // passamos o valor que desejamos inserir como parâmetro. 
no *novo = new no;  // O limite para a inserção no caso da lista encadeada é a própria memória. 
novo->valor = valor; 

    if (fim != NULL) { // ou seja, temos algo alocado, simplesmente inserimos normalmente
     fim->proximo = novo; 
    } else { 
     inicio = novo;
    }
 fim = novo;  
}

no* removefila () { 
no* removido = NULL; // quero que ela retorne um ponteiro. Caso retorne o ponteiro como null não foi possível remover. 
    if (inicio != NULL) { // ou seja a lista não está vazia
    removido = inicio; // ponteiro que iremos retornar
    inicio = inicio->proximo; // "excluindo" um elemento. 
      if(inicio == NULL) { // se depois dessa exclusão, inicio recebeu NULL, então excluímos o ultimo ou único elemento dessa lista. E portanto inicio == fim, e deveremos atualizar fim também!! 
        fim = NULL; // não temos mais nenhum elemento na lista, portanto, precisamos resetar o ponteiro fim também!
      }  
  } else {
    cout << "Lista vazia, não é possível remover" << endl; 
  }
  return removido; 
}

void imprimir() { 
    no* ptr = inicio; 
    if (ptr == NULL) {
        cout << "lista vazia" << endl; 
    } else { 
    while (ptr != NULL) { 
        cout << ptr->valor; 
        if (ptr->proximo != NULL) { 
            cout << "->"; 
        }
       ptr = ptr->proximo; 
    }
    cout << endl;  
  }
}

int main () { 

inserefila(1); 
imprimir();
inserefila(2);
imprimir(); 
removefila(); 
imprimir(); 
removefila(); 
imprimir(); 
removefila(); 
removefila(); 
inserefila(4); 
imprimir(); 
inserefila(5); 
imprimir(); 



}