#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct piece
{
    int right;
    int left;
};

int blueprint[56] = {6, 6, 6, 5, 6, 4, 6, 3, 6, 2, 6, 1, 6, 0, 5, 5, 5, 4, 5, 3, 5, 2, 5, 1, 5, 0, 4, 4, 4, 3, 4, 2, 4, 1, 4, 0, 3, 3, 3, 2, 3, 1, 3, 0, 2, 2, 2, 1, 2, 0, 1, 1, 1, 0, 0, 0};

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
    printf("\n----------------------------\n");
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