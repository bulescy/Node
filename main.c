#include <stdio.h>


#include "core/core.h"

int main(int argc, char *argv[])
{

    int version = 0;
    version = get_version();
    printf("get version %d\n", version);

    printf("main end\n");
    return 0;
}
