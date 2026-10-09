/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048A158[];
extern char D_0048A160[];
extern char D_004DA3E0[]; /* vtable */
extern int PhysicalBase_Construct(char* self, char*, char*);

/* Constructor: base construct, set vtable, clear words +0x38 and +0x3C. */
char* func_0017F2E0(char* self) {
    PhysicalBase_Construct(self, D_0048A158, D_0048A160);
    *(char**)self = D_004DA3E0;
    *(int*)(self + 0x38) = 0;
    *(int*)(self + 0x3C) = 0;
    return self;
}
