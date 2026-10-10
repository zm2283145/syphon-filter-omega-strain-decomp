#include "types.h"

extern void ObjectList_EraseRange(int* out, int* key, int* value, int** ref);
extern int D_004EA190, D_004EA194, D_004EA198;
extern int D_004EA370, D_004EA374, D_004EA378;
extern int D_004EA1B0, D_004EA1B4, D_004EA1B8;

/* Registers three static (key, value, ref) triples via ObjectList_EraseRange. */
void func_001589D0(void) {
    int* ref3;
    int value3;
    int out3;
    int* ref2;
    int value2;
    int out2;
    int* ref1;
    int value1;
    int out1;

    ref1 = &D_004EA194;
    value1 = D_004EA198;
    ObjectList_EraseRange(&out1, &D_004EA190, &value1, &ref1);
    ref2 = &D_004EA374;
    value2 = D_004EA378;
    ObjectList_EraseRange(&out2, &D_004EA370, &value2, &ref2);
    ref3 = &D_004EA1B4;
    value3 = D_004EA1B8;
    ObjectList_EraseRange(&out3, &D_004EA1B0, &value3, &ref3);
}
