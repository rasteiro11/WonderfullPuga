
void controller(int option, struct table table);

void controller(int option, struct table table)
{
    // int io = 1;
    int pos;
    int play;
    int player;
    int playerMenu = 100;
    do
    {
        printMenu();
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nsolo\n");
            initialize(pieces);
            shuffle(pieces);
            createLeftDeck(pieces, &table.left);
            distributeForP1(pieces, &table.playerP1);
            distributeForP2(pieces, &table.playerP2);
            whoStarts(&table, &player);
            printf("\nO player que vai comecar e o: %d\n", player);
            // if (player == 1)
            // {
            //     printf("Player 1\n");
            //     printf("Voce e o jogador com a maior peca!! Inicie o jogo\n");
            //     printHand(table.playerP1.hand, table.playerP1.tamHand);
            //     printf("\n");
            //     firstPlayerP1Turn(pos, &table);
            // }
            // else if (player == 2)
            // {
            //     printf("\nPlayer 2\n");
            //     printf("Voce e o jogador com a maior peca!! Inicie o jogo\n");
            //     printHand(table.playerP2.hand, table.playerP2.tamHand);
            //     printf("\n");
            //     firstPlayerP2Turn(pos, &table);
            // }
            switch (player)
            {
            case 1:
                printf("Player 1\n");
                printf("Voce e o jogador com a maior peca!! Inicie o jogo\n");
                printHand(table.playerP1.hand, table.playerP1.tamHand);
                printf("\n");
                firstPlayerP1Turn(pos, &table);
                player = 2;
                break;
            case 2:
                printf("\nPlayer 2\n");
                printf("Voce e o jogador com a maior peca!! Inicie o jogo\n");
                printHand(table.playerP2.hand, table.playerP2.tamHand);
                printf("\n");
                firstPlayerP2Turn(pos, &table);
                player = 1;
                break;
            default:
                break;
            }
            do
            {
                printf("\nMiddle");
                printMid(table.middle.mid, table.middle.tamMid);
                switch (player)
                {
                case 1:
                    printf("Player 1\n");
                    printHand(table.playerP1.hand, table.playerP1.tamHand);
                    printPlayerMenu();
                    scanf("%d", &play);
                    switch (play)
                    {
                    case 1:
                        playerP1Turn(pos, &table);
                        break;
                    case 2:
                        buyPieceP1(&table);
                        break;
                    default:
                        break;
                    }
                    player = 2;
                    break;
                case 2:
                    printf("\nPlayer 2\n");
                    printHand(table.playerP2.hand, table.playerP2.tamHand);
                    printPlayerMenu();
                    scanf("%d", &play);
                    switch (play)
                    {
                    case 1:
                        playerP2Turn(pos, &table);
                        break;
                    case 2:
                        buyPieceP2(&table);
                        break;
                    default:
                        break;
                    }
                    player = 1;
                    break;
                default:
                    break;
                }
            } while (playerMenu != 0);

            break;
        case 2:
            printf("\ndupla\n");
            break;
        default:
            break;
        }
    } while (option != 0);
}
