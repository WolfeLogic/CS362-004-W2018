/******************************************************************************
* FILE: unittest2.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* UNIT TEST: gainCard() function in dominion.c. 
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
    int rSeed = 1500;
    struct gameState gState;

    printf("\nUNIT TEST 2: GAINCARD() FUNCTION\n");
    
    memset(&gState,23,sizeof(struct gameState));
    initializeGame(2, testCards, rSeed, &gState);

    //Ensures test begins with zero gold
    gState.supplyCount[gold] = 0;
    printf("\nGOLD = 0\n");
    assertTrue(gainCard(gold,&gState,0,0),-1);
    //Sets GOLD to 30
    gState.supplyCount[gold] = 30;
    //Sets DECK COUNT to 0, then adds a card    
    int deckCount = gState.deckCount[0];
    printf("\n+1 to DECK COUNT\n");
    gainCard(gold,&gState,1,0);
    assertTrue(deckCount+1,gState.deckCount[0]);
    //Sets DISCARD COUNT to 0, then adds a card    
    int discardCount = gState.discardCount[0];
    printf("\n+1 to DISCARD COUNT\n");
    gainCard(gold,&gState,0,0);
    assertTrue(discardCount+1,gState.discardCount[0]);
    //Sets HAND COUNT to 0, then adds a card    
    int handCount = gState.handCount[0];
    printf("\n+1 to HAND COUNT\n");
    gainCard(gold,&gState,2,0);
    assertTrue(handCount+1,gState.handCount[0]);
    //Sets GOLD supply to game state supply count, then runs gainCard()    
    int goldSupply = gState.supplyCount[gold];
    printf("\n-1 GOLD supply & compare\n");
    gainCard(gold,&gState,0,0);
    assertTrue(goldSupply-1,gState.supplyCount[gold]);

    //Defines number of faied tests, or confirms successful completion
    if (fCount) 
    {
        printf("\nGAINCARD(): ONE OR MORE TESTS FAILED. SEE OUTPUT\n");
        printf("FAILURES: %d\n\n",fCount);
    }
    else 
    {
        printf("\nGAINCARD(): ALL TESTS COMPLETED SUCCESSFULLY!\n\n");
    }
    return 0;
}
