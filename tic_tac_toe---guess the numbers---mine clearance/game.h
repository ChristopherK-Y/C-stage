#ifndef _GAME_H_
#define _GAME_H_

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#define CORRECT_ID "Bit" 
#define CORRECT_PASSWARD "Bits"
#define OPPORTUNITY 3

#define COL 3
#define ROW 3
#pragma warning(disable:4996)

void ShowNumberMenu();
void GameNumber();
int LoginNumber();

void ShowGameMenu();
void ShowChessMenu();
void GameChess();

#endif