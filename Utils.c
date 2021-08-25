
void swap(int i, int j, struct piece p1[]);
int randomImpl();
void shuffle(struct piece p1[]);
int calcTam();
void pushToMid();
void pushToMid(struct piece mid[], struct piece hand[], int pos, int tamMidlle);

//void calcTam(struct piece hand[]);

int randomImpl()
{
    return rand() % 28;
}

void swap(int i, int j, struct piece p1[])
{
    struct piece temp;
    temp = p1[i];
    p1[i] = p1[j];
    p1[j] = temp;
}

void shuffle(struct piece p1[])
{
    for (int i = 0; i < 28; i++)
    {
        int t = randomImpl();
        swap(i, t, p1);
    }
}

// void calcTam(struct piece hand[])
// {
//     int tam = sizeof hand / sizeof hand[0];
//     printf("%d", tam);
// }

int calcTam()
{
    int tam = sizeof pieces / sizeof pieces[0];
    return tam;
}

void pushToMid(struct piece mid[], struct piece hand[], int pos, int tamMidlle)
{
    mid[tamMidlle] = hand[pos];
}

void firstPushToMid(struct piece mid[], struct piece hand[], int pos, int tamMidlle)
{
    mid[tamMidlle] = hand[pos];
}

void buyPieceP1(struct table *table)
{
    for (int i = table->playerP1.tamHand; i >= 0; i--)
    {
        table->playerP1.hand[i + 1] = table->playerP1.hand[i];
    }
    table->playerP1.tamHand++;
    table->playerP1.hand[0] = table->left.pieces[0];

    for (int j = 0; j < table->left.tamLeftDeck; j++)
    {
        table->left.pieces[j] = table->left.pieces[j + 1];
    }
    table->left.tamLeftDeck--;
}

void buyPieceP2(struct table *table)
{
    for (int i = table->playerP2.tamHand; i >= 0; i--)
    {
        table->playerP2.hand[i + 1] = table->playerP2.hand[i];
    }
    table->playerP2.tamHand++;
    table->playerP2.hand[0] = table->left.pieces[0];

    for (int j = 0; j < table->left.tamLeftDeck; j++)
    {
        table->left.pieces[j] = table->left.pieces[j + 1];
    }
    table->left.tamLeftDeck--;
}

