#ifndef _NODE_COMMON_H
#define _NODE_COMMON_H

#include "../internal.h"

typedef void (*operation)();
typedef int (*parameter_func)(char *param);

#define MAX_NAME_LENGTH 64

struct NODE_Base_s;

typedef int (*EventCallbackFunc)(struct NODE_Base_s *pstNode, char *pszEventName, void *pData, size_t szSize);

typedef struct SupportedParameter_s {
    char parameterName[MAX_NAME_LENGTH];
    size_t szSize;
}SupportedParameter_t;

typedef struct TrackingParameter_s {
    char parameterOwner[MAX_NAME_LENGTH];
    char parameterName[MAX_NAME_LENGTH];
    size_t szSize;
}TrackingParameter_t;

typedef struct SupportedEvent_s {
    char eventName[MAX_NAME_LENGTH];
}SupportedEvent_t;

typedef struct TrackingEvent_s {
    char eventOwner[MAX_NAME_LENGTH];
    char eventName[MAX_NAME_LENGTH];
}TrackingEvent_t;

typedef struct NODE_Operation_s {
    int (*Init)(struct NODE_Base_s *pstNode);
    int (*Deinit)(struct NODE_Base_s *pstNode);
    int (*Open)(struct NODE_Base_s *pstNode);
    int (*Close)(struct NODE_Base_s *pstNode);
    int (*Reset)(struct NODE_Base_s *pstNode);
    int (*Loop)(struct NODE_Base_s *pstNode);

    int (*SetParameter)(struct NODE_Base_s *pstNode, char *pszParameterName, void *pData, size_t szSize);
    int (*GetParameter)(struct NODE_Base_s *pstNode, char *pszParameterName, void *pData, size_t szSize);
    int (*GetSupportedParameterList)(struct NODE_Base_s *pstNode, SupportedParameter_t *pstSupportedParameter, size_t szSize);
    int (*GetSupportedParameterListSize)(struct NODE_Base_s *pstNode, size_t *pszSize);
    int (*GetTrackingParameterList)(struct NODE_Base_s *pstNode, TrackingParameter_t *pstTrackingParameter, size_t szSize);
    int (*GetTrackingParameterListSize)(struct NODE_Base_s *pstNode, size_t *pszSize);

    EventCallbackFunc OnEvent;
    int (*RegisterEventCallback)(struct NODE_Base_s *pstNode, EventCallbackFunc pfEventCallback);

    int (*GetSupportedEventList)(struct NODE_Base_s *pstNode, SupportedEvent_t *pstSupportedEvent, size_t szSize);
    int (*GetSupportedEventListSize)(struct NODE_Base_s *pstNode, size_t *pszSize);
    int (*GetTrackingEventList)(struct NODE_Base_s *pstNode, TrackingEvent_t *pstTrackingEvent, size_t szSize);
    int (*GetTrackingEventListSize)(struct NODE_Base_s *pstNode, size_t *pszSize);

}NODE_Operation_t;


typedef struct NODE_Base_s {
    char *name;
    NODE_Operation_t opts;
    EventCallbackFunc pfNotifyEvent;
}NODE_Base_t;

#define LOCAL_NODE_NUMBER_MAX     10




#endif
