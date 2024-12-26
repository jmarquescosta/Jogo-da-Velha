#include "common.h"

// Jogo do n�vel dif�cil
void jogo3(void)
{
	char done = VAZIO;
	
	inicia_tabuleiro();
	
	do
	{
		exibe_tabuleiro();
		
		get_player_move();
		
		done = check();
		
		if(done != VAZIO) break;
		
		get_computer_move3();
		
		done = check();
	} while(done == VAZIO);
	
	if(done == PLAYER) printf("\n*** Voc� ganhou! ***\n");
	else printf("\n*** Eu ganhei!!! ***\n");
	
	exibe_tabuleiro(); // Mostra as posi��es finais
	
	menu();
	
	return;
}
