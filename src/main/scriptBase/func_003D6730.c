#include "types.h"
typedef struct { int val; char* name; int pad; } E6730;
typedef struct { char* name; int pad; int count; E6730* ents; } S6730;
typedef struct { char pad[0xA8]; int* cur; } W6730;
extern int strlen(const char* s);
extern void func_003D6580(W6730* w, int n);
extern int func_003D6570(W6730* w, int n);
extern void func_003D63C0(W6730* w, int n);
extern void String_Copy(void* d, const char* s);
static inline void WStr6730(W6730* w, const char* s)
{
    int n = strlen(s) + 1;
    func_003D6580(w, n);
    n = func_003D6570(w, n);
    func_003D63C0(w, n);
    String_Copy(w->cur, s);
    w->cur += n;
}
static inline void WInt6730(W6730* w, int v)
{
    func_003D63C0(w, 1);
    *w->cur++ = v;
}
#pragma opt_strength_reduction off
void func_003D6730(S6730* s, W6730* w)
{
    int n;
    int i;
    WStr6730(w, s->name);
    n = s->count;
    WInt6730(w, n);
    for (i = 0; i < n; i++) {
        WStr6730(w, s->ents[i].name);
        WInt6730(w, s->ents[i].val);
    }
}
