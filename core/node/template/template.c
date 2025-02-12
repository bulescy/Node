#include "../node_common.h"
#include "../../internal.h"

static SupportedEvent_t _astTemplateHeaderSupportedEvent[] = {
    {.eventName = "TemplateEvent"},
};

static int TemplateHeader_Init(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_Deinit(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_Open(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_Close(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_Reset(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_Loop(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_SetParameter(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_GetParameter(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int TemplateHeader_GetSupportedEventList(struct NODE_Base_s *pstNode, SupportedEvent_t *pstSupportedEvent, size_t szSize)
{
    memcpy(pstSupportedEvent, _astTemplateHeaderSupportedEvent, sizeof(_astTemplateHeaderSupportedEvent));
    return 0;
}

static int TemplateHeader_GetSupportedEventListSize(struct NODE_Base_s *pstNode, size_t *pszSize)
{
    *pszSize = sizeof(_astTemplateHeaderSupportedEvent);
    return 0;
}

NODE_Base_t TemplateHeader_node = {
    .name = "template",
    .opts.Init = TemplateHeader_Init,
    .opts.Deinit = TemplateHeader_Deinit,
    .opts.Open = TemplateHeader_Open,
    .opts.Close = TemplateHeader_Close ,
    .opts.Reset = TemplateHeader_Reset,
    .opts.Loop = TemplateHeader_Loop,

    .opts.SetParameter = NULL,
    .opts.GetParameter = NULL,
    .opts.GetSupportedParameterList = NULL,
    .opts.GetSupportedParameterListSize = NULL,
    .opts.GetTrackingParameterList = NULL,
    .opts.GetTrackingParameterListSize = NULL,

    .opts.GetSupportedEventList = TemplateHeader_GetSupportedEventList,
    .opts.GetSupportedEventListSize = TemplateHeader_GetSupportedEventListSize,
    .opts.GetTrackingEventList = NULL,
    .opts.GetTrackingEventListSize = NULL,

    .opts.RegisterEventCallback = NULL,
    .opts.OnEvent = NULL,
};




