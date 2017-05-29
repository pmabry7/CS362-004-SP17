CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

unittests: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	echo "Running unit tests: " > unittestresult.out
	echo "unittest1.c:" >> unittestresult.out
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	
	echo "unittest2.c:" >> unittestresult.out
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	
	echo "unittest3.c:" >> unittestresult.out
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	unittest3 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	
	echo "unittest4.c:" >> unittestresult.out
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	unittest4 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	
	echo "cardtest1.c:" >> unittestresult.out
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	cardtest1 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	
	echo "cardtest2.c:" >> unittestresult.out
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	cardtest2 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	
	echo "cardtest3.c:" >> unittestresult.out
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	cardtest3 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	
	echo "cardtest4.c:" >> unittestresult.out
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	cardtest4 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out

randomtests: randomtestcard1.c randomtestcard2.c randomtestadventure.c dominion.o rngs.o
	echo "randomtestcard1.c:" > randomtestcard1.out
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	
	echo "randomtestcard2.c:" > randomtestcard2.out
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

cleantest:
	rm unittestresult.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventure randomtestcard1 randomtestcard2 *.gcda *.gcno *.gcov


