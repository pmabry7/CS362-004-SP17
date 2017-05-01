//testing isGameOver function

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
	
	printf("\nTesting the isGameOver function\n");
	
	
	t = isGameOver(&G);
	
	//test the initial game
	if (t == 1){
		printf("Game over. Initialization failed!\n");
		testFail = 1;
	}
	else
		printf("Initialization passed!\n");
		
	//test for province at 0
	G.supplyCount[province] = 0;
	
	t = isGameOver(&G);
	
	if(t == 1)
		printf("Game over. Province-empty test passed!\n");
	else{
		printf("Province-empty test failed!\n");
		testFail = 1;
	}
	
	//test for two supplies at 0(not including province)
	G.supplyCount[province] = 8;
	G.supplyCount[curse] = 0;
	G.supplyCount[duchy] = 0;
	
	t = isGameOver(&G);
	
	if(t == 1){
		printf("Game over. Two empty supply test failed!\n");
		testFail = 1;
	}
	else
		printf("Two empty supply test passed!\n");
	
	
	//test for three empty supplies(not including province)
	G.supplyCount[estate] = 0;
	t = isGameOver(&G);
	
	if(t == 1)
		printf("Game over. Three empty supply test passed!\n");
	else{
		printf("Three empty supply test failed!\n");
		testFail = 1;
	}

	if(testFail == 1)
		printf("ISGAMEVOER TESTS HAVE FAILED!\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
	
	return 0;
}

