/******************************************************************************
* FILE: unittest3.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* UNIT TEST: updateCoins() function in dominion.c. 
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
    int i = 0;
    int b = 0;
    int numbPlayers = 2;
    int player = 0;
    int testCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int rSeed = 1500;
    struct gameState gState;
    int handCount = 0;
    int bonus = 1;

    //Initialize and fill treasure arrays
    int gold[MAX_HAND];
    int silver[MAX_HAND];
    int copper[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) 
    {
        gold[i] = gold;
        silver[i] = silver;
        copper[i] = copper;        
    }

    printf("\nUNIT TEST 3: UPDATECOINS() FUNCTION\n");

    //Tests impact of handCount at multiple counts
    for (handCount = 0; handCount <= 5; handCount = handCount + 5) 
    {
        printf("\n\nBONUS: %d\n", bonus);
        printf("HAND COUNT: %d\n",handCount);

        memset(&gState,23,sizeof(struct gameState));
        b = initializeGame(numbPlayers, testCards, rSeed, &gState);
        gState.handCount[player] = handCount;

        //COPPER test
        memcpy(gState.hand[player],copper,sizeof(int)*handCount);
        updateCoins(player,&gState,bonus);
        printf("\nCOINT COUNT - COPPER\n");
        printf("Expected output: %d\n",handCount*1+bonus);
        printf("Actual output: %d\n",gState.coins);
        assertTrue(gState.coins,handCount*1+bonus);
        //SILVER test
        memcpy(gState.hand[player],silver,sizeof(int)*handCount);
        updateCoins(player,&gState,bonus);
        printf("\nCOINT COUNT - SILVER\n");
        printf("Expected output: %d\n",handCount*2+bonus);
        printf("Actual output: %d\n",gState.coins);
        assertTrue(gState.coins,handCount*2+bonus);
        //GOLD test
        memcpy(gState.hand[player],gold,sizeof(int)*handCount);
        updateCoins(player,&gState,bonus);
        printf("\nCOINT COUNT - GOLD\n");
        printf("Expected output: %d\n",handCount*3+bonus);
        printf("Actual output: %d\n",gState.coins);
        assertTrue(gState.coins,handCount*3+bonus);

        bonus = bonus + 2;
    }
    //Defines number of faied tests, or confirms successful completion
    if (fCount) 
    {
        printf("\nUPDATECOINS(): ONE OR MORE TESTS FAILED. SEE OUTPUT\n");
        printf("FAILURES: %d\n\n",fCount);
    }
    else 
    {
        printf("\nUPDATECOINS(): ALL TESTS COMPLETED SUCCESSFULLY!\n\n");
    }
    return 0;
}
