#include "common.h"

// Menu com as op��es de jogo
void menu(void)
{
	int nivel;
	
    while(1)
	{
    	printf("\nEscolha o n�vel de dificuldade\n");
        printf("1 - F�cil\t2 - M�dio\t3 - Dif�cil\t4 - Sair\nN�vel: ");
        scanf("%d",&nivel);
        switch(nivel)
		{
        	case 1: jogo1(); break;
            case 2: jogo2(); break;
            case 3: jogo3(); break;
            case 4: exit(SUCCESS);
            default: printf("\nOp��o inv�lida, tente novamente.\n");
		}
    }
}
