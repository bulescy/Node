#include "core.h"
#include "internal.h"
#include "node/node_common.h"

NODE_Base_t temp_node;

extern NODE_Base_t demo;
NODE_Base_t *_apstRegisteredNode[] = {
    &temp_node,
    &demo,
};


void NODE_Initialize()
{
    for (uint32_t i = 0; i < sizeof(_apstRegisteredNode)/sizeof(_apstRegisteredNode[0]); ++i) {
        NODE_Base_t *pstNode = _apstRegisteredNode[i];
        if (pstNode->opts.Init) {
            pstNode->opts.Init(pstNode);
        }
        printf("%s\n", __func__);
    }
    printf("%s\n", __func__);
}

void NODE_Work()
{
    for (uint32_t i = 0; i < sizeof(_apstRegisteredNode)/sizeof(_apstRegisteredNode[0]); ++i) {
        NODE_Base_t *pstNode = _apstRegisteredNode[i];
        if (pstNode->opts.Loop) {
            pstNode->opts.Loop(pstNode);
        }
    }
    printf("%s\n", __func__);
}

