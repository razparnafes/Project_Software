/*
 * sp_nim.h
 *
 *  Created on: 5 Dec 2017
 *      Author: Raz Parnafes
 */

#ifndef SP_NIM_H_
#define SP_NIM_H_


#include <stdio.h>

#define USER 0
#define COMPUTER 1

int isGameOver(int* heaps, int n);
//void userTurn(int* heaps, int n);
void playTurn(int heap, int remove, int player, int* heaps);
void computerTurn(int* heaps, int n);
int getNonEmptyHeap(int* heaps, int n);
int getWinningHeap(int* heaps, int n);
int getNimSum(int* heaps, int n);


#endif /* SP_NIM_H_ */
