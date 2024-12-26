#ifndef COMMON_H
#define COMMON_H

// Headers padr�o
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��es globais, se necess�rio
#define SUCCESS 0
#define FAILURE 1
#define PLAYER 'X'
#define COMPUTER 'O'
#define VAZIO ' '
#define TAM 3

char tabuleiro[TAM][TAM];

// Declara��es de fun��es globais
// (Apenas inclua as declara��es de fun��es que ser�o usadas entre diferentes arquivos .c)
void menu(void);
void jogo1(void);
void jogo2(void);
void jogo3(void);
void inicia_tabuleiro(void);
void exibe_tabuleiro(void);
int eh_empate(void);
void get_player_move(void);
void get_computer_move1(void);
void get_computer_move2(void);
void get_computer_move3(void);
int minimax(int isMaximizing);
void melhorJogada(void);

#endif // COMMON_H
