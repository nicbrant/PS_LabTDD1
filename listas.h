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

List* CriaLista();
void CriaNodo(List* lista,char nome[15],char genero,char tipo[7],char estado[10],unsigned int idade);
