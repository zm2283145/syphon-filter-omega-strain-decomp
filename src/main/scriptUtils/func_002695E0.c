#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct NodeList {
    char pad[0x60];
    void* group;
} NodeList;

extern int func_0015C120(int);
extern NodeList* func_00269810(void*);
extern int func_003D9C80(void*, int);

/* Script: cNodeList.Contains(node). */
int Script_cNodeList_Contains(ScriptArg* args) {
    int node = func_0015C120(args[1].i);
    return func_003D9C80(func_00269810(args[0].p)->group, node) != -1;
}
