#include "types.h"

typedef struct Human3468 {
    char pad[0x3468];
    unsigned char flagA;
    unsigned char flagB;
    char pad2[0x3528 - 0x346A];
    int handle;
} Human3468;

extern int func_004704F0(int handle);

/* True when neither flag is set and func_004704F0(handle) returns 0 (as a byte). */
int func_001A3730(Human3468* h) {
    int result = !(h->flagA != 0 || h->flagB != 0);
    if (result) {
        result = (unsigned char)func_004704F0(h->handle) == 0;
    }
    return result;
}
