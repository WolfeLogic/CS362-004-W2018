/******************************************************************************
* FILE: randomtestadventurer.c
* AUTHOR: Drew Wolfe
* CS362-004-W2018
* RANDOM TEST: ADVENTURER
* NOTE:
* http://wiki.dominionstrategy.com/index.php/Adventurer
* ADVENTURER is a terminal ACTION that digs for Treasure cards in your deck.
* Reveal cards from your deck until you reveal 2 Treasure cards. Put those
* Treasure cards into your hand and discard the other revealed cards.
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

void adventurerCrdTst(int, struct gameState*);

// for-loop stopping/counter variables
int badHandCount = 0;
int badShuffle = 0;
int badTreasureCount = 0;
int badDraw = 0;
int badCardOutput = 0;

int main()
{
    printf("********************************* RANDOM TEST *********************************\n\n");
    printf("                    Random Test of play_adventurer() Function\n\n");
    printf("*******************************************************************************\n\n");
    
    int testCycles = 25000;
    int i = 0;
    int n = 0;
    int player = 0;
    int treasureTotal;
    int booty[] = {copper, silver, gold};
    struct gameState gState;
    int min = 3; // swap 
    srand(time(NULL));

    for (n = 0; n < testCycles; n++)
    {
        for (i = 0; i < sizeof(struct gameState); i++)
        {// setup game state
            ((char*)&gState)[i] = floor(Random() * 400);
        }
        player = floor(Random() * MAX_PLAYERS);
        gState.deckCount[player] = floor(Random() * ((MAX_DECK - min) + 1) + min);
        treasureTotal = floor(Random() * ((gState.deckCount[player] - min) + 1) + min);
        
        for (i = 0; i < treasureTotal; i++)
        {// essentially replace "min" w/ booty
            gState.deck[player][i] = booty[rand() % 3];
        }
        gState.discardCount[player] = 0;
        gState.handCount[player] = floor(Random() * ((MAX_HAND - min) + 1) + min);
        gState.whoseTurn = player;

        adventurerCrdTst(player, &gState);
    }
    int errorCount = badCardOutput + badDraw + badShuffle + badHandCount + badTreasureCount;

    if (testCycles - errorCount <= 0)
    {
        printf("*********************************** FINDINGS ***********************************\n");
        printf("TESTS PASSED: %d\n", 0);
        printf("TESTS FAILED: %d\n", testCycles);
    }
    else
    {
        printf("*********************************** FINDINGS ***********************************\n");
        printf("TESTS PASSED: %d\n", testCycles - errorCount);
        printf("TESTS FAILED: %d\n\n", errorCount);
    }

    if (errorCount == 0)
    {
        printf ("*********************** HOLY COW, RANDOM TESTS PASSED!!! **********************\n");
    }
    else
    {
        printf("\n************************ WOMP WOMP... RANDOM TEST FAILED ************************\n");
        printf("drawCard() ERROR: %d\n", badDraw);
        printf("cardEffect() ERROR: %d\n", badCardOutput);
        printf("shuffle() ERROR: %d\n", badShuffle);
        printf("INVALID Treasure Count: %d\n", badTreasureCount);
        printf("INVALID hand OR deck count: %d\n", badHandCount);
        printf("\n********************** RUBBING IT IN... RANDOM TEST FAILED *********************\n");
    }
    printf ("\n********************************* GCOV OUTPUT *********************************\n");
    return 0;
}

// Adventurer Card Test Function
void adventurerCrdTst(int p, struct gameState* post)
{
    
    int preBootyCount = 0;
    int postBootyCount = 0;
    int card = 0;
    int cardDrawn = 0;
    int currTestHand[MAX_HAND];
    int capturedBooty = 0;
    struct gameState pre;
    int bonus = 0;
    int r, s, t, i;
    int z = 0;

    memcpy(&pre, post, sizeof(struct gameState)); // game state goes to pre

    r = cardEffect(adventurer, 0, 0, 0, post, 0, &bonus); // call cardEffect w/ Adventurer (lame)

    if (r)
    {// cardEffect failure
        badCardOutput++;
    }

    while (capturedBooty < 2)
    {
        if (pre.deckCount[p] < 1) 
        {// re-fill the deck
            s = shuffle(p, &pre);
            if (s == -1 && pre.deckCount[p] >= 1)
            {// validate shuffle()
                badShuffle++;
            }
        }
        t = drawCard(p, &pre);

        if (t == -1 && pre.deckCount[p] != 0) 
        {// validate drawCard
            badDraw++;
        }

        cardDrawn = pre.hand[p][pre.handCount[p] - 1]; // top card == drawn card
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
        {
            capturedBooty++;
        }
        else
        {// not treasure/booty, remove top card
            currTestHand[z] = cardDrawn;
            pre.handCount[p]--; 
            z++;
        }
    }
    while (z - 1 >= 0)
    {// discard drawn cards
        pre.discard[p][pre.discardCount[p]++] = currTestHand[z - 1]; 
        z = z - 1;
    }
    
    for (i = 0; i < post->handCount[p]; i++)
    {// post booty/treasure count & store it
        card = post->hand[p][i];
        if (card == copper || card == silver || card == gold)
        {
            postBootyCount++;
        }
    }

    for (i = 0; i < pre.handCount[p]; i++)
    {// pre booty/treasure count & store it
        card = pre.hand[p][i];
        if (card == copper || card == silver || card == gold)
        {
            preBootyCount++;
        }
    }

    if (postBootyCount != preBootyCount)
    {//pre / post bootyCount comparison
        badTreasureCount++;
    }

    // capture counts for comparisons / validation
    int beforeHandCount = pre.handCount[p];
    int beforeDeckCount = pre.deckCount[p];
    int beforeDiscardCount = pre.discardCount[p];
    int afterHandCount = post->handCount[p];
    int afterDeckCount = post->deckCount[p];
    int afterDiscardCount = post->discardCount[p];

    if (!(afterHandCount == beforeHandCount && afterDeckCount == beforeDeckCount && afterDiscardCount == beforeDiscardCount))
    {// hand && deck comparison/validation
        badHandCount++;
    }
}