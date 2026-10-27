#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
#include "alloc_guard.h"
/* cScriptBase_registerEnum: create a script enum (name, value items with the "scope:" prefix stripped) and register it */
extern "C" {
extern char D_004BD3B0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
int strlen(const char* s);
void* memcpy(void* d, const void* s, int n);
char* strrchr(const char* s, int c);
}
struct EItem { int value; char* name; char* full; };
struct EVec { int cap; int count; EItem* data; };
struct SEnum { char* name; EVec items; int pad10; int id; };
struct SReg { int pad; int base; };
extern "C" {
extern SReg* D_00554F30;
void cScriptBase_checkInitTypes(void* src);
char* buildNameWithPrefix(void* src);
void cArray_EnumField_ctor(EVec* v, int n, const EItem& fill);
void std_vector_EnumDefPtr_push_back(SReg* r, SEnum** e);
int cScriptBase_registerEnum(void* src, EItem* items, int n);
}
static inline void* SD_Alloc(int n, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, n, D_004BD3B0, line);
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
static inline void Resize_8F60(EVec* v, int n, const EItem& f = EItem()) { cArray_EnumField_ctor(v, n, f); }
#pragma opt_strength_reduction off
int cScriptBase_registerEnum(void* src, EItem* items, int n)
{
    char* name;
    SEnum* e;
    int i;
    SEnum* r;
    cScriptBase_checkInitTypes(src);
    name = buildNameWithPrefix(src);
    e = (SEnum*)SD_Alloc(24, 100);
    if (e) {
        int base = D_00554F30->base;
        char* d = Dup(name);
        Resize_8F60(&e->items, n);
        e->name = d;
        e->id = base + 10;
    }
    r = e;
    for (i = 0; i < n; i++) {
        EItem* it;
        char* c;
        r->items.data[i] = *items;
        it = &r->items.data[i];
        it->full = it->name;
        c = strrchr(it->name, ':');
        if (c) it->name = c + 1;
        items++;
    }
    std_vector_EnumDefPtr_push_back(D_00554F30, &r);
    return r->id;
}
