#pragma cplusplus on
#include "types.h"
struct It1E1480 { char* p; };
struct E1E1480 { char pad[0x30]; unsigned char kind; };
extern "C" {
char* func_001E1470(void* v);
char* func_001E1440(void* v);
void func_001E1460(It1E1480* out, void* v, char** p);
int ColEdge_AreConnected(E1E1480* a, E1E1480* b, float x, float y, float z);
static const float dat_004A0360[2] = { 0.707f, 0.0f };
extern float D_004A0368;
extern float D_004A0370;
}
static inline bool It1E1480_eq(char* a, char* b) { return a == b; }
static inline bool It1E1480_ne(char* a, char* b) { return !It1E1480_eq(a, b); }
extern "C" bool func_001E1480(void* v, E1E1480* k)
{
    It1E1480 it;
    It1E1480 end;
    char* p;
    char* e;
    {
        char* t = func_001E1470(v);
        func_001E1460(&it, v, &t);
    }
    p = it.p;
    {
        char* t = func_001E1440(v);
        func_001E1460(&end, v, &t);
    }
    e = end.p;
    if (It1E1480_ne(p, *(char* volatile*)&end.p)) {
        do {
            E1E1480* x = *(E1E1480**)p;
            if ((x->kind & ~0x80) == (k->kind & ~0x80) && ColEdge_AreConnected(x, k, (*(float*)dat_004A0360), D_004A0368, D_004A0370)) return true;
            p += 4;
        } while (It1E1480_ne(p, e));
    }
    return false;
}
