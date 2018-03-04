/******************************************************************************
* FILE: unittest1.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* UNIT TEST: shuffle() function in dominion.c. 
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
    int numbPlayers = 2;
    int player = 0;
    int testCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int rSeed = 1500;
    struct gameState gState;

    memset(&gState,23,sizeof(struct gameState));
    initializeGame(numbPlayers, testCards, rSeed, &gState);

    printf("\nUNIT TEST 1: SHUFFLE() FUNCTION\n");

    //Tests shuffle() w/ zero cards
    gState.deckCount[player] = 0;
    printf("\nPlayer's DECK COUNT = 0\n");
    assertTrue(shuffle(player,&gState),-1);
    //Tests shuffle() w/ 10 cards
    gState.deckCount[player] = 10;
    printf("\nPlayer's DECK COUNT = 10\n");
    shuffle(player,&gState);
    assertTrue(gState.deckCount[player],10);
    //Tests to ensure a difference in the pre & post shuffle state of deck
    int pre_shuffle_card = gState.deck[player][0];
    printf("\nDeck shuffled by shuffle() function\n");
    shuffle(player,&gState);
    int post_shuffle_card = gState.deck[player][0];
    if (pre_shuffle_card != post_shuffle_card) 
    {
        assertTrue(1,1);
    }
    else 
    {
        assertTrue(0,1);
    }
    //Defines number of faied tests, or confirms successful completion
    if (fCount) 
    {
        printf("\nSHUFFLE(): ONE OR MORE TESTS FAILED. SEE OUTPUT\n");
        printf("FAILURES: %d\n\n",fCount);
    }
    else 
    {
        printf("\nSHUFFLE(): ALL TESTS COMPLETED SUCCESSFULLY!\n\n");
    }
    return 0;
}
