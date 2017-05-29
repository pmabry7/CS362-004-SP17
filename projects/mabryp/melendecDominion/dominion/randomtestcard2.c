//test greatHallEffect function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testHall(int p, struct gameState *G, int pos){
	
	int numAct, numCards, r;
	int failed = 0;
	numAct = G->numActions + 1;
	numCards = G->handCount[p];
	
	r = cardEffect(great_hall, -1, -1, -1, G, pos, -1);
	assert(r==0);
	
	if(G->numActions == numAct && G->handCount[p] != numCards){
		//printf("Test failed! The function did not return the correct number of cards\n");
		failed = 1;
	}
	else if(G->numActions == numCards && G->handCount[p] != numAct){
		//printf("Test failed! The function did not set the correct number of actions\n");
		failed = 1;
	}
	else if(G->numActions != numAct && G->handCount[p] != numCards){
		//printf("Test failed! The function did not set the correct number of actions, or return the correct number of cards\n");
		failed = 1;
	}
	
	assert(r==0);
	return failed;
}

int main(){
	
	int n, i, p, testFail;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int numFail = 0;
	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	printf ("Testing Great Hall card.\n");

	printf ("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);
	
	for (n = 0; n < 2000; n++) {
		testFail = 0;
		for (i = 0; i < sizeof(struct gameState); i++) {
		  ((char*)&G)[i] = floor(Random() * 256);
		}		
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		G.numActions = floor(Random() * 5);
		G.whoseTurn = p;
		int pos = floor(Random() * G.handCount[p]);
		G.hand[p][pos] = great_hall;
		G.playedCardCount = 0;
		testFail = testHall(p,&G, pos);
		if(testFail != 0){			
			numFail++;
		}
	}
	if (numFail == 0)
		printf ("ALL TESTS OK\n");
	else{
		printf("GREATHALLEFFECT TESTS HAVE FAILED!\n");
		printf("Number of tests that failed: %d\n", numFail);
	}
	return 0;
}