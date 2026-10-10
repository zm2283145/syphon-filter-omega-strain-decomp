#include "types.h"
extern void* Group_FromHandle(int handle);
extern int func_003CB1C0(int handle);
extern unsigned char Script_IsGroupMember(void* group, int obj);
/* Script: cGroup.Contains(obj). */
int Script_cGroup_Contains(int* args)
{
    void* group = Group_FromHandle(args[0]);
    return Script_IsGroupMember(group, func_003CB1C0(args[1]));
}
