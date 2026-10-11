#include "types.h"
typedef struct { void* root; } R1Tree_31660;
typedef struct { R1Tree_31660 tree; } R1Own_31660;
extern void** func_004316E0(R1Tree_31660* t);
extern void func_004307E0(R1Tree_31660* t, void* n);
extern void operator_delete(void* p);
static inline void R1TreeDtor_31660(R1Tree_31660* t)
{
    if (*func_004316E0(t))
        func_004307E0(t, *func_004316E0(t));
}
R1Own_31660* func_00431660(R1Own_31660* o, short del)
{
    if (o) {
        R1Tree_31660* t = &o->tree;
        if (t)
            R1TreeDtor_31660(t);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}