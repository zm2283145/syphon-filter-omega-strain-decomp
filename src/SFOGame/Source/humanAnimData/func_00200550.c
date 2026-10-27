#include "types.h"
extern void cPointer_cSkaNode_dtor(void* p, int n);
extern void operator_delete(void* p);
void* cSkaAnimationBlend_dtor(void* p, short flag)
{
    if (p) {
        cPointer_cSkaNode_dtor(p, -1);
        if (flag > 0) {
            operator_delete(p);
        }
    }
    return p;
}