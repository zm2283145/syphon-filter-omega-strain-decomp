#include "types.h"
typedef struct { char pad[0x14]; int x14; char x18[1]; } Los13AB50;
extern void nArray_InitSlots_cGOBJPP_int_int_cGOBJPR(void*, int, int, int*);
extern void cArray_FixedCapacity_cGOBJPtr_2_ResizeActual(int*, int, int*);
void cCollisionModelList_Resize_ExclusionList(Los13AB50* p, unsigned int n) {
    int a[1];
    int b[1];
    a[0] = 0;
    if (n < 3) {
        nArray_InitSlots_cGOBJPP_int_int_cGOBJPR(p->x18, p->x14, n - 1, a);
        p->x14 = n;
    } else {
        b[0] = 0;
        cArray_FixedCapacity_cGOBJPtr_2_ResizeActual(&p->x14, 2, b);
    }
}