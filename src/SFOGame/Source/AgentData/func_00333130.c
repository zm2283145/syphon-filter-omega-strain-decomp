/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData flag helper.
 */

#include "types.h"

extern unsigned char* cAgentData_FindRequirement(int a0, int a1, int a2);

/* Looks up a flag byte and sets it if it is still clear. */
void cAgentData_UnlockRequirement(int a0, int a1, int a2) {
    unsigned char* flag = cAgentData_FindRequirement(a0, a1, a2);
    if (flag != 0 && *flag == 0) {
        *flag = 1;
    }
}
