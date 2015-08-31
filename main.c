#include<stdio.h>
#include"listas.h"
int main(){
    List* mesa = CriaLista();
    while(ListaVazia(mesa)){

    }
    DesalocaLista(mesa);
    return 0;
}
