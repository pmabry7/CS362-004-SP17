//test greatHallEffect function
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
	
	printf("\nTesting the greatHallEffect function.\n");
	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	numAct = G.numActions + 1;
	numCards = G.handCount[0];
	
	
	int r = cardEffect(great_hall, -1, -1, -1, &G, 1, -1);
	assert(r==0);
	
	if (G.numActions == numAct && G.handCount[0] == numCards)
		printf("Test passed! The number of cards and actions are correct\n");
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
		printf("GREATHALLEFFECT TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
	
}