#include "types.h"
typedef struct { int m0; void* m4; } T3F80;
extern void func_003E4090(T3F80* t, void* n);
extern void operator_delete(void* p);
T3F80* func_003E3F80(T3F80* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_003E4090(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
