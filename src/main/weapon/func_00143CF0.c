#include "types.h"
typedef struct { char pad[0x85]; unsigned char item; } Inv3CF0;
extern void func_00142C50(Inv3CF0* p, int item);
void func_00143CF0(Inv3CF0* p) {
    if (p->item != 6) {
        func_00142C50(p, ((signed char*)p)[0x85]);
    }
}