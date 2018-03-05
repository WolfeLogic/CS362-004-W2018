# Zheng Zhu’s (zhuzhe) Assignment 2 core directory as part of Drew Wolfe’s (wolfedr) Assignment 5  

### TO RUN DOMINION
- make all
- $ ./playdom <int> 
  * For instance, $ ./playdom 534
- That’s it… See the _make rules_ below to see what tests can be run against the _Dominion_ source  

### The following tests / files where imported into Zheng’s “dominion” directory as part of Drew Wolfe’s Assignment 5:
* cardtest1.c
* cardtest2.c
* cardtest3.c
* cardtest4.c
* unittest1.c
* unittest2.c
* unittest3.c
* unittest4.c
* randomtestcard1.c
* randomtestcard2.c
* randomtestadventurer.c  

### MAKEFILE Commands
## Strongly Recommended to run _make clean_ between running tests as there seems to be an occasional issue appending _dominion.c.gcov_ to successive output files.
- make all //compiles all relevant _Dominion_ files for subsequent  tests to be run
- make randomtestcard1.out //compiles the random tester, runs gcov, outputs to _randomtestcard1.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make randomtestcard2.out //compiles the random tester, runs gcov, outputs to _randomtestcard2.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make randomtestadventurer.out //compiles the random tester, runs gcov, outputs to _randomtestadventurer.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make unittestresults.out //compiles the unitTest1-4 and cardTest1-4, runs gcov, outputs to _unittestresults.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make completeTestSuite.out //this is seemingly the most “useful” suite of tests. It’s generally readable as well as comprehensive. It compiles the unitTest1-4, cardTest1-4, the random tests, buy and draw card tests. It still runs gcov, but the gcov outputs are at the end and the only cover the random tests and dominion. It outputs to _completeTestSuite.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make completeExhaustiveTestSuite.out //compiles the unitTest1-4 and cardTest1-4, the random tests, buy and draw card tests, runs gcov, but like, stupid exhaustively… And honestly, the “correct” way as it removes the .gcda file after running every test, but also nearly incomprehensible
given that it results in a stupid-long file, outputs to _exhaustiveunittestresults.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make clean // Makes a nice clean slate. Specifically deletes: \*.o playdom.exe playdom player player.exe \*.out \*.gcov \*.gcda \*.gcno \*.so testDrawCard badTestDrawCard testDrawCard.exe unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 randomtestcard1 randomtestcard2 randomtestadventurer 