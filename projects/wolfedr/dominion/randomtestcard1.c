/******************************************************************************
* FILE: randomtestcard1.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* RANDOM TEST: COUNCIL ROOM 
* NOTE: 
* http://wiki.dominionstrategy.com/index.php/Council_Room
* ACTION terminal card + 4 cards +1 buy
* The other players draw a card whether they want to or not.
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

void councilRoomCrdTst(int, struct gameState*);

// fail counter variables
int badHandCount = 0;
int badHandCount_AltPlyr = 0;
int badDraw = 0;
int badCardOutput = 0;
int badDiscard = 0;
int badBuyCount = 0;

int main () 
{
    printf("********************************* RANDOM TEST *********************************\n\n");
    printf("                  Random Test of council_roomCard() Function\n\n");
    printf("*******************************************************************************\n\n");

    int testCycles = 25000;
    int i = 0;
    int n = 0;
    int player = 0;
    int handCount = 0;
    int deckCount = 0; 
    int discardCount = 0;
    int totalPlayers[] = {2,3,4};
    struct gameState gState;
    srand(time(NULL));

    for (n = 0; n < testCycles; n++) 
    {// setup game state
        for (i = 0; i < sizeof(struct gameState); i++) 
        {
            ((char*)&gState)[i] = floor(Random() * 400);
        }
        gState.numPlayers = totalPlayers[rand() % 3];
        player = gState.numPlayers - 2;
        gState.numBuys = 1;
        gState.playedCardCount = floor(Random() * (MAX_DECK-1));
        handCount = floor(Random() * MAX_HAND);
        deckCount = floor(Random() * MAX_DECK);
        discardCount = floor(Random() * MAX_DECK);
        gState.whoseTurn = player;

        for (i = 0; i < gState.numPlayers; i++) 
        {// alt-player setup
            gState.deckCount[i] = deckCount;
            gState.handCount[i] = handCount;
            gState.discardCount[i] = discardCount;
        }

        councilRoomCrdTst(player,&gState);
    }

    int errorCount = badCardOutput + badDiscard + badDraw + badHandCount + badBuyCount;
    printf("\n*********************************** FINDINGS ***********************************\n");
    printf("TESTS PASSED: %d\n",testCycles - errorCount);
    printf("TESTS FAILED: %d\n\n",errorCount);

    if (errorCount == 0) 
    {
        printf ("*********************** HOLY COW, RANDOM TESTS PASSED!!! ***********************\n");
    }
    else 
    {
        printf("\n*********************** WOMP WOMP... RANDOM TEST FAILED ************************\n");
        printf("INVALID numBuys: %d\n",badBuyCount);
        printf("drawCard() ERROR: %d\n",badDraw);
        printf("cardEffect() ERROR: %d\n",badCardOutput);
        printf("discardCard() ERROR: %d\n",badDiscard);
        printf("INVALID player hand OR deck count: %d\n",badHandCount);
        printf("INVALID Alt-players hand OR deck count: %d\n",badHandCount_AltPlyr);
        printf("\n********************** RUBBING IT IN... RANDOM TEST FAILED *********************\n");
    }
    printf ("\n********************************* GCOV OUTPUT **********************************\n");
    return 0;
}

// Council Room Card Test Function
void councilRoomCrdTst(int p, struct gameState *post) 
{
    int bonus = 0;
    int x = 0;
    int i = 0;
    int m = 0; 
    int n = 0;
    int o = 0;
    int q = 0;
    int r = 0;
    int s = 0;

    struct gameState pre;

    memcpy(&pre,post,sizeof(struct gameState)); // game state goes to pre

    m = cardEffect(council_room,0,0,0,post,0,&bonus); // call cardEffect w/ council room

    n = drawCard(p,&pre);
    o = drawCard(p,&pre);
    q = drawCard(p,&pre);
    r = drawCard(p,&pre);

    pre.numBuys++;

    for (i = 0; i < pre.numPlayers; i++) 
    { // all players drawCard
        if (i != p) {
            s = drawCard(i,&pre);
            if (s == -1 && pre.deckCount[i] != 0) 
            {// validate drawCard
                badDraw++;
            }
        }
    }

    x = discardCard(0, p, &pre, 0);

    // capture counts for comparisons
    int beforeHandCount = pre.handCount[p];
    int beforeDeckCount = pre.deckCount[p];
    int afterHandCount = post->handCount[p];
    int afterDeckCount = post->deckCount[p];

    if (pre.numBuys != post->numBuys) 
    {// gameState numBuys comparison
        badBuyCount++;
    }

    if (!(afterHandCount == beforeHandCount && afterDeckCount == beforeDeckCount)) 
    {// hand && deck comparison/validation
        badHandCount++;
    }

    if (!(m == 0 && x == 0)) 
    {
        if (m) 
        {// cardEffect failure
            badCardOutput++;
        }
        if (x) 
        {// discardCard failure
            badDiscard++;
        }
    }

    if (n == -1 && pre.deckCount[p] != 0) 
    {// gameState deckCount validation
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
    if (r == -1 && pre.deckCount[p] != 0) 
    {
        badDraw++;
    }

    for (i = 0; i < pre.numPlayers; i++) 
    {// after thought... 
        if (i != p) 
        {
            if (!(post->handCount[i] == pre.handCount[i] && post->deckCount[i] == pre.deckCount[i])) 
            {// alt player's hand && deck comparison/validation
                      badHandCount_AltPlyr++;
            }
        }
    }
}