#include "core.h"
#include "internal.h"
#include "node/node_common.h"

NODE_Base_t temp_node;

extern NODE_Base_t demo;
NODE_Base_t *pstNodeInstance[] = {
    &temp_node,
    &demo,
};


void NODE_Initialize()
{
    for (uint32_t i = 0; i < sizeof(pstNodeInstance)/sizeof(pstNodeInstance[0]); ++i) {
        if (pstNodeInstance[i]->opts.init) {
            pstNodeInstance[i]->opts.init();
        }
        printf("%s\n", __func__);
    }
    printf("%s\n", __func__);
}

void NODE_Work()
{
    for (uint32_t i = 0; i < sizeof(pstNodeInstance)/sizeof(pstNodeInstance[0]); ++i) {
        if (pstNodeInstance[i]->opts.loop) {
            pstNodeInstance[i]->opts.loop();
        }
    }
    printf("%s\n", __func__);
}



int get_version()
{
    return 10;
}
