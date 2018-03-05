/******************************************************************************
* FILE: unittest4.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* UNIT TEST: isGameOver() function in dominion.c. 
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
    int numbPlayers = 2;
    int rSeed = 1500;
    struct gameState gState;

    printf("\nUNIT TEST 4: ISGAMEOVER() FUNCTION\n");

    memset(&gState,23,sizeof(struct gameState));
    initializeGame(numbPlayers, testCards, rSeed, &gState);
    //Set PROVINCE count to 0
    gState.supplyCount[province] = 0;
    printf("\nPROVINCE count = 0\n");
    assertTrue(isGameOver(&gState),1);
    //Set PROVINCE count to 1
    gState.supplyCount[province] = 1;
    //Set supplyCount array to 0
    gState.supplyCount[0] = 0;
    gState.supplyCount[1] = 0;
    gState.supplyCount[2] = 0;

    printf("\nEach of 3 piles in supplyCount = 0\n");
    assertTrue(isGameOver(&gState),1);
    //Set supplyCount array to 1
    gState.supplyCount[0] = 1;
    gState.supplyCount[1] = 1;
    gState.supplyCount[2] = 1;

    printf("\nPROVINCE count NOT EMPTY\n");
    printf("\nEach of 3 piles in supplyCount = 1\n");
    assertTrue(isGameOver(&gState),0);

    //Defines number of faied tests, or confirms successful completion
    if (fCount) 
    {
        printf("\nISGAMEOVER(): ONE OR MORE TESTS FAILED. SEE OUTPUT\n");
        printf("FAILURES: %d\n\n",fCount);
    }
    else 
    {
        printf("\nISGAMEOVER(): ALL TESTS COMPLETED SUCCESSFULLY!\n\n");
    }
    return 0;
}
