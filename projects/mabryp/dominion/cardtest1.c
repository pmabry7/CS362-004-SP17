//test villageEffect function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(){
	int t, numAct, numCards;
	int testFail = 0;
	
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	printf("\nTesting the villageEffect function.\n");
	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	numAct = G.numActions + 2;
	numCards = G.handCount[0];
	
	villageEffect(&G, 0, village);
	
	if (G.numActions == numAct && G.handCount[0] == numCards)
		printf("ALL TESTS HAVE PASSED!\n");
	else if(G.numActions == numAct && G.handCount[0] != numCards){
		printf("Test failed! The function did not return the correct number of cards\n");
		testFail = 1;
	}
	else if(G.numActions != numAct && G.handCount[0] == numCards){
		printf("Test failed! The function did not set the correct number of actions\n");
		testFail = 1;
	}
	else{
		printf("Test failed! The function did not set the correct number of actions, or return the correct number of cards\n");
		testFail = 1;
	}
	
	if(testFail == 1)
		printf("VILLAGEEFFECT TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
	
}