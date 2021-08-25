#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.c"
#include "View.c"
#include "Utils.c"
#include "Controller.c"

int main()
{
    struct table table = {playerP1, playerP2, left, middle};
    int o;
    srand(time(0));
    controller(o, table);
    return 0;
}
