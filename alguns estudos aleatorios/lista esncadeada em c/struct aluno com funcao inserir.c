#include <stdio.h>
#include <stdlib.h>

typedef struct data 
    {
        int dia;
        int mes;
        int ano;
    }Data;

typedef struct aluno
{
    int matricula;
    
    float media;
    Data dataNascimento;
    struct aluno *proximo;
}Aluno;

void inserirAlunoInicio(Aluno **turma, int MatriculaAluno, int diaN, int mesN, int anoN, float mediaAluno)
{
    Aluno *novo = malloc(sizeof(Aluno));
    
    if(novo){
        novo->matricula = MatriculaAluno;
        novo->dataNascimento.dia = diaN;
        novo->dataNascimento.mes = mesN;
        novo->dataNascimento.ano = anoN;
        novo->media = mediaAluno;
        novo->proximo = *turma;
        *turma = novo;
    }else
    printf("Erro ao alocar memoria!");
}

int main()
{
   Aluno *turma = NULL;
   
    return 0;
}
