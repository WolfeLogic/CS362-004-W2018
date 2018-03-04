/******************************************************************************
* FILE: cardtest3.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* CARD TEST: COUNCIL ROOM 
* NOTE: Decided to use my own assertion function in this test. It's nice 
* because it totals the number of failures. Unfortunately the pass/failure 
* outputs are not as specific (so I went back to previous approach in 
* cardtest4.c)
* http://wiki.dominionstrategy.com/index.php/Council_Room
* COUNCIL ROOM is a terminal card draw, meaning it provides +Cards but no 
* +Action. The other players draw a card whether they want to or not.
*****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int fCount = 0;

void assertTrue(int a, int b) 
{
    if (a == b) 
    {
        printf("\tPASSED \n");
    }
    else 
    {
        printf("\tFAILED \n");
        fCount++;
    }
}

int main () 
{
    int testCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int i;
    int rSeed = 1500;
    int player1 = 0;
    int player2 = 1;
    int handpos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;
    int numbPlayers = 2;
    
    struct gameState gState, testCpy;
    
    memset(&gState,23,sizeof(struct gameState));
    memset(&testCpy,23,sizeof(struct gameState));

    initializeGame(numbPlayers, testCards, rSeed, &gState);

    printf("\nCARD TEST 3: COUNCIL ROOM\n");

    memcpy(&testCpy, &gState, sizeof(struct gameState));

    cardEffect(council_room, choice1, choice2, choice3, &gState, handpos, &bonus);
    
    //Tests the impact of COUNCIL ROOM on HAND COUNT
    printf("\nPLAYER-1 gains 4 cards\n");
    assertTrue(gState.handCount[player1],testCpy.handCount[player1]+3);
    //Tests the impact of COUNCIL ROOM on DECK COUNT
    printf("\nPLAYER-1 gains 4 cards from his own pile\n");
    assertTrue(gState.deckCount[player1],testCpy.deckCount[player1]-4);
    //Tests the impact of COUNCIL ROOM on number of player's BUYs 
    printf("\nPLAYER-1 number of buys increments\n");
    assertTrue(gState.numBuys,testCpy.numBuys+1);
    //Tests the impact of COUNCIL ROOM on VICTORY supply count
    printf("\nExpecting no change to following VICTORY card piles\n");
    printf("PROVICE Pile\n");
    assertTrue(gState.supplyCount[province],testCpy.supplyCount[province]);
    printf("DUCHY Pile\n");
    assertTrue(gState.supplyCount[duchy],testCpy.supplyCount[duchy]);
    printf("ESTATE Pile\n");
    assertTrue(gState.supplyCount[estate],testCpy.supplyCount[estate]);
    //Tests the impact of COUNCIL ROOM on test card supply count
    printf("\nExpecting no change to testCards supplyCount\n");
    for (i = 0; i < 10; i++) 
    {
        printf("Comparing gameState w/ testCpy supplyCount\n");
        assertTrue(gState.supplyCount[testCards[i]],testCpy.supplyCount[testCards[i]]);
    }
    //Tests whether card distribution is correct after COUNCIL ROOM card impact
    printf("\nPLAYER-2 expected to gain 1 card\n");
    assertTrue(gState.handCount[player2],testCpy.handCount[player2]+1);
    printf("\nPLAYER-2 expected to gain 1 from PLAYER-2 own deck\n");
    assertTrue(gState.deckCount[player2],testCpy.deckCount[player2]-1);
    //Defines number of faied tests, or confirms successful completion
    if (fCount) 
    {
        printf("\nCOUNCIL ROOM: ONE OR MORE TESTS FAILED. SEE OUTPUT\n");
        printf("\tFAILURES: %d\n",fCount);
    }
    else 
    {
        printf("\nCOUNCIL ROOM: ALL TESTS COMPLETED SUCCESSFULLY!\n\n");
    }
    return 0;
}
