#include "types.h"

typedef struct FlagByteObj {
    char pad00[0x80];
    unsigned char flag; /* 0x80 */
} FlagByteObj;

/* Clears the flag byte at +0x80 if it is set. */
void func_00347690(FlagByteObj* obj) {
    if (obj->flag) {
        obj->flag = 0;
    }
}
