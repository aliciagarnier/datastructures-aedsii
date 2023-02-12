#include <iostream>


using namespace std;




typedef struct noArv_ { 

  int valor;
  struct noArv_ *esq; 
  struct noArv_ *dir; 

} noArv; 


noArv *raiz;


   bool isBST(noArv* raiz) 
    {
        if (raiz->esq && raiz->dir != NULL) { 
            if (raiz->dir->valor > raiz->valor) { 
               isBST(raiz->dir); 
                
            } 
             if(raiz->esq->valor < raiz->valor) { 
                isBST(raiz->esq); 
            }
       return 0; 
    } 
    return 1; 
};


noArv* buscaArv(noArv* raiz, int k) { 
  if (raiz == NULL || raiz->valor == k) { 
    return raiz; 
  }
 
  if (raiz->valor > k) { 
   return buscaArv(raiz->esq, k);

  
  } else { 
    return buscaArv(raiz->dir, k); 
  }
}

noArv *arvNovoNo(int valor)
{
  noArv *raiz = new (noArv);
  raiz->valor = valor;
  raiz->esq = NULL;
  raiz->dir = NULL;
  return raiz;
}

noArv *insere_no(noArv *raiz, int valor) { 
if (buscaArv(raiz,valor)) { 
  cout << "Elemento já foi alocado, tente outro valor." << endl;
  return NULL; 
} else { 
  if (raiz == NULL)
  {
    return arvNovoNo(valor);
  }

  if (raiz->valor < valor)
  {
    raiz->dir = insere_no(raiz->dir, valor);
  }
  else
  {
    raiz->esq = insere_no(raiz->esq, valor);
  }
  return raiz;
 }
}

void pre_ordem(noArv *raiz)
{
  if (raiz != NULL)
  {
    cout << raiz->valor << " ";
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
  }
}

void em_ordem (noArv *raiz) { 
    if (raiz != NULL) { 
        em_ordem(raiz->esq);
        cout << raiz->valor << " ";
        em_ordem(raiz->dir);
    }
}

void pos_ordem (noArv *raiz) { 
     if(raiz != NULL) { 
        pos_ordem(raiz->esq); 
        pos_ordem(raiz->dir);
        cout << raiz->valor << " ";
     }

}
noArv* valorMin(noArv *raiz) { 
  noArv *aux = raiz; // nó que eu irei encontrar o menor dos maiores
   while (aux && aux->dir != NULL) { 
    aux = aux->dir; 

   }
   return aux; 
}

noArv *removeArvBin (noArv *raiz, int valor) {
  if(buscaArv(raiz, valor)) { 
   
   if (raiz == NULL) { 
    return raiz; 

   }
   
   if (valor < raiz->valor) { 
    raiz->esq = removeArvBin(raiz->esq, valor); 

   }
   else if (valor > raiz->valor) { 
    raiz->dir = removeArvBin (raiz->dir, valor); 

   }

   else { // valor foi encontrado 
      if (raiz->esq == NULL && raiz->dir == NULL) {  // nó folha
        return NULL; 
      }
      else if (raiz->esq == NULL) { 
        noArv* tmp = raiz->dir; 
        delete (raiz);
        return tmp; 
      }
      else if (raiz->dir == NULL) { 
        noArv *tmp = raiz->esq; 
        delete (raiz);
        return tmp; 
      }

      noArv* min = valorMin(raiz->esq); 
      raiz->valor = min->valor; 
      raiz->esq = removeArvBin(raiz->esq, min->valor); 
   }
   return raiz; 

  } else { 
    cout << "Elemento não encontrado, não é possivel remover!" << endl;
    return NULL; 
  }
}

int main ()  { 

raiz = insere_no(raiz, 12); 
insere_no(raiz, 43); 
insere_no(raiz, 11); 
insere_no(raiz, 76); 
insere_no(raiz, 45); 
insere_no(raiz, 5); 
insere_no(raiz, 32);
insere_no(raiz, 10); 
insere_no(raiz, 6); 
insere_no(raiz, 1); 
insere_no(raiz, 3);
insere_no(raiz, 32);
removeArvBin(raiz, 7); 
removeArvBin(raiz, 12);


pre_ordem(raiz); 
cout << endl; 
em_ordem(raiz); 
cout << endl; 
pos_ordem(raiz); 




}