#include "template.h"
#include "../node_common.h"
#include "../../internal.h"

int Demo_Init(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}

int Demo_Deinit(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}

int Demo_Open(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}

int Demo_Close(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}

int Demo_Reset(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}

int Demo_Loop(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}

int Demo_SetParameter(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}

int Demo_GetParameter(struct NODE_Base_s *pstNode)
{
    printf("%s enter\n", __func__);
    return 0;
}


NODE_Base_t demo = {
    .name = "template",
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

    .opts.GetSupportedEventList = NULL,
    .opts.GetSupportedEventListSize = NULL,
    .opts.GetTrackingEventList = NULL,
    .opts.GetTrackingEventListSize = NULL,

    .opts.RegisterEventCallback = NULL,
    .opts.OnEvent = NULL,
};




