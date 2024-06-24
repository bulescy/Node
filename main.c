#include <stdio.h>

#include <unistd.h>

#include "core/core.h"

int main(int argc, char *argv[])
{



    NODE_Initialize();



    while (1) {
        sleep(1);
        NODE_Work();
    }


    printf("main end\n");
    return 0;
}
