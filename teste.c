#include <stdio.h>
#include <stdlib.h>

struct piece
{
    int right;
    int left;
};

int blueprint[56] = {6, 6, 6, 5, 6, 4, 6, 3, 6, 2, 6, 1, 6, 0, 5, 5, 5, 4, 5, 3, 5, 2, 5, 1, 5, 0, 4, 4, 4, 3, 4, 2, 4, 1, 4, 0, 3, 3, 3, 2, 3, 1, 3, 0, 2, 2, 2, 1, 2, 0, 1, 1, 1, 0, 0, 0};

void printPiece(struct piece p);
void populatePiece(struct piece *p, int left, int right);
void initialize(struct piece p1[]);

int main()
{
    struct piece p1[28];
    initialize(p1);

    return 0;
}

void printPiece(struct piece p)
{
    printf(" %d|%d ", p.left, p.right);
    printf("\n");
}

void populatePiece(struct piece *p, int left, int right)
{
    p->left = left;
    p->right = right;
}

void initialize(struct piece p1[])
{
    int j = 0;
    for (int i = 0; i < 28; i++)
    {
        p1[i].left = blueprint[j];
        j++;
        p1[i].right = blueprint[j];
        printPiece(p1[i]);
        j++;
    }
}