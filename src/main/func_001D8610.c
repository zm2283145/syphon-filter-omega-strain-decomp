#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Q_1D8610;
typedef struct {
    signed char b0, b1, b2, b3;
    unsigned char b4, b5;
    char pad6[0xA];
    Q_1D8610 v10;
    Q_1D8610 q20;
    Q_1D8610 q30;
    Q_1D8610 q40;
    Q_1D8610 q50;
    int w60;
    char pad64[0xC];
} E_1D8610;
extern void* Vec4_GetZero(void);
extern void Vec4_Assign(void* d, void* s);
extern void Quat_SetIdentity(Q_1D8610* q);
extern void func_00132800(Q_1D8610* d, Q_1D8610* s);
E_1D8610* UpperBodyLook_ClearRecords(E_1D8610* arr)
{
    E_1D8610* e = arr;
    do {
        Q_1D8610 qa;
        Q_1D8610 qb;
        Q_1D8610 qc;
        Q_1D8610 qd;
        e->b0 = -1;
        e->b1 = -1;
        e->b2 = -1;
        e->b3 = -1;
        e->b4 = 0;
        e->b5 = 0;
        Vec4_Assign(&e->v10, Vec4_GetZero());
        Quat_SetIdentity(&qa);
        func_00132800(&e->q20, &qa);
        Quat_SetIdentity(&qb);
        func_00132800(&e->q30, &qb);
        Quat_SetIdentity(&qc);
        func_00132800(&e->q40, &qc);
        Quat_SetIdentity(&qd);
        func_00132800(&e->q50, &qd);
        e->w60 = 0;
        e++;
    } while (e != arr + 2);
    return arr;
}