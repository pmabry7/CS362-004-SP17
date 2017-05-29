//test smithyEffect function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int checkSmithy(int p, struct gameState *G, int pos){
	
	int testFail = 0;
	int numCards, r, discard;

	numCards = G->handCount[p] + 2;
	discard = G->discardCount;
	r = cardEffect(smithy, -1, -1, -1, G, pos, -1);
	assert(r==0);

	if (G->handCount[p] != numCards)
		testFail = 1;
	if(G->discardCount != discard)
		testFail = 1;
	
	assert(r == 0);
	return testFail;
}


int main(){
	int n, i, p, testFail;
	int numFail = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	printf ("Testing Smithy card.\n");

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
		G.hand[p][pos] = smithy;
		G.playedCardCount = 0;
		testFail = checkSmithy(p,&G, pos);
		if(testFail != 0){			
			numFail++;
		}
	}
	if (numFail == 0)
		printf ("ALL TESTS OK\n");
	else{
		printf("SMITHYEFFECT TESTS HAVE FAILED!\n");
		printf("Number of tests that failed: %d\n", numFail);
	}
	return 0;
}