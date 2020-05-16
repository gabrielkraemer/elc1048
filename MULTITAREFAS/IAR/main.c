#include <stdint.h>
#include <stdio.h>

#include "multitarefas.h"

/*
 * Prototipos das tarefas
 */
void tarefa_0(void);
void tarefa_1(void);
void tarefa_2(void);
void tarefa_3(void);
void tarefa_4(void);
void tarefa_5(void);
void tarefa_6(void);

/*
 * Configuracao dos tamanhos das pilhas
 */
#define TAM_PILHA_0		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_1		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_2		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_3		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_4		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_5		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_6		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_OCIOSA	(TAM_MINIMO_PILHA + 24)

/*
 * Declaracao das pilhas das tarefas
 */
uint32_t PILHA_TAREFA_0[TAM_PILHA_0];
uint32_t PILHA_TAREFA_1[TAM_PILHA_1];
uint32_t PILHA_TAREFA_2[TAM_PILHA_2];
uint32_t PILHA_TAREFA_3[TAM_PILHA_3];
uint32_t PILHA_TAREFA_4[TAM_PILHA_4];
uint32_t PILHA_TAREFA_5[TAM_PILHA_5];
uint32_t PILHA_TAREFA_6[TAM_PILHA_6];
uint32_t PILHA_TAREFA_OCIOSA[TAM_PILHA_OCIOSA];

/*
 * Funcao principal de entrada do sistema
 */
int main(void)
{
	
	/* Criacao das tarefas */
	/* Parametros: ponteiro, nome, ponteiro da pilha, tamanho da pilha, prioridade da tarefa */
	
        CriaTarefa(tarefa_0, "Tarefa 0", PILHA_TAREFA_0, TAM_PILHA_0, 6);
  
	CriaTarefa(tarefa_1, "Tarefa 1", PILHA_TAREFA_1, TAM_PILHA_1, 5);
	
	CriaTarefa(tarefa_2, "Tarefa 2", PILHA_TAREFA_2, TAM_PILHA_2, 4);
        
        CriaTarefa(tarefa_3, "Tarefa 3", PILHA_TAREFA_3, TAM_PILHA_3, 3);
        
        CriaTarefa(tarefa_4, "Tarefa 4", PILHA_TAREFA_4, TAM_PILHA_4, 2);
        
        CriaTarefa(tarefa_5, "Tarefa 5", PILHA_TAREFA_5, TAM_PILHA_5, 1);
        
        CriaTarefa(tarefa_6, "Tarefa 6", PILHA_TAREFA_6, TAM_PILHA_6, 7);
	
	/* Cria tarefa ociosa do sistema */
	CriaTarefa(tarefa_ociosa,"Tarefa ociosa", PILHA_TAREFA_OCIOSA, TAM_PILHA_OCIOSA, 0);
        
        TCB[1].estado = ESPERA;
        TCB[2].estado = ESPERA;
        TCB[3].estado = ESPERA;
        TCB[4].estado = ESPERA;
        TCB[5].estado = ESPERA;
	
	/* Configura marca de tempo */
	ConfiguraMarcaTempo();   
	
	/* Inicia sistema multitarefas */
	IniciaMultitarefas();
	
	/* Nunca chega aqui */
	while (1)
	{
	}
}

uint32_t cnt0 = 0;
uint32_t cnt1 = 0;
uint32_t cnt2 = 0;
uint32_t cnt3 = 0;
uint32_t cnt4 = 0;
uint32_t cnt5 = 0;
uint32_t cnt6 = 0;

void tarefa_0(void) 
{
	for(;;)
	{
          cnt0++;
          TarefaSuspende(1);
	}
}

void tarefa_1(void) 
{
	for(;;)
	{
          cnt1++;
          TarefaContinua(1);
          TarefaSuspende(2);
	}
}

void tarefa_2(void) 
{
	for(;;)
	{
          cnt2++;
          TarefaContinua(2);
          TarefaSuspende(3);
	}
}

void tarefa_3(void) 
{
	for(;;)
	{
          cnt3++;
          TarefaContinua(3);
          TarefaSuspende(4);
	}
}

void tarefa_4(void) 
{
	for(;;)
	{
          cnt4++;
          TarefaContinua(4);
          TarefaSuspende(5);
	}
}

void tarefa_5(void) 
{
	for(;;)
	{
          cnt5++;
          TarefaContinua(5);
	}
}

void tarefa_6(void) 
{
	for(;;)
	{
          cnt6 = cnt0 + cnt1 + cnt2 + cnt3 + cnt4 + cnt5;
          TarefaEspera(30);
	}
}