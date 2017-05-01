//test the whoseTurn function

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
	
	printf("\nTesting the whoseTurn function.\n");
	
	//test the initial value of whose turn
	t = whoseTurn(&G);
	
	if (t != 0){
		printf("Initialization failed! The game was not set to start with player 1\n");
		testFail = 1;
	}
	else
		printf("Initialization passed!\n");
	
	//test a change to whoseTurn
	G.whoseTurn = 1;
	
	t = whoseTurn(&G);
	
	if (t != 1){
		printf("Test failed! The function did not return the correct player\n");
		testFail = 1;
	}
	else
		printf("Test passed passed!\n");
	
	
	if(testFail == 1)
		printf("WHOSETURN TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
}