#include "types.h"

typedef struct Human3468 {
    char pad[0x3468];
    unsigned char flagA;
    unsigned char flagB;
    char pad2[0x3528 - 0x346A];
    int handle;
} Human3468;

extern int ItemInv_Any(int handle);

/* True when neither flag is set and ItemInv_Any(handle) returns 0 (as a byte). */
int cHuman_CanPackBeDeleted(Human3468* h) {
    int result = !(h->flagA != 0 || h->flagB != 0);
    if (result) {
        result = (unsigned char)ItemInv_Any(h->handle) == 0;
    }
    return result;
}
