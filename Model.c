
struct piece
{
    int right;
    int left;
};
struct player
{
    struct piece hand[28];
    int tamHand;
};
struct leftDeck
{
    struct piece pieces[14];
    int tamLeftDeck;
};

struct mid
{
    struct piece mid[28];
    int tamMid;
    int leftMostSide;
    int rightMostSide;
};
struct table
{
    struct player playerP1;
    struct player playerP2;
    struct leftDeck left;
    struct mid middle;
};

struct piece pieces[28];
struct player playerP1;
struct player playerP2;
struct leftDeck left;
struct mid middle;

void populatePiece(struct piece *p, int left, int right);
void initialize(struct piece p1[]);
void distributeForP2(struct piece pieces[], struct player *playerP2);
void distributeForP1(struct piece pieces[], struct player *playerP1);

void populatePiece(struct piece *p, int left, int right)
{
    p->left = left;
    p->right = right;
}

void initialize(struct piece p1[])
{
    int t = 0;
    for (int i = 0; i <= 6; i++)
    {
        for (int j = i; j <= 6; j++)
        {
            populatePiece(&p1[t], i, j);
            t++;
        }
    }
}

void distributeForP1(struct piece pieces[], struct player *playerP1)
{
    for (int i = 0; i < 7; i++)
    {
        if (i < 7)
        {
            playerP1->hand[i] = pieces[i];
        }
    }
    playerP1->tamHand = 7;
}

void distributeForP2(struct piece pieces[], struct player *playerP2)
{
    int i = 0;
    for (int j = 7; j < 14; j++)
    {
        if (j >= 7)
        {
            playerP2->hand[i] = pieces[j];
        }
        i++;
    }
    playerP2->tamHand = 7;
}

void createLeftDeck(struct piece pieces[], struct leftDeck *left)
{
    int j = 0;
    for (int i = 14; i < 28; i++)
    {
        left->pieces[j] = pieces[i];
        j++;
    }
    left->tamLeftDeck = 14;
}