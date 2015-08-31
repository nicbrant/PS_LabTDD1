#include<stdio.h>
#include"listas.h"
int main(){
    int i;
    List* mesa = CriaLista();
    //
    //criaçao dos nodos e elitura do arquivo
    //
    Node* atual = mesa->init;
    while(ListaVazia(mesa)){
        if(atual->humor >= 5){
            if(atual == mesa->init){
                if(atual == atual->next)
                    mesa->init = NULL;
                else
                    mesa->init = atual->next;
            }
            Node* t = atual->next;
            DesalocaNodo(atual);
            atual = t;
            mesa->n--;
        }else{
            atual->humor++;
            atual = atual->next;
        }
    }
    DesalocaLista(mesa);
    return 0;
}
