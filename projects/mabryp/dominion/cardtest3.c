//test smithyEffect function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(){
	int t, numCards;
	int testFail = 0;
	
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	printf("\nTesting the smithyEffect function.\n");
	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	numCards = G.handCount[0] + 2;
	
	smithyEffect(&G, 0, smithy);
	
	if (G.handCount[0] == numCards)
		printf("Test passed! The number of cards is correct\n");
	else {
		printf("Test failed! The function did not return the correct number of cards\n");
		testFail = 1;
	}
	
	if(testFail == 1)
		printf("SMITHYEFFECT TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
	
}