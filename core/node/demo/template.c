#include "template.h"
#include "../node_common.h"
#include "../../internal.h"

void demo_init()
{
    printf("demo init\n");
}



NODE_Base_t demo = {
    .name = "template",
    .opts.init = demo_init,
};




