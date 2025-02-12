#include "../node_common.h"
#include "../../internal.h"

#include "DEV_Config.h"
#include "GUI_Paint.h"
#include "GUI_BMPfile.h"
#include "EPD_7in3e.h"
// #include "ImageData.h"
#include "Debug.h"
#include <stdlib.h> // malloc() free()

static SupportedEvent_t _astPictureSupportedEvent[] = {
    {.eventName = "TemplateEvent"},
};

void picture_test()
{
    printf("EPD_7IN3E_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }

    printf("cyril e-Paper Init and Clear...\r\n");
    EPD_7IN3E_Init();

    //Create a new image cache
    UBYTE *BlackImage;
    UDOUBLE Imagesize = ((EPD_7IN3E_WIDTH % 2 == 0)? (EPD_7IN3E_WIDTH / 2 ): (EPD_7IN3E_WIDTH / 2 + 1)) * EPD_7IN3E_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_7IN3E_WIDTH, EPD_7IN3E_HEIGHT, 0, EPD_7IN3E_WHITE);
    Paint_SetScale(6);

#if 1   // show bmp
    printf("show bmp1-----------------\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(EPD_7IN3E_WHITE);
    GUI_ReadBmp_RGB_6Color("../pic/test2.bmp", 0, 0);
	//Paint_DrawBitMap(Image6color);
    EPD_7IN3E_Display(BlackImage);
    DEV_Delay_ms(3000);
#endif

#if 0   // Drawing on the image
    Paint_NewImage(BlackImage, EPD_7IN3E_WIDTH, EPD_7IN3E_HEIGHT, 0, EPD_7IN3E_WHITE);
    Paint_SetScale(6);
    // 1.Select Image
    printf("SelectImage:BlackImage\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(EPD_7IN3E_WHITE);

    // 2.Drawing on the image
    printf("Drawing:BlackImage\r\n");
    Paint_DrawPoint(10, 80, EPD_7IN3E_RED, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    Paint_DrawPoint(10, 90, EPD_7IN3E_BLUE, DOT_PIXEL_2X2, DOT_STYLE_DFT);
    Paint_DrawPoint(10, 100, EPD_7IN3E_GREEN, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    Paint_DrawLine(20, 70, 70, 120, EPD_7IN3E_YELLOW, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawLine(70, 70, 20, 120, EPD_7IN3E_YELLOW, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawRectangle(20, 70, 70, 120, EPD_7IN3E_BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawRectangle(80, 70, 130, 120, EPD_7IN3E_BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawCircle(45, 95, 20, EPD_7IN3E_BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawCircle(105, 95, 20, EPD_7IN3E_WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawLine(85, 95, 125, 95, EPD_7IN3E_YELLOW, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawLine(105, 75, 105, 115, EPD_7IN3E_YELLOW, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawString_CN(10, 160, "你好abc", &Font12CN, EPD_7IN3E_BLACK, EPD_7IN3E_WHITE);
    Paint_DrawString_CN(10, 180, "微雪电子", &Font24CN, EPD_7IN3E_WHITE, EPD_7IN3E_BLACK);
    Paint_DrawNum(10, 33, 123456789, &Font12, EPD_7IN3E_BLACK, EPD_7IN3E_WHITE);
    Paint_DrawNum(10, 50, 987654321, &Font16, EPD_7IN3E_WHITE, EPD_7IN3E_BLACK);
    Paint_DrawString_EN(400, 0, "waveshare", &Font16, EPD_7IN3E_BLACK, EPD_7IN3E_WHITE);
    Paint_DrawString_EN(400, 20, "waveshare", &Font16, EPD_7IN3E_GREEN, EPD_7IN3E_WHITE);
    Paint_DrawString_EN(400, 40, "waveshare", &Font16, EPD_7IN3E_BLUE, EPD_7IN3E_WHITE);
    Paint_DrawString_EN(400, 60, "waveshare", &Font16, EPD_7IN3E_RED, EPD_7IN3E_WHITE);
    Paint_DrawString_EN(400, 80, "waveshare", &Font16, EPD_7IN3E_YELLOW, EPD_7IN3E_WHITE);
    Paint_DrawString_EN(150, 0, "hello world", &Font24, EPD_7IN3E_WHITE, EPD_7IN3E_BLACK);
    Paint_DrawString_EN(150, 30, "hello world", &Font24, EPD_7IN3E_GREEN, EPD_7IN3E_BLACK);
    Paint_DrawString_EN(150, 60, "hello world", &Font24, EPD_7IN3E_BLUE, EPD_7IN3E_BLACK);
    Paint_DrawString_EN(150, 90, "hello world", &Font24, EPD_7IN3E_RED, EPD_7IN3E_BLACK);
    Paint_DrawString_EN(150, 120, "hello world", &Font24, EPD_7IN3E_YELLOW, EPD_7IN3E_BLACK);
    Paint_DrawString_EN(150, 180, "hello world", &Font24, EPD_7IN3E_BLACK, EPD_7IN3E_YELLOW);

    printf("EPD_Display\r\n");
    EPD_7IN3E_Display(BlackImage);
    DEV_Delay_ms(3000);
#endif

    // printf("Clear...\r\n");
//    EPD_7IN3E_Clear(EPD_7IN3E_WHITE);

    printf("Goto Sleep...\r\n");
    EPD_7IN3E_Sleep();
    free(BlackImage);
    BlackImage = NULL;
    DEV_Delay_ms(2000); // important, at least 2s
    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();

}

static int Picture_Init(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    picture_test();
    return 0;
}

static int Picture_Deinit(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Picture_Open(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Picture_Close(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Picture_Reset(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Picture_Loop(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Picture_SetParameter(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Picture_GetParameter(struct NODE_Base_s *pstNode)
{
    NODE_PRINT("%s enter\n", __func__);
    return 0;
}

static int Picture_GetSupportedEventList(struct NODE_Base_s *pstNode, SupportedEvent_t *pstSupportedEvent, size_t szSize)
{
    memcpy(pstSupportedEvent, _astPictureSupportedEvent, sizeof(_astPictureSupportedEvent));
    return 0;
}

static int Picture_GetSupportedEventListSize(struct NODE_Base_s *pstNode, size_t *pszSize)
{
    *pszSize = sizeof(_astPictureSupportedEvent);
    return 0;
}

NODE_Base_t picture = {
    .name = "picturess",
    .opts.Init = Picture_Init,
    .opts.Deinit = Picture_Deinit,
    .opts.Open = Picture_Open,
    .opts.Close = Picture_Close ,
    .opts.Reset = Picture_Reset,
    .opts.Loop = Picture_Loop,

    .opts.SetParameter = NULL,
    .opts.GetParameter = NULL,
    .opts.GetSupportedParameterList = NULL,
    .opts.GetSupportedParameterListSize = NULL,
    .opts.GetTrackingParameterList = NULL,
    .opts.GetTrackingParameterListSize = NULL,

    .opts.GetSupportedEventList = Picture_GetSupportedEventList,
    .opts.GetSupportedEventListSize = Picture_GetSupportedEventListSize,
    .opts.GetTrackingEventList = NULL,
    .opts.GetTrackingEventListSize = NULL,

    .opts.RegisterEventCallback = NULL,
    .opts.OnEvent = NULL,
};




