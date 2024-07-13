#include "core.h"
#include "internal.h"
#include "node/node_common.h"

extern NODE_Base_t demo;
extern NODE_Base_t template_node;
NODE_Base_t *_apstRegisteredNode[] = {
//    &template_node,
    &demo,
};

SupportedEvent_t *pstAllEvent;

void EventInitialize()
{
    size_t szAllEventSize = 0;
    for (uint32_t i = 0; i < sizeof(_apstRegisteredNode)/sizeof(_apstRegisteredNode[0]); ++i) {
        NODE_Base_t *pstNode = _apstRegisteredNode[i];
        size_t szSize = 0;
        pstNode->opts.GetSupportedEventListSize(pstNode, &szSize);
        szAllEventSize += szSize;
    }
    printf("szAllEventSize %zu\n", szAllEventSize);
    pstAllEvent = (SupportedEvent_t *)malloc(szAllEventSize);

    SupportedEvent_t *pEventStart = pstAllEvent;
    for (uint32_t i = 0; i < sizeof(_apstRegisteredNode)/sizeof(_apstRegisteredNode[0]); ++i) {
        NODE_Base_t *pstNode = _apstRegisteredNode[i];
        size_t szSize = 0;
        pstNode->opts.GetSupportedEventListSize(pstNode, &szSize);
        pstNode->opts.GetSupportedEventList(pstNode, pEventStart, szSize);
        pEventStart += szSize / sizeof(SupportedEvent_t);
        printf("%d\n", i);
    }

    SupportedEvent_t *pEvent = pstAllEvent;
    for (uint32_t i = 0; i < szAllEventSize / sizeof(SupportedEvent_t); ++i) {
        printf("i %d, event: %s \n", i, pEvent->eventName);
        pEvent++;
    }
}

void NODE_Initialize()
{
    EventInitialize();

    for (uint32_t i = 0; i < sizeof(_apstRegisteredNode)/sizeof(_apstRegisteredNode[0]); ++i) {
        NODE_Base_t *pstNode = _apstRegisteredNode[i];
        if (pstNode->opts.Init) {
            pstNode->opts.Init(pstNode);
        }
        printf("%s\n", __func__);
    }
    printf("%s\n", __func__);
}


void EventHandler()
{
    
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

