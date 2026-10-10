#include "types.h"
extern int Script_IsGroupMember(void* g, void* o);
extern void func_003D7930(char* msg);
extern void Group_AddObjectDup(void* g, void* o);
extern char D_004BD490[];
void Group_AddObject(void* g, void* o)
{
    if (Script_IsGroupMember(g, o)) {
        func_003D7930(D_004BD490);
    } else {
        Group_AddObjectDup(g, o);
    }
}