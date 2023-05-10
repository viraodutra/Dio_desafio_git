#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserirInicio(No **lista, int num){
    No *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
        
    }else
        printf("Erro ao alocar memoria!");
}

void inserirFinal(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        
        if(*lista ==NULL)
            *lista = novo;
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;    
            
        }
        
    }else
        printf("Error ao alocar memoria!");
    
}


void inserirMeio(No **lista, int num, int anterior){
    No *aux, *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = num;
        
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->valor != anterior && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
}

void imprimir(No *no){
    printf("\n\tLista:");
    while(no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main()
{
    int opcao, valor, ant;
    No *lista = NULL;
    do
    {
        printf("\n\t 0 - Sair\n\t 1 - Inserir no inicio\n\t 2 - inserir no fim\n\t 3 -inserir no meio");
        printf("\n\t 4 - imprimir \n:");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirFinal(&lista, valor);
                break;
            case 3:
                printf("Digite um valor e o valor referencia: ");
                scanf("%d %d", &valor, &ant);
                inserirMeio(&lista, valor, ant);
                break;
            case 4:
            imprimir(lista);
                break;
                
            default:
                if(opcao != 0)
                    printf("\nOpcao invalida!\n");
        }
        }while(opcao != 0);
    
    
    return 0;
}
