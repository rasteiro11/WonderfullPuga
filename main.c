#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.c"
#include "View.c"
#include "Utils.c"
#include "Controller.c"

int main()
{
    srand(time(0));
    initialize(pieces);
    shuffle(pieces);
    printf("Jogador 1\n");
    distributeForP1(pieces, &playerP1);
    printHand(playerP1.hand, playerP1.tamHand);
    printf("\n-----------------\n");
    printf("Jogador 2\n");
    distributeForP2(pieces, &playerP2);
    printHand(playerP2.hand, playerP2.tamHand);
    printf("\n-----------------\n");
    char screen = '1';
    controller(screen);
    printf("\n-----------------\n");
    screen = '2';
    controller(screen);

    return 0;
}
