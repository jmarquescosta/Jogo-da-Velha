#include "common.h"

// Menu com as opções de jogo
void menu(void)
{
	int nivel;
	
    while(1)
	{
    	printf("\nEscolha o nível de dificuldade\n");
        printf("1 - Fácil\t2 - Médio\t3 - Difícil\t4 - Sair\nNível: ");
        scanf("%d",&nivel);
        switch(nivel)
		{
        	case 1: jogo1(); break;
            case 2: jogo2(); break;
            case 3: jogo3(); break;
            case 4: exit(SUCCESS);
            default: printf("\nOpção inválida, tente novamente.\n");
		}
    }
}
