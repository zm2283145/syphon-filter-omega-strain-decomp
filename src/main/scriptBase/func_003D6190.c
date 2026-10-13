#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BD3B0[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
int strlen(const char* s);
void* memcpy(void* d, const void* s, unsigned int n);
}
struct S6190 {
    char* name;
    int a;
    unsigned char has;
    int b;
    int c10;
    int c14;
    unsigned char b18;
    unsigned char b19;
};
static inline char* Alloc6190(int n) {
    AllocGuard g;
    return (char*)Mem_Alloc(0, n, D_004BD3B0, 0x130);
}
static inline int Round6190(int n) { return (n + 31) / 32 * 32; }
extern "C" S6190* func_003D6190(S6190* s, const char* name, int a, int b, unsigned char f)
{
    char* p = 0;
    if (name) {
        int n = Round6190(strlen(name) + 1);
        p = Alloc6190(n);
        memcpy(p, name, n);
    }
    s->name = p;
    s->a = a;
    s->has = b != 0;
    s->b = b;
    s->c10 = 0;
    s->c14 = 0;
    s->b18 = 0;
    s->b19 = f;
    return s;
}
