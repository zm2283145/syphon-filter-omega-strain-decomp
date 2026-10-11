#include "types.h"
typedef struct { int m0; void* m4; } TB5C0;
extern void func_0013F310(TB5C0* t, void* n);
extern void operator_delete(void* p);
TB5C0* func_0013F090(TB5C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_0013F310(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
