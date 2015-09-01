#include<stdio.h>
#include"listas.h"
void PegaDadosArquivo(List* atual){
    char palavra[15],tipo,genero;
    int idade,humor;
    FILE* arquivo = fopen("Convidados.txt","r");
    if(arquivo == NULL)
        end(9);
    while(fscanf(arquivo,"%s",palavra)!= EOF){
            fscanf(arquivo,"%s %i %c %c %i",palavra,&idade,&genero,&tipo,&humor);
            CriaNodo(atual,palavra,genero,tipo,humor,idade);
    }
    fclose(arquivo);
}

int main(){
    int i;
    List* mesa = CriaLista();
    PegaDadosArquivo(mesa);
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
