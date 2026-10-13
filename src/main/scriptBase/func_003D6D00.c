#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
#pragma opt_strength_reduction off
extern "C" {
extern char D_004BD3B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
int strlen(const char* s);
void* memcpy(void* d, const void* s, int n);
void PtrVector_Resize(void* v, int n, int* val);
}
typedef struct { char* name; int id; int val; } E6D00;
typedef struct { int pad0; int count; E6D00** data; } V6D00;
typedef struct { int pad0; V6D00 vec; char pad10[0x3C - 0x10]; unsigned char b3C; char pad3D[3]; int x40; unsigned char b44; char pad45[3]; int x48; } S6D00;
static inline void* SD_Alloc(int n, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, n, D_004BD3B0, line);
}
static inline char* Dup(char* s)
{
    char* p = 0;
    if (s) {
        int len = strlen(s) + 1;
        int n = (len + 31) / 32 * 32;
        p = (char*)SD_Alloc(n, 0x130);
        memcpy(p, s, n);
    }
    return p;
}
extern "C" void func_003D6D00(S6D00* self, int n, char** names, int* vals, int x40, int base)
{
    int i;
    int zero;
    self->x40 = x40;
    zero = 0;
    PtrVector_Resize(&self->vec, n, &zero);
    self->b44 = 1;
    self->b3C = 1;
    self->x48 = base + n;
    for (i = 0; i < n; i++) {
        E6D00** slot = &self->vec.data[i];
        E6D00* e = (E6D00*)SD_Alloc(0xC, 0x17F);
        if (e) {
            char* nm = *names;
            int v = *vals;
            char* d = Dup(nm);
            e->id = base + i;
            e->val = v;
            e->name = d;
        }
        *slot = e;
        vals++;
        names++;
    }
}


