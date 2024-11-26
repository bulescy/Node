#include "../node_common.h"
#include "../../internal.h"

static SupportedEvent_t _astDemoSupportedEvent[] = {
    {.eventName = "hello"},
    {.eventName = "finished"},
};

static int Demo_Init(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_Deinit(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_Open(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_Close(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_Reset(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_Loop(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_SetParameter(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_GetParameter(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Demo_GetSupportedEventList(struct NODE_Base_s *pstNode, SupportedEvent_t *pstSupportedEvent, size_t szSize)
{
    NODE_PRINT("%s size: %zu\n", _astDemoSupportedEvent[0].eventName, sizeof(_astDemoSupportedEvent));
    memcpy(pstSupportedEvent, _astDemoSupportedEvent, sizeof(_astDemoSupportedEvent));
    return 0;
}

static int Demo_GetSupportedEventListSize(struct NODE_Base_s *pstNode, size_t *pszSize)
{
    *pszSize = sizeof(_astDemoSupportedEvent);
    return 0;
}

NODE_Base_t demo = {
    .name = "demo",
    .opts.Init = Demo_Init,
    .opts.Deinit = Demo_Deinit,
    .opts.Open = Demo_Open,
    .opts.Close = Demo_Close ,
    .opts.Reset = Demo_Reset,
    .opts.Loop = Demo_Loop,

    .opts.SetParameter = NULL,
    .opts.GetParameter = NULL,
    .opts.GetSupportedParameterList = NULL,
    .opts.GetSupportedParameterListSize = NULL,
    .opts.GetTrackingParameterList = NULL,
    .opts.GetTrackingParameterListSize = NULL,

    .opts.GetSupportedEventList = Demo_GetSupportedEventList,
    .opts.GetSupportedEventListSize = Demo_GetSupportedEventListSize,
    .opts.GetTrackingEventList = NULL,
    .opts.GetTrackingEventListSize = NULL,

    .opts.RegisterEventCallback = NULL,
    .opts.OnEvent = NULL,
};


