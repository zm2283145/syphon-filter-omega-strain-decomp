/*
 * Matched functions (byte-identical with the retail executable).
 * Calls two helpers with the same arguments.
 */

#include "types.h"
#include "path_types.h"

extern int func_0015FFD0(void* a0, int a1);
extern void func_00160C40(void* a0, int a1);

void func_0015FF90(void* a0, int a1) {
    func_0015FFD0(a0, a1);
    func_00160C40(a0, a1);
}
