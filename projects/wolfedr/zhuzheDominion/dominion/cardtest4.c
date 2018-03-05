/******************************************************************************
* FILE: cardtest4.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* CARD TEST: VILLAGE
* NOTE: Generally returned to the design pattern of cardtest1.c & cardtest2.c
* http://wiki.dominionstrategy.com/index.php/Village
* VILLAGE gives you +1 card from the deck and +2 actions, allowing you to 
* play more than one terminal action each turn.
*****************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main () 
{

   int testCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, remodel, tribute, smithy, council_room};
   int i = 0;
   int rSeed = 100;
   int drawnCards = 1;
   int discardedCards = 1;
   int handPos = 0;
   int choice1 = 0, choice2 = 0, choice3 = 0;
   int bonus = 0;
   int success_flag = 1;
   int numbPlayers = 2;

   struct gameState gState, testCpy;

   initializeGame(numbPlayers, testCards, rSeed, &gState);

   printf("\nCARD TEST 4: VILLAGE\n");

   memcpy(&testCpy, &gState, sizeof(struct gameState));

   cardEffect(village, choice1, choice2, choice3, &testCpy, handPos, &bonus);

   //Tests HAND COUNT after playing VILLAGE
   if (testCpy.handCount[0] != gState.handCount[0] + drawnCards - discardedCards) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect HAND COUNT after playing VILLAGE.\n\t Expected output %d, actual output %d\n", gState.handCount[0] + drawnCards - discardedCards, testCpy.handCount[0]);
   }
   else 
   {
      printf("\tPASS: Correct HAND COUNT for VILLAGE (no change)\n");
   }
   //Tests impact of drawnCards on deckCount
   if (testCpy.deckCount[0] != gState.deckCount[0] - drawnCards) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect DECK COUNT after playing VILLAGE.\n\t Expected output %d, actual output %d\n", gState.deckCount[0] - drawnCards, testCpy.deckCount[0]);
   }
   else 
   {
      printf("\tPASS: Correct DECK COUNT for VILLAGE (-1)\n");
   }
   //Tests to ensure score has not changed
   if (scoreFor(0, &testCpy) != scoreFor(0, &gState)) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect SCORE after playing VILLAGE.\n\t Expected output %d, actual output %d\n", scoreFor(0, &gState), scoreFor(0, &testCpy));
   }
   else 
   {
      printf("\tPASS: Correct SCORE for VILLAGE (no change)\n");
   }
   //Test to ensure ACTION count increments by +2
   if (testCpy.numActions != gState.numActions + 2) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect ACTIONS count after playing VILLAGE.\n\t Expected output %d, actual output %d\n", gState.numActions + 2, testCpy.numActions);
   }
   else 
   {
      printf("\tPASS: Correct ACTIONS count for VILLAGE (+2)\n");
   }
   //Test compares states
   if (testCpy.handCount[1] != gState.handCount[1]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect HAND COUNT for PLAYER-2 after PLAYER-1 played VILLAGE.\n\t Expected output %d, actual output %d\n", gState.handCount[1], testCpy.handCount[1]);
   }
   else 
   {
      printf("\tPASS: PLAYER-2's HAND COUNT correct after PLAYER-1 played VILLAGE\n");
   }
   if (testCpy.deckCount[1] != gState.deckCount[1]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect DECK COUNT for PLAYER-2's after PLAYER-1 played VILLAGE.\n\t Expected output %d, actual output %d\n", gState.deckCount[1], testCpy.deckCount[1]);
   }
   else 
   {
      printf("\tPASS: PLAYER-2's DECK COUNT correct after PLAYER-1 played VILLAGE\n");
   }
   if (scoreFor(1, &testCpy) != scoreFor(1, &gState)) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect SCORE for PLAYER-2's after PLAYER-1 played VILLAGE.\n\t Expected output %d, actual output %d\n", scoreFor(1, &gState), scoreFor(1, &testCpy));
   }
   else 
   {
      printf("\tPASS: PLAYER-2's SCORE correct after PLAYER-1 played VILLAGE\n");
   }
   //Test compares VICTORY card piles
   if (testCpy.supplyCount[estate] != gState.supplyCount[estate]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect number of ESTATE cards.\n\t Expected output %d, actual output %d\n", gState.supplyCount[estate], testCpy.supplyCount[estate]);
   }
   else 
   {
      printf("\tPASS: Correct number of ESTATE cards after playing VILLAGE\n");
   }

   if (testCpy.supplyCount[duchy] != gState.supplyCount[duchy]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect number of DUCHY cards.\n\t Expected output %d, actual output %d\n", gState.supplyCount[duchy], testCpy.supplyCount[duchy]);
   }
   else 
   {
      printf("\tPASS: Correct number of DUCHY cards after playing VILLAGE\n");
   }

   if (testCpy.supplyCount[province] != gState.supplyCount[province]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect number of PROVINCE cards.\n\t Expected output %d, actual output %d\n", gState.supplyCount[province], testCpy.supplyCount[province]);
   }
   else 
   {
      printf("\tPASS: Correct number of PROVINCE cards after playing VILLAGE\n");
   }
   //Test compares the testCpy with the initial gState
   for (i = 0; i < 10; i++) 
   {

      if (testCpy.supplyCount[testCards[i]] != gState.supplyCount[testCards[i]]) 
      {
        success_flag = 0;
        printf("\tFAIL: Inital card count #%d does not contain initial number of cards\n", i);
      }
      else 
      {
        printf("\tPASS: Inital card count #%d contains initial number of cards\n", i);
      }

   }
   if (success_flag) 
   {
      printf("\nVILLAGE: ALL TESTS COMPLETED SUCCESSFULLY!\n\n");
   }
   else 
   {
      printf("\nVILLAGE: ONE OR MORE TESTS FAILED. SEE OUTPUT\n\n");
   }
   return 0;
}
