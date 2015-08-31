/*
 * Programação Sistematica - Turma A - Professora: Genaina Nunes Rodrigues
 * Rafael Martins - 14/0159461 <rafaelmartinsrm@gmail.com>
 * Nicholas Brant - 14/0157158
*/
#include<stdio.h>
#include<string.h>
struct Node
{
    struct Node* next;
    struct Node* prev;
    char name[15];
    unsigned short int idade;
    char gender; /* 0 if male, 1 if female */
    char type; /* 0 if dwarf, 1 if mage */
    unsigned short int humor; /* pessimo, ruim, moderado, bom, satisfeito, feliz */
};
typedef struct Node Node;

struct List
{
	Node* init; /* First element */
	unsigned int n; /* Count */
};
typedef struct List List;

List* CriaLista()
void CriaNodo(List* lista,char nome[15],char genero,char tipo,unsigned short int estado,unsigned short int idade);
void DesalocaNodo(Node* atual);
void DesalocaLista(List* atual);
int ListaVazia(List* atual);
