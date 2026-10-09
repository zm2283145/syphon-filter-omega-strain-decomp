/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DB810[];
extern int func_001391E0(int);
extern int func_003CB110(int);
extern int func_0040F650(void);

int func_00229E60(int a0) {
    func_003CB110(a0);
    *(int*)((char*)a0) = (int)D_004DB810;
    func_001391E0((a0 + 44));
    func_0040F650();
    return a0;
}
