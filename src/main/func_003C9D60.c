#include "types.h"
extern void operator_delete(void*);
extern int D_004DFD80;
typedef struct { void* vt; } cMessageD4;
cMessageD4* cMessage_dtor(cMessageD4* p, short flag)
{
    if (p) {
        p->vt = &D_004DFD80;
        if (flag > 0) operator_delete(p);
    }
    return p;
}