void reArrange(struct piece hand[], int pos, int tam)
{
    for (int i = pos; i < tam; i++)
    {
        hand[i] = hand[i + 1];
    }
}
int playIsValidP1(struct table *table, int pos)
{
    if ((table->playerP1.hand[pos].right == table->middle.leftMostSide) || (table->playerP1.hand[pos].left == table->middle.rightMostSide))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int playIsValidP2(struct table *table, int pos)
{
    if ((table->playerP2.hand[pos].right == table->middle.leftMostSide) || (table->playerP2.hand[pos].left == table->middle.rightMostSide))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insertLeft(struct table *table, struct piece piece)
{
    for (int i = table->middle.tamMid; i >= 0; i--)
    {
        table->middle.mid[i + 1] = table->middle.mid[i];
    }
    table->middle.mid[0] = piece;
}
void insertRight(struct table *table, struct piece piece)
{
    table->middle.mid[table->middle.tamMid] = piece;
}

void playerP1Turn(int pos, struct table *table)
{
    int IsValid;
    printf("Entre com o indice da peca que voce quer dar o push P1:\n");
    scanf("%d", &pos);
    IsValid = playIsValidP1(table, pos);
    printf("O Valor de isValid e: %d, digite outro indice", IsValid);
    while (IsValid != 1)
    {
        printf("\nA peca nao pode ser inserida\n");
        scanf("%d", &pos);
        IsValid = playIsValidP1(table, pos);
    }
    if (table->playerP1.hand[pos].right == table->middle.leftMostSide)
    {
        printf("\nInserir a esquerda\n");
        insertLeft(table, table->playerP1.hand[pos]);
        table->middle.tamMid++;
    }
    else if (table->playerP1.hand[pos].left == table->middle.rightMostSide)
    {
        printf("\nInserir a direita\n");
        insertRight(table, table->playerP1.hand[pos]);
        table->middle.tamMid++;
    }
    table->middle.leftMostSide = table->middle.mid[0].left;
    table->middle.rightMostSide = table->middle.mid[table->middle.tamMid - 1].right;
    printf("\n O lado esquerdo da primeira peca vale: %d\n", table->middle.leftMostSide);
    printf("\n O lado direito da ultima peca vale: %d\n", table->middle.rightMostSide);
    table->playerP1.tamHand--;
    reArrange(table->playerP1.hand, pos, table->playerP1.tamHand);
}

void firstPlayerP1Turn(int pos, struct table *table)
{
    printf("Entre com o indice da peca que voce quer dar o push P1:\n");
    scanf("%d", &pos);
    firstPushToMid(table->middle.mid, table->playerP1.hand, pos, table->middle.tamMid);
    printf("\n O lado esquerdo da primeira peca vale: %d\n", table->middle.mid[0].left);
    printf("\n O lado direito da ultima peca vale: %d\n", table->middle.mid[0].right);
    table->middle.leftMostSide = table->middle.mid[0].left;
    table->middle.rightMostSide = table->middle.mid[0].right;
    table->middle.tamMid++;
    table->playerP1.tamHand--;
    reArrange(table->playerP1.hand, pos, table->playerP1.tamHand);
}

void playerP2Turn(int pos, struct table *table)
{
    int IsValid;
    printf("Entre com o indice da peca que voce quer dar o push P2:\n");
    scanf("%d", &pos);
    IsValid = playIsValidP2(table, pos);
    printf("O Valor de isValid e: %d, digite outro indice", IsValid);
    while (IsValid != 1)
    {
        printf("\nA peca nao pode ser inserida\n");
        scanf("%d", &pos);
        IsValid = playIsValidP2(table, pos);
    }
    if (table->playerP2.hand[pos].right == table->middle.leftMostSide)
    {
        printf("\nInserir a esquerda\n");
        insertLeft(table, table->playerP2.hand[pos]);
        table->middle.tamMid++;
    }
    else if (table->playerP2.hand[pos].left == table->middle.rightMostSide)
    {
        printf("\nInserir a direita\n");
        insertRight(table, table->playerP2.hand[pos]);
        table->middle.tamMid++;
    }
    table->middle.leftMostSide = table->middle.mid[0].left;
    table->middle.rightMostSide = table->middle.mid[table->middle.tamMid - 1].right;
    printf("\n O lado esquerdo da primeira peca vale: %d\n", table->middle.leftMostSide);
    printf("\n O lado direito da ultima peca vale: %d\n", table->middle.rightMostSide);
    table->playerP2.tamHand--;
    reArrange(table->playerP2.hand, pos, table->playerP2.tamHand);
}

void firstPlayerP2Turn(int pos, struct table *table)
{
    printf("Entre com o indice da peca que voce quer dar o push P2:\n");
    scanf("%d", &pos);
    firstPushToMid(table->middle.mid, table->playerP2.hand, pos, table->middle.tamMid);
    printf("\n O lado esquerdo da primeira peca vale: %d\n", table->middle.mid[0].left);
    printf("\n O lado direito da ultima peca vale: %d\n", table->middle.mid[0].right);
    table->middle.leftMostSide = table->middle.mid[0].left;
    table->middle.rightMostSide = table->middle.mid[0].right;
    table->middle.tamMid++;
    table->playerP2.tamHand--;
    reArrange(table->playerP2.hand, pos, table->playerP2.tamHand);
}

void whoStarts(struct table *table, int *player)
{
    //printHand(table->playerP1.hand, table->playerP1.tamHand);
    // // printf("\n");
    //printHand(table->playerP2.hand, table->playerP2.tamHand);
    struct piece maxPieceP1 = {-1, -1};
    struct piece maxPieceP2 = {-1, -1};
    for (int i = 0; i < 7; i++)
    {
        for (int j = 6; j >= 0; j--)
        {
            if (table->playerP1.hand[i].left == table->playerP1.hand[i].right)
            {
                //printf("\nA peca de posicao %d tem lados %d|%d\n", i, table->playerP1.hand[i].left, table->playerP1.hand[i].right);
                if (table->playerP1.hand[i].left > maxPieceP1.left)
                {
                    maxPieceP1.left = table->playerP1.hand[i].left;
                    maxPieceP1.right = table->playerP1.hand[i].right;
                }
            }
        }
    }
    for (int x = 0; x < 7; x++)
    {
        for (int j = 6; j >= 0; j--)
        {
            if (table->playerP2.hand[x].left == table->playerP2.hand[x].right)
            {
                //printf("\nA peca de posicao %d tem lados %d|%d\n", i, table->playerP2.hand[i].left, table->playerP2.hand[i].right);
                if (table->playerP2.hand[x].left > maxPieceP2.left)
                {
                    maxPieceP2.left = table->playerP2.hand[x].left;
                    maxPieceP2.right = table->playerP2.hand[x].right;
                }
            }
        }
    }
    printf("\nA peca de maior numeros e: \n");
    printPiece(maxPieceP1);
    printPiece(maxPieceP2);
    printf("\nA maior peca de todas e: \n");
    if (maxPieceP2.left > maxPieceP1.right)
    {
        printPiece(maxPieceP2);
        *player = 2;
    }
    else
    {
        printPiece(maxPieceP1);
        *player = 1;
    }
}
