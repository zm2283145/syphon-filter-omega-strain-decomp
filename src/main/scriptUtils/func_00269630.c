#include "types.h"
typedef struct { char pad[0x60]; void* list; } Obj00269630;
extern int func_0015C120(int handle);
extern Obj00269630* func_00269810(int handle);
extern int func_003D9C80(void* list, int key);
/* Script: cNodeList.Find(key). */
int Script_cNodeList_Find(int* args)
{
    int key = func_0015C120(args[1]);
    volatile int result = func_003D9C80(func_00269810(args[0])->list, key);
    return result;
}
