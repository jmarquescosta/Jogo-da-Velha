#include "common.h"
#include <time.h>

// Todas as funções usadas nos jogos

// Essa função zera o tabuleiro para novas jogadas
void inicia_tabuleiro(void)
{
	int linha, coluna;
	
	for(linha = 0; linha < TAM; linha++)
	{
		for(coluna = 0; coluna < TAM; coluna++)
		{
			tabuleiro[linha][coluna] = VAZIO;
		}
	}
}

// Essa função mostra o tabuleiro atual
void exibe_tabuleiro(void)
{
	int contador;
	
	printf("\n");
	
	for(contador = 0;contador < TAM; contador++)
	{
		printf(" %c | %c | %c ", tabuleiro[contador][0], tabuleiro[contador][1], tabuleiro[contador][2]);
		if(contador != 2) printf("\n---|---|---\n");
	}
	
	printf("\n\n");
	return;
}

int eh_empate(void)
{
	
	int linha, coluna;
	
	for (linha = 0; linha < TAM; linha++)
	{
		for(coluna = 0; coluna < TAM; coluna++)
		{
			if(tabuleiro[linha][coluna] == ' ') return 0; // Ainda há espaços livres
		}
	}
	
	return 1;
}

char check(void)
{
	
	int linha;
	
	// Verifica a vitória nas linhas e colunas
	for(linha = 0; linha < TAM; linha++)
	{
		if(tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2] && tabuleiro[linha][0] != VAZIO)
			return tabuleiro[linha][0];
		if(tabuleiro[0][linha] == tabuleiro[1][linha] && tabuleiro[1][linha] == tabuleiro[2][linha] && tabuleiro[0][linha] != VAZIO)
			return tabuleiro[0][linha];
	}
	
	// Verifica vitória nas diagonais
	if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != VAZIO)
		return tabuleiro[0][0];
	if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][0] != VAZIO)
		return tabuleiro[0][2];
	
	return VAZIO; // Sem vitória
}

// Função Minimax
int minimax(int isMaximizing)
{
	int linha, coluna;
	char vencedor = check();
	
	if(vencedor == COMPUTER) return 10;
	if(vencedor == PLAYER) return -10;
	if(eh_empate()) return 0;
	
	int melhorPontuacao = isMaximizing ? -1000 : 1000;
	
	for(linha = 0; linha < TAM; linha++)
	{
		for(coluna = 0; coluna < TAM; coluna++)
		{
			if(tabuleiro[linha][coluna] == VAZIO)
			{
				tabuleiro[linha][coluna] = isMaximizing ? COMPUTER : PLAYER;
				int pontuacao = minimax(!isMaximizing);
				
				tabuleiro[linha][coluna] = VAZIO;
				melhorPontuacao = isMaximizing ? (pontuacao > melhorPontuacao ? pontuacao : melhorPontuacao) : (pontuacao < melhorPontuacao ? pontuacao : melhorPontuacao);
			}
		}
	}
	
	return melhorPontuacao;
}

// Melhor jogada para o computador
void melhorJogada(void)
{
}

// Obtem jogada do usuário
void get_player_move(void)
{
	int linha, coluna;
	
	do
	{
		printf("Digite o número da linha: ");
		scanf("%d",&linha);
		printf("Digite o número da coluna: ");
		scanf("%d",&coluna);
		
		linha--; coluna--;
		
		if(linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || tabuleiro[linha][coluna] != VAZIO)
		{
			printf("\nPosição inválida, tente novamente.\n");
		}
		else
		{
			break;
		}
	} while(1);
	tabuleiro[linha][coluna] = PLAYER;
	
	return;
}

void get_computer_move1(void)
{
	
	int linha, coluna;
	
	for(linha = 0; linha < TAM; linha++)
	{
		for(coluna = 0; coluna < TAM; coluna++)
		{
			if(tabuleiro[linha][coluna] == VAZIO)
			{
				break;
			}
		}
		if(tabuleiro[linha][coluna] == VAZIO)
		{
			break;
		}
	}
	
	int empate = eh_empate();
	
	if(empate == 1)
	{
		printf("\n*** Empate ***\n\n");
		menu();
	}
	else
	{
		tabuleiro[linha][coluna] = COMPUTER;
	}
	return;
}

void get_computer_move2(void)
{
	int linha, coluna;
	
	// Verifica se o computador pode ganhar na próxima jogada
	for(linha = 0; linha < TAM; linha++)
	{
		for(coluna = 0; coluna < TAM; coluna++)
		{
			if(tabuleiro[linha][coluna] == VAZIO)
			{
				tabuleiro[linha][coluna] = COMPUTER; // Simula a jogada do computador
				if(check() == COMPUTER)
				{
					return; // Se a jogada resultar em vitória, termina
				}
				
				tabuleiro[linha][coluna] = VAZIO; // Desfaz a jogada simulada
			}
		}
	}
	
	// Verifica se o jogador pode ganhar na próxima jogada e bloquear
	for(linha = 0; linha < TAM; linha++)
	{
		for(coluna = 0; coluna < TAM; coluna++)
		{
			if(tabuleiro[linha][coluna] == VAZIO)
			{
				tabuleiro[linha][coluna] = PLAYER; // Simula a jogada do jogador
				if(check() == PLAYER)
				{
					tabuleiro[linha][coluna] = COMPUTER; // Bloqueia o jogador
					return; // Se a jogada resultar em vitória, termina
				}
				
				tabuleiro[linha][coluna] = VAZIO; // Desfaz a jogada simulada
			}
		}
	}
	
	// Caso não haja ameaças ou oportunidades, joga e muma posição aleatória
	srand(time(NULL));
	int k, l;
	do
	{
		k = rand() % 3;
		l = rand() % 3;
	}
	while(tabuleiro[k][l] != VAZIO);
	
	int empate = eh_empate();
	
	if(empate == 1)
	{
		printf("\n*** Empate ***\n\n");
		menu();
	}
	else
	{
		tabuleiro[k][l] = COMPUTER;
	}
	
	
	
	return;
}

void get_computer_move3(void)
{
	int linha, coluna;
	int melhorPontuacao = -1000;
	int movimentoLinha = -1, movimentoColuna = -1;
	
	for(linha = 0; linha < TAM; linha++)
	{
		for(coluna = 0; coluna < TAM; coluna++)
		{
			if(tabuleiro[linha][coluna] == VAZIO)
			{
				tabuleiro[linha][coluna] = COMPUTER;
				
				int pontuacao = minimax(0);
				tabuleiro[linha][coluna] = VAZIO;
				
				if(pontuacao > melhorPontuacao)
				{
					melhorPontuacao = pontuacao;
					movimentoLinha = linha;
					movimentoColuna = coluna;
				}
			}
		}
	}
	
	int empate = eh_empate();
	
	if(empate == 1)
	{
		printf("\n*** Empate ***\n\n");
		menu();
	}
	else
	{
		tabuleiro[movimentoLinha][movimentoColuna] = COMPUTER;
	}
	
}
