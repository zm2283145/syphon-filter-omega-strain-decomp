#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S36D680 { unsigned int flags; char name[0x94]; int* f; };
extern "C" {
extern char D_004BBF90[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
int func_003696B0(void* f, void* name, int mode);
void func_00369700(void* f, int how);
int* func_00369870(void* p);
}
static inline void* New36D680()
{
    AllocGuard g;
    return Mem_Alloc(0, 0xC8, D_004BBF90, 0x21A);
}
static inline void Del36D680(int* f)
{
    AllocGuard g;
    func_00369700(f, -1);
    Mem_Free(0, f, D_004BBF90, 0x235);
}
extern "C" int func_0036D680(S36D680* o)
{
    unsigned char open = 1;
    int err = 0;
    if (!o->f) {
        int* p = (int*)New36D680();
        if (p) p = func_00369870(p);
        o->f = p;
        o->flags |= 0x10;
    } else if (*o->f >= 0) {
        open = 0;
    }
    if (open) {
        if (o->flags & 4) {
            func_003696B0(o->f, o->name, 0x8000);
            err = 3;
        } else if (!func_003696B0(o->f, o->name, 1)) {
            err = 3;
        }
    }
    if ((unsigned char)err && (o->flags & 0x10)) {
        Del36D680(o->f);
        o->flags &= ~0x10;
    }
    return err;
}

