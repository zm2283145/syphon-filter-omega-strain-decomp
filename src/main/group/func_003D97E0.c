#include "types.h"
extern void* Group_FromHandle(int handle);
extern void func_003D99F0(void* group);
/* Script: cGroup.Print(). */
int Script_cGroup_Print(int* args)
{
    func_003D99F0(Group_FromHandle(args[0]));
    return 0;
}
