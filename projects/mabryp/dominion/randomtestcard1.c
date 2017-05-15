//test smithyEffect function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int checkSmithy(int p, struct gameState *G){
	
	G->hand[p][G->handCount[p] ] = smithy;
	int testFail = 0;
	int numCards;

	numCards = G->handCount[p] + 2;
	
	smithyEffect(G, p, smithy);

	if (G->handCount[p] != numCards)
		testFail = 1;
	
	return testFail;
}


int main(){
	int n, i, p;
	int testFail = 0;
	
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	printf ("Testing Smithy card.\n");

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
		testFail = checkSmithy(p,&G);
		if(testFail == 1)
			printf("SMITHYEFFECT TESTS HAVE FAILED!\n");
	}
	return 0;
}