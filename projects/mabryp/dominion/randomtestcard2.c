//test greatHallEffect function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testHall(int p, struct gameState *G){
	
	int numAct, numCards;
	numAct = G->numActions + 1;
	numCards = G->handCount[p] +1;
	
	greatHallEffect(G, p, great_hall);
	
	if(G->numActions == numAct && G->handCount[p] != numCards){
		printf("Test failed! The function did not return the correct number of cards\n");
	}
	else if(G->numActions == numCards && G->handCount[p] != numAct){
		printf("Test failed! The function did not set the correct number of actions\n");
	}
	else if(G->numActions != numAct && G->handCount[p] != numCards){
		printf("Test failed! The function did not set the correct number of actions, or return the correct number of cards\n");
	}
	
	return 0;
}

int main(){
	
	int n, i, p;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	printf("\nTesting the greatHallEffect function.\n");
	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	printf ("Testing Great Hall card.\n");

	printf ("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);
	
	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
		  ((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		G.numActions = floor(Random() * 5);
		testHall(p,&G);
	}
	return 0;
}