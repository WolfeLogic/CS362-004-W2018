/******************************************************************************
* FILE: cardtest1.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* CARD TEST: SMITHY 
* NOTE: cardtest1.c & cardtest2.c are nearly identical. I used a custom
* assert in cardtest3.c and then went back to the initial design pattern for
* cardtest4.c
* http://wiki.dominionstrategy.com/index.php/Smithy
* SMITHY is a terminal, meaning it provides no +Action. You draw 3 cards.
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
   int drawnCards = 3;
   int discardedCards = 1;
   int handPos = 0;
   int choice1 = 0, choice2 = 0, choice3 = 0;
   int bonus = 0;
   int success_flag = 1;
   int numbPlayers = 2;

   struct gameState gState, testCpy;

   initializeGame(numbPlayers, testCards, rSeed, &gState);

   printf("\nCARD TEST 1: SMITHY\n");
   
   memcpy(&testCpy, &gState, sizeof(struct gameState));

   cardEffect(smithy, choice1, choice2, choice3, &testCpy, handPos, &bonus);

   //Tests HAND COUNT after playing SMITHY
   if (testCpy.handCount[0] != gState.handCount[0] + drawnCards - discardedCards) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect HAND COUNT after playing SMITHY. \n\t Expected output %d, actual output %d\n", gState.handCount[0] + drawnCards - discardedCards, testCpy.handCount[0]);
   }
   else 
   {
      printf("\tPASS: Correct HAND COUNT for SMITHY (+3)\n");
   }
   //Tests impact of drawnCards on deckCount
   if (testCpy.deckCount[0] != gState.deckCount[0] - drawnCards) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect DECK COUNT after playing SMITHY. \n\t Expected output %d, actual output %d\n", gState.deckCount[0] - drawnCards, testCpy.deckCount[0]);
   }
   else 
   {
      printf("\tPASS: Correct DECK COUNT for SMITHY (-3)\n");
   }
   //Tests to ensure score has not changed
   if (scoreFor(0, &testCpy) != scoreFor(0, &gState)) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect SCORE after playing SMITHY. \n\t Expected output %d, actual output %d\n", scoreFor(0, &gState), scoreFor(0, &testCpy));
   }
   else 
   {
      printf("\tPASS: Correct SCORE for SMITHY (no change)\n");
   }
   //Test compares states
   if (testCpy.handCount[1] != gState.handCount[1]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect HAND COUNT for PLAYER-2 after PLAYER-1 played SMITHY. \n\t Expected output %d, actual output %d\n", gState.handCount[1], testCpy.handCount[1]);
   }
   else 
   {
      printf("\tPASS: PLAYER-2's HAND COUNT correct after PLAYER-1 played SMITHY\n");
   }
   if (testCpy.deckCount[1] != gState.deckCount[1]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect DECK COUNT for PLAYER-2's after PLAYER-1 played SMITHY. \n\t Expected output %d, actual output %d\n", gState.deckCount[1], testCpy.deckCount[1]);
   }
   else 
   {
      printf("\tPASS: PLAYER-2's DECK COUNT correct after PLAYER-1 played SMITHY\n");
   }
   if (scoreFor(1, &testCpy) != scoreFor(1, &gState)) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect SCORE for PLAYER-2's after PLAYER-1 played SMITHY. \n\t Expected output %d, actual output %d\n", scoreFor(1, &gState), scoreFor(1, &testCpy));
   }
   else 
   {
      printf("\tPASS: PLAYER-2's SCORE correct after PLAYER-1 played SMITHY\n");
   }
   //Test compares VICTORY card piles
   if (testCpy.supplyCount[estate] != gState.supplyCount[estate]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect number of ESTATE cards. \n\t Expected output %d, actual output %d\n", gState.supplyCount[estate], testCpy.supplyCount[estate]);
   }
   else 
   {
      printf("\tPASS: Correct number of ESTATE cards after playing SMITHY\n");
   }
   if (testCpy.supplyCount[duchy] != gState.supplyCount[duchy]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect number of DUCHY cards. \n\t Expected output %d, actual output %d\n", gState.supplyCount[duchy], testCpy.supplyCount[duchy]);
   }
   else 
   {
      printf("\tPASS: Correct number of DUCHY cards after playing SMITHY\n");
   }
   if (testCpy.supplyCount[province] != gState.supplyCount[province]) 
   {
      success_flag = 0;
      printf("\tFAIL: Incorrect number of PROVINCE cards. \n\t Expected output %d, actual output %d\n", gState.supplyCount[province], testCpy.supplyCount[province]);
   }
   else 
   {
      printf("\tPASS: Correct number of PROVINCE cards after playing SMITHY\n");
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
      printf("\nSMITHY: ALL TESTS COMPLETED SUCCESSFULLY!\n\n");
   }
   else 
   {
      printf("\nSMITHY: ONE OR MORE TESTS FAILED. SEE OUTPUT\n\n");
   }
   return 0;
}
