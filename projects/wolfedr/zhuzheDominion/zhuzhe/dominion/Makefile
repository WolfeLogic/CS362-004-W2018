
CFLAGS = -Wall -fpic -coverage -lm

all: playdom player testDrawCard testBuyCard badTestDrawCard cardTest1 cardTest2 cardTest3 cardTest4

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#./playdom <any seed integer> */
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g testDrawCard.c dominion.o rngs.o $(CFLAGS)

cardTest1: cardtest1.c dominion.o rngs.o
	gcc -o cardTest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardTest2: cardtest2.c dominion.o rngs.o 
	gcc -o cardTest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardTest3: cardtest3.c dominion.o rngs.o
	gcc -o cardTest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)	

cardTest4: cardtest4.c dominion.o rngs.o
	gcc -o cardTest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

unitTest1: unittest1.c dominion.o rngs.o
	gcc -o unitTest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unitTest2: unittest2.c dominion.o rngs.o
	gcc -o unitTest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unitTest3: unittest3.c dominion.o rngs.o
	gcc -o unitTest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unitTest4: unittest4.c dominion.o rngs.o
	gcc -o unitTest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g $(CFLAGS)

randomtestcard1.out: randomtestcard1.c dominion.c rngs.c
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 > randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.c rngs.c
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 > randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer > randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

unittestresults.out: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4
	echo "ASSIGNMENT 3 TEST RESULTS: " > unittestresults.out
	./unitTest1 >> unittestresults.out
	./unitTest2 >> unittestresults.out
	./unitTest3 >> unittestresults.out
	./unitTest4 >> unittestresults.out
	./cardTest1 >> unittestresults.out
	./cardTest2 >> unittestresults.out
	./cardTest3 >> unittestresults.out
	./cardTest4 >> unittestresults.out
	echo "GCOV BRANCH PROBABILITIES & FUNCTION SUMMARIES: " >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

exhaustiveunittestresults.out: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 testDrawCard
	echo "ASSIGNMENT 3 EXHAUSTIVE TEST RESULTS: " > exhaustiveunittestresults.out
	rm -f *.gcda
	./unitTest1 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

	rm -f *.gcda
	./unitTest2 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

	rm -f *.gcda
	./unitTest3 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

	rm -f *.gcda
	./unitTest4 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

	rm -f *.gcda
	./cardTest1 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

	rm -f *.gcda
	./cardTest2 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

	rm -f *.gcda
	./cardTest3 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out
	
	rm -f *.gcda
	./cardTest4 >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

	rm -f *.gcda
	./testDrawCard >> exhaustiveunittestresults.out
	gcov -b -f dominion.c >> exhaustiveunittestresults.out
	cat dominion.c.gcov >> exhaustiveunittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

clean:
	rm -f *.o playdom.exe playdom player player.exe *.out *.gcov *.gcda *.gcno *.so testDrawCard badTestDrawCard testDrawCard.exe unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 randomtestcard1 randomtestcard2 randomtestadventurer