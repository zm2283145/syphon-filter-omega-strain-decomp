#include "types.h"
typedef struct { int unk0; int begin; int end; int unkC; int unk10; } Obj00158980;
extern void func_0015B860(int* result, Obj00158980* obj, int* end, int** begin);
/* Clear the range [begin, end) and reset fields 0xC and 0x10. */
void func_00158980(Obj00158980* obj)
{
    int* begin = &obj->begin;
    int end = obj->end;
    int result;
    func_0015B860(&result, obj, &end, &begin);
    obj->unkC = 0;
    obj->unk10 = 0;
}
