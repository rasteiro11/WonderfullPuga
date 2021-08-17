
void printAllPieces(struct piece p1[]);
void printPiece(struct piece p);
void printHand(struct piece hand[], int tam);

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
    printf("\n");
}

void printHand(struct piece hand[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printPiece(hand[i]);
    }
}