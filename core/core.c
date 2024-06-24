#include "core.h"
#include "internal.h"

typedef void (*operation)();

typedef struct NODE_Operation_s {
    operation init;
    operation deinit;
    operation open;
    operation close;
    operation loop;

}NODE_Operation_t;


typedef struct NODE_Base_s {
    char *name;
    NODE_Operation_t opts;
}NODE_Base_t;

#define LOCAL_NODE_NUMBER_MAX     10

NODE_Base_t temp_node;

NODE_Base_t *pstNodeInstance[] = {
    &temp_node,
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
