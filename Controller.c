
void controller(char player);

void controller(char player)
{
    switch (player)
    {
    case '1':
        printHand(playerP1.hand, playerP1.tamHand);
        break;
    case '2':
        printHand(playerP2.hand, playerP2.tamHand);
        break;
    default:
        break;
    }
}