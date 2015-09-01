#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h" 
#include "main.c"
/*
 * Abaixo funções que fazem o teste.
 */
void adicionar_testes_main(void); // Cria a suite


/* Teste numero numero par */
void teste_DT_VerificaParidade_Par(void){
	int resultado;
	resultado = VerificaParidade(2);
	CU_ASSERT_TRUE( !resultado );
}

void  adicionar_testes_main(void){
	CU_pSuite suite;
	
	/*Cria uma suite que conterÃ¡ todos os testes*/
	suite = CU_add_suite("Testes da main",NULL,NULL);
	
}
int main(void){
	/*Inicializa o registro de suÃ­tes e testes do CUnit*/	
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();
    
    /*Adiciona os testes ao registro*/ 	
   	adicionar_testes_main();
	/*Muda o modo do CUnit para o modo VERBOSE
	 O modo VERBOSE mostra algumas informacoes a
	 mais na hora da execucao*/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	/*Roda os testes e mostra na tela os resultados*/
	CU_basic_run_tests();
	/*Limpa o registro*/
	CU_cleanup_registry();
	return CU_get_error();
}
