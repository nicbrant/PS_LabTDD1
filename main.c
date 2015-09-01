/*
 * Programação Sistematica - Turma A - Professora: Genaina Nunes Rodrigues
 * Rafael Martins - 14/0159461 <rafaelmartinsrm@gmail.com>
 * Nicholas Brant - 14/0157158
*/
#include <stdio.h>
#include <string.h>
#include "listas.h"

void PegaDadosArquivo(List* atual){
    char palavra[15],tipo,genero;
    int idade,humor;
    FILE* arquivo = fopen("Convidados.txt","r");
    if(arquivo == NULL)
        return;
    while(fscanf(arquivo,"%s",palavra)!= EOF){
			fseek(arquivo, -strlen(palavra), SEEK_CUR);
            fscanf(arquivo,"%s %d %c %c %d",palavra,&idade,&genero,&tipo,&humor);
            CriaNodo(atual,palavra,genero,tipo,humor,idade);
    }
    fclose(arquivo);
}

int main(){
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
			printf("Voce alimentou %s para humor %d.\n", atual->name, atual->humor);
            atual = atual->next;
        }
    }
    DesalocaLista(mesa);
    return 0;
}
