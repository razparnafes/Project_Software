/*
 * sp_nim.c
 *
 *  Created on: 5 Dec 2017
 *      Author: Raz Parnafes
 */

#include "sp_nim.h"

/*
heaps - pointer to heap array. n - number of heaps
returns Nim Sum of heap
*/
int getNimSum(int* heaps, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum ^= heaps[i];
	}
	return sum;
}


/*
heaps - pointer to heap array. n - number of heaps
returns index of a winning heap. if not found returns -1
*/
int getWinningHeap(int* heaps, int n) {
	int nimsum = getNimSum(heaps, n);
	for (int i = 0; i < n; i++) {
		int h = heaps[i];
		if ((h^nimsum) < h) {			//if winning heap
			return i;				//returns index
		}
	}
	return -1;						//else returns -1
}


/*
heaps - pointer to heap array. n - number of heaps
returns index of first non empty heap.
if non exists, return -1.
*/
int getNonEmptyHeap(int* heaps, int n) {
	for (int i = 0; i < n; i++) {
		if (heaps[i] < 0) {
			return i;
		}
	}
	return -1;
}


/*
heaps - pointer to heap array. n - number of heaps
plays computers turn according to strategy and prints turn
*/
void computerTurn(int* heaps, int n) {
	int nimsum = getNimSum(heaps, n);
	int i;
	if (nimsum != 0) {
		i = getWinningHeap(heaps, n);									//finds winning heap
		playTurn(i, heaps[i] - nimsum, COMPUTER, heaps);	//plays turn
	}
	else {
		i = getNonEmptyHeap(heaps, n);					//finds some heap
		playTurn(i, 1, COMPUTER, heaps);		//plays turn
	}
}

/*
heap - heap to take coins from. remove - num coins to remove
player - player making move. heaps - pointer to heap array
updates heaps accordingly and prints turn to user
*/
void playTurn(int heap, int remove, int player, int* heaps) {
	heaps[heap] -= remove;						//removes coins from heap
	char* s;
	if (player == USER) {
		s = "You take ";
	}
	else {
		s = "Computer takes ";
	}
	printf("%s%d objects from heap %d", s, remove, heap);	//prints turn

}


//void userTurn(int* heaps, int n) {
//	printf("Your turn: please enter the heap index and the number of removed onjects.\n");
//	//TO DO: get input into heap, remove
//	//TO DO: is input valid + reask
//	//playTurn(heap, remove, USER, heaps);
//}

/*
heaps - pointer to heap array. n - number of heaps
return 0 if game over, else 1.
*/
int isGameOver(int* heaps, int n) {
	for (int i = 0; i < n; i++) {
		if (heaps[i] > 0) {				//if heap not empty
			return 1;
		}
	}
	return 0;							//all heaps were empty
}
