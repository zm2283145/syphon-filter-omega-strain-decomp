#pragma cplusplus on
#include "types.h"
struct It1D7A20 { char* p; };
extern "C" {
char* func_001D7B10(void* v);
char* func_001D7AD0(void* v);
void func_001D7B00(It1D7A20* out, void* v, char** p);
extern char* D_004F32B0[];
}
struct O1D7A20 { int pad; char* list; };
static inline bool It1D7A20_eq(char* a, char* b) { return a == b; }
static inline bool It1D7A20_ne(char* a, char* b) { return !It1D7A20_eq(a, b); }
extern "C" void func_001D7A20(O1D7A20* o)
{
    void* v = o->list + 0x18;
    It1D7A20 it;
    It1D7A20 end;
    char* p;
    {
        char* t = func_001D7B10(v);
        func_001D7B00(&it, v, &t);
    }
    p = it.p;
    {
        char* t = func_001D7AD0(v);
        func_001D7B00(&end, v, &t);
    }
    char** out = D_004F32B0;
    char* e = end.p;
    for (; It1D7A20_ne(p, e); p += 0x1D0) {
        *out = p;
        out += 0x40;
    }
}