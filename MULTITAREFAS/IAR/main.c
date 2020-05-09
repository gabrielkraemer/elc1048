#include <stdint.h>
#include <stdio.h>

#include "multitarefas.h"

/*
 * Prototipos das tarefas
 */
void tarefa_1(void);
void tarefa_2(void);

/*
 * Configuracao dos tamanhos das pilhas
 */
#define TAM_PILHA_1		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_2		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_OCIOSA	(TAM_MINIMO_PILHA + 24)

#define N 10

semaforo_t mutex = {1, 0};
semaforo_t empty = {N, 0};
semaforo_t full = {0, 0};
int shared_buffer[10] = {0,0,0,0,0,0,0,0,0,0};

/*
 * Declaracao das pilhas das tarefas
 */
uint32_t PILHA_TAREFA_1[TAM_PILHA_1];
uint32_t PILHA_TAREFA_2[TAM_PILHA_2];
uint32_t PILHA_TAREFA_OCIOSA[TAM_PILHA_OCIOSA];

/*
 * Funcao principal de entrada do sistema
 */
int main(void)
{
	
	/* Criacao das tarefas */
	/* Parametros: ponteiro, nome, ponteiro da pilha, tamanho da pilha, prioridade da tarefa */
	
	CriaTarefa(tarefa_1, "Tarefa 1", PILHA_TAREFA_1, TAM_PILHA_1, 2);
	
	CriaTarefa(tarefa_2, "Tarefa 2", PILHA_TAREFA_2, TAM_PILHA_2, 1);
	
	/* Cria tarefa ociosa do sistema */
	CriaTarefa(tarefa_ociosa,"Tarefa ociosa", PILHA_TAREFA_OCIOSA, TAM_PILHA_OCIOSA, 0);
	
	/* Configura marca de tempo */
	ConfiguraMarcaTempo();   
	
	/* Inicia sistema multitarefas */
	IniciaMultitarefas();
	
	/* Nunca chega aqui */
	while (1)
	{
	}
}

/* Tarefas de exemplo que usam funcoes para suspender/continuar as tarefas */

void tarefa_1(void) // PRODUTOR
{
	for(;;)
	{
                int item = 1;
		SemaforoAguarda(&empty);
                SemaforoAguarda(&mutex);
                
                shared_buffer[full.contador] = item;
                
                SemaforoLibera(&mutex);
                SemaforoLibera(&full);
	
                TarefaEspera((tick_t)2);
	}
}

void tarefa_2(void) // CONSUMIDOR
{
	for(;;)
	{
		SemaforoAguarda(&full);
                SemaforoAguarda(&mutex);
                
                shared_buffer[full.contador] = 0;
                
                SemaforoLibera(&mutex);
                SemaforoLibera(&empty);
	}
}