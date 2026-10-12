#include "types.h"
extern int Script_IsGroupMember(void* g, void* o);
extern void func_003D7930(char* msg);
extern void Group_AddObjectDup(void* g, void* o);
void Group_AddObject(void* g, void* o)
{
    if (Script_IsGroupMember(g, o)) {
        func_003D7930("warning: obj already part of group (not added).");
    } else {
        Group_AddObjectDup(g, o);
    }
}