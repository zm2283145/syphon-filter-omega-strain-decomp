#include "types.h"
typedef struct { void* node; } It1F3280;
extern void func_0013B160(It1F3280* out, void* list);
extern void List_InsertBefore(It1F3280* out, void* list, It1F3280* pos, void* value);
#pragma optimization_level 1
void func_001F3280(void* list, void* value)
{
    It1F3280 r;
    It1F3280 pos;
    func_0013B160(&pos, list);
    List_InsertBefore(&r, list, &pos, value);
}
#pragma optimization_level reset