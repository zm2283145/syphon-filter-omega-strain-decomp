#include "types.h"
typedef struct { int m0; void* m4; } T25C0;
extern void func_003E3060(T25C0* t, void* n);
extern void operator_delete(void* p);
T25C0* func_003E25C0(T25C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_003E3060(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
