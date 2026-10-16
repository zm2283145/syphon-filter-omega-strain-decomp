#include "types.h"

extern void* String_AssignCStr_1C43A0(void* obj);

/* Returns whether String_AssignCStr_1C43A0 yields null. */
int func_003EEAC0(void* obj) {
    return String_AssignCStr_1C43A0(obj) == 0;
}
