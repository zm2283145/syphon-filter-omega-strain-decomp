#pragma opt_strength_reduction off
#include "types.h"

/* Remove every entry equal to *value (swap with last), then shrink. */
typedef struct { int pad0; int count; int* data; } PtrVec_393600;
extern void PtrVector_Resize(PtrVec_393600* v, int n, int* fill);

void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Remove_OrderNotPreserved(PtrVec_393600* v, int* value)
{
    int i;
    int last = v->count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == *value) {
            *e = v->data[last];
            last--;
        }
    }
    fill = 0;
    PtrVector_Resize(v, last + 1, &fill);
}
#pragma opt_strength_reduction reset
