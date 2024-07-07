#ifndef _NODE_COMMON_H
#define _NODE_COMMON_H

typedef void (*operation)();
typedef int (*parameter_func)(char *param);

typedef struct NODE_Operation_s {
    operation init;
    operation deinit;
    operation open;
    operation close;
    operation loop;
    parameter_func set_param;
    parameter_func get_param;
}NODE_Operation_t;


typedef struct NODE_Base_s {
    char *name;
    NODE_Operation_t opts;
}NODE_Base_t;

#define LOCAL_NODE_NUMBER_MAX     10




#endif
