//testing the supplyCount function


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
	printf("\nTesting the supplyCount function.\n");
	
	//Test curse card
	G.supplyCount[curse] = 4;
	
	t = supplyCount(curse, &G);
	
	if (t != 4)	{
		printf("Curse card test failed! incorrect count returned.\n");
		testFail = 1;
	}
	else 
		printf("Curse card test succeeded!\n");
	
	
	//test victory card
	G.supplyCount[duchy] = 1;
	
	t = supplyCount(duchy, &G);
	
	if (t != 1)	{
		printf("Victory card test failed! incorrect count returned.\n");
		testFail = 1;
	}
	else 
		printf("Victory card test succeeded!\n");
	
	
	//test kingdom card
	G.supplyCount[smithy] = 7;
	
	t = supplyCount(smithy, &G);
	
	if (t != 7)	{
		printf("Kingdom card test failed! incorrect count returned.\n");
		testFail = 1;
	}
	else 
		printf("Kingdom card test succeeded!\n");
	
	
	if(testFail == 1)
		printf("SUPPLY COUNT TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
}
