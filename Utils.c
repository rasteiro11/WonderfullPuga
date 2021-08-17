
void swap(int i, int j, struct piece p1[]);
int randomImpl();
void shuffle(struct piece p1[]);
int calcTam();
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