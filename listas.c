/* Programação Sistematica - Turma A - Professora: Genaina Nunes Rodrigues
** Nicholas Brant - 140157158
*/
struct nodo{
    struct nodo* prox;
    struct nodo* ante;
    char nome[15];
    char genero;
    char estado[10];
    unsigned short int idade;
}typedef Nodo;

struct list{
    Nodo* Atual;
    Nodo* Primeiro;
    Nodo* Ultimo;
}typedef List;
