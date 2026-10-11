#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S369700 { int x0; char pad4[0x24]; int x28; char pad2C[0x10]; int x3C; unsigned char b40; unsigned char b41; char pad42[0xC4 - 0x42]; void* pC4; };
extern "C" {
extern char D_004BBDD0[];
void func_003A6F10(S369700* s);
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
static inline void Close369700(S369700* s)
{
    if (s->x0 >= 0) {
        func_003A6F10(s);
        if (s->b40) {
            void* p = s->pC4;
            if (p) {
                {
                    AllocGuard g;
                    Mem_Free(0, p, D_004BBDD0, 0x1DD);
                }
                s->x3C = 0;
            }
        }
        s->x0 = -1;
        s->x28 = 0;
        s->pC4 = 0;
        s->b41 = 0;
        s->b40 = 0;
        s->x3C = 0;
    }
}extern "C" S369700* func_00369700(S369700* self, short del)
{
    if (self) {
        Close369700(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}