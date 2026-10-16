#include "types.h"
extern int Script_IsGroupMember(void* g, void* o);
extern void Script_PrintWarning(char* msg);
extern void Group_AddObjectDup(void* g, void* o);
void Group_AddObject(void* g, void* o)
{
    if (Script_IsGroupMember(g, o)) {
        Script_PrintWarning("warning: obj already part of group (not added).");
    } else {
        Group_AddObjectDup(g, o);
    }
}