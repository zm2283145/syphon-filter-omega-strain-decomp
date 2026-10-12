#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int WeaponInv_SlotOfItem(int);                             

int func_002553E0(int self, int *output, char * table) {
    char *slot;
    int count;
    int deferred;
    int index;
    int item;
    int fallback;

    slot = (char *)(self + 0x64);
    count = 0;
    deferred = -1;
    index = 0;
    do {
        if (F_(slot, 0xCC, int) != 0) {
            item = F_(slot, 0x24, int);
            if ((WeaponInv_SlotOfItem(item) & 0xFF) == 6) {
                deferred = item;
            } else {
                *output = item;
                output += 1;
                count += 1;
            }
        } else if (F_(slot, 0xD0, unsigned char) != 0) {
            fallback = F_((table + (F_(slot, 0x0, unsigned char) * 0x10)), 0x8, int);
            if (fallback != -1) {
                *output = fallback;
                count += 1;
                output += 1;
            }
        }
        index += 1;
        slot += 0xD4;
    } while (index < 3);
    if (deferred >= 0) {
        if (count != 0) {
            if (deferred != F_(table, 0x68, int)) {
                goto append_deferred;
            }
        } else {
append_deferred:
            *output = deferred;
            count += 1;
        }
    }
    return count;
}
