
CFLAGS = -Wall -fpic -coverage -lm

all: playdom player 

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

testBuyCard: testBuyCard.c dominion.o rngs.o
	gcc -o testBuyCard -g testBuyCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g $(CFLAGS)

randomtestcard1.out: randomtestcard1.c dominion.c rngs.c
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 > randomtestcard1.out
	gcov -b -f randomtestcard1.c >> randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.c rngs.c
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 > randomtestcard2.out
	gcov -b -f randomtestcard2.c >> randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer > randomtestadventurer.out
	gcov -b -f randomtestadventurer.c >> randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

unittestresults.out: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4
	echo "ALL UNIT TEST RESULTS: " > unittestresults.out
	./unitTest1 >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	./unitTest2 >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	./unitTest3 >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	./unitTest4 >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	./cardTest1 >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	./cardTest2 >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	./cardTest3 >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	./cardTest4 >> unittestresults.out
	echo "GCOV BRANCH PROBABILITIES & FUNCTION SUMMARIES: " >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

completeTestSuite.out: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 testDrawCard testBuyCard
	echo "COMPLETE TEST RESULTS: " > completeTestSuite.out
	./unitTest1 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./unitTest2 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./unitTest3 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./unitTest4 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./cardTest1 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./cardTest2 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./cardTest3 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./cardTest4 >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./testDrawCard >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./testBuyCard >> completeTestSuite.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./randomtestcard1 >> completeTestSuite.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./randomtestcard2 >> completeTestSuite.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	./randomtestadventurer >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	gcov -b -f dominion.c >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	gcov -b -f randomtestadventurer.c >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	gcov -b -f randomtestcard1.c >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	gcov -b -f randomtestcard2.c >> completeTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeTestSuite.out
	cat dominion.c.gcov >> completeTestSuite.out

completeExhaustiveTestSuite.out: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 testDrawCard testBuyCard
	echo "EXHAUSTIVE TEST RESULTS: " > completeExhaustiveTestSuite.out
	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./unitTest1 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./unitTest2 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./unitTest3 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./unitTest4 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./cardTest1 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./cardTest2 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./cardTest3 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out
	
	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./cardTest4 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./testDrawCard >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./testBuyCard >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./randomtestcard1 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f randomtestcard1.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./randomtestcard2 >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f randomtestcard2.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out

	rm -f *.gcda
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	./randomtestadventurer >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f randomtestadventurer.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	gcov -b -f dominion.c >> completeExhaustiveTestSuite.out
	echo "******************** SEARCHABLE STRING SEPARATOR: 8%^626+39 ********************" >> completeExhaustiveTestSuite.out
	cat dominion.c.gcov >> completeExhaustiveTestSuite.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

clean:
	rm -f *.o playdom.exe playdom player player.exe *.out *.gcov *.gcda *.gcno *.so testDrawCard badTestDrawCard testDrawCard.exe unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 randomtestcard1 randomtestcard2 randomtestadventurer