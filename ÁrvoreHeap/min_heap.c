#include <stdlib.h>
#include <stdio.h>


typedef struct minheap_ { 
int *array_heap; 
int size; 
int heap_size; 

} min_heap; 

// funcoes que irao retornar pai, filho direito e filho esquerdo

int pai (int i) { 
return (i-1)/ 2; 
}
int filho_esquerdo(int i) {
 return (2 * i + 1); 
}
int filho_direito (int i) { 
return (2 * i +2); 
}

int menor_valor () {
    min_heap *aux;
    return aux->array_heap[0]; 
}

void swap(int *x, int *y) { 
    int aux = *x; 
    *x = *y; 
    *y = aux; 

}

min_heap * inicia_heap(int tamanho) { 
min_heap *heap = malloc(sizeof (min_heap));
heap->size = tamanho;
heap->heap_size = 0; 
int array; 
heap->array_heap = malloc(tamanho * sizeof(array));
return heap; 
}
 
void minHeap(min_heap *heap, int i) { 
 int l = filho_esquerdo(i); 
 int r = filho_direito(i); 
 int menor = i; 

 if( l < heap->heap_size && heap->array_heap[l] < heap->array_heap[i]) { 
    menor = l; 
 }

 if( r < heap->heap_size && heap->array_heap[r] < heap->array_heap[menor]) { 
    menor = r; 
 }

 if(menor != i) { 
    swap(&heap->array_heap[i], &heap->array_heap[menor]); 
    minHeap(heap, menor); 
 }

}

void imprime_heap(min_heap *heap) { 

    for (int i = 0; i < heap->heap_size; i++) { 
        printf("%d ", heap->array_heap[i]); 
    }
}

void inserir_heap(min_heap* heap, int valor) { 

    if (heap->heap_size == heap->size) { 
        printf("Overflow! O vetor esta cheio"); 
        return; 
    }
   
    heap->heap_size++; 
    int i = heap->heap_size - 1; 
    heap->array_heap[i] = valor; 

  while(i != 0 && heap->array_heap[pai(i)] > heap->array_heap[i]) {
    int valor = heap->array_heap[pai(i)];
   // printf("%d", valor);
    swap(&heap->array_heap[i], &heap->array_heap[pai(i)]);
    i = pai(i); 
  }
}


int remove_heap(min_heap *heap) { 
 if (heap->heap_size <= 0) {
    printf("Arvore heap vazia"); 
    return 0; 
 }
 if (heap->heap_size == 1) { 
    heap->heap_size--; 
    return heap->array_heap[0]; 
 }


 heap->array_heap[0] = heap->array_heap[heap->heap_size - 1]; 
 heap->heap_size--; 

 minHeap(heap, 0); 

 int raiz = heap->array_heap[0]; 
 return raiz; 

} 


int main () { 

min_heap *raizheap = inicia_heap(10); 
inserir_heap(raizheap, 3); 
inserir_heap(raizheap, 4); 
inserir_heap(raizheap, 7); 
inserir_heap(raizheap, 5); 
inserir_heap(raizheap, 2); 
inserir_heap(raizheap, 6); 
inserir_heap(raizheap, 1); 
imprime_heap(raizheap);
printf("\n");
printf("tamanho do vetor: %d\n", raizheap->heap_size);
/*  printf("\n"); 
remove_heap(raizheap); 
imprime_heap(raizheap);
printf("\n"); 
remove_heap(raizheap); 
imprime_heap(raizheap);
*/
inserir_heap(raizheap, 8); 
inserir_heap(raizheap, 0); 
inserir_heap(raizheap, 9); 
imprime_heap(raizheap);
printf("\n");
printf("tamanho do vetor: %d\n", raizheap->heap_size);
inserir_heap(raizheap, 56); 

}