#include "types.h"
typedef struct { char pad[0xC]; } E413F20;
typedef struct { int x; int size; E413F20* data; } V413F20;
extern void String_Dtor(void* e, int f);
static inline void destroy_(E413F20* p) { if (p) String_Dtor(p, 0); }
void func_00413F20(V413F20* v)
{
    E413F20* b = v->data;
    E413F20* e = b + v->size;
    while (b < e) {
        destroy_(--e);
    }
    v->size = 0;
}