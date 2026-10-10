#include "types.h"
extern int func_002E9A98(void* hdr, void* dst, int size, int count);
unsigned char func_003C9C30(char* s) {
    unsigned char ok = 0;
    if (func_002E9A98(s, s, 4, 1) != 0) goto out;
    if (func_002E9A98(s, s + 4, 4, 1) != 0) goto out;
    ok = 1;
out:
    return ok;
}