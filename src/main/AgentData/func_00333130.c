/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData flag helper.
 */

#include "types.h"

extern unsigned char* func_00333170(int a0, int a1, int a2);

/* Looks up a flag byte and sets it if it is still clear. */
void func_00333130(int a0, int a1, int a2) {
    unsigned char* flag = func_00333170(a0, a1, a2);
    if (flag != 0 && *flag == 0) {
        *flag = 1;
    }
}
