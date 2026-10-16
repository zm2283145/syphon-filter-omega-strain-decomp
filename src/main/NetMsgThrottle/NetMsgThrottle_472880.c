/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "types.h"

extern int func_00471F90(void* obj, int arg);

void* func_00472880(char* self) {
    return self + 4;
}

void func_00472890(int unused, char* obj) {
    if (obj != 0) {
        func_00471F90(obj + 4, -1);
    }
}

void* func_004728C0(void* self) {
    return self;
}
