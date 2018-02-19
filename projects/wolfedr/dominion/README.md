# ASSIGNMENT 4, OSU CS362-400-W2018

## Random Testers

### TO RUN DOMINION
- make all
- $ ./playdom <int> 
  * For instance, $ ./playdom 534
- That’s it… See the _make rules_ below to see what tests can be run against the _Dominion_ source

### MAKEFILE Commands
- make all //compiles all relevant _Dominion_ files for subsequent  tests to be run
- make randomtestcard1.out //compiles the random tester, runs gcov, outputs to _randomtestcard1.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make randomtestcard2.out //compiles the random tester, runs gcov, outputs to _randomtestcard2.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make randomtestadventurer.out //compiles the random tester, runs gcov, outputs to _randomtestadventurer.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make unittestresults.out //compiles the unitTest1-4 and cardTest1-4, runs gcov, outputs to _unittestresults.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make exhaustiveunittestresults.out //compiles the unitTest1-4 and cardTest1-4, runs gcov, but like, stupid exhaustively… And honestly, the “correct” way as it removes the .gcda file after running every test, but also nearly incomprehensible
given that it results in a stupid-long file, outputs to _exhaustiveunittestresults.out_ **MUST RUN ./playdom <int> PRIOR TO EXECUTING THIS MAKE RULE**
- make clean // Makes a nice clean slate. Specifically deletes: \*.o playdom.exe playdom player player.exe \*.out \*.gcov \*.gcda \*.gcno \*.so testDrawCard badTestDrawCard testDrawCard.exe unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 randomtestcard1 randomtestcard2 randomtestadventurer 