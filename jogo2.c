#include "common.h"

// Jogo do nível médio
void jogo2(void)
{
	char done = VAZIO;
	
	inicia_tabuleiro();
	
	do
	{
		exibe_tabuleiro();
		
		get_player_move();
		
		done = check();
		
		if(done != VAZIO) break;
		
		get_computer_move2();
		
		done = check();
	} while(done == VAZIO);
	
	if(done == PLAYER) printf("\n*** Você ganhou! ***\n");
	else printf("\n*** Eu ganhei!!! ***\n");
	
	exibe_tabuleiro(); // Mostra as posições finais
	
	menu();
	
	return;
}
