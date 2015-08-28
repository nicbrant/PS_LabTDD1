/* Programação Sistematica - Turma A - Professora: Genaina Nunes Rodrigues
** Nicholas Brant - 140157158
*/
#include<stdio.h>
#include<string.h>

struct nodo{
    struct nodo* prox;
    struct nodo* ante;
    char nome[15];
    char genero;
    char tipo[7];
    char estado[10];
    unsigned int idade;
}typedef Nodo;

struct list{
    Nodo* Atual;
    Nodo* Primeiro;
    Nodo* Ultimo;
}typedef List;

List* CriaLista(){
    List* nova = (List*)malloc(sizeof(List));
    if(nova==NULL)
        end(2);
    return nova;
}

void CriaNodo(List* lista,char nome[15],char genero,char tipo[7],char estado[10],unsigned int idade){
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if(novo==NULL){
        //desaloca os nodos e a lista
        end(3);
    }
    if(lista->Primeiro==NULL){
        lista->Primeiro = novo;
        lista->Ultimo = novo;
        novo->prox = novo;
        novo->ante = novo;
    }else{
        Nodo* exultimo = lista->Ultimo;
        exultimo->prox = novo;
        novo->ante = exultimo;
        novo->prox = lista->Primeiro;
        lista->Ultimo = novo;
        lista->Primeiro->ante = novo;
    }
    strcpy(novo->nome,nome);
    novo->genero = genero;
    strcpy(novo->tipo,tipo);
    strcpy(novo->estado,estado);
    novo->idade = idade;
}
