#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct piece
{
    int right;
    int left;
};

void printAllPieces(struct piece p1[]);
void printPiece(struct piece p);
void populatePiece(struct piece *p, int left, int right);
void initialize(struct piece p1[]);
void swap(int i, int j, struct piece p1[]);
int randomImpl();
void shuffle(struct piece p1[]);

int main()
{
    srand(time(0));

    struct piece p1[28];
    initialize(p1);
    printf("\n----------------------------\n");
    printAllPieces(p1);
    shuffle(p1);
    printAllPieces(p1);

    return 0;
}

void printPiece(struct piece p)
{
    printf(" %d|%d ", p.left, p.right);
    printf("\n");
}

void printAllPieces(struct piece p1[])
{
    for (int i = 0; i < 28; i++)
    {
        printPiece(p1[i]);
    }
}

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