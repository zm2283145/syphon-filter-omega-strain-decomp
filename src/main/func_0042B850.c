/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between DME.cc (ends 0x0042ACD0) and nellymoser_wrapper.c.
 */

#include "types.h"

extern char D_005721B0;
extern char D_005724B8[];
extern int func_002EBC48(void* obj);

void* func_0042B850(void* self) {
    D_005721B0 = 0;
    func_002EBC48(D_005724B8);
    return self;
}
