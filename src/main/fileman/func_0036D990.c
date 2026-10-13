#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char* p0; int p4; char* p8; unsigned char c; } H36D990;
typedef struct { unsigned int flags; char pad[0x80]; short idx; H36D990 h; char* a98; } S36D990;
extern "C" {
extern char D_004BBF90[];
void* Mem_Alloc(int pool, int size, char* file, int line);
int FileHal_Read(void* f, void* buf, int size, int off);
int func_0036CAC0(void* f, int idx, void* buf, int off);
int func_0036D380(void* f, int idx);
char* func_0036D4E0(void* f, int idx);
}
static inline char* Get(H36D990* h) { return h->p8 ? h->p8 : h->p0; }
static inline int GetSize(S36D990* o)
{
    unsigned int f = o->flags;
    if (f & 2) return func_0036D380(o->a98, o->idx);
    if (f & 1) return (*(int*)(o->a98 + 0x2C) / 0x800) * 0x800 + 0x800;
    return 0;
}
static inline void* Alloc36D990(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BBF90, line);
}
extern "C" int func_0036D990(S36D990* o, char** out, int size)
{
    unsigned int f;
    int err;
    H36D990* h;
    int sz;
    if (size) sz = size; else sz = GetSize(o);
    f = o->flags;
    err = 0;
    h = &o->h;
    if ((f & 4) && h->c) {
        *out = Get(h);
    } else if (f & 2) {
        char* d = o->a98;
        if (*(unsigned char*)(d + 0x14C) == 2) {
            if (h->c) {
                *out = Get(h);
            } else {
                if (!*out) *out = (char*)Alloc36D990(sz, 0x176);
                if (func_0036CAC0(o->a98, o->idx, *out, 0)) err = 4;
            }
        } else {
            *out = func_0036D4E0(d, o->idx);
        }
    } else if (f & 1) {
        if (!*out) *out = (char*)Alloc36D990(sz, 0x18F);
        if (!FileHal_Read(o->a98, *out, sz, 0)) err = 4;
    } else {
        err = 5;
    }
    return err;
}

