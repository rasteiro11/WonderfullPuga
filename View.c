
void printAllPieces(struct piece p1[]);
void printPiece(struct piece p);
void printHand(struct piece hand[], int tam);
void printMid(struct piece mid[], int tam);
void printMenu();

void printAllPieces(struct piece p1[])
{
    for (int i = 0; i < 28; i++)
    {
        printPiece(p1[i]);
    }
}

void printPiece(struct piece p)
{
    printf(" %d|%d ", p.left, p.right);
    // printf("\n");
}

void printHand(struct piece hand[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printPiece(hand[i]);
    }
}

void printLeftDeck(struct piece pieces[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printPiece(pieces[i]);
    }
}

void printMid(struct piece mid[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printPiece(mid[i]);
    }
    printf("\n");
}

void printMenu()
{
    printf("\t<|---- Bem vindo ao wonderfull puga domino ----|>\n");
    printf("\t1) Pressione 1 se voce deseja jogar sozinho\n");
    printf("\t2) Pressione 2 se voce deseja jogar com um amigo");
}

void printPlayerMenu()
{
    printf("\n");
    printf("\tPressione 1 se quiser jogar uma peca\n");
    printf("\tPressione 2 se quiser comprar uma peca\n");
}