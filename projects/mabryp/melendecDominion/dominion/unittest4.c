//test numHandCards

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(){
	int t;
	int testFail = 0;
	
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	printf("\nTesting the numHandCards function.\n");
	
	//test the initial value of numHandCards(should be 5 for the first player)
	t = numHandCards(&G);
	
	if (t != 5){
		printf("Initialization failed! The number of cards returned for player 1 is incorrect.\n");
		testFail = 1;
	}
	else
		printf("Initialization passed!\n");
	
	//test a change to to the number of cards
	t = G.handCount[0] = 3;
	t = numHandCards(&G);
	
	if (t != 3){
		printf("Test failed! The function did not return the correct hand count\n");
		testFail = 1;
	}
	else
		printf("Test passed!\n");
	
	
	if(testFail == 1)
		printf("NUMHANDCARDS TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
}

