//test adventurerEffect function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(){
	int t, i, numCards;
	int numTrea = 0;
	int retTrea = 0;
	int testFail = 0;
	
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	printf("\nTesting the adventurerEffect function.\n");
	
	struct gameState G;
	
	initializeGame(2, k, 1, &G);
	
	numCards = G.handCount[0] + 1;
	
	//count the number of treasure cards currently in hand
	for (i = 0; i < G.handCount[0]; i++){
		if (G.hand[0][i] == copper)
			numTrea++;
		else if (G.hand[0][i] == silver)
			numTrea++;
		else if (G.hand[0][i] == gold)
			numTrea++;
    }	
		
	int r = cardEffect(adventurer, -1, -1, -1, &G, 1, -1);
	assert(r==0);
	
	//get the number of treasure cards after calling function
	
	for (i = 0; i < G.handCount[0]; i++){
		if (G.hand[0][i] == copper)
			retTrea++;
		else if (G.hand[0][i] == silver)
			retTrea++;
		else if (G.hand[0][i] == gold)
			retTrea++;	
    }	
	
	//check the number of cards total
	if (G.handCount[0] == numCards)
		printf("Test passed! The number of cards is correct\n");
	else {
		printf("Test failed! The function did not return the correct number of cards\n");
		testFail = 1;
	}
	
	//check the number of treasure cards
	if (retTrea == numTrea)
		printf("Test passed! The number of treasure cards is correct\n");
	else {
		printf("Test failed! The function did not return the correct number of treasure cards\n");
		testFail = 1;
	}
	
	if(testFail == 1)
		printf("ADVENTUREREFFECT TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
	
}