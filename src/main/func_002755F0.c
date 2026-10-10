#include "types.h"
typedef struct { char pad[0x110]; int w110; char pad2; unsigned char b115; char pad3; unsigned char b117; char pad4[0x150 - 0x118]; } E2755;
extern E2755 D_004FFE60[50];
extern void func_002757A0(E2755* e);
static inline int ok_2755(E2755* p) { return p->b117 != 0 || p->w110 != 0; }
void func_002755F0(void)
{
    int i;
    for (i = 0; i < 50; i++) {
        if (D_004FFE60[i].b115) {
            if (ok_2755(&D_004FFE60[i]))
                func_002757A0(&D_004FFE60[i]);
        }
    }
}