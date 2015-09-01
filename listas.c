/* Programação Sistematica - Turma A - Professora: Genaina Nunes Rodrigues
* Rafael Martins - 14/0159461
* Nicholas Brant - 14/0157158
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listas.h"

List* CriaLista(){
    List* nova = (List*)malloc(sizeof(List));
    if(nova==NULL)
        exit(2);
    nova->init = NULL;
    nova->n = 0;
    return nova;
}

void CriaNodo(List* lista,char nome[15],char genero,char tipo,unsigned short int estado,unsigned short int idade){
    Node* novo = (Node*)malloc(sizeof(Node));
    if(novo==NULL){
        DesalocaLista(lista);
        exit(3);
    }
    if(lista->init==NULL){
        lista->init = novo;
        novo->next = novo;
        novo->prev = novo;
    }else{
        Node* exultimo = lista->init->prev;
        exultimo->next = novo;
        novo->prev = exultimo;
        novo->next = lista->init;
        lista->init->prev = novo;
    }
    strcpy(novo->name,nome);
    novo->gender = genero;
    novo->type = tipo;
    novo->humor = estado;
    novo->idade = idade;
    lista->n++;
}

void DesalocaNodo(Node* atual){
    if(atual){
        atual->next->prev = atual->prev;
        atual->prev->next = atual->next;
        free(atual);
    }
}

void DesalocaLista(List* atual){
    if(atual){
	if(atual->init){
		Node* q = atual->init->prev;
		Node* t = q->prev;
		printf("teste");
		while(q != t){
		    t = q->prev;
		    atual->n--;
		    DesalocaNodo(q);
		    q = t;
		}
		atual->n--;
		DesalocaNodo(q);
	}
        free(atual);
    }
}

int ListaVazia(List* atual){
    if(atual->n)
        return 1;
    return 0;
}
