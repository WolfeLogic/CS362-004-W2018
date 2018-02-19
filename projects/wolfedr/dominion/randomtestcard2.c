/******************************************************************************
* FILE: randomtestcard2.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* RANDOM TEST: SMITHY 
* NOTE: 
* http://wiki.dominionstrategy.com/index.php/Smithy
* SMITHY is a terminal, meaning it provides no +Action. You draw 3 cards.
*****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void smithyCrdTst(int, struct gameState*);

// for-loop counter variables
int badHandCount = 0;
int badDraw = 0;
int badCardOutput = 0;
int badDiscard = 0;

int main () 
{
    printf("********************************* RANDOM TEST *********************************\n\n");
    printf("                     Random Test of simthyCard() Function\n\n");
    printf("*******************************************************************************\n\n");

    int testCycles = 25000;
    int i = 0;
    int n = 0;
    int player = 0;
    struct gameState gState;
    srand(time(NULL));

    for (n = 0; n < testCycles; n++) 
    {// setup game state
        for (i = 0; i < sizeof(struct gameState); i++) 
        {
            ((char*)&gState)[i] = floor(Random() * 400);
        }
        player = floor(Random() * MAX_PLAYERS);
        gState.handCount[player] = floor(Random() * MAX_HAND);
        gState.deckCount[player] = floor(Random() * MAX_DECK);
        gState.playedCardCount = floor(Random() * (MAX_DECK-1));
        gState.discardCount[player] = floor(Random() * MAX_DECK);
        gState.whoseTurn = player;

        smithyCrdTst(player,&gState);
    }
    int errorCount = badCardOutput + badDiscard + badDraw + badHandCount;
    printf("\n********************************** FINDINGS ***********************************\n");
    printf("TESTS PASSED: %d\n",testCycles - errorCount);
    printf("TESTS FAILED: %d\n\n",errorCount);

    if (errorCount == 0) 
    {
        printf ("*********************** HOLY COW, RANDOM TESTS PASSED!!! **********************\n");
    }
    else 
    {
        printf("\n************************ WOMP WOMP... RANDOM TEST FAILED ************************\n");
        printf("drawCard() ERROR: %d\n",badDraw);
        printf("discardCard() ERROR: %d\n",badDiscard);
        printf("cardEffect() ERROR: %d\n",badCardOutput);
        printf("INVALID hand OR deck count: %d\n",badHandCount);
        printf("\n********************** RUBBING IT IN... RANDOM TEST FAILED *********************\n");
    }
    printf ("\n******************************** GCOV OUTPUT **********************************\n");
    return 0;
}

// Smithy Card Test Function
void smithyCrdTst(int p, struct gameState *post) 
{
    int m = 0; 
    int n = 0;
    int o = 0;
    int q = 0;
    int r = 0;
    int bonus = 0;

    struct gameState pre;

    memcpy(&pre,post,sizeof(struct gameState)); // game state goes to pre

    m = cardEffect(smithy,0,0,0,post,0,&bonus); // call cardEffect w/ smithy

    n = drawCard(p,&pre);
    o = drawCard(p,&pre);
    q = drawCard(p,&pre);

    r = discardCard(0, p, &pre, 0);

    // capture counts for comparisons / validation
    int beforeHandCount = pre.handCount[p];
    int beforeDeckCount = pre.deckCount[p];
    int afterHandCount = post->handCount[p];
    int afterDeckCount = post->deckCount[p];

    if (!(m == 0 && r == 0)) 
    {
        if (m) 
        {// cardEffect failure
            badCardOutput++;
        }
        if (r) 
        {// discardCard failure
            badDiscard++;
        }
    }

    if (n == -1 && pre.deckCount[p] != 0) 
    {// validate drawCard
        badDraw++;
    }
    if (o == -1 && pre.deckCount[p] != 0) 
    {
        badDraw++;
    }
    if (q == -1 && pre.deckCount[p] != 0) 
    {
        badDraw++;
    }

    if (!(afterHandCount == beforeHandCount && afterDeckCount == beforeDeckCount)) 
    {// hand && deck comparison/validation
        badHandCount++;
    }
}
