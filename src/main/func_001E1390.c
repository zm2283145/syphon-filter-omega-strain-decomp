#pragma cplusplus on
#include "types.h"
#pragma opt_common_subs off
struct It1E1390 { char* p; };
extern "C" {
char* func_001E1470(void* v);
char* func_001E1440(void* v);
void func_001E1460(It1E1390* out, void* v, char** p);
void func_001E12E0(void* self, char* elem);
}
static inline bool It1E1390_eq(char* a, char* b) { return a == b; }
static inline bool It1E1390_ne(char* a, char* b) { return !It1E1390_eq(a, b); }
extern "C" void func_001E1390(void* self, void* v)
{
    It1E1390 it;
    It1E1390 end;
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
    for (; It1E1390_ne(p, e); p += 4)
        func_001E12E0(self, p);
}