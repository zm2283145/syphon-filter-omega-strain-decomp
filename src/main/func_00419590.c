#include "types.h"
typedef struct { char p[8]; void* item; } Node419590;
typedef struct { int size; int pad; Node419590* first; } List419590;
typedef struct { char p[0x14]; List419590 a; List419590 b; char s[0x10]; } Obj419590;
extern void func_00418E00(Obj419590* o, void* item, int f);
extern void func_00138B70(void* p, int f);
extern void func_002CCD80(void* p, int f);
extern void func_00419660(Obj419590* p, int f);
extern void operator_delete(void* p);
Obj419590* func_00419590(Obj419590* self, short del)
{
    if (self) {
        while (self->a.size) func_00418E00(self, self->a.first->item, 1);
        if (self->s) func_00138B70(self->s, 0);
        if (&self->b) func_002CCD80(&self->b, 0);
        if (&self->a) func_002CCD80(&self->a, 0);
        if (self) func_00419660(self, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}
