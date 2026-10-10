#include "types.h"
#pragma opt_strength_reduction off
typedef struct { char pad[0x2F3]; unsigned char b2F3; char pad2[0x308 - 0x2F4]; int x308; } G3E_00257040;
typedef struct { int pad; int count; G3E_00257040** items; } G3L_00257040;
extern unsigned char D_005721C8;
extern G3L_00257040* D_004F7F30;
void func_00257040(int x) {
    if (D_005721C8) {
        G3L_00257040* l = D_004F7F30;
        int i;
        for (i = 0; i < l->count; i++) {
            G3E_00257040* e = l->items[i];
            if (!e->b2F3) {
                int* p = &e->x308;
                if (x == *p) *p = 0;
            }
        }
    }
}